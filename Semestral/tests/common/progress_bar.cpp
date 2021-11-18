#include "progress_bar.h"

ProgressBar::ProgressBar(int all)
{
	reset(all);
}

ostream& ProgressBar::printProgressBar(ostream & stream)
{
	stream << "0% -  -  -  -  -  -  - 25% -  -  -  -  -  -  -  50%  -  -  -  -  -  -  - 75% -  -  -  -  -  -  100%" << endl;
	return stream;
}

ostream& ProgressBar::printProgressBar()
{
	return checkAndPrint(cout);
}

ostream& ProgressBar::checkAndPrint(ostream& stream)
{
	if (calledCount++ == 0)
	{
		printProgressBar(stream);
	}

	if (calledCount % onePercent == 0)
	{
		if (passedCount++ < 99)
		{
			stream << '|';
		}
		else
		{
			stream << endl;
			reset();
		}
	}

	return stream;
}

ostream& ProgressBar::checkAndPrint()
{
	return checkAndPrint(cout);
}

void ProgressBar::reset(int all)
{
	if (all >= 100)
	{
		onePercent = static_cast<int>(all / 100);
	}

	calledCount = 0;
	passedCount = 0;
}
