#include "uintview.hh"

using namespace std;

namespace views {

size_t UIntView::bitLength()
{
	return sizeof(value_) * 8;
}

unsigned int UIntView::getBit_(size_t pos)
{
	return (value_ >> bitLength() - 1u - pos) & 1u;
}

unsigned int UIntView::filter_(size_t from, size_t n)
{
	unsigned int filter_mask = createFilterMask(from, n);
	return value_ & filter_mask;
}

void UIntView::setBits_(size_t from, unsigned int value, size_t n)
{
	unsigned int set_mask = createFilterMask(from, n);
	if ((value & 1u) == 1u)
		value_ |= set_mask;
	else
		value_ &= ~set_mask;
}

void UIntView::setBitsWithMask_(size_t from, unsigned int mask, size_t len)
{
	unsigned int unset_mask = createFilterMask(from, len);

	// ensure that mask has only wanted bits left
	mask &= unset_mask;
	value_ &= ~unset_mask;
	value_ |= mask;
}

}	// namespace views