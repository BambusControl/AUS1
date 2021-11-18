#pragma once

#include "../../structures/matrix/coherent_matrix.h"
#include "test_matrix.h"

namespace tests
{

	class TestCoherentMatrix : public TestMatrix
	{

	public:

		TestCoherentMatrix(ostream& output, int operationCount);

	protected:

		string structureName() final;

	private:

		Matrix<int>* createMatrix(size_t height, size_t width = 0) final;

	};

}
