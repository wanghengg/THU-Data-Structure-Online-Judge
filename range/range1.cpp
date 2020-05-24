#include <stdio.h>
#include <stdlib.h>
# define L 50000

// 参考cppreference.com qsort的用法
int compare(const void *a, const void *b) {
    return (*(const int *)a) - (*(const int *)b);
}

int binarySearch(const int A[], const int& e, int lo, int hi) {
    while (lo < hi) {
        int mi = (lo + hi) >> 1;
        (e < A[mi]) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

int main() {
    int n, m;
    static int AA[L];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &AA[i]);
    qsort(AA, n, sizeof(int), compare);
    int a, b;
    int result;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        result = binarySearch(AA, b, 0, n) - binarySearch(AA, a - 1, 0, n);
        printf("%d\n", result);
    }

    return 0;
}