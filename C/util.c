#include "util.h"

#include <stdlib.h>
#include <stdio.h>

void PrintState(int round, char *name, State s) {
    int i;
    int j;

    printf("round[%.2d].%s\t", round, name);
    for (i=0; i < 4; i++) {
        for (j=0; j < 4; j++) {
            printf("%.2x", s[j][i]);
        }
    }
    printf("\n");
}

void WordsToState(State s, Word rks[], int round) {
    int i, j;
    int start = round*4;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            s[j][i] = rks[start + i][j];
        }
    }
}

void CopyWord(Word w0, Word w1) {
    int i;

    for (i = 0; i < 4; i++) {
        w1[i] = w0[i];
    }
}

void CopyState(State s0, State s1) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            s1[i][j] = s0[i][j];
        }
    }
}

unsigned char mult2(unsigned char n1) {
    unsigned short res = n1;

    res = res << 1;
    if ((res & 0x0100) != 0) {
        res = res ^ 0x011b;
    }

    return (unsigned char) res;
}
