// REQUIRES: fastrand
#include "../fastrand/fastrand.cpp"

//****************************************************************************
// BEGIN TREAP
//
// Problem: insert, delete, lessthan, select in O(lg n) time.
//

// CONFIG:
#define MAX_NODES 1000000

// IMPL:
#define INT_MASK 0x7fffffff
struct tnode {
	int v;
	unsigned p;
	size_t w, sz;
	tnode *lc, *rc;
};

tnode pool[MAX_NODES], *root, *null;
size_t plsz = 0;

static inline void lrot(tnode **n) {
	auto m = (*n)->rc;
	(*n)->rc = m->lc;
	m->lc = *n;
	(*n)->sz = (*n)->lc->sz + (*n)->w + (*n)->rc->sz;
	m->sz = m->lc->sz + m->w + m->rc->sz;
	*n = m;
}

static inline void rrot(tnode **n) {
	auto m = (*n)->lc;
	(*n)->lc = m->rc;
	m->rc = *n;
	(*n)->sz = (*n)->lc->sz + (*n)->w + (*n)->rc->sz;
	m->sz = m->lc->sz + m->w + m->rc->sz;
	*n = m;
}

#define treap_alloc() (&(pool[plsz++]))

void treap_init() {
	plsz = 0;
	null = treap_alloc();
	null->v = -1;
	null->p = INT_MASK;
	null->sz = 0;
	null->w = 0;
	null->lc = null->rc = null;
	root = null;
}

void treap_insert(tnode **n, int val) {
	if ((*n) == null) {
		*n = treap_alloc();
		(*n)->v = val;
		(*n)->p = xorshiftRand() & INT_MASK;
		(*n)->sz = (*n)->w = 1;
		(*n)->lc = (*n)->rc = null;
	} else if (val < (*n)->v) {
		treap_insert(&((*n)->lc), val);
		(*n)->sz++;
		if ((*n)->lc->p < (*n)->p) rrot(n);
	} else if (val > (*n)->v) {
		treap_insert(&((*n)->rc), val);
		(*n)->sz++;
		if ((*n)->rc->p < (*n)->p) lrot(n);
	} else {
		(*n)->sz++;
		(*n)->w++;
	}
}

// val must be in treap
void treap_delete(tnode **n, int val) {
	if (val < (*n)->v) {
		(*n)->sz--;
		treap_delete(&((*n)->lc), val);
	} else if (val > (*n)->v) {
		(*n)->sz--;
		treap_delete(&((*n)->rc), val);
	} else if ((*n)->w > 1) {
			(*n)->w--;
			(*n)->sz--;
	} else if ((*n)->lc == null) {
		*n = (*n)->rc;
	} else if ((*n)->rc == null) {
		*n = (*n)->lc;
	} else if ((*n)->lc->p < (*n)->rc->p) {
		rrot(n);
		(*n)->sz--;
		treap_delete(&((*n)->rc), val);
	} else {
		lrot(n);
		(*n)->sz--;
		treap_delete(&((*n)->lc), val);
	}
}

// # of item LESS THAN val
int treap_cntless(tnode *n, int val) {
	int rv = 0;
	while (n != null) {
		if (val == n->v)
			return rv + n->lc->sz;
		else if (val < n->v)
			n = n->lc;
		else {
			rv += n->lc->sz + n->w;
			n = n->rc;
		}
	}
	return rv;
}

// rank: at the x-th position, from the 1-st.
tnode* treap_select(tnode* n, int rank) {
	while (n != null) {
		if (rank <= n->lc->sz) {
			n = n->lc;
		} else {
			rank -= n->lc->sz;
			if (rank <= n->w)
				return n;
			rank -= n->w;
			n = n->rc;
		}
	}
	return null;
}

void traverse(tnode* n) {
	if (n == null) return;
	traverse(n->lc);
	printf("%dx%lu ", n->v, n->w);
	if (n->sz != n->lc->sz + n->rc->sz + n->w)
		printf("BAD at v=%d, sz=%lu!=%lu+%lu+%lu\n", n->v, n->sz, n->lc->sz, n->w, n->rc->sz);
	traverse(n->rc);
}

// END TREAP
//****************************************************************************
