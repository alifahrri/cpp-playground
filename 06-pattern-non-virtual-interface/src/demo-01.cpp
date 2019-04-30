#include <chrono>
#include <thread>
#include <cstdio>
#include <memory>
#include <iostream>

class BaseProcess
{
public:
    void process() {
        std::cout << __PRETTY_FUNCTION__ << " calling preprocess : " << std::endl;
        preporcess();
        while(!done()) {
            std::cout << __PRETTY_FUNCTION__ << " doing work : " << std::endl;
            work();
        }
        std::cout << __PRETTY_FUNCTION__ << " calling postprocess : " << std::endl;
        postporcess();
    }
private:
    virtual void preporcess() = 0;
    virtual void postporcess() = 0;
    virtual void work() = 0;
    virtual bool done() = 0;
};

class DummyProcess : public BaseProcess
{
private:
    void preporcess() {
        std::cout << __PRETTY_FUNCTION__ << " : doing preprocessing" << std::endl;
        counter = 0; // reset counter
    }
    void postporcess() {
        std::cout << __PRETTY_FUNCTION__ << " : done! see you" << std::endl;
    }
    bool done() {
        return counter == target_count;
    }
    void work() {
        std::cout << __PRETTY_FUNCTION__ << " : incrementing the counter" << std::endl;;
        counter++;
    }
private:
    size_t counter = 0;
    static constexpr size_t target_count = 9;
};

class FakeProcess : public BaseProcess
{
private:
    void preporcess() {
        std::cout << __PRETTY_FUNCTION__ << " : doing preprocessing" << std::endl;
        t0 = std::chrono::high_resolution_clock::now();
    }
    void postporcess() {
        std::cout << __PRETTY_FUNCTION__ << " : done! see you" << std::endl;
    }
    bool done() {
        auto dt = std::chrono::high_resolution_clock::now() - t0;
        return dt.count() > target_count;
    }
    void work() {
        std::cout << __PRETTY_FUNCTION__ << " : sleeping for 500ms" << std::endl;;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
private:
    decltype(std::chrono::high_resolution_clock::now()) t0;
    static constexpr size_t target_count = 3e9;
};

int main(int argc, char**argv)
{
    auto dummy_ptr = std::make_shared<DummyProcess>();
    auto fake_ptr = std::make_shared<FakeProcess>();

    std::shared_ptr<BaseProcess> base_ptr;
    base_ptr = dummy_ptr;
    base_ptr->process();
    base_ptr = fake_ptr;
    base_ptr->process();
    return 0;
}