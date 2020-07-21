
#include "foo.h"

/* implement the ugly callback */
void ugly_fast(
int a,
char b,
float c,
void* d,
void* e,
int f,
char g,
float h,
void* i,
void* j,
char* k) {
    return;
}

/* implement the pretty callback */
void pretty_slow(foo_t *f) {
    return;
}
