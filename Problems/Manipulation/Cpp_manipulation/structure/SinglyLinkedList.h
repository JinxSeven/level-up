# pragma once

class ListNode {
    public:
        char node_data;
        ListNode* next;

    ListNode(char value);
};

class SinglyLinkedList {
    private:
        ListNode* head;
        int len;
    
    public:
        SinglyLinkedList();
        int length();
        void appendNodeToList(char value);
        void printList();
};