#pragma once
#include <iostream>
#include "common/timer.h"
#include "common/progress_bar.h"
#include "common/enums.h"

using namespace std;

namespace tests
{

	class Test
	{

	public:

		Test(ostream& output, int operationCount) :
			output(output),
			opCount(operationCount > 0 ? operationCount : 1)
		{}

		virtual bool runScenario(Scenario scenario) = 0;

		virtual void runAll() = 0;

		virtual ~Test()
		{ }

	protected:

		const int opCount;
		ostream& output;
		Timer timer;

		virtual string structureName() = 0;

	};

}