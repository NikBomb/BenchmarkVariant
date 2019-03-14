#pragma once

#include <memory>
#include "IFly.hpp"

class Duck {
public:
	Duck(std::shared_ptr<IFly> f);
	void fly();
private:
	const std::shared_ptr<IFly> flyBehaviour;
};