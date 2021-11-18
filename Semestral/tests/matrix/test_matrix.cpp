#include "test_matrix.h"

namespace tests
{

	TestMatrix::TestMatrix(ostream& output, int operationCount) :
		Test(output, operationCount),
		time(0)
	{ }

	bool TestMatrix::runScenario(Scenario scenario)
	{
		switch (scenario)
		{
		case Scenario::All:
			runAll();
			break;

		case Scenario::A:
			scenarioA();
			break;

		case Scenario::B:
			scenarioB();
			break;

		default:
			return false;
		}

		return true;
	}

	void TestMatrix::runAll()
	{
		scenarioA();
		scenarioB();
	}

	Matrix<int>& TestMatrix::addition(Matrix<int>& result, Matrix<int>& a, Matrix<int>& b)
	{
		/*if (
			a.getHeight() != b.getHeight() ||
			a.getHeight() != result.getHeight() ||
			a.getWidth() != b.getWidth() ||
			a.getWidth() != result.getWidth()
			)
		{
			throw invalid_argument("TestMatrix::addition : Matrices must have equal dimensions!");
		}

		if (a.getHeight() == 0 || a.getWidth() == 0)
		{
			throw invalid_argument("TestMatrix::addition : Matrices must have dimensions greater than 0!");
		}*/

		timer.start();

		for (size_t row = 0; row < result.height(); row++)
		{
			for (size_t col = 0; col < result.width(); col++)
			{
				result.set(
					row,
					col,
					a.get(row, col) + b.get(row, col)
				);
			}
		}

		time += timer.stop();

		return result;
	}

	Matrix<int>& TestMatrix::multiplication(Matrix<int>& result, Matrix<int>& a, Matrix<int>& b)
	{
		/*if (
			a.getHeight() != result.getHeight() ||
			a.getWidth() != b.getHeight() ||
			b.getWidth() != result.getWidth()
			)
		{
			throw invalid_argument("TestMatrix::addition : Matrices must have correct dimensions!");
		}

		if (a.getHeight() == 0 || a.getWidth() == 0 || b.getWidth() == 0)
		{
			throw invalid_argument("TestMatrix::addition : Matrices must have dimensions greater than 0!");
		}*/

		int x;
		timer.start();

		for (size_t row = 0; row < result.height(); row++)
		{
			for (size_t col = 0; col < result.width(); col++)
			{
				x = 0;

				for (size_t i = 0; i < a.width(); i++)
				{
					x += a.get(row, i) * b.get(i, col);
				}

				result.set(row, col, x);
			}
		}

		time += timer.stop();

		return result;
	}

	void TestMatrix::resetDuration()
	{
		time = 0;
		timer.reset();
	}

	ostream& TestMatrix::printMatrix(ostream& stream, Matrix<int>& matrix)
	{
		for (size_t row = 0; row < matrix.height(); row++)
		{
			for (size_t col = 0; col < matrix.width(); col++)
			{
				stream << matrix.get(row, col) << ' ';
			}
			stream << endl;
		}

		return stream;
	}

	Matrix<int>& TestMatrix::fillMatrix(int from, int to, Matrix<int>& matrix)
	{
		for (size_t row = 0; row < matrix.height(); row++)
		{
			for (size_t col = 0; col < matrix.width(); col++)
			{
				matrix.set(row, col, rand() % (to - from) + from);
			}
		}

		return matrix;
	}

	void TestMatrix::scenarioA()
	{
		std::cout << "Testing matrix scenario A" << endl;
		testAddition(4, 2000, 4);
		output << endl;
	}

	void TestMatrix::scenarioB()
	{
		std::cout << "Testing matrix scenario B" << endl;
		testMultiplication(10, 2000, 10);
		output << endl;
	}

	void TestMatrix::testAddition(int from, int to, int step)
	{
		if (from < 1 || to < 1 || step < 1)
		{
			throw std::invalid_argument("TestMatrix::testMatrix : The arguments must be >= 1!");
		}

		// Write Header
		output
			<< "[structure],[operation],[operation_count],[m_n_from],[m_n_to],[time_unit]" << endl
			<< structureName() << ','
			<< "Addition,"
			<< opCount << ','
			<< from << ','
			<< to << ','
			<< timer.getTimeUnit() << endl
			<< "[m],[n],[operation_time]" << endl;

		// Init ProgressBar
		ProgressBar progressBar((2 * to) / step);

		//progressBar.reset(2 * to);
		Matrix<int>* a, * b, * result;

		// Lambda function
		auto f = [&](int height, int width) 
		{
			// Init 
			a = createMatrix(height, width);
			b = createMatrix(height, width);
			result = createMatrix(height, width);

			for (int i = 0; i < opCount; i++)
			{
				// Init 
				time = 0;

				// Run operation
				addition(*result, *a, *b);

				//Output
				output
					<< height << ','
					<< width << ','
					<< time << endl;
			}

			// Free memory
			delete a;
			delete b;
			delete result;

			//progressBar.checkAndPrint();
		};

		for (size_t width = from; width <= to; width += step)
		{
			f(constSize_, width);
			progressBar.checkAndPrint();
		}

		for (size_t height = from; height <= to; height += step)
		{
			f(height, constSize_);
			progressBar.checkAndPrint();
		}

		std::cout << endl;
	}

	void TestMatrix::testMultiplication(int from, int to, int step)
	{
		if (from < 1 || to < 1 || step < 1)
		{
			throw std::invalid_argument("TestMatrix::testMatrix : The arguments must be >= 1!");
		}

		// Write Header
		output
			<< "[structure],[operation],[operation_count],[m_n_from],[m_n_to],[time_unit]" << endl
			<< structureName() << ','
			<< "MatrixMultiplication,"
			<< opCount << ','
			<< from << ','
			<< to << ','
			<< timer.getTimeUnit() << endl
			<< "[m],[n],[operation_time]" << endl;

		// Init ProgressBar
		ProgressBar progressBar((2 * to) / step);

		//progressBar.reset(2 * to);
		Matrix<int>* a, * b, * result;

		// Lambda function
		auto f = [&](int height, int width)
		{
			// Init
			a = createMatrix(height, width);
			b = createMatrix(width, height);
			result = createMatrix(height);

			for (int i = 0; i < opCount; i++)
			{
				// Init
				time = 0;

				// Run operation
				multiplication(*result, *a, *b);

				//Output
				output
					<< height << ','
					<< width << ','
					<< time << endl;
			}

			// Free memory
			delete a;
			delete b;
			delete result;
		};

		for (size_t width = from; width <= to; width += step)
		{
			f(constSize_, width);
			progressBar.checkAndPrint();
		}

		for (size_t height = from; height <= to; height += step)
		{
			f(height, constSize_);
			progressBar.checkAndPrint();
		}

		std::cout << endl;
	}

}