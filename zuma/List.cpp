#include "List.h"

// init()函数参考了清华大学《数据结构》MOOC
void List::init() {
    header = new ListNode;
    trailer = new ListNode;
    header->succ = trailer;
    header->pred = nullptr;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;
}

// clear()函数参考了清华大学《数据结构》MOOC
int List::clear() {
    int oldSize = _size;
    while (0 < _size)
        remove(header->succ);
    return oldSize;
}

List::~List() {
    clear();
    delete header;
    delete trailer;
    header = nullptr;
    trailer = nullptr;
}

// remove()函数参考了清华大学《数据结构》MOOC
char List::remove(ListNode *p) {
    char e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}

ListNode* List::insertAfter(ListNode *p, const char &e) {
    _size++;
    return p->insertAsSucc(e);
}

ListNode* List::insertLast(const char &e) {
    _size++;
    return trailer->insertAsPred(e);
}

ListNode* List::insertAt(int n, const char &e) {
    ListNode* head = header;
    while (0 < n--)
        head = head->succ;
    return insertAfter(head, e);
}

// 打印list所有元素
void List::print() {
    ListNode* head = header;
    while ((head = head->succ) != trailer)
        printf("%c", head->data);
    printf("\n");
}

/*
 * @brief: 接收一个节点指针参数，返回该节点附近与之data相同的block的元素个数
 * @param: ListNOde* p   指向需要查找的节点的指针
 * @return:  用于返回连续相同字母块的字母总数
 */
int List::searchAround(ListNode *p) {
    if (p == header)
        return 0;
    ListNode* forward = p;
    ListNode* backward = p;
    int count = 0;
    // 向前访问节点，到达header终止，如果该节点的data和查找的元素相同，则count加1，
    // 当出现与查找元素不相同的节点时，也终止向前查找
    // while ((forward = forward->pred) != header && forward->data == p->data)
    while ((forward = forward->pred)->data == p->data)
        ++count;
    // 向后访问节点，到达trailer终止，如果该节点的data和查找的元素相同，则count加1，
    // 当出现与查找元素不相同的节点时，也终止向后查找
    // while ((backward = backward->succ) != trailer && backward->data == p->data)
    while ((backward = backward->succ)->data == p->data)
        ++count;
    // 将deleteHeader指向连续相同字母块首元素之前的节点，用于删除block后继续查找连续相同字母块
    deleteHeader = forward;
    return ++count;
}

/*
 * @brief: searchAround()函数返回了连续相同字母块的元素个数，用于removeBlock()的参数，
 *        removeBlock()函数删除该字母块
 * @param: int n    要删除元素的个数
 * @return: 返回删除块首节点之前的节点的指针，用于下一次查找调用searchAround()的参数
 */
ListNode* List::removeBlock(int n) {
    while (0 < n--)
        remove(deleteHeader->succ);
    return deleteHeader;
}