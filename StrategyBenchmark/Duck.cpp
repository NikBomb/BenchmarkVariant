#include "Duck.hpp"
#pragma once

Duck::Duck( std::shared_ptr<IFly> f) : flyBehaviour(f)
{
}


void Duck::fly()
{
	flyBehaviour->fly();
}
