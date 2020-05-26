#include <cstdio>
#define MAXSIZE 4000000 // 灯塔数目最多为4000000个

struct Point{
    int x, y;
//    void print() const {
//        printf("%d %d\n", x, y);
//    }
};

Point lightHouseCoordinate[MAXSIZE];  // points记录n个灯塔的坐标
Point newPoint[MAXSIZE];
int b[MAXSIZE];
unsigned long count = 0;   // 记录顺序对，使用int类型可能溢出
int coordinateY[MAXSIZE];   // 记录按照x坐标排序后的y坐标

// 归并排序参考了课堂内容
void mergeX(Point* points, int lo, int mid, int hi) {
    int i = lo, j = mid, k = 0;
//    Point* newPoint = new Point[hi - lo];
    for (; i < mid && j < hi;)
        newPoint[k++] = (points[i].x < points[j].x) ? points[i++] : points[j++];
    for (; i < mid; )
        newPoint[k++] = points[i++];
    for (; j < hi; )
        newPoint[k++] = points[j++];
    for (i = lo, k = 0; i < hi; )
        points[i++] = newPoint[k++];
}

void mergeSortX(Point* points, int lo, int hi) {
    if ((hi - lo) < 2)
        return;
    int mid = (lo + hi) >> 1;
    mergeSortX(points, lo, mid);
    mergeSortX(points, mid, hi);
    mergeX(points, lo, mid, hi);
}

void mergeY(int a[], int lo, int mid, int hi) {
    int i = lo, j = mid;
    int k = 0;
//    for (; i < mid && j < hi; ) {
//        if (a[i] < a[j]) {
//            i++;
//            count += (hi - j);
//        }
//        else
//            j++;
//    }
//    int* b = new int[hi-lo];
    for (; i < mid && j < hi; ) {
        b[k++] = (a[i] < a[j]) ? (count += (hi - j), a[i++]) : a[j++];
    }
    for (; i < mid; )
        b[k++] = a[i++];
    for (; j < hi; ) {
        b[k++] = a[j++];
    }
    for (i = lo, k = 0; i < hi; ++i)
        a[i] = b[k++];
}

void mergeSortY(int a[], int lo, int hi) {
    if ((hi - lo) < 2)
        return;
    int mid = (lo + hi) >> 1;
    mergeSortY(a, lo, mid);
    mergeSortY(a, mid, hi);
    mergeY(a, lo, mid, hi);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &lightHouseCoordinate[i].x, &lightHouseCoordinate[i].y);
    mergeSortX(lightHouseCoordinate, 0, n);
//    for (int i = 0; i < n; ++i)
//        lightHouseCoordinate[i].print();
    for (int i = 0; i < n; ++i)
        coordinateY[i] = lightHouseCoordinate[i].y;
    mergeSortY(coordinateY, 0, n);

    printf("%lu\n", count);
    return 0;
}