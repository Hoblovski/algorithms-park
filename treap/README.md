# Treap
Implementation of the balanced binary search tree *Treap*, with support for the following interfaces
* insert `val` into `treap`
* delete `val` from `treap`
* retrieve how many values in the `treap` are less than `val`
* if we lay out values in the `treap` as a sorted list, what would be the value at position `k`
This implementation supports mutiple items with the same value.

For implementation, see `treap.cpp`. Note that the fast RNG in this repo is needed.

# Testing
Needs python3.

1. Compile with `make`.

2. Generate test data.
~~~ bash
$ ./datagen 100000 > data
~~~

3. Run the test
~~~ bash
$ ./testtreap < data
ALL RIGHT!
~~~
