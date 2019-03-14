#pragma once
#include "IFly.hpp"

class JetFly : public IFly {
	// Inherited via IFly
public:
	virtual const void fly() override;
private:
	int distance;
};