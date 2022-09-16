#ifndef VIEW_HH
#define VIEW_HH
#include <string>


namespace views {

class TypeView {
public:
	/*
	 * Created a mask, that is filed with `len` `1`-s starting at
	 * the `start` position.
	 */
	unsigned int createFilterMask(size_t start, size_t len);

	std::string binaryView();

	virtual size_t bitlen() = 0;

	// Bit position is assumed to counted from most significant bit to the least.
	virtual unsigned int getbit(size_t pos) = 0;
	// Get mask with filtered out only `n` bits starting from `from` position.
	virtual unsigned int filter(size_t from, size_t n) = 0;

	/*
	 * Only the least significant bit of the value is taken into
	 * account, all other bits are ignored.
	 */
	virtual void setbits(size_t from, unsigned int value, size_t n = 1) = 0;
	virtual void setbits_with_mask(size_t from, unsigned int value, size_t len) = 0;
};

}	// namespace views

#endif	// VIEW_HH