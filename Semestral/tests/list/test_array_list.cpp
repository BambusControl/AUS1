#include "test_array_list.h"

namespace tests
{

	TestArrayList::TestArrayList(ostream& output, int operationCount) :
		TestList(output, operationCount)
	{
	}

	List<int>* TestArrayList::createList()
	{
		return new ArrayList<int>();
	}

	string TestArrayList::structureName()
	{
		return "ArrayList";
	}

}
