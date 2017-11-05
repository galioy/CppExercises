#include "doubly-linked.h"

List::List() {
    this->first = NULL;
}

List::~List() {
}

void List::insert(int n) {
    Node *temp = new Node;
    temp->val = n;
    temp->next = NULL;

    /*
     * first create the first node in the list, if empty
     */
    if (this->first == NULL) {
        this->first = temp;
        return;
    }

    Node *last = this->first;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = temp;
}

void List::reverse() {
    if(this->first == NULL) return;
    if(this->first->next == NULL) return;

    Node *p1, *p2;
    p1 = this->first;
    p2 = p1->next;

    p1->next = NULL;
    p1->prev = p2;

    while (p2 != NULL) {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }

    this->first = p1;
}

void List::print() {
    Node *q;

    q = this->first;
    while (q != NULL) {
        cout << q->val << ' ';
        q = q->next;
    }
}

//int List::count() {
//    Node *q = this->first;
//    int count = 0;
//
//    while (q != NULL) {
//        q = q->next;
//        count++;
//    }
//
//    return count;
//}
//
//Node List::lastNode(){
//    Node *q = this->first;
//
//    while(q != NULL){
//        q = q->next;
//    }
//
//    return q;
//}

