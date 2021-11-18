#pragma once

#include "../../structures/list/array_list.h"
#include "test_list.h"

namespace tests
{

	class TestArrayList : public TestList
	{

	public:

		TestArrayList(ostream& output, int operationCount);

	protected:

		string structureName() override;


	private:

		List<int>* createList() final;

	};

}