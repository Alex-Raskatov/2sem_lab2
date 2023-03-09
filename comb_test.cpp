#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include "comb.h"


int main () {

    std::ofstream file("comb_test_data.txt");

    unsigned seed = 8191;
    std::default_random_engine rnd(seed);

    const unsigned size = 30;
    unsigned arr[size];

    // прямо упорядоченый

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < size; i++) {
        file << arr[i] << ' ';
    }
    file << '\n';

    comb_sort(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        file << arr[i] << ' ';
    }
    file << "\n\n";


    //обратно упорядоченый

    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }

    for (int i = 0; i < size; i++) {
        file << arr[i] << ' ';
    }
    file << '\n';

    comb_sort(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        file << arr[i] << ' ';
    }
    file << "\n\n";

    // рандомно

    for (int i = 0; i < 100; i++) {

        std::shuffle(&arr[0], &arr[size], rnd);

        for (int i = 0; i < size; i++) {
            file << arr[i] << ' ';
        }
        file << '\n';

        comb_sort(arr, 0, size-1);

        for (int i = 0; i < size; i++) {
            file << arr[i] << ' ';
        }
        file << "\n\n";

    }

    file.close();

    return 0;
}