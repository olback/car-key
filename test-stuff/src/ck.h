#include <inttypes.h>

typedef uint32_t Id;
typedef enum {
    Invalid = 0,
    Lock,
    Unlock
} Action;

typedef struct {
    Action action;
    Id id;
} Data;
