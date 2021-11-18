#pragma once

#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "test_priority_queue.h"

namespace tests
{

	class TestPriorityQueueSortedArrayList : public TestPriorityQueue
	{

	public:

		TestPriorityQueueSortedArrayList(ostream& output, int operationCount);

	protected:

		string structureName() override;

	private:

		PriorityQueue<int>* createQueue(int pushQ) final;

	};

}