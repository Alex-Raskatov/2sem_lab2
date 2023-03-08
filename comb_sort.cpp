#include <iostream>
#include <random>
#include <chrono>

unsigned comb_sort( unsigned arr[], unsigned const begin_idx, unsigned const end_idx) {
    
    unsigned step = end_idx - begin_idx;

    unsigned counter = 0;

    while (step > 0) {
        
        for (int i = begin_idx; i + step <= end_idx; i++) {
            if (arr[i] > arr[i + step]) {
                unsigned tmp = arr[i];
                arr[i] = arr[i + step];
                arr[i + step] = tmp;
                ++counter;
            }
        }

        step /= 2;
    }

    return counter;
}

int main() {

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

        comb_sort(arr, 0, 19);

        for (int j = 0; j < 20; j++) {

            std::cout << arr[j] << ' ';
        }
        std::cout << "\n\n";
    }

    return 0;
}