#include "test_priority_queue_heap.h"

namespace tests
{

    TestPriorityQueueHeap::TestPriorityQueueHeap(ostream& output, int operationCount) :
        TestPriorityQueue(output, operationCount)
    {}

    PriorityQueue<int>* TestPriorityQueueHeap::createQueue(int pushQ)
    {
        return new Heap<int>();
    }

    string TestPriorityQueueHeap::structureName()
    {
        return "PriorityQueueHeap";
    }

}