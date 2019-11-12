#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#define TOTAL_LENGTH 16

typedef uint32_t Id;
typedef enum Actions {
    Invalid = 0,
    Lock,
    Unlock
} Action;

struct Data {
    Action action;
    Id id;
};

int main(int argc, char *argv[]) {

    srand(time(NULL));

    struct Data data = {
        action: Unlock,
        id: 65
    };

    printAsArr(&data, sizeof(data));

    uint8_t dataPadded[TOTAL_LENGTH] = {0};
    memcpy(dataPadded, &data, sizeof(data));

    printAsArr(&dataPadded, sizeof(dataPadded));

    for (short i = sizeof(struct Data); i < TOTAL_LENGTH; i++) {
        dataPadded[i] = rand() % 256;
    }

    printAsArr(&dataPadded, sizeof(dataPadded));

    struct Data dataFromPadded = *((struct Data*) &dataPadded);
    printf("After padding, action: %d\n", dataFromPadded.action);
    printf("After padding, id: %d\n", dataFromPadded.id);

    return 0;

}

void printAsArr(const void *data, const uint32_t size) {

    uint8_t *d = data;

    printf("[");

    for(uint32_t i = 0; i < size; i++) {

        if (i != size - 1) {
            printf("0x%02x, ", d[i]);
        } else {
            // printf("%d", d[i]);
            printf("0x%02x", d[i]);
        }
    }

    printf("]\n");

}
