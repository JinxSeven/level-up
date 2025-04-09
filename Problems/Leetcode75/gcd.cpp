#include <iostream>

// Function to find the greatest common divisor of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Main function for testing
int main() {
    int a = 12;
    int b = 18;

    std::cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << std::endl;

    return 0;
}