#include "testFactory.h"

namespace tests {

	TestFactory::~TestFactory()
	{
		if (test != nullptr)
		{
			delete test;
		}
	}

	Test& tests::TestFactory::getTest(TestStructure structure, ostream& output, int operationCount)
	{
		if (test != nullptr)
		{
			delete test;
		}

		switch (structure)
		{
		case TestStructure::ArrayList:
			test = new TestArrayList(output, operationCount);
			break;
		case TestStructure::LinkedList:
			test = new TestLinkedList(output, operationCount);
			break;
		case TestStructure::BilinkedList:
			test = new TestBilinkedList(output, operationCount);
			break;
		case TestStructure::SortedArrayPriorityQueue:
			test = new TestPriorityQueueSortedArrayList(output, operationCount);
			break;
		case TestStructure::HeapPriorityQueue:
			test = new TestPriorityQueueHeap(output, operationCount);
			break;
		case TestStructure::TwoListConst:
			test = new TestPriorityQueueTwoListsConst(output, operationCount);
			break;
		case TestStructure::TwoListSqrt:
			test = new TestPriorityQueueTwoListsSqrt(output, operationCount);
			break;
		case TestStructure::TwoListHalf:
			test = new TestPriorityQueueTwoListsHalf(output, operationCount);
			break;
		case TestStructure::CoherentMatrix:
			test = new TestCoherentMatrix(output, operationCount);
			break;
		case TestStructure::IncoherentMatrix:
			test = new TestIncoherentMatrix(output, operationCount);
			break;
		default:
			break;
		}

		return *test;
	}

	Test& tests::TestFactory::getTest(TestStructure structure)
	{
		return getTest(structure, cout);
	}

	void TestFactory::runAll(TestStructureType structureType, ostream& output, int operationCount)
	{
		switch (structureType)
		{
		case tests::TestStructureType::List:
			getTest(TestStructure::ArrayList, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::LinkedList, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::BilinkedList, output, operationCount).runAll();
			break;
		case tests::TestStructureType::PriorityQueue:
			getTest(TestStructure::SortedArrayPriorityQueue, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::HeapPriorityQueue, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::TwoListConst, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::TwoListSqrt, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::TwoListHalf, output, operationCount).runAll();
			break;
		case tests::TestStructureType::Matrix:
			getTest(TestStructure::CoherentMatrix, output, operationCount).runAll();
			output << endl;
			getTest(TestStructure::IncoherentMatrix, output, operationCount).runAll();
			break;
		default:
			throw std::invalid_argument("TestFactory::runAll : Invalid structureType!");
			break;
		}
		output << endl;
	}

	void TestFactory::runAllOneScenario(TestStructureType structureType, Scenario scenario, ostream& output, int operationCount)
	{
		switch (structureType)
		{
		case tests::TestStructureType::List:
			getTest(TestStructure::ArrayList, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::LinkedList, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::BilinkedList, output, operationCount).runScenario(scenario);
			break;
		case tests::TestStructureType::PriorityQueue:
			getTest(TestStructure::SortedArrayPriorityQueue, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::HeapPriorityQueue, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::TwoListConst, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::TwoListSqrt, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::TwoListHalf, output, operationCount).runScenario(scenario);
			break;
		case tests::TestStructureType::Matrix:
			getTest(TestStructure::CoherentMatrix, output, operationCount).runScenario(scenario);
			output << endl;
			getTest(TestStructure::IncoherentMatrix, output, operationCount).runScenario(scenario);
			break;
		default:
			throw std::invalid_argument("TestFactory::runAll : Invalid structureType!");
			break;
		}
		output << endl;
	}

	list<string> TestFactory::getStructureTypeNames()
	{
		list<string> list = {
			"ADT List",
			"ADT Priority Queue",
			"ADT Matrix",
		};

		return list;
	}

	list<string> TestFactory::getStructureNames(TestStructureType structureType)
	{
		switch (structureType)
		{
		case tests::TestStructureType::List:
			return list<string>{
				"ArrayList",
					"LinkedList",
					"BilinkedCircularList"
			};

		case tests::TestStructureType::PriorityQueue:
			return list<string>{
				"SortedArray",
					"Heap",
					"TwoListsConst",
					"TwoListsVarSqrt",
					"TwoListsVarHalf"
			};

		case tests::TestStructureType::Matrix:
			return list<string>{
				"CoherentMatrix",
					"IncoherentMatrix"
			};

		default:
			throw std::logic_error("TestFactory::getStructureNames() : Invalid structureType!");
		}
	}

	TestStructure TestFactory::getStructureOfType(TestStructureType structureType, int offset)
	{
		switch (structureType)
		{
		case tests::TestStructureType::List:
			return static_cast<TestStructure>(static_cast<int>(TestStructure::ArrayList) + offset);

		case tests::TestStructureType::PriorityQueue:
			return static_cast<TestStructure>(static_cast<int>(TestStructure::SortedArrayPriorityQueue) + offset);

		case tests::TestStructureType::Matrix:
			return static_cast<TestStructure>(static_cast<int>(TestStructure::CoherentMatrix) + offset);

		default:
			throw std::logic_error("TestFactory::getStructureOfType() : invalid structureType!");
		}
	}

	list<string> TestFactory::getAvailableScenarioNames(TestStructureType structureType)
	{
		switch (structureType)
		{
		case tests::TestStructureType::List:
			return list<string>{ "A [20; 20; 50; 10]", "B [35; 35; 20; 10]", "C [45; 45;  5;  5]" };

		case tests::TestStructureType::PriorityQueue:
			return list<string>{ "A [35; 35; 30]", "B [50; 30; 20]", "C [70; 25;  5]" };

		case tests::TestStructureType::Matrix:
			return list<string>{ "A [ Scitanie]", "B [Nasobenie]" };

		default:
			throw std::logic_error("TestFactory::getAvailableScenarioNames() : Invalid structureType!");
		}
	}

}
