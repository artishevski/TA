#include <iostream>

int lowerBound(int *arr, int arrSize, int request) {
    int l = 0;
    int r = arrSize;
    while (l < r) {

        int m = (l + r) / 2;
        if (arr[m] < request) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int upperBound(int *arr, int arrSize, int request) {
    int l = 0;
    int r = arrSize;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] <= request) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    int arrSize;
    std::cin >> arrSize;
    int *arr = new int[arrSize];
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }
    int requestsSize;
    std::cin >> requestsSize;
    int *requests = new int[requestsSize];
    for (int i = 0; i < requestsSize; i++) {
        std::cin >> requests[i];
    }
    for (int i = 0; i < requestsSize; i++) {
        int lb = lowerBound(arr, arrSize, requests[i]);
        int ub = upperBound(arr, arrSize, requests[i]);
        if (lb != arrSize && arr[lb] == requests[i]) {
            std::cout << 1 << ' ';
        } else {
            std::cout << 0 << ' ';
        }

        std::cout << lb << ' ';
        if (ub != arrSize && arr[ub] == requests[i]) {
            std::cout << ub + 1 << '\n';
        } else {
            std::cout << ub << '\n';
        }
    }
    return 0;
}