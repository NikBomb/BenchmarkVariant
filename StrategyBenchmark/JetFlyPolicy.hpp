#pragma once

class JetFlyPolicy {
public:
	void fly() { distance += 3; };
private: 
	int distance = 0;
};