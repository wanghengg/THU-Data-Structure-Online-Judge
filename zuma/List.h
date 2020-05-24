#ifndef DATA_STRUCTURE_ONLINE_JUDGE_LIST_H
#define DATA_STRUCTURE_ONLINE_JUDGE_LIST_H

#include "ListNode.h"
#include <stdio.h>

class List {
private:
    int _size;
    ListNode* header;
    ListNode* trailer;
    // deleteHeader指向删除块首元素之前的元素，可以用来查找下次要删除的block
    ListNode* deleteHeader = nullptr;

protected:
    void init();
    int clear();

public:
    List() { init(); }
    ~List();
    char remove(ListNode* p);
    ListNode* insertAfter(ListNode* p, char const &e);
    ListNode* insertLast(char const &e);
    ListNode* insertAt(int n, char const &e);
    void print();
    int searchAround(ListNode* p);
    ListNode* removeBlock(int n);
    int size() const { return _size; }
};


#endif //DATA_STRUCTURE_ONLINE_JUDGE_LIST_H
