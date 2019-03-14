#pragma once
#include "IFly.hpp"

class GentleFly : public IFly {
	// Inherited via IFly
public:
	virtual const void fly() override;
private:
	int distance = 0;
};