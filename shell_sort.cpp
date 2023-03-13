#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
#include "shell.h"



int main() {

    std::ofstream file_time("shell_1_sort_data.txt");
    std::ofstream file_per("shell_1_sort_per_data.txt");

    unsigned start = 100, stop = 5000, step = 100;

    unsigned fib_arr[40];

    fib(fib_arr, 39);

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        unsigned seed = 11*SIZE % 8191;
        std::default_random_engine rnd(seed);
        std::uniform_int_distribution<int> dstr(0, SIZE);

        unsigned arr[SIZE], counter = 0;

        auto global_begin = std::chrono::steady_clock::now();
        auto global_end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(global_end - global_begin);

        for (int i = 0; i < 100; i++) {

            for (int j = 0; j < SIZE; ++j) {
                arr[j] = j;
            }

            std::shuffle(&arr[0], &arr[SIZE], rnd);

            auto begin = std::chrono::steady_clock::now();

            counter += shell_sort_1(arr, 0, SIZE - 1);

            auto end = std::chrono::steady_clock::now();

            time_span += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        }

        file_time << size << " " << time_span.count() << '\n';
        file_per << size << " " << counter << '\n';

    }

    file_time.close();
    file_per.close();

    return 0;
}