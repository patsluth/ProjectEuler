.PHONY: all clean





# C preprocessor
CPPFLAGS =
# C compiler
CFLAGS = -Isercantutar-infint
# C++ compiler
CXXFLAGS = -std=gnu++11 -stdlib=libc++ -Wall -Wextra
# linker
LDFLAGS = 





all: clean
	clang++ $(CXXFLAGS) *.cpp $(CFLAGS) -o projecteuler;





clean:
	rm -rf projecteuler




