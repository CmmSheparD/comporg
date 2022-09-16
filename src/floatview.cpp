#include "floatview.hh"

using namespace std;

namespace views {

FloatView::FloatView(float value)
{
	value_.value = value;
}

size_t FloatView::bitLength()
{
	return sizeof(value_) * 8u;
}

unsigned int FloatView::getBit_(size_t pos)
{
	return (value_.view >> bitLength() - 1u - pos) & 1u;
}

unsigned int FloatView::filter_(size_t from, size_t n)
{
	unsigned int filter_mask = createFilterMask(from, n);
	return value_.view & filter_mask;
}

void FloatView::setBits_(size_t from, unsigned int value, size_t n)
{
	unsigned int set_mask = createFilterMask(from, n);
	if ((value & 1u) == 1u)
		value_.view |= set_mask;
	else
		value_.view &= ~set_mask;
}

void FloatView::setBitsWithMask_(size_t from, unsigned int mask, size_t len)
{
	unsigned int unset_mask = createFilterMask(from, len);

	// ensure that mask has only wanted bits left
	mask &= unset_mask;
	value_.view &= ~unset_mask;
	value_.view |= mask;
}

}	// namespace views