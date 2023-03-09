#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>
#include "shaker.h"


int main () {

    std::ofstream file_forward("shaker_test_forward_data.txt");
    std::ofstream file_backward("shaker_test_backward_data.txt");
    std::ofstream file_sort("shaker_test_sort_data.txt");

    unsigned seed = 8191;
    std::default_random_engine rnd(seed);

    const unsigned size = 30;
    unsigned arr[size];

    // прямо упорядоченый

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < size; i++) {
        file_forward << arr[i] << ' ';
    }
    file_forward << '\n';

    forward_step(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        file_forward << arr[i] << ' ';
    }
    file_forward << "\n\n";

    for (int i = 0; i < size; i++) {
        file_backward << arr[i] << ' ';
    }
    file_backward << '\n';

    backward_step(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        file_backward << arr[i] << ' ';
    }
    file_backward << "\n\n";

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < size; i++) {
        file_sort << arr[i] << ' ';
    }
    file_sort << '\n';

    shaker_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        file_sort << arr[i] << ' ';
    }
    file_sort << "\n\n";

    //обратно упорядоченый

    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }

    for (int i = 0; i < size; i++) {
        file_forward << arr[i] << ' ';
    }
    file_forward << '\n';

    forward_step(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        file_forward << arr[i] << ' ';
    }
    file_forward << "\n\n";

    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }

    for (int i = 0; i < size; i++) {
        file_backward << arr[i] << ' ';
    }
    file_backward << '\n';

    backward_step(arr, 0, size-1);

    for (int i = 0; i < size; i++) {
        file_backward << arr[i] << ' ';
    }
    file_backward << "\n\n";

    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }

    for (int i = 0; i < size; i++) {
        file_sort << arr[i] << ' ';
    }
    file_sort << '\n';

    shaker_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        file_sort << arr[i] << ' ';
    }
    file_sort << "\n\n";

    // рандомно

    for (int i = 0; i < 100; i++) {

        // вперед

        std::shuffle(&arr[0], &arr[size], rnd);

        for (int i = 0; i < size; i++) {
            file_forward << arr[i] << ' ';
        }
        file_forward << '\n';

        forward_step(arr, 0, size-1);

        for (int i = 0; i < size; i++) {
            file_forward << arr[i] << ' ';
        }
        file_forward << "\n\n";

        //назад

        std::shuffle(&arr[0], &arr[size], rnd);

        for (int i = 0; i < size; i++) {
            file_backward << arr[i] << ' ';
        }
        file_backward << '\n';

        backward_step(arr, 0, size-1);

        for (int i = 0; i < size; i++) {
            file_backward << arr[i] << ' ';
        }
        file_backward << "\n\n";

        //сортировка

        std::shuffle(&arr[0], &arr[size], rnd);

        for (int i = 0; i < size; i++) {
            file_sort << arr[i] << ' ';
        }
        file_sort << '\n';

        shaker_sort(arr, 0, size-1);

        for (int i = 0; i < size; i++) {
            file_sort << arr[i] << ' ';
        }
        file_sort << "\n\n";

    }

    file_forward.close();
    file_backward.close();
    file_sort.close();

    return 0;
}