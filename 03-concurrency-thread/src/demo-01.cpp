#include "thread_executor.hpp"
#include "helper.hpp"

#include <functional>

using helper::f00;

int main(int argc, char** argv)
{
	ThreadExecutor executor;

	std::function<void(void)> f = f00;
	auto nop = [](){};
	executor(f,nop);
	return 0;
}
