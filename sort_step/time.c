#include <stdio.h>
#include <time.h>

int main() {
    unsigned long long i;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (i = 0; i < 1000000000; i++) {
        // Just counting, no operation
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
