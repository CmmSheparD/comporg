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

	virtual std::string binaryView() = 0;

	virtual size_t bitLength() = 0;

	// Bit position is assumed to counted from most significant bit to the least.
	unsigned int getBit(size_t pos);
	// Get mask with filtered out only `n` bits starting from `from` position.
	unsigned int filter(size_t from, size_t n);

	/*
	 * Only the least significant bit of the value is taken into
	 * account, all other bits are ignored.
	 */
	void setBits(size_t from, unsigned int value, size_t n = 1);
	void setBitsWithMask(size_t from, unsigned int mask, size_t len);
protected:
	virtual unsigned int getBit_(size_t pos) = 0;
	virtual unsigned int filter_(size_t from, size_t n) = 0;

	virtual void setBits_(size_t from, unsigned int value, size_t n = 1) = 0;
	virtual void setBitsWithMask_(size_t from, unsigned int value, size_t len) = 0;
};

}	// namespace views

#endif	// VIEW_HH