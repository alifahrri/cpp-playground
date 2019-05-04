#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
 
class Worker
{
public:
    Worker() 
        : processed(false) 
        , ready(false)
    {
        std::cout << "thread " << std::this_thread::get_id() << " starting worker thread\n";
        thread = std::thread(&Worker::process, this);
    }
    ~Worker() {
        if(thread.joinable())
            thread.join();
    }
    void set_data(const std::string &data) 
    {
        std::lock_guard<std::mutex> lock(mutex);
        this->data = data;
        ready = true;
        std::cout << "thread " << std::this_thread::get_id() << " signals data ready for processing\n";
        cv.notify_one();
    }
    std::string get_processed_data() 
    {
        std::unique_lock<std::mutex> lock(mutex);
        std::cout << "thread " << std::this_thread::get_id() << " waits for processed data\n";
        cv.wait(lock, [&]{ return processed; });
        return data;
    }
private:
    void process() 
    {
        std::cout << "thread " << std::this_thread::get_id() << " process loop, waiting for data ready signal\n";
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [&]{ return ready; });

        std::cout << "Worker thread " << std::this_thread::get_id() << " is processing data\n";
        data += " after processing";

        processed = true;
        std::cout << "Worker thread " << std::this_thread::get_id() << " signals data processing completed\n";

        lock.unlock();
        cv.notify_one();
    }
private:
    std::thread thread;
    std::mutex mutex;
    std::condition_variable cv;
    std::string data;
    bool ready;
    bool processed;
};
 
int main()
{
    Worker worker;
    worker.set_data("Example data");
    auto processed_data = worker.get_processed_data();
    std::cout << "main thread (" << std::this_thread::get_id() << "); data = " << processed_data << std::endl;
    return 0;
}