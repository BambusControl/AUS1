#include "test_linked_list.h"

namespace tests
{

	TestLinkedList::TestLinkedList(ostream& output, int operationCount) :
		TestList(output, operationCount)
	{}

	List<int>* TestLinkedList::createList()
	{
		return new LinkedList<int>();
	}

	string TestLinkedList::structureName()
	{
		return "LinkedList";
	}

}
