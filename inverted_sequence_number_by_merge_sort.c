#include <stdio.h>
#include <stdlib.h>
#define N 50000
int A[N], B[N], n, i, cnt = 0;
void merge(int A[N], int B[N], int left, int mid, int right) {
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
            cnt += mid - i;
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
void merge_sort(int A[N], int B[N], int left, int right) {
    if (right - left > 1) {
        int mid = (left + right) >> 1;
        merge_sort(A, B, left, mid);
        merge_sort(A, B, mid, right);
        merge(A, B, left, mid, right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", A + i);
    }
    merge_sort(A, B, 0, n);
    printf("%d\n", cnt);
    return 0;
}
