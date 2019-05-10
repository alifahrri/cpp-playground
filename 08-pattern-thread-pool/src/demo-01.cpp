#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t);
    template <class F, class ... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

ThreadPool::ThreadPool(size_t n_threads)
    : stop(false)
{
    for(size_t i=0; i<n_threads; i++) {
        workers.emplace_back([this]{
            for(;;) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    this->condition.wait(lock,[this]{
                        return this->stop || !this->tasks.empty(); 
                    });
                    if(this->stop && this->tasks.empty())
                        return;
                    task = std::move(this->tasks.front());
                    this->tasks.pop();
                }
                task();
            }
        });
    }
}

template <class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&& ...args) 
    -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_t = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<return_t()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    std::future<return_t> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        if(stop) {
            throw std::runtime_error("enqueue on stopped thread pool!");
        }
        tasks.emplace([task](){
            (*task)();
        });
    }
    condition.notify_one();
    return res;
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for(auto &worker : workers)
        worker.join();
}

struct printer_t {
    template <typename T>
    void operator()(const T &str) {
        std::unique_lock<std::mutex> lock(mutex);
        std::cout << str;
    }
    std::mutex mutex;
};

int main(int argc, char **argv)
{
    std::cout << "main thread id : " << std::this_thread::get_id() << std::endl;
    ThreadPool thread_pool(4);
    std::vector<std::future<size_t>> resuts;
    printer_t printer;
    for(size_t i=0; i<8; i++) {
        resuts.emplace_back(
            thread_pool.enqueue([i, &printer]{
                std::stringstream ss;
                ss << __PRETTY_FUNCTION__ 
                    << " from thread : " << std::this_thread::get_id() 
                    << "; i : " << i << "\n";
                printer(ss.str());
                std::this_thread::sleep_for(std::chrono::seconds(1));
                return i*i;
            })
        );
    }

    std::this_thread::sleep_for(std::chrono::seconds(1));
    for(auto && result : resuts) {
        std::stringstream ss;
        ss << result.get() << "; ";
        printer(ss.str());
    }
    std::cout << std::endl;

    return 0;
}