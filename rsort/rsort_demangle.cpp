//****************************************************************************
// BEGIN INT SORT
//
// Problem: sort an array of 32 bit integers as fast as possible.
//
// Basic idea:
//	First sort the lower 16 bits using radix sort (O(65536) + O(n)), 
//	then sort the higher 16 bits stably using radix sort (O(65536) + O(n))

// CONFIG:
#define MAX_N 5000000

// IMPL:
#include <cstring>
#define l16(a) ((a)&65535)
#define h16(a) (((unsigned)(a))>>16)
size_t cnt[65536];
int store[MAX_N];

static inline void pass1(int* a, int n) {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[l16(a[i])]++;
	for (int i = 1; i < 65536; i++) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; i--) store[--cnt[l16(a[i])]] = a[i];
}

static inline void pass2(int* a, int n) {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[h16(a[i])]++;
	for (int i = 1; i < 65536; i++) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; i--) a[--cnt[h16(store[i])]] = store[i];
}

void rsort(int* a, int n) {
	pass1(a, n);
	pass2(a, n);
}

// END INT SORT
//****************************************************************************
