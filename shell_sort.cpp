#include <cmath>
#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

void fib(unsigned fib_arr[], unsigned size){

    fib_arr[0] = 1;
    fib_arr[1] = 2;

    for (int i = 2; i <= size; i++){
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }
}

unsigned shell_sort_1( unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned size = end_idx - begin_idx + 1;

    unsigned s = size / 2;

    while (s > 0) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
            }
        }

        s /= 2;
    }

    return 0;
}

unsigned shell_sort_2( unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned size = end_idx - begin_idx + 1;

    unsigned i = std::log2(size + 1), s = std::pow(2, i) - 1;

    while (i > 0) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
            }
        }
        --i;
        s = std::pow(2, i) - 1;
    }

    return 0;
}

unsigned shell_sort_3(unsigned arr[], unsigned fib_arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned size = end_idx - begin_idx + 1;

    unsigned i = 0;

    while (fib_arr[i] < size) {
        i++;
    }

    unsigned s = fib_arr[i];

    while (i > 0) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
            }
        }
        --i;
        s = fib_arr[i];
    }

    return 0;
}

int main() {

    std::ofstream file("shell_sort_3_data.txt");

    unsigned start = 100, stop = 1000, step = 100;

    unsigned fib_arr[40];

    fib(fib_arr, 39);

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        unsigned seed = 10*SIZE % 8191;
        std::default_random_engine rnd(seed);
        std::uniform_int_distribution<int> dstr(0, SIZE);

        unsigned arr[SIZE];

        auto global_begin = std::chrono::steady_clock::now();
        auto global_end = std::chrono::steady_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::nanoseconds>(global_end - global_begin);

        for (int i = 0; i < 100; i++) {

            for (int i = 0; i < SIZE; ++i) {
                arr[i] = dstr(rnd);
            }

            auto begin = std::chrono::steady_clock::now();

            shell_sort_3(arr, fib_arr, 0, SIZE - 1);

            auto end = std::chrono::steady_clock::now();

            time_span += std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

        }

        file << size << " " << time_span.count() << '\n';

    }

    return 0;
}