//
// Created by dim on 3/27/21.
//

#include "MatrixProxy/MatrixProxy.h"
#include <iostream>

int main(){
    auto * matrix = new pattern_matrix::Matrix<int,0>();
    auto proxy((pattern_matrix::MatrixProxy<int,0>(matrix)));

    std::cout << proxy.size() << std::endl;
    std::cout << proxy(10,10) << std::endl;
    proxy(10,10) = 5;
    std::cout << proxy(10,10) << std::endl;
    
    delete matrix;

    return 0;
}