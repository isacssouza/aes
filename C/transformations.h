#ifndef __TRANSFORMATIONS_H
#define __TRANSFORMATIONS_H

#include "types.h"

void SubBytes(State s);
void AddRoundKey(State s, State rk);
void ShiftRows(State s);
void MixColumns(State s);
void KeyExpansion(State key, Word rks[4*11]);
void CopyState(State s0, State s1);
void CopyWord(Word w0, Word w1);
void RotWord(Word w);
void SubWord(Word w);
void XorWord(Word w0, unsigned char w1);
void XorWords(Word w0, Word w1);
void KeyExpansion(State key, Word rks[4*11]);
unsigned char mult2(unsigned char n1);

#endif /* __TRANSFORMATIONS_H */
