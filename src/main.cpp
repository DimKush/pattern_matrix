//
// Created by dim on 3/27/21.
//

#include "MatrixProxy/MatrixProxy.h"
#include <iostream>

int main(){
    pattern_matrix::Matrix<int,0> matrix;
    std::cout << matrix.size() << std::endl;
    std::cout << matrix(10,10) << std::endl;
    matrix(10,10) = 5;
    std::cout << matrix(10,10) << std::endl;
    matrix[1][1] = 10;
    matrix[1][1] = 1000;
    matrix(1,1) = 20;
    std::cout << matrix[1][1] << std::endl;
    std::cout << matrix.size() << std::endl;
    return 0;
}