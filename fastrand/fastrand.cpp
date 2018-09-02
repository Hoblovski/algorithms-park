//****************************************************************************
// BEGIN XORSHIFT
//
// Problem: generate random unsigned's fast
//
// Algorithm: see xorshift paper

#define SEED_X 123456789
#define SEED_Y 362436069
#define SEED_Z 521288629
#define SEED_W 88675123

unsigned xorshiftRand(void) {
    static unsigned x = SEED_X, y = SEED_Y,
                        z = SEED_Z, w = SEED_W;
    unsigned t;
    t = x ^ (x << 11);
    x = y; y = z; z = w;
    return (w = (w ^ (w>>19)) ^ (t ^ (t>>8)));
}

// END XORSHIFT
//****************************************************************************
