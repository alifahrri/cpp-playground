#ifndef THREAD_EXECUTOR_HPP
#define THREAD_EXECUTOR_HPP

#include "choice.hpp"
#include <thread>
#include <utility>
#include <iostream>

// see https://en.wikipedia.org/wiki/Asynchronous_method_invocation
class ThreadExecutor {
private:
	std::thread thread;
public:
	ThreadExecutor() {
		std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
	}
	~ThreadExecutor() {
		std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
		if(thread.joinable()) {
			std::cout << std::this_thread::get_id() << ": "
				<< "joining thread" << std::endl;
			thread.join();
			std::cout << std::this_thread::get_id() << ": "
				<< "joined!" << std::endl;
		}
	}
	template <typename Callable, typename Callback, typename ... Args>
	void operator()(Callable &function, Callback &callback, Args ... args) {
		std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
		if(thread.joinable()) {
			std::cout << std::this_thread::get_id() << ": "
				<< "joining thread" << std::endl;
			thread.join();
		}
		std::cout << std::this_thread::get_id() << ": "
			<< "starting thread" << std::endl;
		thread = std::thread([&, callback=std::move(callback)]{
			function(args...);
			callback_impl(choice<1>{},callback);		
		});
	}
private:
	template <typename Callback, typename ... Args>
	auto callback_impl(choice<1>, Callback &callback, Args ... args) 
		->decltype(callback(args...))
	{
		return callback(args...);	
	}
	template <typename Callback, typename ... Args>
	auto callback_impl(choice<0>, Callback &callback, Args ... args) 
		->decltype((*callback)(args...))
	{	
		return (*callback)(args...);	
	}
	template <typename Callback, typename ... Args>
	auto callback_impl(choice<1>, const Callback &callback, Args ... args) 
		->decltype(callback(args...))
	{
		return callback(args...);	
	}
	template <typename Callback, typename ... Args>
	auto callback_impl(choice<0>, const Callback &callback, Args ... args) 
		->decltype((*callback)(args...))
	{	
		return (*callback)(args...);	
	}
};
#endif // THREAD_EXECUTOR_HPP
