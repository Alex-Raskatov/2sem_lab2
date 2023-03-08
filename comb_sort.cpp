#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

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

    std::ofstream file_time("comb_sort_data.txt");
    std::ofstream file_per("comb_sort_per_data.txt");

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

        unsigned perest = 0;

        for (int i = 0; i < 100; i++) {

            for (int i = 0; i < SIZE; ++i) {
                arr[i] = dstr(rnd);
            }

            auto begin = std::chrono::steady_clock::now();

            perest += comb_sort(arr, 0, SIZE - 1);

            auto end = std::chrono::steady_clock::now();

            time_span += std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        }

        file_time << size << " " << time_span.count() << '\n';
        file_per << size << " " << perest << '\n';
    }

    file_per.close();
    file_time.close();

    return 0;
}