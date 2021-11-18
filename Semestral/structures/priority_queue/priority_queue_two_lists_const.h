#pragma once

#include "priority_queue_two_lists.h"

namespace structures
{
	
	template<typename T>
	class PriorityQueueTwoListsConst : public PriorityQueueTwoLists<T>
	{
	public:
		PriorityQueueTwoListsConst();

		PriorityQueueTwoListsConst(size_t shortListSize);

	protected:
		size_t generateSize() override;
	};


	template<typename T>
	inline PriorityQueueTwoListsConst<T>::PriorityQueueTwoListsConst() :
		PriorityQueueTwoLists<T>()
	{ }

	template<typename T>
	inline PriorityQueueTwoListsConst<T>::PriorityQueueTwoListsConst(size_t shortListSize) :
		PriorityQueueTwoLists<T>(static_cast<int>(shortListSize))
	{ }

	template<typename T>
	inline size_t PriorityQueueTwoListsConst<T>::generateSize()
	{
		return this->shortList_->getCapacity();
	}

}