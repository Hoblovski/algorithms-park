#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

const char BLANK_CHARS[] = " \t\n\r";

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("BAD USAGE\n");
		return 1;
	}
	int n = atoi(argv[1]);
	for (int i = 0; i < n; i++) {
		unsigned v = (rand()<<16)^(rand());
		// put number
		printf("%u", v);
		// put chaotic white spaces
		int nblank = 1 + (rand() % 10);
		while (nblank--) {
			printf("%c", BLANK_CHARS[rand() % 4]);
		}
	}
	return 0;
}


