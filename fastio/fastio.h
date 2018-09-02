#ifndef FASTIO_H
#define FASTIO_H

// Just the interface of fastio

unsigned readint(void);
char peekchar();
void writeint(unsigned v);
void writechar(char v);
void fastio_flush();
extern int fastio_err_eof;

void set_fastio_fout(FILE* fout);
void set_fastio_fin(FILE* fin);
void fastio_reinit_in();

#endif // FASTIO_H
