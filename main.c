#include <time.h>
#include <stdio.h>
#include <math.h>
#include "foo.h"

#define ITERATIONS 100000000
#define BILLION    1000000000
#define SAMPLES 20
#define GHZ 1.2

double compute_elapsed(struct timespec *start, struct timespec *end) {
    double startd = (double)(start->tv_sec) + ((double)(start->tv_nsec) / BILLION);
    double endd = (double)(end->tv_sec) + ((double)(end->tv_nsec) / BILLION);
    return endd - startd;
}

void report(const char * label1, double total1, double sumsquare1,
              const char * label2, double total2, double sumsquare2) {
    double mean1 = total1 / (double)(SAMPLES);
    double stddev1 = (sumsquare1 / SAMPLES) - (mean1 * mean1);
    printf("\n%s: %f +/- %f\n", label1, mean1, stddev1);
    double mean2 = total2 / (double)(SAMPLES);
    double stddev2 = (sumsquare2 / SAMPLES) - (mean2 * mean2);
    printf("%s: %f +/- %f\n", label2, mean2, stddev2);
    double diff = mean2 - mean1;
    double error = sqrt((stddev1 * stddev1) + (stddev2 * stddev2));
    printf("Diff  : %f +/- %f\n", diff, error);
    double cost = (diff / (double)(ITERATIONS)) * (double)(BILLION);
    double error_cost = (error / (double)(ITERATIONS)) * (double)(BILLION);
    printf("Cost  : %f +/- %f ns per call\n", cost, error_cost);
    printf("Cost  : %f +/- %f cycles per call\n", cost * GHZ, error_cost * GHZ);
}

int main (int argc, char * argv[]) {
    int i;
    struct timespec start;
    struct timespec end;
    int outer;
    double elapsed;
    double total_ugly = 0;
    double total_pretty = 0;
    double sumsqr_ugly = 0;
    double sumsqr_pretty = 0;
    for (outer = 0 ; outer < SAMPLES ; outer++) {
        printf("ugly: "); fflush(stdout);
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (i = 0 ; i < ITERATIONS ; i++) {
            call_ugly_fast();
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = compute_elapsed(&start, &end);
        printf("  %f seconds\n", elapsed);
        total_ugly = total_ugly + elapsed;
        sumsqr_ugly = sumsqr_ugly + (elapsed*elapsed);

        printf("pretty: "); fflush(stdout);
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (i = 0 ; i < ITERATIONS ; i++) {
            call_pretty_slow();
        }
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = compute_elapsed(&start, &end);
        printf("%f seconds\n", elapsed);
        total_pretty = total_pretty + elapsed;
        sumsqr_pretty = sumsqr_pretty + (elapsed*elapsed);
    }
    report("Ugly  ", total_ugly, sumsqr_ugly, "Pretty", total_pretty, sumsqr_pretty);
}
