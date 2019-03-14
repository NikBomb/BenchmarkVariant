#include <iostream>
#include "IFly.hpp"
#include "JetFly.hpp"
#include "GentleFly.hpp"
#include "Duck.hpp"
#include "memory.h"
#include <vector>
#include <algorithm>
#include <vld.h>
#include <chrono>
#include "PolicyDuck.hpp"
#include "GentleFlyPolicy.hpp"
#include "JetFlyPolicy.hpp"
#include <variant>
#include <array>

typedef std::chrono::high_resolution_clock Clock;

int main() {
	const int runSize = 10;
	std::vector<long long> timeStrategy;
	std::vector<long long> timePolicy;
	std::vector<long long> results;



	int loopSize = 100000;
	for (int k = 0; k < runSize; k++) {

		auto normalDuck(std::make_shared<GentleFly>());
		auto richDuck(std::make_shared<JetFly>());

		std::vector<Duck> ducks;
		ducks.emplace_back(normalDuck);
		ducks.emplace_back(richDuck);

		auto then = Clock::now();

		for (int i = 0; i < loopSize; i++) {
			std::for_each(ducks.begin(), ducks.end(), [](auto duck) {duck.fly(); });
		}

		auto now = Clock::now();

		timeStrategy.push_back(std::chrono::duration_cast
			<std::chrono::nanoseconds>(now - then).count());
		
		//Strategy Pattern with Policies

		auto normalPolicyDuck = PolicyDuck<GentleFlyPolicy>();
		auto jetPolicyDuck = PolicyDuck<JetFlyPolicy>();


		std::vector<std::variant<PolicyDuck<GentleFlyPolicy>, PolicyDuck<JetFlyPolicy> > > policyDucks;

		policyDucks.emplace_back(normalPolicyDuck);
		policyDucks.emplace_back(jetPolicyDuck);

		auto lambdaFlyVisitor = [](auto&& in) {in.fly(); };

		then = Clock::now();
		for (int i = 0; i < loopSize; i++) {
			std::for_each(policyDucks.begin(), policyDucks.end(), [&lambdaFlyVisitor](auto duck) {std::visit(lambdaFlyVisitor, duck); });
		}

		now = Clock::now();
		timePolicy.push_back(std::chrono::duration_cast
			<std::chrono::nanoseconds>(now - then).count());
	}
	
	for (int i = 0; i < timePolicy.size(); i++) {
		results.push_back(timePolicy[i] - timeStrategy[i]);
	}
	auto count = std::count_if(results.begin(), results.end(), [](auto res) { return res <= 0; });
	std::cout << "Policy has been faster: " << ((double) count / ((double) runSize))*100 <<" % of times"<< std::endl;
	
	return 0;
}