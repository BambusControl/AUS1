#pragma once

#include "priority_queue_two_lists.h"

namespace structures
{

	template<typename T>
	class PriorityQueueTwoListsHalf : public PriorityQueueTwoLists<T>
	{
	public:
		PriorityQueueTwoListsHalf();

		PriorityQueueTwoListsHalf(size_t shortListSize);

	protected:
		size_t generateSize() override;
	};


	template<typename T>
	inline PriorityQueueTwoListsHalf<T>::PriorityQueueTwoListsHalf() :
		PriorityQueueTwoLists<T>()
	{ }

	template<typename T>
	inline PriorityQueueTwoListsHalf<T>::PriorityQueueTwoListsHalf(size_t shortListSize) :
		PriorityQueueTwoLists<T>(shortListSize)
	{ }

	template<typename T>
	inline size_t PriorityQueueTwoListsHalf<T>::generateSize()
	{
		return 
			this->longList_->size() < 4 ?
			2 : 
			this->longList_->size() / 2;
	}

}