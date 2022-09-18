#include <stdexcept>

#include "view.hh"

using namespace std;

namespace views {

unsigned int TypeView::createFilterMask(size_t start, size_t len)
{
	const size_t length = bitLength();
	unsigned int mask = 1u << length - 1 - start;
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
		throw out_of_range("Trying to get non-existent bit.");
	return getBit_(pos);
}

unsigned int TypeView::filter(size_t from, size_t n)
{
	if (from + n > bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	return filter_(from, n);
}

void TypeView::setBits(size_t from, unsigned int value, size_t n)
{
	if (from >= bitLength() || from + n > bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	setBits_(from, value, n);
}

void TypeView::setBitsWithMask(size_t from, unsigned int mask, size_t len)
{
	if (from + len > bitLength())
		throw out_of_range("Trying to get non-existent bit.");
	setBitsWithMask_(from, mask, len);
}

}	// namespace views