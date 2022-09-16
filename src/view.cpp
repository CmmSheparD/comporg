#include "view.hh"

namespace views {

unsigned int TypeView::createFilterMask(size_t start, size_t len)
{
	const size_t length = bitLength();
	unsigned int mask = 1u << length - 1 - start;
	for (size_t i = 0; i < length - 1; ++i) {
		unsigned int prev = mask;
		mask >>= 1u;
		mask |= prev;
	}
	return mask;
}

std::string TypeView::binaryView()
{
	const size_t length = bitLength();
	std::string view;
	unsigned int mask = 1u << (sizeof(mask) * 8u - 1u);
	for (int i = 0; i < length; ++i) {
		view.push_back(getBit(i) ? '1' : '0');
	}
	return view;
}

}	// namespace views