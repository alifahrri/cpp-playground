#include "thread_executor.hpp"
#include "helper.hpp"

#include <vector>
#include <memory>
#include <functional>


int main(int argc, char** argv)
{
	std::vector<ThreadExecutor> executor(4);

	std::function<void(void)> f = helper::f00;

	auto nop = [](){};
	auto functor = helper::Functor00();
	// needs c++14
	auto functor_ptr = std::make_unique<helper::Functor00>();

	executor[0](f, nop);
	executor[1](helper::f00, nop);
	executor[2](helper::f00, functor);
	executor[3](helper::f00, functor_ptr);

	return 0;
}
