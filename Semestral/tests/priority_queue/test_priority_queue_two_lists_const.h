#pragma once

#include "../../structures/priority_queue/priority_queue_two_lists_const.h"
#include "test_priority_queue.h"

namespace tests
{

	class TestPriorityQueueTwoListsConst : public TestPriorityQueue
	{

	public:

		TestPriorityQueueTwoListsConst(ostream& output, int operationCount);

	protected:

		virtual string structureName() override;

	private:

		virtual PriorityQueue<int>* createQueue(int pushQ) final;

	};

}