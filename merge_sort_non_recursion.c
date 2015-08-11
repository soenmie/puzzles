#include <stdio.h>
#include <stdlib.h>
#define N 50000
#define min(a, b) ((a) < (b) ? (a) : (b))
int A[N], B[N], n, i;
void merge_sort() {
    int step;
    for (step = 1; step < n; step *= 2) {
        int left, mid, right;
        for (left = 0; left < n - step; left = right) {
            int i, j, k;
            mid = left + step;
            right = min(mid + step, n);
            i = k = left;
            j = mid;
            while (i < mid && j < right) {
                if (A[i] < A[j]) {
                    B[k++] = A[i++];
                } else {
                    B[k++] = A[j++];
                }
            }
            while (i < mid) {
                B[k++] = A[i++];
            }
            while (j < right) {
                B[k++] = A[j++];
            }
            for (i = left; i < right; ++i) {
                A[i] = B[i];
            }
        }
    }
}
int main () {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", A + i);
    }
    merge_sort();
    for (i = 0; i < n; ++i) {
        printf("%d\n", A[i]);
    }
    return 0;
}
