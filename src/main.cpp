#include <iostream>
#include <limits>
#include <string>

#include "uintview.hh"
#include "floatview.hh"
#include "bitmirror.hh"

using namespace std;
using namespace views;

TypeView *supplyTypeView();
UIntView *supplyUIntView();
FloatView *supplyFloatView();

void performMirrorBits(TypeView *const view);

void getMirrorParameters(const TypeView *const view, size_t &right, size_t &bits);

unsigned int parseUIntFromInput();
float parseFloatFromInput();
char parseCharFromInput();

int main()
{
	TypeView *view = supplyTypeView();
	char input;
	do {
		cout << view->stringView() << endl;
		cout << view->binaryView() << endl;
		cout << "Mirror bits? (y/n):" << endl;
		do {
			cout << "> ";
			input = parseCharFromInput();
			if (input != 'y' && input != 'n')
				cout << "Incorrect input, no such option! Try again." << endl;
		} while (input != 'y' && input != 'n');
		if (input == 'y')
			performMirrorBits(view);
	} while (input != 'n');
	delete view;
	return 0;
}

TypeView *supplyTypeView()
{
	TypeView *result = nullptr;
	cout << "Select type to work on:" << endl;
	cout << "1. Unsigned int" << endl;
	cout << "2. Float" << endl;
		
	unsigned int choice;
	do {
		cout << "Option: " << endl;
		choice = parseUIntFromInput();
		if (choice == 1)
			result = supplyUIntView();
		else if (choice == 2)
			result = supplyFloatView();
		else
			cout << "Incorrect input, no such option! Try again." << endl;
	} while (result == nullptr);
	return result;
}

UIntView *supplyUIntView()
{
	cout << "Enter unsigned integer value ("
	     << numeric_limits<unsigned int>::min()
	     << " - "
	     << numeric_limits<unsigned int>::max() << "):"
	     << endl;
	return new UIntView(parseUIntFromInput());	
}

FloatView *supplyFloatView()
{
	cout << "Enter floating-point value ("
	     << numeric_limits<float>::min()
	     << " - "
	     << numeric_limits<float>::max() << "):"
	     << endl;
	return new FloatView(parseFloatFromInput());	
}

void performMirrorBits(TypeView *const view)
{
	size_t right, bits;
	getMirrorParameters(view, right, bits);
	bitMirror(view, right, bits);
}

void getMirrorParameters(const TypeView *const view, size_t &right, size_t &bits)
{
	cout << "Enter right-most bit (0 - "
	     << view->bitLength() - 1 << "):"
	     << endl;
	do {
		right = parseUIntFromInput();
		if (right >= view->bitLength())
			cout << "Too big value! Try again!" << endl;
	} while (right >= view->bitLength());
	cout << "Enter number of bits to mirror (0 - "
	     << right + 1 << "):"
	     << endl;
	do {
		bits = parseUIntFromInput();
		if (bits > right + 1)
			cout << "Too big value! Try again!" << endl;
	} while (right > right + 1);
}

unsigned int parseUIntFromInput()
{
	string buffer;
	unsigned int input;
	do {
		cout << "> ";
		getline(cin, buffer);
		try {
			input = stoul(buffer);
			break;
		} catch (exception) {
			cout << "Invalid input! Try again!" << endl;
		}
	} while (true);
	return input;
}

float parseFloatFromInput()
{
	string buffer;
	float input;
	do {
		cout << "> ";
		getline(cin, buffer);
		try {
			input = stof(buffer);
			break;
		} catch (exception) {
			cout << "Invalid input! Try again!" << endl;
		}
	} while (true);
	return input;
}

char parseCharFromInput()
{
	string buffer;
	getline(cin, buffer);
	return buffer[0];
}