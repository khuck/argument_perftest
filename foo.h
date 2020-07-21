
/* define a structure for use in pretty_slow() call */
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

/* declare the ugly call for the tool to implement */
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

typedef void (*ugly_fast_t)(
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



/* declare the pretty call for the tool to implement */
void pretty_slow(foo_t *foo_struct);

typedef void (*pretty_slow_t)(foo_t *foo_struct);

/* declare the init call for the tool to implement */

void init_tool(ugly_fast_t* , pretty_slow_t*);


/* declare functions for the runtime to implement */
void call_ugly_fast(void);
void call_pretty_slow(void);

void call_ugly_fast_by_pointer(void);
void call_pretty_slow_by_pointer(void);

void init_runtime(int);
