//
// Created by User on 22-Feb-21.
//
#include <string>
#include <fstream>

#ifndef WATER_LILY_WATERLILY_H
#define WATER_LILY_WATERLILY_H


class WaterLily {
public:
    WaterLily(std::string filename){
        std::ifstream in(filename);

        in.close();
    }

private:
    int*arr;
    int 
};


#endif //WATER_LILY_WATERLILY_H
