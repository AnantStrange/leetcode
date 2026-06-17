#pragma  once

#include <iostream>
#include <vector>

template<typename T>
void printVec(std::vector<T> vec){
    std::cout<<"[ ";
    for(T elem : vec){
        std::cout<<elem<<", ";
    }
    std::cout<<"]\n";
}

template<typename T>
void printVecVec(std::vector<std::vector<T>> vec){
    std::cout<<"[\n";
    for(auto inner_vec : vec){
        std::cout<<"[ ";
        for(T elem : inner_vec){
            std::cout<<elem<<", ";
        }
        std::cout<<"],\n";
    }
    std::cout<<"]\n";
}
