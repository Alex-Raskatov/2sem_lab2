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

unsigned booble(unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    
    bool sorted = false;
    unsigned counter = 0, tmp;

    while (!sorted) {
        sorted = true;
        for (int i = begin_idx; i < end_idx; i++){
            if (arr[i] > arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                sorted = false;
                counter++;
            }
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

    counter += booble(arr, begin_idx, end_idx);

    return counter;
}