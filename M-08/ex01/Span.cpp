#include "Span.hpp"

Span::Span() : max(0), vect(0, 0) {}
Span::Span(unsigned int n) : max(n), vect(0, 0) {}
Span::Span(const Span &ref) {*this = ref;}
Span::~Span() {}

const Span& Span::operator=(const Span &ref) {
	this->max = ref.max;
	this->vect = ref.vect;
	return *this;
}

void Span::addNumber(int n) {
	if (vect.size() == max)
		throw NoSpaceLeftException();
	vect.push_back(n);
}

void Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (vect.size() + (end - start) > max)
		throw RangeTooBigException();
	for (std::vector<int>::iterator it = start; it != end; it++) {
		vect.push_back(*it);
	}
}

int Span::shortestSpan() {
	if (vect.size() < 2)
		throw NoSpanException();

	std::vector<int> copy(vect);
	std::sort(copy.begin(), copy.end());

	int result(copy[1] - copy[0]);
	for (int i = 0; i < static_cast<int>(copy.size()) - 1; i++) {
		if (copy[i + 1] - copy[i] < result)
			result = copy[i + 1] - copy[i];
	}

	return result;
}

int Span::longestSpan() {
	if (vect.size() < 2)
		throw NoSpanException();

	std::vector<int>::iterator min = min_element(vect.begin(), vect.end());
	std::vector<int>::iterator max = max_element(vect.begin(), vect.end());

	return *max - *min;
}