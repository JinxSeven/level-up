#include <iostream>
#include <cstdlib>
#include <fstream>

unsigned int nums;

int main() {
    std::cout << "Enter count limit: ";
    std::cin >> nums;
    std::ofstream odds("odds.txt");
    std::ofstream evens("evens.txt");
    
    if (!odds.is_open()) {
        std::cerr << "Unable to open file";
        return 1;
    }
    
    else if (!evens.is_open()) {
        std::cerr << "Unable to open file";
        return 2;
    }
    
    for (int x = 0; x <= nums; x++) {
        if (x % 2 == 0) {
            evens << x << std::endl;
        } else {
            odds << x << std::endl;
        }
    }
    return 0;
}
