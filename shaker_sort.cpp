#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include "shaker.h"

int main () {

    std::ofstream file("shaker_sort_data.txt");

    unsigned start = 100, stop = 1000, step = 100;

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        unsigned seed = 10*SIZE % 8191;
        std::default_random_engine rnd(seed);
        std::uniform_int_distribution<int> dstr(0, SIZE);

        unsigned arr[SIZE];

        auto global_begin = std::chrono::steady_clock::now();
        auto global_end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(global_end - global_begin);

        for (int i = 0; i < 100; i++) {

            for (int j = 0; j < SIZE; ++j) {
                arr[j] = j;
            }

            std::shuffle(&arr[0], &arr[SIZE], rnd);

            auto begin = std::chrono::steady_clock::now();

            shaker_sort(arr, 0, SIZE - 1);

            auto end = std::chrono::steady_clock::now();

            time_span += std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        }

        file << size << " " << time_span.count() << '\n';
    }

    file.close();

    return 0;
}