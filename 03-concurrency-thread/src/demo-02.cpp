#include "thread_executor.hpp"
#include "helper.hpp"

#include <memory>
#include <functional>


int main(int argc, char** argv)
{
	ThreadExecutor executor;

	std::function<void(void)> f = helper::f00;

	auto nop = [](){};
	auto functor = helper::Functor00();
	auto functor_ptr = std::make_unique<helper::Functor00>();

	executor(f, nop);
	executor(helper::f00, nop);
	executor(helper::f00, functor);
	executor(helper::f00, functor_ptr);

	return 0;
}
