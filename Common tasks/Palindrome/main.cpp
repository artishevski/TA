#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>

class Palindrome {
private:
    std::string word;
    int **matrix;
public:
    Palindrome(std::istream& in, std::ostream& out);
};

Palindrome::Palindrome(std::istream& in, std::ostream& out) {
    in >> word;
    matrix = new int *[word.length()];
    for (int i = 0; i < word.length(); i++) {
        matrix[i] = new int[word.length()];
        matrix[i][i] = 1;
    }
    for (int j = 1; j < word.length(); j++) {
        for (int i = j - 1; i >= 0; i--) {
            if (j == i + 1) {
                if (word[i] == word[j]) {
                    matrix[i][j] = 2;
                } else {
                    matrix[i][j] = 1;
                }
            } else {
                if (word[i] == word[j]) {
                    matrix[i][j] = matrix[i + 1][j - 1] + 2;
                } else {
                    matrix[i][j] = std::max(matrix[i + 1][j], matrix[i][j - 1]);
                }
            }
        }
    }

//    for (int i = 0; i < word.length(); i++) {
//        for (int j = 0; j < word.length(); j++) {
//            std::cout << std::setw(12) << matrix[i][j];
//        }
//        std::cout << '\n';
//    }
    std::string res;
    int resLength = 0;

    for(int i=0,j=word.length()-1;j>i;){
        if(word[i]==word[j]){
            res+=word[i];
            resLength++;
            i++;
            j--;
            if(matrix[i][j]==1){
                res+=word[j];
            }
        } else if (matrix[i+1][j]>matrix[i][j-1]){
            i++;
        } else{
            j--;
        }
    }
    if(word.length()==1){
        res+=word[0];
    }
    if(res.length()==0){
        res+=word[0];
    }

    for (int k = resLength - 1; k >= 0; k--) {
        res += res[k];
    }

    out << matrix[0][word.length() - 1] << '\n' << res;
}

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    Palindrome matrix(in, out);
    in.close();
    out.close();
    return 0;
}