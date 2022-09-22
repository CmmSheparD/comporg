#include <string>
#include <sstream>

#include "floatview.hh"

using namespace std;

namespace views {

FloatView::FloatView(float value)
{
	value_.value = value;
}

string FloatView::binaryView() const
{
	const size_t length = bitLength();
	std::string view;
	unsigned int mask = 1u << length - 1u;
	for (int i = 0; i < length; ++i) {
		if (i == 1 || i == 9)
			view.push_back(' ');
		view.push_back(getBit(i) ? '1' : '0');
	}
	return view;
}

string FloatView::stringView() const
{
	string view;
	stringstream buf;
	buf.flags(buf.flags() | buf.scientific);
	buf << value_.value;
	buf >> view;
	return view;
}

size_t FloatView::bitLength() const
{
	return sizeof(value_) * 8u;
}

unsigned int FloatView::getBit_(size_t pos) const
{
	return (value_.view >> bitLength() - 1u - pos) & 1u;
}

unsigned int FloatView::filter_(size_t from, size_t n) const
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