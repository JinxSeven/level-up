#include <bits/stdc++.h>

int main() {
    int arr[] = {12 ,10, 3, 45, 8};
    int arr2[] = {56, 25, 51, 78, 11, 4};

    std::sort(arr, arr + sizeof(arr)/sizeof(arr[0]));

    int arr2Size = std::size(arr2);

    std::sort(arr2, arr2 + arr2Size);

    int out[(sizeof(arr)/sizeof(arr[0])) + arr2Size];

    std::copy(arr, arr + sizeof(arr)/sizeof(arr[0]), out);
    std::copy(arr2, arr2 + arr2Size, out + (sizeof(arr)/sizeof(arr[0])));

    for (int i : out)
    {
        std::cout << i << ", ";
    }
}