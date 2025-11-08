#include <bits/stdc++.h>

class ListNode {
    public:
        char node_data;
        ListNode* next;

    ListNode(int value) {
        this->node_data = value;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
    private:
        ListNode* head;
        int len;
    
    public:
        SinglyLinkedList() {
            this->head = nullptr;
            this->len = 0;
        }

        int length() { return len; }

        void appendNodeToList(char value) {
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

        void printList() {
            ListNode* curr = head;
            do {
                std::cout << curr->node_data << " ";
                curr = curr->next;
            } while (curr != nullptr);
        }
};

int main() {
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    SinglyLinkedList sll;

    std::cout << "List length before appending values: " << sll.length() << std::endl;
    
    for (char v : vowels) {
        sll.appendNodeToList(v);
    }
    
    std::cout << "List length after appending values: " << sll.length() << std::endl;

    sll.printList();
}