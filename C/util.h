#ifndef __UTIL_H
#define __UTIL_H

#include "types.h"

void PrintState(int round, char *name, State s);
void WordsToState(State s, Word rks[], int round);
void CopyState(State s0, State s1);
void CopyWord(Word w0, Word w1);
unsigned char mult2(unsigned char n1);

#endif /* __UTIL_H */
