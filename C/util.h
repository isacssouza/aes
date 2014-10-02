#ifndef __UTIL_H
#define __UTIL_H

#include "types.h"

void PrintState(int round, char *name, State s);
void WordsToState(State s, Word rks[], int round);
void CopyState(State s0, State s1);
void CopyWord(Word w0, Word w1);
void PrintKey(char *name, Word rks[], int round);
void PrintKeyWord(char *name, Word w, int round);
byte mult2(byte n1);

#endif /* __UTIL_H */
