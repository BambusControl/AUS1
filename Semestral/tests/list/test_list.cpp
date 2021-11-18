#include "test_list.h"

namespace tests
{

	TestList::TestList(ostream& output, int operationCount) :
		Test(output, operationCount)
	{}

	void TestList::testList(List<int>& list, int insert, int cancel, int access)
	{
		// Calculate last quotient
		int index = 100 - (insert + cancel + access);

		if (index < 0)
		{
			throw std::invalid_argument("TestList::testList : The sum of quotients cannot be greater than 100!");
		}

		// Write Header
		output
			<< "[structure],[operation_count],[insert_q],[cancel_q],[access_q],[index_q],[time_unit]" << endl
			<< structureName() << ','
			<< opCount << ','
			<< insert << ','
			<< cancel << ','
			<< access << ','
			<< index << ','
			<< timer.getTimeUnit() << endl
			<< "[operation],[structure_size],[modified_index],[operation_time]" << endl;

		// Init ProgressBar
		ProgressBar progressBar(opCount);

		// Modify values for randomization
		cancel += insert;
		access += cancel;

		// Randomizer
		int rNum;
		for (int i = 0; i < opCount; i++)
		{
			rNum = rand() % 100;
			if (rNum < insert)
			{
				insertRand(list);
			}
			else if (rNum < cancel)
			{
				cancelRand(list);
			}
			else if (rNum < access)
			{
				setAccess(list);
			}
			else
			{
				testIndexOf(list);
			}

			progressBar.checkAndPrint();
		}

		cout << endl;
		//output << "[total_time]" << endl << timer.getTotalSum() << endl;

		// Cleanup
		list.clear();
		resetDuration();
	}

	void TestList::resetDuration()
	{
		timer.reset();
	}

	bool TestList::runScenario(Scenario scenario)
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

	void TestList::runAll()
	{
		scenarioA();
		scenarioB();
		scenarioC();
	}

	void TestList::scenarioA()
	{
		std::cout << "Testing List, Scenario A" << std::endl;
		List<int>* list = createList();
		testList(*list, 20, 20, 50);
		delete list;
		output << endl;
	}

	void TestList::scenarioB()
	{
		std::cout << "Testing List, Scenario B" << std::endl;
		List<int>* list = createList();
		testList(*list, 35, 35, 20);
		delete list;
		output << endl;
	}

	void TestList::scenarioC()
	{
		std::cout << "Testing List, Scenario C" << std::endl;
		List<int>* list = createList();
		testList(*list, 45, 45, 5);
		delete list;
		output << endl;
	}

	void TestList::test(int insert, int cancel, int access)
	{
		List<int>* list = createList();
		testList(*list, insert, cancel, access);
		delete list;
	}

	void TestList::insertRand(List<int>& list)
	{
		int randNum = rand();
		int selectNum = randNum % 3;

		if (selectNum == 0)
		{
			putInFront(list, randNum);
		}
		else if (selectNum == 1)
		{
			insertAt(list, randNum, rand());
		}
		else
		{
			addLast(list, randNum);
		}
	}

	void TestList::putInFront(List<int>& list, int value)
	{
		output
			<< "putInFront,"
			<< list.size()
			<< ",0,";

		timer.start();
		list.insert(value, 0);
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestList::insertAt(List<int>& list, int value, int index)
	{
		index = list.isEmpty() ? 0 : index % list.size();
		output
			<< "insertAt,"
			<< list.size() << ','
			<< index << ',';

		timer.start();
		list.insert(value, index);
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestList::addLast(List<int>& list, int value)
	{
		output
			<< "addLast,"
			<< list.size() << ','
			<< list.size() << ',';

		timer.start();
		list.add(value);
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestList::cancelRand(List<int>& list)
	{
		if (list.isEmpty())
		{
			return;
		}

		int selectNum = rand() % 3;

		if (selectNum == 0)
		{
			removeFirst(list);
		}
		else if (selectNum == 1)
		{
			removeAt(list, rand());
		}
		else
		{
			removeLast(list);
		}
	}

	void TestList::removeFirst(List<int>& list)
	{
		output
			<< "removeFirst,"
			<< list.size()
			<< ",0,";

		timer.start();
		list.removeAt(0);
		double time = timer.stop();
		
		output
			<< time << endl;
	}

	void TestList::removeAt(List<int>& list, int index)
	{
		index %= list.size();

		output
			<< "removeAt,"
			<< list.size() << ','
			<< index << ',';

		timer.start();
		list.removeAt(index % list.size());
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestList::removeLast(List<int>& list)
	{
		output
			<< "removeLast,"
			<< list.size() << ','
			<< list.size() - 1 << ',';

		timer.start();
		list.removeAt(list.size() - 1);
		double time = timer.stop();

		output
			<< time << endl;
	}

	void TestList::setAccess(List<int>& list)
	{
		int selectNum = rand() % 2;

		if (list.isEmpty())
		{
			return;
		}

		if (selectNum == 0)
		{
			accessIndex(list, rand());
		}
		else
		{
			setAtIndex(list, rand(), rand());
		}

	}

	void TestList::accessIndex(List<int>& list, int index)
	{
		index %= list.size();

		timer.start();
		list[index];
		double time = timer.stop();

		output
			<< "acessIndex,"
			<< list.size() << ','
			<< index << ','
			<< time << endl;
	}

	void TestList::setAtIndex(List<int>& list, int index, int value)
	{
		index %= list.size();
		
		timer.start();
		list[index] = value;
		double time = timer.stop();

		output
			<< "setAtIndex,"
			<< list.size() << ','
			<< index << ','
			<< time << endl;
	}

	void TestList::testIndexOf(List<int>& list)
	{
		indexOf(list, rand());
	}

	void TestList::indexOf(List<int>& list, int value)
	{
		int index;

		timer.start();
		index = list.getIndexOf(value);
		double time = timer.stop();

		output
			<< "indexOf,"
			<< list.size() << ','
			<< index << ','
			<< time << endl;
	}

}