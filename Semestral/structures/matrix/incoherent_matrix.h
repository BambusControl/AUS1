#pragma once

#include "../array/array.h"
#include "matrix.h"

using namespace structures;
namespace structures
{

	template <typename T>
	class IncoherentMatrix : public Matrix<T>
	{

	public:

		IncoherentMatrix(size_t height, size_t width, const T& initValue);

		IncoherentMatrix(size_t height, size_t width);

		IncoherentMatrix(const IncoherentMatrix<T>& other);

		~IncoherentMatrix();

		Structure* clone() const override;

		Matrix<T>& operator=(const Matrix<T>& other) override;

		IncoherentMatrix<T>& operator=(const IncoherentMatrix<T>& other);

		void set(const size_t row, const size_t column, const T& value) override;

		T& get(const size_t row, const size_t column) override;

	private:
		Array<Array<T>*>* array_;

		void clear();

	};

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(size_t height, size_t width, const T& initValue) :
		IncoherentMatrix(height, width)
	{
		fill(initValue);
	}

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(size_t height, size_t width) :
		Matrix<T>(height, width),
		array_(new Array<Array<T>*>(height))
	{
		for (size_t row = 0; row < this->height_; row++)
		{
			array_->operator[](row) = new Array<T>(width);
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(const IncoherentMatrix<T>& other) :
		Matrix<T>(other.height_, other.width_),
		array_(new Array<Array<T>*>(*other.array_))
	{
		for (int row = 0; row < this->height_; row++)
		{
			array_->operator[](row) = new Array<T>(*(other.array_->operator[](row)));
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::~IncoherentMatrix()
	{
		clear();
	}

	template<typename T>
	inline Structure* IncoherentMatrix<T>::clone() const
	{
		return new IncoherentMatrix<T>(*this);
	}

	template<typename T>
	inline Matrix<T>& IncoherentMatrix<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const IncoherentMatrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline IncoherentMatrix<T>& IncoherentMatrix<T>::operator=(const IncoherentMatrix<T>& other)
	{
		if (this != &other)
		{
			clear();

			this->height_ = other.height_;
			this->width_ = other.width_;

			array_ = new Array<Array<T>*>(*other.array_);
			for (size_t row = 0; row < this->height_; row++)
			{
				//array_->operator[](row) = new Array<T>(*(array_->operator[](row)));
				array_->operator[](row) = new Array<T>(*(other.array_->operator[](row)));
			}
		}
		return *this;
	}

	template<typename T>
	inline void IncoherentMatrix<T>::set(const size_t row, const size_t column, const T& value)
	{
		array_->operator[](row)->operator[](column) = value;
	}

	template<typename T>
	inline T& IncoherentMatrix<T>::get(const size_t row, const size_t column)
	{
		return array_->operator[](row)->operator[](column);
	}

	template<typename T>
	inline void IncoherentMatrix<T>::clear()
	{
		for (size_t row = 0; row < array_->size(); row++)
		{
			delete array_->operator[](row);
		}
		delete array_;
		array_ = nullptr;
		this->height_ = 0;
		this->width_ = 0;
	}

}