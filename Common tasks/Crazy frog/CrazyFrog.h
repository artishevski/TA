//
// Created by User on 22-Feb-21.
//
#include <string>
#include <fstream>

#ifndef WATER_LILY_WATERLILY_H
#define WATER_LILY_WATERLILY_H


class CrazyFrog {
public:
    CrazyFrog(std::string filename);
    void solution();
    void getRes(std::string filename);
    void dp(int i);

private:
    int *arr;
    int arrSize;
};


#endif //WATER_LILY_WATERLILY_H
