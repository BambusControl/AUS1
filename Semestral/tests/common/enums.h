#pragma once

namespace tests {

	enum class TestStructure
	{
		All,
		ArrayList, LinkedList, BilinkedList,
		SortedArrayPriorityQueue, HeapPriorityQueue, TwoListConst, TwoListSqrt, TwoListHalf,
		CoherentMatrix, IncoherentMatrix
	};

	enum class TestStructureType { List, PriorityQueue, Matrix };

	enum class Scenario { All, A, B, C };

}