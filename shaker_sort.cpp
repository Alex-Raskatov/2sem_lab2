#include <iostream>
#include <chrono>
#include <random>

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

    unsigned start = 1000, stop = 100000, step = 1000;

    unsigned seed = 1003;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<unsigned> dist(0, 20);

    for (int i = 0; i < 10; i++) {

        unsigned arr[20];

        for (int j = 0; j < 20; j++) {

            arr[j] = dist(rnd);
        }

        for (int j = 0; j < 20; j++) {

            std::cout << arr[j] << ' ';
        }
        std::cout << '\n';

        shaker_sort(arr, 0, 19);

        for (int j = 0; j < 20; j++) {

            std::cout << arr[j] << ' ';
        }
        std::cout << "\n\n";
    }

    return 0;
}