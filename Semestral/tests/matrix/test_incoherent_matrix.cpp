#include "test_incoherent_matrix.h"

namespace tests
{

	TestIncoherentMatrix::TestIncoherentMatrix(ostream& output, int operationCount) :
		TestMatrix::TestMatrix(output, operationCount)
	{}

	Matrix<int>* TestIncoherentMatrix::createMatrix(size_t height, size_t width)
	{
		return new IncoherentMatrix<int>(height, width == 0 ? height : width);
	}

	string TestIncoherentMatrix::structureName()
	{
		return string("IncoherentMatrix");
	}

}