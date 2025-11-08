#include <iostream>
#include <vector>

class Node {
public:
    char data;
    Node *next;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

class SList {
public:
    Node *head;
    int length;

    SList() : head(nullptr) {};

    void appendList(char data) {
        Node *new_node = new Node(data);
            if (head == nullptr) {
                head = new_node;
            } else {
                Node *current = head;
                while (current->next != nullptr) {
                    current = current->next;
                }

                current->next = new_node;
            }
            length++;
        }

    void prependList(char data) {
        Node *new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node *current = new_node;
            current->next = head;
            head = new_node;
        }
    }

    void indexGet(int index) {
        if (index < 0 || index >= length) {
            std::cout << "invalid index" << std::endl;
        }

        else {
            Node *temp = head;
            for (int x = 0; x < index; x++) {
                temp = temp->next;
            }

            std::cout << temp->data << std::endl;
        }
    }

    void displayList() {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current->data << "  " ;
            current = current->next;
        }
    }

    void deleteFirst() {
        if (head ==  nullptr) {
            std::cout << "No nodes to delete" << std::endl;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        }

        else {
            Node *current = head;
            head = head->next;
            delete current;
        }
    }

    void reverseList() {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
    }

    void deleteLast() {
        if (head == nullptr) {
            std::cout << "No nodes to delete" << std::endl;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
        Node *current = head;
        Node *prev = nullptr;
        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }

        delete current;
        prev->next = nullptr;
        length = length - 1;
        }
    }

    void listLength() {
        std::cout << length << " " ;
    }
};

int main() {
    std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    std::vector<char> last_five = {'v', 'w', 'x', 'y', 'z'};
    SList one;
    for (char out : vowels) {
        one.appendList(out);
    }
    for (char out : last_five) {
        one.prependList(out);
    }
    one.displayList();
    return 0;
}
