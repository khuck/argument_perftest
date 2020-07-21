
typedef struct foo {
int a;
char b;
float c;
void* d;
void* e;
int f;
char g;
float h;
void* i;
void* j;
char* k;
} foo_t;

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
char* k);

void pretty_slow(foo_t *foo_struct);

void call_ugly_fast(void);
void call_pretty_slow(void);
