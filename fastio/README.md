# Fast IO
This is a fast IO library (not strictly an algorithm though).
It's dedicated to IO with decimal `unsigned`s.
It uses `fread` and `fwrite` and also adds buffers effectively.

See `fastio.cpp` for implementation, and `fastio.h` for interface.

# Benchmark
This is a benchmark between fastio and `stdio.h` (stdio). The program reads 5000000 (around 73 MB) of data, parse unsigned integers, and output them added by one.

It's common knowlegde that iostream is exactly slower than molasses in January, so no one ever use iostream for fast IO.

**Environments**: same as rsort.

**Disk**: don't remember but it's HDD not SSD.

| optimization level | IO size       | fastio | stdio |
| ---                | ---           | ---    | ---   |
| -O2                | 73 MB / 52 MB | 0.698  | 1.770 |
| -O0                | 73 MB / 52 MB | 0.900  | 1.772 |

# Benchmark reproduction guide
Use `make` to compile.

Then run like
~~~ bash
$ ./datagen 5000000 > data
$ time ./fastio fastio < data > data_fastio
./fastio fastio < data > data_fastio  0.36s user 0.08s system 62% cpu 0.698 total
$ time ./fastio stdio < data > data_stdio
./fastio stdio < data > data_stdio  1.69s user 0.08s system 99% cpu 1.770 total
$ diff -sq data_fastio data_stdio # ensure we don't make mistakes
Files data_fastio and data_stdio are identical
~~~
