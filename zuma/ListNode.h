#ifndef DATA_STRUCTURE_ONLINE_JUDGE_LISTNODE_H
#define DATA_STRUCTURE_ONLINE_JUDGE_LISTNODE_H


struct ListNode {
    char data = 0;
    ListNode* pred;
    ListNode* succ;

    ListNode() {}
    ListNode(char e, ListNode* p = nullptr, ListNode* s = nullptr)
    : data(e), pred(p), succ(s) {}

    ListNode* insertAsPred(char const &e);
    ListNode* insertAsSucc(char const &e);
};


#endif //DATA_STRUCTURE_ONLINE_JUDGE_LISTNODE_H
