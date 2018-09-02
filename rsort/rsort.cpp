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
#define _rsort_l16(a) ((a)&65535)
#define _rsort_h16(a) (((unsigned)(a))>>16)
size_t _rsort_cnt[65536];
int _rsort_store[MAX_N];

static inline void _rsort_pass1(int* a, int n) {
	memset(_rsort_cnt, 0, sizeof(_rsort_cnt));
	for (int i = 0; i < n; i++) _rsort_cnt[_rsort_l16(a[i])]++;
	for (int i = 1; i < 65536; i++) _rsort_cnt[i] += _rsort_cnt[i-1];
	for (int i = n-1; i >= 0; i--) _rsort_store[--_rsort_cnt[_rsort_l16(a[i])]] = a[i];
}

static inline void _rsort_pass2(int* a, int n) {
	memset(_rsort_cnt, 0, sizeof(_rsort_cnt));
	for (int i = 0; i < n; i++) _rsort_cnt[_rsort_h16(a[i])]++;
	for (int i = 1; i < 65536; i++) _rsort_cnt[i] += _rsort_cnt[i-1];
	for (int i = n-1; i >= 0; i--) a[--_rsort_cnt[_rsort_h16(_rsort_store[i])]] = _rsort_store[i];
}

void rsort(int* a, int n) {
	_rsort_pass1(a, n);
	_rsort_pass2(a, n);
}

// END INT SORT
//****************************************************************************
