#include "test_priority_queue_two_lists_half.h"

namespace tests
{

    TestPriorityQueueTwoListsHalf::TestPriorityQueueTwoListsHalf(ostream& output, int operationCount) :
        TestPriorityQueue(output, operationCount)
    {}

    PriorityQueue<int>* TestPriorityQueueTwoListsHalf::createQueue(int pushQ)
    {
        return new PriorityQueueTwoListsHalf<int>();
    }

    string TestPriorityQueueTwoListsHalf::structureName()
    {
        return "PriorityQueueTwoListsVarHalf";
    }

}