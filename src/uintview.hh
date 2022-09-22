#ifndef UINTVIEW_HH
#define UINTVIEW_HH

#include <string>

#include "view.hh"

namespace views {

class UIntView : public TypeView {
public:
	UIntView(unsigned int value) : value_(value) {}

	std::string binaryView() const;
	std::string stringView() const;

	size_t bitLength() const;
protected:
	unsigned int getBit_(size_t pos) const;
	unsigned int filter_(size_t from, size_t n) const;

	void setBits_(size_t from, unsigned int value, size_t n = 1);
	void setBitsWithMask_(size_t from, unsigned int mask, size_t len);
private:
	unsigned int value_;	
};

}	// namespace views

#endif	// UINTVIEW_HH