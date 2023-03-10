#include <iostream>
#include <cmath>

void fib(unsigned fib_arr[], unsigned size){

    fib_arr[0] = 1;
    fib_arr[1] = 2;

    for (int i = 2; i <= size; i++){
        fib_arr[i] = fib_arr[i-1] + fib_arr[i-2];
    }
}

unsigned shell_sort_1( unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned size = end_idx - begin_idx + 1, counter = 0;

    unsigned s = size;

    while (s > 0) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
                counter++;
            }
        }

        s /= 2;
    }

    return counter;
}

unsigned shell_sort_2( unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned size = end_idx - begin_idx + 1, counter = 0;

    unsigned i = std::log2(size + 1), s = std::pow(2, i) - 1;

    while (i > 0) {
        for (int i = s; i < size; ++i) {
            for (int j = i - s; j >= 0 && arr[j] > arr[j + s]; j -= s) {
                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
                counter++;
            }
        }
        --i;
        s = std::pow(2, i) - 1;
    }

    return counter;
}

unsigned shell_sort_3(unsigned arr[], unsigned fib_arr[], unsigned const begin_idx, unsigned const end_idx) {

    unsigned size = end_idx - begin_idx + 1, counter = 0;

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
                counter++;
            }
        }
        --i;
        s = fib_arr[i];
    }

    return counter;
}