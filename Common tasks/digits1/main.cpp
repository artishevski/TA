#include <iostream>
//#include "Solution.h"

class Solution {
private:
    int lines;
    int digits;
    int **matrix;
public:
    Solution();
};

Solution::Solution() {

    std::cin >> lines >> digits;
    lines++;
    digits++;
    matrix = new int *[lines];

    for (int i = 0; i < lines; i++) {
        matrix[i] = new int[digits]{};
        matrix[i][0] = 1;
        if (i < digits) {
            matrix[i][i] = 1;
        }
    }

    for (int i = 2; i < lines; i++) {
        for (int j = 1; j < i && j < digits; j++) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
        }
    }

    std::cout << matrix[lines - 1][digits - 1] % 1000000007;
}

int main() {
    new Solution();
    return 0;
}
