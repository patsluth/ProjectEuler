.PHONY: all clean




all: clean
	clang++ -std=c++11 -stdlib=libc++ -Wall -Wextra *.cpp -o projecteuler;





clean:
	rm -rf projecteuler




