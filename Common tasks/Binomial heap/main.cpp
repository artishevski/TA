#include <iostream>
#include <fstream>

int main() {
    int64_t num;
    std::ifstream in("input.txt");
    in >> num;
    in.close();
    std::ofstream out("output.txt");
    int k;
    for (k = 0; num; k++) {
        if (num % 2 == 1) {
            out << k << '\n';
        }
        num /= 2;
    }
    out.close();
    return 0;
}