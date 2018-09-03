#include <cstdio>

#include "str.cpp"

char myptn[] = "0000";
char mytxt[] = "0000001";

int main() {
	kmp_makenext(myptn, 4);
	kmp_match(mytxt, 7);
	return 0;
}

