CPPC = g++
CPPFLAGS = -Wall -Wextra -Wpedantic
EXE = mirror
OBJ = `find . -name "*.o"`

all: $(EXE)

$(EXE): main.o bitmirror.o floatview.o uintview.o view.o
	$(CPPC) -o $@ $(OBJ)

main.o: main.cpp bitmirror.hh floatview.hh uintview.hh
bitmirror.o: bitmirror.cpp bitmirror.hh view.hh
floatview.o: floatview.cpp floatview.hh view.hh
uintview.o: uintview.cpp uintview.hh view.hh
view.o: view.cpp view.hh

clean:
	rm -f $(EXE) $(OBJ)