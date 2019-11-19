#include <stdio.h>
#include "print_as_array.h"

void printAsArr(const void *data, const uint32_t size) {

    const uint8_t *d = data;

    // printf("(%d)", size);

    printf("[");

    for(uint32_t i = 0; i < size; i++) {

        if (i != size - 1) {
            printf("0x%02x, ", d[i]);
        } else {
            // printf("%d", d[i]);
            printf("0x%02x", d[i]);
        }
    }

    printf("] (%d)\n", size);

}
