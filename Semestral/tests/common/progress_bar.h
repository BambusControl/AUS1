#pragma once

#include <iostream>

using namespace std;

class ProgressBar
{

public:

	ProgressBar(int all);

	ostream& printProgressBar(ostream& stream);

	ostream& printProgressBar();

	ostream& checkAndPrint(ostream& stream);

	ostream& checkAndPrint();

	void reset(int all = 0);

private:

	int onePercent;
	int calledCount;
	int passedCount;

};