.PHONY: all clean

all: testtreap

testtreap: main.cpp treap.cpp ../fastrand/fastrand.cpp
	g++ main.cpp -o testtreap -O2 -std=c++11

clean:
	rm testtreap
