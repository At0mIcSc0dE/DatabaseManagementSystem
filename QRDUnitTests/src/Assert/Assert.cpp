#include "Assert.h"
#include <exception>

void QRDTest::Assert::FailOnCondition(bool condition, const char* message)
{
	if(condition)
		throw std::exception(message);
}
