#include <iostream>
#include <chrono>
#include <random>
#include <fstream>

bool sorted (unsigned arr[], unsigned size) {
    for (int i = 0; i < size-1; i++) {
        if (arr[i] > arr[i+1]) return false;
    }

    return true;
}

unsigned forward_step (unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {

    bool sorted = true;
    unsigned right = end_idx;

    for (unsigned idx = begin_idx; idx < end_idx; idx++) {
        if (arr[idx] > arr[idx + 1]) {
            std::swap(arr[idx], arr[idx + 1]);
            right = idx;
            sorted = false;
        }
    }
    if (!sorted) {
        return right;
    }
    else {
        return begin_idx;
    }
}


unsigned backward_step (unsigned arr[], unsigned const begin_idx, unsigned const end_idx){

    bool sorted = true;
    unsigned left = begin_idx;

    for (unsigned idx = end_idx; idx > begin_idx; idx--) {
        if (arr[idx] < arr[idx - 1]) {
            std::swap(arr[idx], arr[idx - 1]);
            left = idx;
            sorted = false;
        }
    }
    if (!sorted) {
        return left;
    }
    else {
        return end_idx;
    }
}


void shaker_sort (unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned left = begin_idx;
    unsigned right = end_idx;

    while (left < right) {
        right = forward_step(arr, left, right);
        left = backward_step(arr, left,right);
    }
}

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

            for (int i = 0; i < SIZE; ++i) {
                arr[i] = dstr(rnd);
            }

            auto begin = std::chrono::steady_clock::now();

            shaker_sort(arr, 0, SIZE - 1);

            auto end = std::chrono::steady_clock::now();

            time_span += std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        }

        file << size << " " << time_span.count() << '\n';
        std::cout << size << " " << time_span.count() << '\n';


    }

    file.close();

    return 0;
}