#include "test_priority_queue_sorted_array_list.h"

namespace tests
{

    TestPriorityQueueSortedArrayList::TestPriorityQueueSortedArrayList(ostream& output, int operationCount) :
        TestPriorityQueue(output, operationCount)
    { }

    PriorityQueue<int>* TestPriorityQueueSortedArrayList::createQueue(int pushQ)
    {
        return new PriorityQueueSortedArrayList<int>();
    }

    string TestPriorityQueueSortedArrayList::structureName()
    {
        return "PriorityQueueSortedArrayList";
    }

}