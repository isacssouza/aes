#include "aes.h"
#include "util.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int i, j, offset = 0;
    unsigned int temp = 0;
    State out;

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
                sscanf(argv[1] + offset, "%2x", &temp);
                offset += 2;
                s[j][i] = temp;
                printf("%x\n", s[j][i]);
            }
        }
    }

    AesEnc(s, k, out);

    PrintState(-1, "output", out);

    return 0;
}
