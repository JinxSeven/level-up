#include <bits/stdc++.h>

int midValue(int arr[], int size) {
    int righthand = 0;
    int lefthand = 0;

    for (int x = 0; x < size; x++) {
        righthand += arr[x];
    }

    for (int x = 0; x < size; x++) {
        righthand -= arr[x];
        if (righthand == lefthand) return x;
        else lefthand += arr[x];
    }
    return -1;
}

int main(int argc, char **argv) {
    int input[] = {-7, 1, 5, 2, -4, 3, 0};
    int size = sizeof(input)/sizeof(input[0]);

    std::cout << midValue(input, size);
}
