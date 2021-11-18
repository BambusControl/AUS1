#pragma once

#include "../../structures/matrix/incoherent_matrix.h"
#include "test_matrix.h"

namespace tests
{

	class TestIncoherentMatrix : public TestMatrix
	{

	public:

		TestIncoherentMatrix(ostream& output, int operationCount);

	protected:

		string structureName() final;

	private:

		Matrix<int>* createMatrix(size_t height, size_t width = 0) final;

	};

}