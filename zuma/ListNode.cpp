#include "ListNode.h"

ListNode* ListNode::insertAsPred(const char &e) {
    ListNode* x = new ListNode(e, pred, this);
    pred->succ = x;
    pred = x;
    return x;
}

ListNode* ListNode::insertAsSucc(const char &e) {
    ListNode* x = new ListNode(e, this, succ);
    succ->pred = x;
    succ = x;
    return x;
}