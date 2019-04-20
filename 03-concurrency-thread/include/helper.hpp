#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include <thread>

namespace helper {
	void f00() {
		std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
	}
	template <typename ...Args>
	void f01(Args ...args) {
		std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
	}
	template <typename Callable, typename ...Args>
	void f02(Callable callable, Args ...args) {
		std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
		callable(args...);
	}
	struct Functor00 {
		Functor00() {
			std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
		}
		~Functor00() {
			std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
		}
		void operator()() const {
			std::cout << std::this_thread::get_id() << ": "
			<< __PRETTY_FUNCTION__ << std::endl;
		}
	};
}
#endif // HELPER_HPP
