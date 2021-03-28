//
// Created by dim on 3/27/21.
//

#include "Matrix/Matrix.h"
#include <iostream>

int main(){
    pattern_matrix::Matrix<int,0> matrix;
    std::cout << matrix.size() << std::endl;
    std::cout << matrix(10,10) << std::endl;
    matrix(10,10) = 5;
    std::cout << matrix(10,10) << std::endl;
    return 0;
}