#include "List.h"

int main() {
    // 默认构造一个空的list
    List list;
    // 根据输入的第一行字符串，按顺序插入list中
    char e;
    scanf("%c", &e);
    while (e != '\n') {
        list.insertLast(e);
        scanf("%c", &e);
    }

    int n;  // n表示回放操作的次数
    int r;  // r表示新插入字母的位置
    char c; // c表示新插入的字母
    scanf("%d", &n);
    int repeatNumbers;
    ListNode* x;
    while (0 < n--) {
        scanf("%d %c", &r, &c);
        x = list.insertAt(r, c);
        while ( (repeatNumbers = list.searchAround(x)) >= 3)
            x = list.removeBlock(repeatNumbers);
        if (list.size() == 0)
            printf("%c\n", '-');
        else
            list.print();
    }
    return 0;
}