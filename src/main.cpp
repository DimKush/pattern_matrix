//
// Created by dim on 3/27/21.
//

#include "MatrixProxy/MatrixProxy.h"
#include <iostream>

int main(){
    pattern_matrix::Matrix<int,0> matrix;

    for (int i=0; i < 10; i++)
    {
        for (int j=0; j < 10; j++)
        {
            matrix[i][j] = (i + j) % 2;
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (int i=0; i < 10; i++){
        for (int j=0; j < 10; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    // TODO: error can't cout last element in matrix
    std::cout << std::endl;
    int i = 0;
    for(const auto & iter : matrix){
        std::cout << iter << " ";
        if(++i == 10){
            std::cout << std::endl;
            i = 0;
        }
    }

    return 0;
}