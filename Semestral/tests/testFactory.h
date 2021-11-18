#pragma once
#include <iostream>
#include <list>

#include "test.h"
#include "list/test_array_list.h"
#include "list/test_linked_list.h"
#include "list/test_bilinked_list.h"
#include "priority_queue/test_priority_queue_sorted_array_list.h"
#include "priority_queue/test_priority_queue_heap.h"
#include "priority_queue/test_priority_queue_two_lists_const.h"
#include "priority_queue/test_priority_queue_two_lists_sqrt.h"
#include "priority_queue/test_priority_queue_two_lists_half.h"
#include "matrix/test_coherent_matrix.h"
#include "matrix/test_incoherent_matrix.h"

using namespace std;

namespace tests
{

	class TestFactory
	{

	public:

		~TestFactory();

		Test& getTest(TestStructure structure, ostream& output, int operationCount = 100);

		Test& getTest(TestStructure structure);

		void runAll(TestStructureType structureType, ostream& output, int operationCount = 100);

		void runAllOneScenario(TestStructureType structureType, Scenario scenario, ostream& output, int operationCount = 100);

		static list<string> getStructureTypeNames();

		static list<string> getStructureNames(TestStructureType structureType);

		static TestStructure getStructureOfType(TestStructureType structureType, int offset);

		static list<string> getAvailableScenarioNames(TestStructureType structureType);

	private:
		Test* test;

	};

}