CC=g++-4.9
SRC=${wildcard *.cpp}

TARGETS = main_inline main_virtual main_direct
all: $(TARGETS)

main_inline: main_inline.cc ${SRC}
	$(CC) $< -o $@ TestVec.cpp -Wall -O3 -std=c++1y

main_virtual: main_virtual.cc ${SRC}
	$(CC) $< -o $@ TestVec.cpp -Wall -O3 -std=c++1y

main_direct: main_direct.cc ${SRC}
	$(CC) $< -o $@ TestVec.cpp -Wall -O3 -std=c++1y

clean:
	rm $(TARGETS)

again: clean $(TARGETS)
