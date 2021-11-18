#pragma once

#include "../../structures/list/list.h"
#include "../Test.h"

using namespace structures;

namespace tests
{

	class TestList : public Test
	{

	public:

		TestList(ostream& output, int operationCount);

		bool runScenario(Scenario scenario) final;

		void runAll() final;

		void test(int insert, int cancel, int access);

	protected:

		//virtual string structureName() = 0;

	private:
				
		virtual List<int>* createList() = 0;

		void testList(List<int>& list, int insert, int cancel, int access);

		void scenarioA();

		void scenarioB();

		void scenarioC();

		// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

		void insertRand(List<int>& list);

		void putInFront(List<int>& list, int value);

		void insertAt(List<int>& list, int value, int index);

		void addLast(List<int>& list, int value);

		// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

		void cancelRand(List<int>& list);

		void removeFirst(List<int>& list);

		void removeAt(List<int>& list, int index);

		void removeLast(List<int>& list);

		// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

		void setAccess(List<int>& list);

		void accessIndex(List<int>& list, int index);

		void setAtIndex(List<int>& list, int index, int value);

		// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

		void testIndexOf(List<int>& list);

		void indexOf(List<int>& list, int value);

		// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

		void resetDuration();

	};

}