#pragma once

#include "../structure.h"
#include "../array/array.h"
#include "matrix.h"

using namespace structures;
namespace structures
{

	template <typename T>
	class CoherentMatrix : public Matrix<T>
	{

	public:

		CoherentMatrix(size_t height, size_t width, const T& initValue);

		CoherentMatrix(size_t height, size_t width);

		CoherentMatrix(const CoherentMatrix<T>& other);

		~CoherentMatrix();

		Structure* clone() const override;

		Matrix<T>& operator=(const Matrix<T>& other) override;

		CoherentMatrix<T>& operator=(const CoherentMatrix<T>& other);

		void set(const size_t row, const size_t column, const T& value) override;

		T& get(const size_t row, const size_t column) override;

	private:

		Array<T>* array_;

		size_t mapIndex(const size_t row, const size_t column);

	};

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(size_t height, size_t width, const T& initValue) :
		CoherentMatrix(height, width)
	{
		fill(initValue);
	}

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(size_t height, size_t width) :
		Matrix<T>(height, width),
		array_(new Array<T>(height * width))
	{}

	template<typename T>
	inline CoherentMatrix<T>::CoherentMatrix(const CoherentMatrix<T>&other) :
		Matrix<T>(other.height_, other.width_),
		array_(new Array<T>(*other.array_))
	{}

	template<typename T>
	inline CoherentMatrix<T>::~CoherentMatrix()
	{
		delete array_;
		array_ = nullptr;
		this->width_ = 0;
		this->height_ = 0;
	}

	template<typename T>
	inline Structure* CoherentMatrix<T>::clone() const
	{
		return new CoherentMatrix<T>(*this);
	}

	template<typename T>
	inline Matrix<T>& CoherentMatrix<T>::operator=(const Matrix<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const CoherentMatrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline CoherentMatrix<T>& CoherentMatrix<T>::operator=(const CoherentMatrix<T>& other)
	{
		if (this != &other)
		{
			delete array_;
			array_ = new Array<T>(*other.array_);
			this->height_ = other.height_;
			this->width_ = other.width_;
		}
		return *this;
	}

	template<typename T>
	inline void CoherentMatrix<T>::set(const size_t row, const size_t column, const T& value)
	{
		array_->operator[](mapIndex(row, column)) = value;
	}

	template<typename T>
	inline T& CoherentMatrix<T>::get(const size_t row, const size_t column)
	{
		return array_->operator[](mapIndex(row, column));
	}

	template<typename T>
	inline size_t CoherentMatrix<T>::mapIndex(const size_t row, const size_t column)
	{
		return row * (this->width_) + column;
	}

}
