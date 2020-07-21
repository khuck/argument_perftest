#include "foo.h"

static int a = 0;
static char b = 'b';
static float c = 1.1;
static void* d = (void*)0x1;
static void* e = (void*)0x2;
static int f = 1;
static char g = 'g';
static float h = 2.2;
static void* i = (void*)0x3;
static void* j = (void*)0x4;
static char* k = "A string";

/* implement the ugly call */
void call_ugly_fast(void) {
    ugly_fast(a, b, c, d, e, f, g, h, i, j, k);
}

/* implement the pretty call, populating a structure */
void call_pretty_slow(void) {
    foo_t foo_struct;
    foo_struct.a = a;
    foo_struct.b = b;
    foo_struct.c = c;
    foo_struct.d = d;
    foo_struct.e = e;
    foo_struct.f = f;
    foo_struct.g = g;
    foo_struct.h = h;
    foo_struct.i = i;
    foo_struct.j = j;
    foo_struct.k = k;

    pretty_slow(&foo_struct);
}
