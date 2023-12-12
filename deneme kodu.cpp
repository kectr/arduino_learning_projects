#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int readBit(uint8_t value, uint8_t position) {
    return (value >> position) & 1;
}

int main() {
    uint8_t data[] = {0xa0, 0xa0, 0xa0, 0xff, 0xff, 0xa0, 0xa0, 0xa0};

    uint8_t i, j;
    for (i = 0; i < 8; i++) {
        for (j = 7; j >= 0; j--) {
            printf("%" PRIu8, readBit(data[i], j));
        }
        printf("\n");
    }

    return 0;
}

