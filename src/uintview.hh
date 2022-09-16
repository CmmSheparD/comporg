#ifndef UINTVIEW_HH
#define UINTVIEW_HH

#include <string>

#include "view.hh"


namespace views {


class UIntView : public TypeView {
public:
	UIntView(unsigned int value) : value_(value) {}

	std::string binaryView();

	size_t bitlen();
	unsigned int getbit(size_t pos);
	void setbits(size_t from, unsigned int value, size_t n = 1);
private:
	unsigned int value_;	
};

}	// namespace views

#endif	// UINTVIEW_HH