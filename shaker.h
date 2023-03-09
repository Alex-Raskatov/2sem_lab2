#include <iostream>

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
