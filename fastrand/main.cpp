#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "fastrand.cpp"

void usage(char** argv) {
	printf("Usage: %s METHOD NUM_OF_RANDS\n", argv[0]);
	printf("\nMETHOD: xorshift|stdlib\n");
}

volatile unsigned v; 

int main(int argc, char** argv) {
	if (argc != 3) {
		usage(argv);
		return 1;
	}
	int n = atoi(argv[2]);
	if (!strcmp(argv[1], "xorshift")) {
		while (n--) {
			v = xorshiftRand();
		}
	} else if (!strcmp(argv[1], "stdlib")) {
		while (n--) {
			v = (rand()<<16)^rand();
		}
	}
	return 0;
}

