#include "transformations.h"
#include "aes.h"
#include "util.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int round = 0;
    Word rks[4*11];
    int i, j;
    unsigned int temp = 0;

    State s = { {0x00, 0x44, 0x88, 0xcc},
                {0x11, 0x55, 0x99, 0xdd},
                {0x22, 0x66, 0xaa, 0xee},
                {0x33, 0x77, 0xbb, 0xff} };

    State k = { {0x00, 0x04, 0x08, 0x0c},
                {0x01, 0x05, 0x09, 0x0d},
                {0x02, 0x06, 0x0a, 0x0e},
                {0x03, 0x07, 0x0b, 0x0f} };

    if (argc > 1) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                scanf("%x", &temp);
                k[j][i] = temp;
                printf("%x\n", k[j][i]);
            }
        }
    }

    
    PrintState(round, "input", s);

    KeyExpansion(k, rks);

    State curKey;
    WordsToState(curKey, rks, round);

    PrintState(round, "k_sch", curKey);

    AddRoundKey(s, curKey);

    round = 1;
    for (round = 1; round < 10; round++) {
        PrintState(round, "start", s);
        SubBytes(s);
        PrintState(round, "s_box", s);
        ShiftRows(s);
        PrintState(round, "s_row", s);
        MixColumns(s);
        PrintState(round, "m_col", s);
        WordsToState(curKey, rks, round);
        AddRoundKey(s, curKey);
        PrintState(round, "k_sch", curKey);
    }

    PrintState(round, "start", s);
    SubBytes(s);
    PrintState(round, "s_box", s);
    ShiftRows(s);
    PrintState(round, "s_row", s);
    WordsToState(curKey, rks, round);
    AddRoundKey(s, curKey);
    PrintState(round, "k_sch", curKey);

    PrintState(round, "output", s);

    return 0;
}
