#include <iostream>
#include <cmath>

class Summator {
private:
    int64_t *arr;
    int arrSize;
    int64_t *blocks;
    int blockSize;
public:
    Summator() {
        std::cin >> arrSize;
        blockSize = sqrt(arrSize);
        if (blockSize * blockSize != arrSize) {
            blockSize++;
        }
        arr = new int64_t[arrSize]{};
        blocks = new int64_t[blockSize]{};
        for (int i = 0; i < arrSize; i++) {
            std::cin >> arr[i];
            blocks[i / blockSize] += arr[i];
        }
//        std::cout<<'\n';
//        for(int i=0;i< arrSize;i++){
//            std::cout<<arr[i]<<' ';
//        }
//        std::cout<<'\n';
//        for(int i=0;i<blocksAmount;i++){
//            std::cout<<blocks[i]<<' ';
//        }
//        std::cout<<'\n';
    }

    void findSum(int begin,int end){
        int64_t sum=0;
        if (begin/blockSize==end/blockSize){
            for(int i=begin;i<end;i++){
                sum+=arr[i];
            }
        }
        else{
            int leftBound=begin/blockSize;
            int rightBound=end/blockSize;
            for(int i=begin;i<(leftBound+1)*blockSize;i++){
                sum+=arr[i];
            }
            for(int i=leftBound+1;i<rightBound;i++){
                sum+=blocks[i];
            }
            for(int i=rightBound*blockSize;i<end;i++){
                sum+=arr[i];
            }
        }
        std::cout<<sum<<'\n';
    }

    int add(int i, int val) {
        arr[i] += val;
        blocks[i / blockSize] += val;
    }

    void start() {
        int requestsAmount;
        std::cin >> requestsAmount;
        std::string request;
        int arg1, arg2;
        while (requestsAmount) {
            std::cin >> request >> arg1 >> arg2;
            if (request == "FindSum") {
                findSum(arg1, arg2);
            } else {
                add(arg1, arg2);
            }
            requestsAmount--;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    (new Summator())->start();
    return 0;
}
