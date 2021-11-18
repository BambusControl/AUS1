#include "test_priority_queue_two_lists_sqrt.h"

namespace tests
{

    TestPriorityQueueTwoListsSqrt::TestPriorityQueueTwoListsSqrt(ostream& output, int operationCount) :
        TestPriorityQueue(output, operationCount)
    {}

    PriorityQueue<int>* TestPriorityQueueTwoListsSqrt::createQueue(int pushQ)
    {
        return new PriorityQueueTwoListsSqrt<int>();
    }

    string TestPriorityQueueTwoListsSqrt::structureName()
    {
        return "PriorityQueueTwoListsVarSqrt";
    }

}