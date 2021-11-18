#pragma once

#include "../../structures/priority_queue/priority_queue_two_lists_var_sqrt.h"
#include "test_priority_queue.h"

namespace tests
{

	class TestPriorityQueueTwoListsSqrt : public TestPriorityQueue
	{

	public:

		TestPriorityQueueTwoListsSqrt(ostream& output, int operationCount);

	protected:

		virtual string structureName() override;

	private:

		virtual PriorityQueue<int>* createQueue(int pushQ) final;

	};

}