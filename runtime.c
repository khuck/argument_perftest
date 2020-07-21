#include "foo.h"

//#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#define UNLIKELY(x) x

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

ugly_fast_t ugly_fast_p;
pretty_slow_t pretty_slow_p;

int tool_enabled;

/* implement the ugly call */
void call_ugly_fast(void) {
#ifdef USE_TOOL
    if(UNLIKELY(tool_enabled)) {
        ugly_fast(a, b, c, d, e, f, g, h, i, j, k);
    }
#endif
}

void call_ugly_fast_by_pointer(void) {
#ifdef USE_TOOL
    if(UNLIKELY(tool_enabled)) {
        ugly_fast_p(a, b, c, d, e, f, g, h, i, j, k);
    }
#endif
}

/* implement the pretty call, populating a structure */
void call_pretty_slow(void) {
#ifdef USE_TOOL
    if(UNLIKELY(tool_enabled)) {
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
#endif
}

void call_pretty_slow_by_pointer(void) {
#ifdef USE_TOOL
    if(UNLIKELY(tool_enabled)) {
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

        pretty_slow_p(&foo_struct);
    }
#endif
}

void init_runtime(int enable){
    tool_enabled = enable;
    init_tool(&ugly_fast_p, &pretty_slow_p);
}
