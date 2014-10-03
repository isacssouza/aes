#include "types.h"
#include "aes.h"
#include "util.h"
#include "transformations.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void AesCbc(State IV, State *inputBlocks, int numBlocks, State k, State *out) {
    State curBlock, curOut;
    int i;

    CopyState(IV, curOut);
    for (i = 0; i < numBlocks; i++) {
        CopyState(curOut, curBlock);
        XorStates(curBlock, inputBlocks[i]);
        AesEnc(curBlock, k, curOut);
        CopyState(curOut, out[i]);
    }
}

int main(int argc, char **argv) {
    int i, j, inputLen, curBlock, numBlocks = 0;
    unsigned int temp = 0;
    byte *input;
    State *out;
    State *inputBlocks;

    State IV = { {0x00, 0x04, 0x08, 0x0c},
                {0x01, 0x05, 0x09, 0x0d},
                {0x02, 0x06, 0x0a, 0x0e},
                {0x03, 0x07, 0x0b, 0x0f} };

    State k = { {0x00, 0x04, 0x08, 0x0c},
                {0x01, 0x05, 0x09, 0x0d},
                {0x02, 0x06, 0x0a, 0x0e},
                {0x03, 0x07, 0x0b, 0x0f} };

    if (argc > 1) {
        inputLen = strlen(argv[1]);
        input = malloc(inputLen * sizeof(byte));
        numBlocks = inputLen/2/16;
        inputBlocks = malloc(numBlocks * sizeof(State));

        for (curBlock = 0; curBlock < numBlocks; curBlock++) {
            for (i = 0; i < inputLen; i += 2) {
                sscanf(argv[1] + (curBlock*16*2) + i, "%2x", &temp);
                input[i/2] = temp;
            }

            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    inputBlocks[curBlock][j][i] = input[(i*4)+j];
                }
            }
        }
    }
    out = malloc(numBlocks * sizeof(State));

    if (argc > 2) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                sscanf(argv[2] + (((i*4) + j) * 2), "%2x", &temp);
                k[j][i] = temp;
            }
        }
    }

    AesCbc(IV, inputBlocks, numBlocks, k, out);

    for (curBlock = 0; curBlock < numBlocks; curBlock++) {
        PrintState(curBlock, "output", out[curBlock]);
    }

    return 0;
}
