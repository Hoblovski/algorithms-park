//****************************************************************************
// BEGIN STRINGS

// KMP STRING MATCHING:
// CONFIG:
//	MAX_M: max length of pattern plus one
#define MAX_M 10017

// next[j]: max k, 0 <= k < j such that p[j-k..j-1] == p[0..k-1]
//
//  0        j-1   j
//  ^        ^   /
//  |        |  /
//  +--------+-+
//  |        | |
//  +--------+-+
//      .    .  \
//      . eq .   - eq?
//      .    .  /
//      +----+-+
//      |    | |
//      +----+-+
//      |    |  \
//      v    v   \
//      0    k-1  k
int next[MAX_M];
const char* ptn;
int ptnlen;

void kmp_makenext(const char* p, int len) {
	ptn = p;
	ptnlen = len;
	next[0] = -1; // in fact this value is undefined
	int c = -1; // c: candidate compare
	for (int j = 1; j <= len; j++) {
		// now p[0..c-1] till p[j-c..j-1] matches
		while (c >= 0 && p[j-1] != p[c])
			c = next[c];
		next[j] = ++c;
	}
}

void kmp_match(char* t, int len) {
	int c = 0;
	for (int i = 0; i < len; i++) {
		while (c >= 0 && t[i] != ptn[c])
			c = next[c];
		if (t[i] == ptn[c]) { // advance txt ptr cause of match
			c++;
			if (c == ptnlen) {
				// found match
				printf("match at t[%d..%d]\n", i-ptnlen+1, i);
				c = next[c];
			}
		} else { // advance txt ptr cause cant match
			c = 0;
		}
	}
}

// END STRINGS
//****************************************************************************

