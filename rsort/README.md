# Radix sort

This is the fastest algorithm for sorting `int`s, in my knowledge.
However it's dedicated to sorting integers (or anything else comparable like integers).
In this example it sorts non-negative `int`s, but it's easy to extend it to `long long`.
It legerages *radix sort* to achieve `O(4n + 2*65536)` complexity.

**Importing notice**: the implementation only deal with non-negative `int`s!
The algorithm can handle negative `int`s, but you should modify it on your own.

The algorithm is simple enough, you should look it up in `rsort_demangle.cpp`.

# Benchmark 
This is a benchmark between Radix sort (rsort), `std::sort` (stdsort), stdlib's qsort (qsort).

**Machine**: Lenovo T440, with i5-4200U.

**GCC**: 5.4.0 on ubuntu 16.04.

Time is measures using `time` command, taking the total column, and is shown in seconds.

| optimization level | num of `int`s to sort | rsort | qsort | stdsort |
| --- | --- | --- | --- | --- |
| -O0 | 5000000 |  0.417 | 1.409 | 1.988 |
| -O0 | 1000000 |  0.089 | 0.255 | 0.357 |
| -O2 | 5000000 |  0.399 | 1.071 | 0.657 |
| -O2 | 1000000 |  0.084 | 0.198 | 0.127 |

# Benchmark reproduction guide
Compile with `make`.

Then simply run like
~~~ bash
$ time ./rsort rsort 5000000
./rsort rsort 5000000  0.37s user 0.02s system 99% cpu 0.399 total
$
$ time ./rsort qsort 5000000
./rsort qsort 5000000  1.05s user 0.02s system 99% cpu 1.071 total
$
$ time ./rsort stdsort 5000000
./rsort stdsort 5000000  0.65s user 0.01s system 99% cpu 0.657 total
~~~
