#pragma once

#include "../../structures/list/bilinked_circular_list.h"
#include "test_list.h"

namespace tests
{

	class TestBilinkedList : public TestList
	{

	public:

		TestBilinkedList(ostream& output, int operationCount);

	protected:

		string structureName() override;

	private:

		List<int>* createList() override;

	};

}