//****************************************************************************
// BEGIN NUMBER THEORY
// 
// Problem: miscellaneous number theory algorithms
#include <cmath>
#include <cstring>

// CONFIG and IMPL:

typedef long long i64;

// a**n mod m
i64 fastpow(i64 a, i64 n, i64 m) {
	i64 ans = 1;
	while (n) {
		if (n & 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		n >>= 1;
	}
	return ans;
}

// (-1)**a
#define m1pow(a) (((a)&1) ? (-1) : 1)

// mod result always in [0, b)
static inline i64 cmod(i64 a, i64 b) {
	i64 rv = a % b;
	return (rv < 0) ? rv + b : rv;
}

// give gcd result d, and give x y such that ax + by == d
void exgcd(i64 a, i64 b, i64* x, i64* y, i64* d) {
	if (!b) {
		*d = a; *x = 1; *y = 0;
	} else {
		i64 t;
		exgcd(b, a % b, &t, x, d);
		*y = t - (a/b) * *x;
	}
}

// modulo inversion, return 0 if not possible
i64 inv(i64 a, i64 mod) {
	i64 x, y, d;
	exgcd(a, mod, &x, &y, &d);
	return (d == 1) ? x : 0;
}

// make \choose{i}{j} for 0 <= i <= j <= n
#define MAX_CHOOSE 117
i64 choose[MAX_CHOOSE][MAX_CHOOSE];
void makechoose(int n, i64 mod) {
	memset(choose, 0, sizeof(choose));
	for (int i = 0; i <= n; i++)
		choose[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % mod;
}

#define MAX_ISPRIME 100017
#define MAX_CPRIME 30017
bool isprime[MAX_ISPRIME];
int prime[MAX_CPRIME];
int cprime;
// compute isprime[0]..isprime[N] inclusive
void eratosthenes_sieve(int n) {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	int loop_i_ub = (int) sqrt(n);
	for (int i = 2; i <= loop_i_ub; i++)
		if (isprime[i])
			for (int j = i * i; j <= n; j += i)
				isprime[j] = false;
}

// compute isprime[0]..isprime[N] inclusive
void euler_sieve(int n) {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	cprime = 0;
	for (int i = 2; i <= n; i++) {
		if (isprime[i])
			prime[cprime++] = i;
		for (int j = 0; j < cprime; j++) {
			isprime[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
}

// compute multiplicative function f
//	requires knowledge to compute f(p) and f(np), where p | n
// use euler phi function as example.
// also applicable to mobius mu function etc.
int mf[MAX_ISPRIME];
#define mf_pr(p) (p-1)
#define mf_pfac(p, n) (p * mf[n])
void euler_sieve_mf(int n) {
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	cprime = 0;
	mf[1] = 1; // by definition
	for (int i = 2; i <= n; i++) {
		if (isprime[i]) {
			prime[cprime++] = i;
			mf[i] = mf_pr(i);
		}
		for (int j = 0; j < cprime; j++) {
			int k = i * prime[j];
			isprime[k] = false;
			if (i % prime[j] == 0) {
				mf[k] = mf_pfac(prime[j], i);
				break;
			} else {
				mf[k] = mf[prime[j]] * mf[i];
			}
		}
	}
}

// END NUMBER THEORY
//****************************************************************************
