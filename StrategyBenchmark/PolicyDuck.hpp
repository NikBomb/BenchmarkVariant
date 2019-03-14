#pragma once
#include "IFly.hpp"

template <typename FlyPolicy>
class PolicyDuck {
private:
	FlyPolicy flyBehaviour;
public:
     void fly()  
	{
		flyBehaviour.fly();
	}
};

