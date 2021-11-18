#include "test_priority_queue.h"

namespace tests
{

	TestPriorityQueue::TestPriorityQueue(ostream& output, int operationCount) :
		Test(output, operationCount)
	{ }

	bool TestPriorityQueue::runScenario(Scenario scenario)
	{
		switch (scenario)
		{
		case Scenario::All:
			runAll();
			break;

		case Scenario::A:
			scenarioA();
			break;

		case Scenario::B:
			scenarioB();
			break;

		case Scenario::C:
			scenarioC();
			break;

		default:
			return false;
		}

		return true;
	}

	void TestPriorityQueue::runAll()
	{
		scenarioA();
		scenarioB();
		scenarioC();
	}

	void TestPriorityQueue::testQueue(PriorityQueue<int>& queue, int push, int pop)
	{
		// Calculate last quotient
		int peek = 100 - (push + pop);

		if (peek < 0)
		{
			throw std::invalid_argument("TestList::testList : The sum of quotients cannot be greater than 100!");
		}

		// Write Header
		output
			<< "[structure],[operation_count],[push_q],[pop_q],[peek_q],[time_unit]" << endl
			<< structureName() << ','
			<< opCount << ','
			<< push << ','
			<< pop << ','
			<< peek << ','
			<< timer.getTimeUnit() << endl
			<< "[operation],[structure_size],[priority],[operation_time]" << endl;

		// Init ProgressBar
		ProgressBar progressBar(opCount);

		// Modify values for randomization
		pop += push;

		// Randomizer
		int rNum;
		for (int i = 0; i < opCount; i++)
		{
			rNum = rand() % 100;
			if (rNum < push)
			{
				pushQueue(queue, rand(), rand());
			}
			else if (rNum < pop)
			{
				popQueue(queue);
			}
			else
			{
				peekQueue(queue);
			}

			progressBar.checkAndPrint();
		}

		cout << endl;

		// Cleanup
		queue.clear();
		resetDuration();
	}

	void TestPriorityQueue::resetDuration()
	{
		timer.reset();
	}

	void TestPriorityQueue::scenarioA()
	{
		std::cout << "Testing PriorityQueue, Scenario A" << std::endl;
		test(35, 35);
		output << endl;
	}

	void TestPriorityQueue::scenarioB()
	{
		std::cout << "Testing PriorityQueue, Scenario B" << std::endl;
		test(50, 30);
		output << endl;
	}

	void TestPriorityQueue::scenarioC()
	{
		std::cout << "Testing PriorityQueue, Scenario C" << std::endl;
		test(70, 25);
		output << endl;
	}

	void TestPriorityQueue::test(int push, int pop)
	{
		PriorityQueue<int>* queue = createQueue(push);
		testQueue(*queue, push, pop);
		delete queue;
	}

	void TestPriorityQueue::pushQueue(PriorityQueue<int>& queue, int priority, int value)
	{
		priority %= 10001;

		output
			<< "push,"
			<< queue.size() << ','
			<< priority << ',';

		timer.start();
		queue.push(priority, value);
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestPriorityQueue::popQueue(PriorityQueue<int>& queue)
	{
		if (queue.isEmpty())
		{
			return;
		}

		output
			<< "pop,"
			<< queue.size() << ','
			<< queue.peekPriority() << ',';

		timer.start();
		queue.pop();
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestPriorityQueue::peekQueue(PriorityQueue<int>& queue)
	{
		if (queue.isEmpty())
		{
			return;
		}

		output
			<< "peek,"
			<< queue.size() << ','
			<< queue.peekPriority() << ',';

		timer.start();
		queue.peek();
		double time = timer.stop();

		output
			<< time << endl;
	}

}