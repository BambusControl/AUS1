#pragma once

#include "../../structures/priority_queue/heap.h"
#include "test_priority_queue.h"

namespace tests
{

	class TestPriorityQueueHeap : public TestPriorityQueue
	{

	public:

		TestPriorityQueueHeap(ostream& output, int operationCount);

	protected:

		string structureName() override;

	private:

		PriorityQueue<int>* createQueue(int pushQ) final;

	};

}