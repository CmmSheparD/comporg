#ifndef VIEW_HH
#define VIEW_HH

#include <string>
#include <stdexcept>

namespace views {

class TypeView {
public:
	virtual ~TypeView() = default;
	/*
	 * Created a mask, that is filed with `len` `1`-s starting at
	 * the `from` position.
	 */
	unsigned int createFilterMask(size_t from, size_t len) const;

	virtual std::string binaryView() const = 0;
	virtual std::string stringView() const = 0;

	virtual size_t bitLength() const = 0;

	// Bit position is assumed to counted from most significant bit to the least.
	unsigned int getBit(size_t pos) const;
	// Get mask with filtered out only `n` bits starting from `from` position.
	unsigned int filter(size_t from, size_t n) const;

	/*
	 * Only the least significant bit of the value is taken into
	 * account, all other bits are ignored.
	 */
	void setBits(size_t from, unsigned int value, size_t n = 1);
	void setBitsWithMask(size_t from, unsigned int mask, size_t len);
protected:
	virtual unsigned int getBit_(size_t pos) const = 0;
	virtual unsigned int filter_(size_t from, size_t n) const = 0;

	virtual void setBits_(size_t from, unsigned int value, size_t n = 1) = 0;
	virtual void setBitsWithMask_(size_t from, unsigned int value, size_t len) = 0;
};


class BitAddressException : public std::runtime_error {
public:
	BitAddressException(size_t address, size_t bits) :
		std::runtime_error("Trying to get out of range bit."),
		address(address),
		type_bit_length(bits)
	{}

	size_t address;
	size_t type_bit_length;
};


class BitRangeAccessException : public std::runtime_error {
public:
	BitRangeAccessException(size_t left, size_t right, size_t bits) :
		std::runtime_error("Trying to access bits out of the type's range."),
		left_most_address(left),
		right_most_address(right),
		type_bit_length(bits)
	{}

	size_t left_most_address;
	size_t right_most_address;
	size_t type_bit_length;
};

}	// namespace views

#endif	// VIEW_HH