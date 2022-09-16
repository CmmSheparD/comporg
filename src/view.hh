#ifndef VIEW_HH
#define VIEW_HH
#include <string>


namespace views {


class TypeView {
public:
	virtual std::string binaryView() = 0;
	virtual size_t bitlen() = 0;

	// Bit position is assumed to counted from most significant bit to the least.
	virtual unsigned int getbit(size_t pos) = 0;
	/*
	 * Only the least significant bit of the value is given into account, all
	 * other bits are ignored.
	 */
	virtual void setbits(size_t from, unsigned int value, size_t n = 1) = 0;
};


}	// namespace views

#endif	// VIEW_HH