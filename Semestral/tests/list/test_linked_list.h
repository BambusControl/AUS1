#pragma once

#include "../../structures/list/linked_list.h"
#include "test_list.h"

namespace tests
{

	class TestLinkedList : public TestList
	{

	public:

		TestLinkedList(ostream& output, int operationCount);

	protected:

		string structureName() override;


	private:

		List<int>* createList() override;

	};

}