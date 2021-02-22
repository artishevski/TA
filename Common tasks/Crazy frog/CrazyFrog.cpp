//
// Created by User on 22-Feb-21.
//

#include "CrazyFrog.h"
#include <algorithm>

CrazyFrog::CrazyFrog(std::string filename) {
    std::ifstream in(filename);
    in >> arrSize;
    arr = new int[arrSize];
    int i = 0;
    int temp;
    while (in >> temp) {
        arr[i++] = temp;
    }
    in.close();
}

void CrazyFrog::solution() {
    int i = 0;
    while (i < arrSize) {
        switch (i) {
            case 0:
                break;
            case 1:
                arr[i] = -1;
                break;
            case 2:
                arr[i] += arr[i - 2];
                break;
        }
        if (i > 2) {
            dp(i);
            break;
        }
        i++;
    }
    if (i == 0 || i == 1) {
        arr[arrSize - 1] = -1;
    }
}

void CrazyFrog::dp(int i) {
    if (i != arrSize) {
        arr[i] += std::max(arr[i - 3], arr[i - 2]);
        dp(i + 1);
    }
}

void CrazyFrog::getRes(std::string filename) {
    std::ofstream out(filename);
    out << arr[arrSize - 1];
    out.close();
}
