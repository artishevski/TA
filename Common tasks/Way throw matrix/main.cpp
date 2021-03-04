#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

int myMin(int val1, int val2, int val3) {
    if (val1 < val2) {
        if (val1 < val3) {
            return val1;
        }
    }
    if (val2 < val3) {
        return val2;
    }
    return val3;
}

class Matrix {
public:
    Matrix(std::string filename1, std::string filename2) {
        std::ifstream in(filename1);
        in >> n >> m;
        if(m>n){
            std::ofstream out(filename2);
            out << -1;
            out.close();
            return;
        }
        matrix = new int *[n];
        totalCost = new int *[n];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[m];
            totalCost[i] = new int[m];
            for (int j = 0; j < m; j++) {
                in >> matrix[i][j];
                totalCost[i][j] = 0;
            }
        }
        in.close();
        totalCost[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i+1 && j<m; j++) {
                if (j == 0 && totalCost[i][j+1]==0) {
                    totalCost[i][j] = matrix[i][j] + totalCost[i - 1][j];
                } else if(j==0){
                    totalCost[i][j] = std::min(matrix[i][j] + totalCost[i - 1][j],
                                               matrix[i][j] + totalCost[i - 1][j + 1]);
                }
                else if(totalCost[i-1][j-1]==0){

                }else if(totalCost[i-1][j]==0){
                    totalCost[i][j]=matrix[i][j] + totalCost[i - 1][j - 1];
                }else if(j==m-1||totalCost[i-1][j+1]==0){
                    totalCost[i][j] = std::min(matrix[i][j] + totalCost[i - 1][j - 1],
                                               matrix[i][j] + totalCost[i - 1][j]);
                }
                else {
                    totalCost[i][j] = myMin(matrix[i][j] + totalCost[i - 1][j - 1], matrix[i][j] + totalCost[i - 1][j],
                                            matrix[i][j] + totalCost[i - 1][j + 1]);
                }
            }
        }
        std::ofstream out(filename2);
        out << totalCost[n - 1][m - 1];
        out.close();
    }

private:
    int n;
    int m;
    int **matrix;
    int **totalCost;
};

int main() {
    Matrix("input.txt", "output.txt");
    return 0;
}
