/*
 * 总体思想是：设计一个数组，读取n个坐标点，并将读取的坐标点对应的位置设置为1
 * 然后从左往右，一次将数组当前位置的值加上前一个位置的值，结束之后，数组的每
 * 个位置的值就是小于等于当前位置索引值的坐标点数，最终通过points[b]-points[a]得到结果
 */

#include <cstdio>

#define N 10000001
int points[N];  // 关于全局变量的存储区参阅了<c++ primer>

int main()
{
    int n, m, x;
    int a, b;
    scanf("%d %d", &n, &m);

    // 读取n个坐标点，并设置points相应位置的值为1
    while (n--)
    {
        scanf("%d", &x);
        points[x] = 1;
    }

    // 依次将当前位置的值加上前一个位置的值，最后数组中的每个位置的值就是不大于当前索引的坐标点数
    for (int i = 1; i < N; ++i)
        points[i] += points[i - 1];

    int result;
    while (m--)
    {
        scanf("%d %d", &a, &b);
        // points[b]-points[a]包含b但是不包含a
        result = points[b] - points[a];
        // 如果a刚好是某个坐标值，那么应该将result加1
        /*
         * 判断a是否刚好是坐标值的方法：如果a==0且points[0]=1,那么result需要加1,
         * 如果a>0且points[a]>points[a-1]，说明a恰好是一个坐标点，那么result也需要加1
         */
        if ((a == 0 && points[0] == 1) || (a > 0 && points[a] > points[a - 1]))
            result += 1;
        printf("%d\n", result);
    }
    return 0;
}