#include "test_bilinked_list.h"

namespace tests
{

	TestBilinkedList::TestBilinkedList(ostream& output, int operationCount) :
		TestList(output, operationCount)
	{}

	List<int>* TestBilinkedList::createList()
	{
		return new BilinkedCircularList<int>();
	}

	string TestBilinkedList::structureName()
	{
		return "BilinkedCircularList";
	}

}
