#include <stdexcept>

#include "view.hh"

using namespace std;

namespace views {

unsigned int TypeView::createFilterMask(size_t from, size_t len)
{
	if (from + len > bitLength())
		throw BitRangeAccessException(from, from + len, bitLength());
	const size_t length = bitLength();
	unsigned int mask = 1u << length - 1 - from;
	for (size_t i = 0; i < len - 1; ++i) {
		unsigned int prev = mask;
		mask >>= 1u;
		mask |= prev;
	}
	return mask;
}

unsigned int TypeView::getBit(size_t pos)
{
	if (pos >= bitLength())
		throw BitAddressException(pos, bitLength());
	return getBit_(pos);
}

unsigned int TypeView::filter(size_t from, size_t n)
{
	if (from + n > bitLength())
		throw BitRangeAccessException(from, from + n, bitLength());
	return filter_(from, n);
}

void TypeView::setBits(size_t from, unsigned int value, size_t n)
{
	if (from + n > bitLength())
		throw BitRangeAccessException(from, from + n, bitLength());
	setBits_(from, value, n);
}

void TypeView::setBitsWithMask(size_t from, unsigned int mask, size_t n)
{
	if (from + n > bitLength())
		throw BitRangeAccessException(from, from + n, bitLength());
	setBitsWithMask_(from, mask, n);
}

}	// namespace views