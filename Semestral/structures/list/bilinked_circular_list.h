#pragma once

#include "list.h"
#include "../structure_iterator.h"
#include "../ds_routines.h"

namespace structures
{

	/// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typeparam>
	template<typename T>
	class BilinkedListItem : public DataItem<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		/// <param name = "data"> Data, ktore uchovava. </param>
		BilinkedListItem(T data);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Prvok jednstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
		BilinkedListItem(const BilinkedListItem<T>& other);

		/// <summary> Destruktor. </summary>
		~BilinkedListItem();

		/// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
		BilinkedListItem<T>* getNext();

		/// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <param name= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
		void setNext(BilinkedListItem<T>* next);

		/// <summary> Getter predchadzajuceho prvku zretazeneho zoznamu. </summary>
		/// <returns> Predchadzajuci prvok zretazeneho zoznamu. </returns>
		BilinkedListItem<T>* getPrevious();

		/// <summary> Setter predchadzajuceho prvku zretazeneho zoznamu. </summary>
		/// <param name= "next"> Novy predchadzajuci prvok zretazeneho zoznamu. </param>
		void setPrevious(BilinkedListItem<T>* previous);
	private:
		/// <summary> Nasledujuci prvok zretazeneho zoznamu. </summary>
		BilinkedListItem<T>* next_;

