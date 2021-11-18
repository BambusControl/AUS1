#include "test_priority_queue_two_lists_const.h"

namespace tests
{

    TestPriorityQueueTwoListsConst::TestPriorityQueueTwoListsConst(ostream& output, int operationCount) :
        TestPriorityQueue(output, operationCount)
    {}

    PriorityQueue<int>* TestPriorityQueueTwoListsConst::createQueue(int pushQ)
    {
        size_t value = opCount * (pushQ / 100.f) / 1000.f;
        return new PriorityQueueTwoListsConst<int>(value);
    }

    string TestPriorityQueueTwoListsConst::structureName()
    {
        return "PriorityQueueTwoListsConst";
    }

}