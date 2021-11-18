#pragma once

#include "../../structures/matrix/matrix.h"
#include "../test.h"

using namespace structures;

namespace tests
{

	class TestMatrix : public Test
	{

	public:

		TestMatrix(ostream& output, int operationCount);

		bool runScenario(Scenario scenario) final;

		void runAll() final;

		void testAddition(int from, int to, int step = 4);

		void testMultiplication(int from, int to, int step = 20);

		static ostream& printMatrix(ostream& stream, Matrix<int>& matrix);

		static Matrix<int>& fillMatrix(int from, int to, Matrix<int>& matrix);

	private:

		const int constSize_ = 1;
		double time;

		virtual Matrix<int>* createMatrix(size_t height, size_t width = 0) = 0;

		void scenarioA();

		void scenarioB();

		Matrix<int>& addition(Matrix<int>& result, Matrix<int>& a, Matrix<int>& b);

		Matrix<int>& multiplication(Matrix<int>& result, Matrix<int>& a, Matrix<int>& b);

		void resetDuration();

	};

}