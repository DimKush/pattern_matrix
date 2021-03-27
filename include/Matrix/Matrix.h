//
// Created by dim on 3/27/21.
//

#pragma once

#include "RealMatrix/RealMatrix.h"

#include <iostream>
#include <tuple>

namespace pattern_matrix {

    template<typename T, int Val>
    class Matrix : protected RealMatrix<T,Val> {
        using RM = RealMatrix<T,Val>;
        std::vector<std::tuple<std::size_t,std::size_t, std::size_t>> matrix;
    public:
        Matrix(){

        }
        T & operator () (int const & x, int const & y) {
            if(matrix.size() != 0)
                for(auto iter : matrix){
                    if(std::get<0>(iter) == x && std::get<1>(iter) == y)
                        return RM::matrix.at(std::get<2>(iter));
                    else
                        return RM::default_val;
                }
            else
                return RM::default_val;
        }
        std::size_t size(){
            return RM::matrix.size();
        }

    };
}

