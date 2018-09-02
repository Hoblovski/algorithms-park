#include <cstdio>		// shame on iostream
#include <cstdlib>
#include <algorithm>
#include <ctime>

#include "rsort.cpp"

int a[MAX_N];
int n = MAX_N;

void gendata() {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = ((unsigned) (rand()<<16)^(rand())) >> 1;
}

int check() {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i-1]) {
			printf("BAD: a[%d]=%d > a[%d]=%d\n", i, a[i], i-1, a[i-1]);
			return 1;
		}
	}
	return 0;
}

void usage(char** argv) {
		printf("Usage: %s METHOD PROBSIZE\n", argv[0]);
		printf("\nMETHOD: rsort|stdsort\n");
}

int qsort_cmpint(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int main(int argc, char** argv) {
	if (argc != 3) {
		usage(argv);
		return 1;
	}

	n = atoi(argv[2]);
	if (n > MAX_N) {
		printf("PROBSIZE too large\n");
		return 1;
	}
	gendata();

	if (!strcmp(argv[1], "rsort")) {
		rsort(a, n);
	} else if (!strcmp(argv[1], "stdsort")) {
		std::sort(a, a+n);
	} else if (!strcmp(argv[1], "qsort")) {
		qsort(a, n, sizeof(int), qsort_cmpint);
	} else {
		printf("BAD METHOD\n");
		usage(argv);
		return 1;
	}

	return check();
}
