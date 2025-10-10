#include <bits/stdc++.h>

int maxFavPoss(std::string str, int num, char fav = 'a') {
    int counter = 0;
    int maximum = 0;
    int j = 0, i = 0;
    while (j < num) {
        if (str[j] == fav) {
            counter++;
        }
        j++;
    }
        maximum = std::max(maximum, counter);

    while (j < str.length()) {
        if (str[i] == fav) counter--;
        if (str[j] == fav) counter++;
        maximum = std::max(maximum, counter);
        i++;
        j++;
    }
    return maximum;
}

int main(int argc, char **argv) {
    std::string input = "acbsabbabaa";
    int window = 4;

    std::cout << "The answer is: " << maxFavPoss(input, window);
}
