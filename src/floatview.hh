#ifndef FLOATVIEW_HH
#define FLOATVIEW_HH

#include <string>

#include "view.hh"

namespace views {

class FloatView : public TypeView {
public:
	FloatView(float value);

	~FloatView() = default;

	std::string binaryView() const;
	std::string stringView() const;

	size_t bitLength() const;
protected:
	unsigned int getBit_(size_t pos) const;
	unsigned int filter_(size_t from, size_t n) const;

	void setBits_(size_t from, unsigned int value, size_t n = 1);
	void setBitsWithMask_(size_t from, unsigned int mask, size_t len);
private:
	union {
		float value;
		unsigned int view;
	} value_;
};

}	// namespace views

#endif	// FLOATVIEW_HH