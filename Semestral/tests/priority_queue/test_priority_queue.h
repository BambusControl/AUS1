#pragma once

#include "../../structures/priority_queue/priority_queue.h"
#include "../test.h"

using namespace structures;

namespace tests
{

	class TestPriorityQueue : public Test
	{

	public:

		TestPriorityQueue(ostream& output, int operationCount);

		virtual bool runScenario(Scenario scenario) final;

		virtual void runAll() final;

		void test(int push, int pop);

	protected:

		//virtual string structureName() = 0;

	private:

		virtual PriorityQueue<int>* createQueue(int pushQ = 20) = 0;

		void scenarioA();

		void scenarioB();

		void scenarioC();

		void testQueue(PriorityQueue<int>& queue, int push, int pop);

		void pushQueue(PriorityQueue<int>& queue, int priority, int value);

		void popQueue(PriorityQueue<int>& queue);

		void peekQueue(PriorityQueue<int>& queue);

		void resetDuration();

	};

}