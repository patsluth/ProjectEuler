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
	#clang++ $(CXXFLAGS) *.cpp $(CFLAGS) -o projecteuler;
	clang++ $(CXXFLAGS) main.cpp problem_60.cpp libProjectEuler.cpp $(CFLAGS) -o projecteuler;





clean:
	rm -rf projecteuler




