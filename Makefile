.PHONY: all clean





# C preprocessor
CPPFLAGS =
# C compiler
CFLAGS = 
# C++ compiler
CXXFLAGS = -std=gnu++11 -stdlib=libc++ -Wall -Wextra -O3
# linker
LDFLAGS = 





all: clean
	clang++ -x c++-header $(CXXFLAGS) projectEuler.pch -o prefix.pch;
	clang++ -include-pch prefix.pch $(CXXFLAGS) *.cpp $(CFLAGS) -o projecteuler;





clean:
	rm -rf projecteuler;
	rm -rf prefix.pch;




