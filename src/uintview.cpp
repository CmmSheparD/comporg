#include <stdexcept>

#include "uintview.hh"

using namespace std;

namespace views {

std::string UIntView::binaryView()
{
	unsigned int mask = 1u << (sizeof(mask) * 8 - 1);
	std::string view;
	for (int i = 0; i < bitlen(); ++i) {
		view.push_back(getbit(i) ? '1' : '0');
	}
	return view;
}

size_t UIntView::bitlen()
{
	return sizeof(value_) * 8;
}

unsigned int UIntView::getbit(size_t pos)
{
	const size_t len = bitlen();
	if (pos >= len)
		throw out_of_range("Trying to get non-existent bit.");
	return (value_ >> len - 1 - pos) & 1u;
}

void UIntView::setbits(size_t from, unsigned int value, size_t n)
{
	const size_t len = bitlen();
	if (from >= len || from + n >= len)
		throw out_of_range("Trying to get non-existent bit.");
	unsigned int set_mask = 1u << len - 1 - from;
	for (size_t i = 0; i < n - 1; ++i) {
		unsigned int prev = set_mask;
		set_mask >>= 1u;
		set_mask |= prev;
	}
	if ((value & 1u) == 1u)
		value_ |= set_mask;
	else
		value_ &= ~set_mask;
}

}	// namespace views