//
// Created by dim on 3/27/21.
//

#include "MatrixProxy/MatrixProxy.h"
#include <iostream>

int main(){
    pattern_matrix::Matrix<int,0> matrix;

    for (int i=0; i < 10; i++)
        for (int j=0; j < 10; j++)
            matrix[i][j] = (i + j) % 2;

    int i = 0;
    for(const auto & iter : matrix){
        std::cout << iter << " ";
        if(++i == 10){
            std::cout << std::endl;
            i = 0;
        }
    }

    std::cout << matrix.size() << std::endl;

    matrix.showAll();


    return 0;
}