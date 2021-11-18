#include "test_coherent_matrix.h"

namespace tests
{

	TestCoherentMatrix::TestCoherentMatrix(ostream& output, int operationCount) :
		TestMatrix::TestMatrix(output, operationCount)
	{}

	Matrix<int>* TestCoherentMatrix::createMatrix(size_t height, size_t width)
	{
		return new CoherentMatrix<int>(height, width == 0 ? height : width);
	}

	string TestCoherentMatrix::structureName()
	{
		return string("CoherentMatrix");
	}

}