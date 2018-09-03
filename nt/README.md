# Number theory
Implementation of miscellaneous number theory algorithms.

Current list:

* Fast power. Compute `a**n mod m` in `O(lg n)` time.
* Canonical modulo. C/C++ is not suitable for maths programming.
* Extended euclid algorithm.
* Modulo inverse.
* Make `C[n][k]` table.
* Eratosthenes sieve.
* Euler sieve, possibly computing a multiplicative function.

# Testing
Compile with `make`, then

~~~ bash
$ diff -sq <(./testnt) stdans
Files /proc/self/fd/11 and stdans are identical
~~~
