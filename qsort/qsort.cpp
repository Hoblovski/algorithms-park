// CONFIG:
#define MAX_N 5000000

// l and r are inclusive
void _myqsort(int *a, int l, int r) {
    int i = l, j = r, p = a[(l+r)>>1];
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i > j) break;
        int u = a[i]; a[i] = a[j]; a[j] = u;
        i++; j--;
    }
    if (i < r) _myqsort(a, i, r);
    if (j > l) _myqsort(a, l, j);
}

void myqsort(int *a, int n) {
    _myqsort(a, 0, n-1);
}
