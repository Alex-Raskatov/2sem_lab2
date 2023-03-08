#include <cmath>
#include <iostream>
#include <random>
#include <chrono>

void fib(unsigned fib_arr[], unsigned n){

    fib_arr[0] = 1;
    fib_arr[1] = 2;

    for (int i = 2; i <= n; i++){
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

    unsigned seed = 1003;
    std::default_random_engine rnd(seed);
    std::uniform_int_distribution<unsigned> dist(0, 20);

    unsigned fib_arr[38];

    fib(fib_arr, 37);

    for (int i = 0; i < 10; i++) {

        unsigned arr[20];

        for (int j = 0; j < 20; j++) {

            arr[j] = dist(rnd);
        }

        for (int j = 0; j < 20; j++) {

            std::cout << arr[j] << ' ';
        }
        std::cout << '\n';

        shell_sort_1(arr, 0, 19);
        // shell_sort_1(arr, 0, 19);
        // shell_sort_3(arr, fib_arr, 0, 19);

        for (int j = 0; j < 20; j++) {

            std::cout << arr[j] << ' ';
        }
        std::cout << "\n\n";
    }

    return 0;
}