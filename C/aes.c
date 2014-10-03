#include "transformations.h"
#include "aes.h"
#include "util.h"

#include <stdlib.h>
#include <stdio.h>

void AesEnc(State s, State k, State out) {
    int round = 0;
    Word rks[4*11];

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

    CopyState(s, out);
}
