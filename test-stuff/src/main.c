#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "print_as_array.h"
#include "ck.h"

#define TOTAL_LENGTH 16

int main(int argc, char *argv[]) {

    srand(time(NULL));

    Data data = {
        action: Unlock,
        id: 65
    };

    printAsArr(&data, sizeof(data));

    uint8_t dataPadded[TOTAL_LENGTH] = {0};
    memcpy(dataPadded, &data, sizeof(data));

    printAsArr(&dataPadded, sizeof(dataPadded));

    for (short i = sizeof(Data); i < TOTAL_LENGTH; i++) {
        dataPadded[i] = rand() % 256;
    }

    printAsArr(&dataPadded, sizeof(dataPadded));

    Data dataFromPadded = *((Data*) &dataPadded);
    printf("After padding, action: %d\n", dataFromPadded.action);
    printf("After padding, id: %d\n", dataFromPadded.id);

    return 0;

}
