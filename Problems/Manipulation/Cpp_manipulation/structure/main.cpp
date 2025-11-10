# include "SinglyLinkedList.h"
# include <iostream>
# include <vector>

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

// Remember to compile with the required implementation file