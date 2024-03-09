#pragma once

template <typename T>
class Array {
	private:
		T *arr;
		int len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &ref);
		const Array &operator=(const Array &ref);
		~Array();
		int size() const;

		class ArrayOutOfBoundException : public std::exception {
			public:
				const char *what() const throw() {return "Array out of bound";}
		};

		T &operator[](int index);
};