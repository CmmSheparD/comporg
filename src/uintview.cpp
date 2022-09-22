#include <string>
#include <sstream>

#include "uintview.hh"

using namespace std;

namespace views {

size_t UIntView::bitLength() const
{
	return sizeof(value_) * 8;
}

string UIntView::binaryView() const
{
	const size_t length = bitLength();
	std::string view;
	unsigned int mask = 1u << (length - 1u);
	for (size_t i = 0; i < length; ++i) {
		if (i % 8u == 0 && i != 0)
			view.push_back(' ');
		view.push_back(value_ & mask ? '1' : '0');
		mask >>= 1u;
	}
	return view;
}

string UIntView::stringView() const
{
	string view;
	stringstream buf;
	buf << value_;
	buf >> view;
	return view;
}

unsigned int UIntView::getBit_(size_t pos) const
{
	return (value_ >> (bitLength() - 1u - pos)) & 1u;
}

unsigned int UIntView::filter_(size_t from, size_t n) const
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