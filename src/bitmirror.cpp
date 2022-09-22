#include "bitmirror.hh"
#include "view.hh"

void bitMirror(views::TypeView *view, const size_t last, const size_t bits)
{
	unsigned int first = last + 1 - bits;
	unsigned int buffer = view->filter(first, bits);
	unsigned int construct = 0;
	unsigned int mask = 1u << (view->bitLength() - last - 1);
	for (size_t i = 0; i < bits / 2; ++i) {
		construct |= (buffer & mask) << (bits - i * 2 - 1);
		mask <<= 1;
	}
	int shift = 0;
	if (bits % 2 != 0) {
		construct |= buffer & mask;
		mask <<= 1;
		shift++;
	}
	for (size_t i = 0; i < bits / 2 + (bits % 2); ++i) {
		construct |= (buffer & mask) >> (i * 2 + 1 + shift);
		mask <<= 1;
	}
	view->setBitsWithMask(first, construct, bits);
}