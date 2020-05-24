#include <cstdio>
//#define MAXNUMBER 4000000

//int a[MAXNUMBER + 2][MAXNUMBER + 2];
//int coordinateX[MAXNUMBER];
//int coordinateY[MAXNUMBER];

/*
 * 两个灯塔能够彼此照亮则(x1 - x2)*(y1 - y2)为正数
 * 结果为正时返回1，否则返回1，后面可以将保存结果的所有元素相加即为可以互相照亮的灯塔对数
 */
int getArea(int x1, int y1, int x2, int y2) {
    return ((x1 - x2) * (y1 - y2) > 0) ? 1 : 0;
}

int main() {
    int n;  // 灯塔的个数
    scanf("%d", &n);
    int length = n + 1;

    // 数组a的前两行存储坐标值，后面的n-1行a[i][j]记录第i-1个灯塔和第j+2个灯塔是否能彼此照亮
    // 如果能够彼此照亮，则a[i][j]记为1，否则记为0
    int a[length][length];
//    for (int i = 0; i < length; ++i) {
//        for (int j = 0; j < length; ++j)
//            a[i][j] = 0;
//    }

//    int coordinateX[n]; // 用于保存灯塔的x坐标
//    int coordinateY[n]; // 用于保存灯塔的y坐标
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a[0][i], &a[1][i]);
    }

    for (int i = 1; i < n; ++i) {
        int index = i - 1;
        for (int j = 0; j < i; ++j) {
            a[j+2][index--] = getArea(a[0][j], a[1][j], a[0][i], a[1][i]);
        }
    }

    unsigned long long count = 0;   // count用来计数能够彼此照亮的灯塔对数
    int max = n - 1;    // 第一个灯塔与其后灯塔组成的对数
    // 如果灯塔对能彼此照亮getArea()函数返回1，所以只用累加所有元素就是灯塔数
    for (int i = 2; i < n + 1; ++i) {
        for (int j = 0; j < max; ++j)
            count += a[i][j];
        max -= 1;   // 后面的灯塔与其后灯塔组成的对数一次减1
    }
//    int max = n - 1;
//    for (int i = 2; i < n - 1; ++i) {
//        for (int j = 0; j < max; ++j) {
//            if (a[i][j] > 0)
//                ++count;
//        }
//        --max;
//    }

    // 参考了https://blog.csdn.net/liangtianmeng/article/details/105017787中关于
    // unsigned long long 的格式化输出占位符
    printf("%llu", count);
    return 0;
}