#include "SinglyLinkedList.h"
#include "iostream"

ListNode::ListNode(char value) {
    this->node_data = value;
    this->next = nullptr;
}

SinglyLinkedList::SinglyLinkedList() {
    this->head = nullptr;
    this->len = 0;
}

int SinglyLinkedList::length() { return len; }

void SinglyLinkedList::appendNodeToList(char value) {
    ListNode* new_node = new ListNode(value);
    if (this->head == nullptr) {
        this->head = new_node;
    } else {
        ListNode* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new_node;
    }

    len++;
}

void SinglyLinkedList::printList() {
    ListNode* curr = head;
    do {
        std::cout << curr->node_data << " ";
        curr = curr->next;
    } while (curr != nullptr);
}
