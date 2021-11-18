#pragma once

#include "priority_queue_two_lists.h"

namespace structures
{

	template<typename T>
	class PriorityQueueTwoListsSqrt : public PriorityQueueTwoLists<T>
	{
	public:
		PriorityQueueTwoListsSqrt();

		PriorityQueueTwoListsSqrt(size_t shortListSize);

	protected:
		size_t generateSize() override;
	};

	template<typename T>
	inline PriorityQueueTwoListsSqrt<T>::PriorityQueueTwoListsSqrt() :
		PriorityQueueTwoLists<T>()
	{ }

	template<typename T>
	inline PriorityQueueTwoListsSqrt<T>::PriorityQueueTwoListsSqrt(size_t shortListSize) :
		PriorityQueueTwoLists<T>(shortListSize)
	{ }

	template<typename T>
	inline size_t PriorityQueueTwoListsSqrt<T>::generateSize()
	{
		// LongList size must be at least 2
		return 
			this->longList_->size() < 4 ? 
			2 : 
			sqrt(this->longList_->size());
	}

}