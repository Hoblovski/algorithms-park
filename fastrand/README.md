# Fast rng
This is a fast random number generator (much faster than stdlib's).
It uses the [xorshift algorithm](https://www.jstatsoft.org/article/view/v008i14/xorshift.pdf) to produce random `unsigned`s.
In fact I just copied the code from their paper, `fastrand.cpp` is **not** should be attributed to them ;).

This algorithm is not cryptographically secure.

# Benchmark
Only compare with C stdlib. C++ RNGs are not considered.

| optimization level | number of random numbers | xorshift | stdlib |
| ---                | ---                      | ---      | ---    |
| -O0                | 10000000                 | 0.057    | 0.224  |
| -O0                | 100000000                | 0.527    | 2.225  |
| -O2                | 10000000                 | 0.033    | 0.215  |
| -O2                | 100000000                | 0.221    | 2.144  |

# Benchmark reproduction guide
Compile with `make`, then run

~~~ bash
$ time ./rng xorshift 10000000
./rng xorshift 10000000  0.06s user 0.00s system 99% cpu 0.057 total
$ time ./rng stdlib 10000000
./rng stdlib 10000000  0.22s user 0.00s system 99% cpu 0.224 total
~~~
