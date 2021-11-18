#pragma once

#include "../structure.h"

namespace structures
{

	template <typename T>
	class Matrix : public Structure
	{

	public:

		virtual Structure* clone() const = 0;

		size_t size() const override;

		Structure& operator=(const Structure& other);

		virtual Matrix<T>& operator=(const Matrix<T>& other) = 0;

		virtual void set(const size_t row, const size_t column, const T& value) = 0;

		virtual T& get(const size_t row, const size_t column) = 0;
		
		size_t height();

		size_t width();

		void fill(const T& value);

		virtual ~Matrix();

	protected:

		size_t height_;
		size_t width_;

		Matrix(size_t height, size_t width);

	};

	template<typename T>
	inline size_t Matrix<T>::size() const
	{
		return height_ * width_;
	}

	template<typename T>
	inline Structure& Matrix<T>::operator=(const Structure& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const Matrix<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline size_t Matrix<T>::height()
	{
		return height_;
	}

	template<typename T>
	inline size_t Matrix<T>::width()
	{
		return width_;
	}

	template<typename T>
	inline void Matrix<T>::fill(const T& value)
	{
		for (size_t row = 0; row < height_; row++)
		{
			for (size_t col = 0; col < width_; col++)
			{
				set(row, col, value);
			}
		}
	}

	template<typename T>
	inline Matrix<T>::~Matrix()
	{}

	template<typename T>
	inline Matrix<T>::Matrix(size_t height, size_t width) :
		height_(height),
		width_(width)
	{
		if (height < 1 || width < 1)
		{
			throw std::out_of_range("Matrix::Matrix : height and width of matrix must be >= 1!");
		}
	}

}
