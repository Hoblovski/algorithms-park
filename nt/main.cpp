#include <cstdio>

#include "nt.cpp"

#define MOD ((i64) 1000000007)

int main() {
	// test fastpow
	i64 a, b, n;
	a = 479; n = 101832;
	printf("%lld**%lld mod %lld, gives %lld\n", a, n, MOD, fastpow(a, n, MOD));
	a = 2; n = 10000000;
	printf("%lld**%lld mod %lld, gives %lld\n", a, n, MOD, fastpow(a, n, MOD));
	printf("\n");

	// test exgcd
	i64 x, y, d;
	a = 24; b = 30;
	exgcd(a, b, &x, &y, &d);
	printf("(%lld, %lld) = %lld, and %lld*%lld + %lld*%lld = %lld\n", a, b, d, a, x, b, y, d);
	a = 1048576; b = MOD;
	exgcd(a, b, &x, &y, &d);
	printf("(%lld, %lld) = %lld, and %lld*%lld + %lld*%lld = %lld\n", a, b, d, a, x, b, y, d);
	printf("\n");

	// test inv
	a = 1048576;
	printf("inv of %lld mod %lld is %lld\n", a, MOD, inv(a, MOD));
	printf("inv of 5 mod 10 is %lld\n", inv(5, 10));
	printf("\n");

	// test choose
	makechoose(5, 100000);
	printf("choose:\n");
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j <= i; j++)
			printf("%5lld", choose[i][j]);
		printf("\n");
	}
	printf("\n");

	// test eratosthenes
	eratosthenes_sieve(100);
	printf("Primes in 0..100 [erato]:\n");
	for (int i = 0; i <= 100; i++)
		if (isprime[i])
			printf("%d ", i);
	printf("\n");
	printf("\n");

	// test euler
	euler_sieve(100);
	printf("Primes in 0..100 [euler]:\n");
	for (int i = 0; i <= 100; i++)
		if (isprime[i])
			printf("%d ", i);
	printf("\n");
	printf("\n");

	// test euler
	euler_sieve_mf(30);
	printf("Euler phi function in 0..30:\n");
	for (int i = 1; i <= 30; i++) {
		printf("phi(%2d)=%2d, ", i, mf[i]);
		if (i % 5 == 0) printf("\n");
	}
	printf("\n");
}
