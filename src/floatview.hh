#ifndef FLOATVIEW_HH
#define FLOATVIEW_HH

#include "view.hh"

namespace views {

class FloatView : public TypeView {
public:
	FloatView(float value);

	size_t bitLength();
protected:
	unsigned int getBit_(size_t pos);
	unsigned int filter_(size_t from, size_t n);

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