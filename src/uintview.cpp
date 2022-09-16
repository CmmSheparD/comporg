#include <stdexcept>

#include "uintview.hh"

using namespace std;

namespace views {

size_t UIntView::bitLength()
{
	return sizeof(value_) * 8;
}

unsigned int UIntView::getBit(size_t pos)
{
	if (pos >= bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	return (value_ >> bitLength() - 1u - pos) & 1u;
}

unsigned int UIntView::filter(size_t from, size_t n)
{
	if (from + n >= bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	unsigned int filter_mask = createFilterMask(from, n);
	return value_ & filter_mask;
}

void UIntView::setBits(size_t from, unsigned int value, size_t n)
{
	if (from >= bitLength() || from + n >= bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	unsigned int set_mask = createFilterMask(from, n);
	if ((value & 1u) == 1u)
		value_ |= set_mask;
	else
		value_ &= ~set_mask;
}

void UIntView::setBitsWithMask(size_t from, unsigned int mask, size_t len)
{
	if (from + len >= bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	unsigned int unset_mask = createFilterMask(from, len);

	// ensure that mask has only wanted bits left
	mask &= unset_mask;
	value_ &= ~unset_mask;
	value_ |= mask;
}

}	// namespace views