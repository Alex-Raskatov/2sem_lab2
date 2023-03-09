#include <iostream>
#include <iterator>
#include <random>
#include <algorithm>
#include "comb.h"

int main() {

    unsigned arr[100];

    unsigned seed = 8191;
    std::default_random_engine rnd(seed);

    for (int i = 0; i < 100; i++) {
        arr[i] = i;
    }

    std::shuffle(std::begin(arr), std::end(arr), rnd);

    for (int i = 0; i < 100; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << "\n\n";

    comb_sort(arr, 0, 99);

    for (int i = 0; i < 100; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << "\n\n";

    return 0;
}