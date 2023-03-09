#include <iostream>

unsigned stepward(unsigned arr[], unsigned const begin_idx, unsigned const end_idx, unsigned step) {

    unsigned counter = 0;

    for (int i = begin_idx; i + step <= end_idx; i++) {
        if (arr[i] > arr[i + step]) {
            unsigned tmp = arr[i];
            arr[i] = arr[i + step];
            arr[i + step] = tmp;
            ++counter;
        }
    }

    return counter;

}

unsigned comb_sort(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    
    unsigned step = end_idx - begin_idx;

    unsigned counter = 0;

    while (step > 0) {
        
        counter += stepward(arr, begin_idx, end_idx, step);

        step /= 2;
    }

    return counter;
}