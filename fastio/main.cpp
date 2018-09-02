#include <cstdio>		// shame on iostream
#include <cstdlib>
#include <cstring>

#include "fastio.cpp"

void usage(char** argv) {
		printf("Usage: %s METHOD\n", argv[0]);
		printf("\nMETHOD: fastio|stdio\n");
}

void fastio_echo() {
	while (true) {
		unsigned v = readint();
		if (fastio_err_eof) break;
		writeint(v+1);
		writechar('\n');
	}
	fastio_flush();
}

void stdio_echo() {
	unsigned v;
	while (scanf("%u", &v) != EOF) {
		printf("%u\n", v+1);
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		usage(argv);
		return 1;
	}

	if (!strcmp(argv[1], "fastio")) {
		fastio_echo();
	} else if (!strcmp(argv[1], "stdio")) {
		stdio_echo();
	} else {
		printf("BAD METHOD\n");
		usage(argv);
		return 1;
	}

	return 0;
}