		/// <summary> Predchadzajuci prvok zretazeneho zoznamu. </summary>
		BilinkedListItem<T>* previous_;
	};

	/// <summary> Jednostranne zretazeny zoznam. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v zozname. </typeparam>
	template<typename T>
	class BilinkedCircularList : public List<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		BilinkedCircularList();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> BilinkedList, z ktoreho sa prevezmu vlastnosti. </param>
		BilinkedCircularList(const BilinkedCircularList<T>& other);

		/// <summary> Destruktor. </summary>
		~BilinkedCircularList();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat zoznamu. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Vrati pocet prvkov v zozname. </summary>
		/// <returns> Pocet prvkov v zozname. </returns>
		size_t size() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zoznam, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zoznam nachadza po priradeni. </returns>
		List<T>& operator=(const List<T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zoznam, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zoznam nachadza po priradeni. </returns>
		BilinkedCircularList<T>& operator=(const BilinkedCircularList<T>& other);

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		T& operator[](const int index) override;

		/// <summary> Vrati hodnotou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Hodnota prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		const T operator[](const int index) const override;

		/// <summary> Prida prvok do zoznamu. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		void add(const T& data) override;

		/// <summary> Vlozi prvok do zoznamu na dany index. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		/// <param name = "index"> Index prvku. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		/// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
		void insert(const T& data, const int index) override;

		/// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
		/// <param name = "data"> Odstranovany prvok. </param>
		/// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
		bool tryRemove(const T& data) override;

		/// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		T removeAt(const int index) override;

		/// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
		/// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
		/// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
		int getIndexOf(const T& data) override;

		/// <summary> Vymaze zoznam. </summary>
		void clear() override;
	
		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getBeginIterator() const override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getEndIterator() const override;
	private:
		/// <summary> Pocet prvkov v zozname. </summary>
		size_t size_;
		/// <summary> Prvy prvok zoznamu. </summary>
		BilinkedListItem<T>* first_;
	private:
		/// <summary> Vrati prvok zoznamu na danom indexe. </summary>
		/// <param name = "index"> Pozadovany index. </summary>
		/// <returns> Prvok zoznamu na danom indexe. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		BilinkedListItem<T>* getItemAtIndex(int index) const;
		/// <summary> Vrati prvok zoznamu na danom indexe. </summary>
		/// <param name = "index"> Pozadovany index. </summary>
		/// <returns> Prvok zoznamu na danom indexe. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		BilinkedListItem<T>* getLast();
	private:
		/// <summary> Iterator pre BilinkedList. </summary>
		class BilinkedListIterator : public Iterator<T>
		{
		public:
			/// <summary> Konstruktor. </summary>
			/// <param name = "position"> Pozicia v zretazenom zozname, na ktorej zacina. </param>
			BilinkedListIterator(const BilinkedCircularList<T>* bilinkedList, const int position);

			/// <summary> Destruktor. </summary>
			~BilinkedListIterator();

			/// <summary> Operator priradenia. Priradi do seba hodnotu druheho iteratora. </summary>
			/// <param name = "other"> Druhy iterator. </param>
			/// <returns> Vrati seba po priradeni. </returns>
			Iterator<T>& operator= (const Iterator<T>& other) override;

			/// <summary> Porovna sa s druhym iteratorom na nerovnost. </summary>
			/// <param name = "other"> Druhy iterator. </param>
			/// <returns> True, ak sa iteratory nerovnaju, false inak. </returns>
			bool operator!=(const Iterator<T>& other) override;

			/// <summary> Vrati data, na ktore aktualne ukazuje iterator. </summary>
			/// <returns> Data, na ktore aktualne ukazuje iterator. </returns>
			const T operator*() override;

			/// <summary> Posunie iterator na dalsi prvok v strukture. </summary>
			/// <returns> Iterator na dalsi prvok v strukture. </returns>
			/// <remarks> Zvycajne vrati seba. Ak vrati iny iterator, povodny bude automaticky zruseny. </remarks>
			Iterator<T>& operator++() override;
		private:
			/// <summary> Iterovany zoznam. </summary>
			const BilinkedCircularList<T>* list_;
			/// <summary> Aktualny item v iteratore. </summary>
			BilinkedListItem<T>* current_;
			/// <summary> Aktualna pozicia v zozname. </summary>
			int position_;

		};
	};

	template<typename T>
	inline BilinkedListItem<T>::BilinkedListItem(T data):
		DataItem<T>(data),
		next_(nullptr),
		previous_(nullptr)
	{
	}

	template<typename T>
	inline BilinkedListItem<T>::BilinkedListItem(const BilinkedListItem<T>& other):
		DataItem<T>(other),
		next_(other.next_),
		previous_(other.previous_)
	{
	}

	template<typename T>
	inline BilinkedListItem<T>::~BilinkedListItem()
	{
		next_ = nullptr;
		previous_ = nullptr;
	}
	
	template<typename T>
	inline BilinkedListItem<T> * BilinkedListItem<T>::getNext()
	{
		return next_;
	}

	template<typename T>
	inline void BilinkedListItem<T>::setNext(BilinkedListItem<T> * next)
	{
		next_ = next;
		if (next)
		{
			next->previous_ = this;
		}
	}

	template<typename T>
	inline BilinkedListItem<T>* BilinkedListItem<T>::getPrevious()
	{
		return previous_;
	}

	template<typename T>
	inline void BilinkedListItem<T>::setPrevious(BilinkedListItem<T>* previous)
	{
		previous_ = previous;
		if (previous)
		{
			previous->next_ = this;
		}
	}

	template<typename T>
	inline BilinkedCircularList<T>::BilinkedCircularList():
		List<T>(),
		size_(0),
		first_(nullptr)
	{
	}

	template<typename T>
	inline BilinkedCircularList<T>::BilinkedCircularList(const BilinkedCircularList<T>& other):
		BilinkedCircularList()
	{
		*this = other;
	}

	template<typename T>
	inline BilinkedCircularList<T>::~BilinkedCircularList()
	{
		clear();
	}

	template<typename T>
	inline Structure * BilinkedCircularList<T>::clone() const
	{
		return new BilinkedCircularList<T>(*this);
	}

	template<typename T>
	inline size_t BilinkedCircularList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	inline List<T>& BilinkedCircularList<T>::operator=(const List<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const BilinkedCircularList<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline BilinkedCircularList<T>& BilinkedCircularList<T>::operator=(const BilinkedCircularList<T>& other)
	{
		if (this != &other)
		{
			clear();

			for (T item : other)
			{
				add(item);
			}
		}
		return *this;
	}

	template<typename T>
	inline T & BilinkedCircularList<T>::operator[](const int index)
	{
		return getItemAtIndex(index)->accessData();
	}

	template<typename T>
	inline const T BilinkedCircularList<T>::operator[](const int index) const
	{
		return getItemAtIndex(index)->accessData();
	}

	template<typename T>
	inline void BilinkedCircularList<T>::add(const T & data)
	{
		BilinkedListItem<T>* item = new BilinkedListItem<T>(data);

		if (first_)
		{
			// Nieco uz je
			item->setPrevious(getLast());
			item->setNext(first_);
		}
		else
		{
			// Prazdny list
			item->setNext(item);
			first_ = item;
		}

		size_++;
	}

	template<typename T>
	inline void BilinkedCircularList<T>::insert(const T & data, const int index)
	{
		if (index == size_)
		{
			add(data);
		}
		else
		{
			DSRoutines::rangeCheckExcept(index, size_, "BilinkedList<T>::insert - Index out of range!");
			BilinkedListItem<T>* item = new BilinkedListItem<T>(data);

			if (index == 0)
			{
				item->setPrevious(getLast());
				item->setNext(first_);
				first_ = item;
			}
			else
			{
				BilinkedListItem<T>* onIndex = getItemAtIndex(index);

				item->setPrevious(onIndex->getPrevious());
				item->setNext(onIndex);
			}

			size_++;
		}
	}

	template<typename T>
	inline bool BilinkedCircularList<T>::tryRemove(const T & data)
	{
		BilinkedListItem<T>* item = first_;

		for (size_t i = 0; i < size_; i++)
		{
			if (item->accessData() == data)
			{
				item->getPrevious()->setNext(item->getNext());
				delete item;
				size_--;
				return true;
			}

			item = item->getNext();
		}

		return false;
	}

	template<typename T>
	inline T BilinkedCircularList<T>::removeAt(const int index)
	{
		DSRoutines::rangeCheckExcept(index, size_, "BilinkedList<T>::removeAt - Index out of bounds!");
		BilinkedListItem<T>* item;

		if (size_ == 1)
		{
			item = first_;
			first_ = nullptr;
		}
		else
		{
			if (index == 0)
			{
				item = first_;
				first_->getNext()->setPrevious(getLast());
				first_ = getLast()->getNext();
			}
			else if (index == (size_ - 1))
			{
				item = getLast();
				item->getPrevious()->setNext(first_);
			}
			else
			{
				item = getItemAtIndex(index);
				item->getNext()->setPrevious(item->getPrevious());
			}
		}

		size_--;
		T data = item->accessData();
		delete item;

		return data;
	}

	template<typename T>
	inline int BilinkedCircularList<T>::getIndexOf(const T & data)
	{
		int index = 0;

		for (T item : *this)
		{
			if (item == data)
			{
				return index;
			}
			index++;
		}

		return -1;
	}

	template<typename T>
	inline void BilinkedCircularList<T>::clear()
	{
		BilinkedListItem<T>* item = first_;
		BilinkedListItem<T>* toDelete = nullptr;

		for (size_t i = 0; i < size_; i++)
		{
			toDelete = item;
			item = item->getNext();
			delete toDelete;
		}

		first_ = nullptr;
		size_ = 0;
	}

	template<typename T>
	inline Iterator<T>* BilinkedCircularList<T>::getBeginIterator() const
	{
		return new BilinkedListIterator(this, 0);
	}

	template<typename T>
	inline Iterator<T>* BilinkedCircularList<T>::getEndIterator() const
	{
		return new BilinkedListIterator(this, size_);
	}

	template<typename T>
	inline BilinkedListItem<T>* BilinkedCircularList<T>::getItemAtIndex(int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "BilinkedList<T>::getItemAtIndex List index out of range!");

		BilinkedListItem<T>* item = first_;
		for (int i = 0; i < index; i++)
		{
			item = item->getNext();
		}

		return item;
	}

	template<typename T>
	inline BilinkedListItem<T>* BilinkedCircularList<T>::getLast()
	{
		return first_ ? first_->getPrevious() : nullptr;
	}

	template<typename T>
	inline BilinkedCircularList<T>::BilinkedListIterator::BilinkedListIterator(const BilinkedCircularList<T>* bilinkedList, const int position):
		list_(bilinkedList),
		current_(position == bilinkedList->size() ? nullptr : bilinkedList->getItemAtIndex(position)),
		position_(position)
	{ }

	template<typename T>
	inline BilinkedCircularList<T>::BilinkedListIterator::~BilinkedListIterator()
	{
		list_ = nullptr;
		current_ = nullptr;
		position_ = 0;
	}

	template<typename T>
	inline Iterator<T>& BilinkedCircularList<T>::BilinkedListIterator::operator=(const Iterator<T>& other)
	{
		const BilinkedListIterator& o = dynamic_cast<const BilinkedListIterator&>(other);
		list_ = o.list_;
		current_ = o.current_;
		position_ = o.position_;

		return *this;
	}

	template<typename T>
	inline bool BilinkedCircularList<T>::BilinkedListIterator::operator!=(const Iterator<T>& other)
	{
		const BilinkedListIterator& o = dynamic_cast<const BilinkedListIterator&>(other);

		return position_ != o.position_ ||
			current_ != o.current_ ||
			list_ != o.list_;
	}

	template<typename T>
	inline const T BilinkedCircularList<T>::BilinkedListIterator::operator*()
	{
		return current_->accessData();
	}

	template<typename T>
	inline Iterator<T>& BilinkedCircularList<T>::BilinkedListIterator::operator++()
	{
		if (position_ < list_->size() - 1)
		{
			current_ = current_->getNext();
		}
		else
		{
			current_ = nullptr;
		}

		position_++;
		return *this;
	}
}