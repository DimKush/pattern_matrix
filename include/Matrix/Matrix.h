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
        Matrix(){}

        void insertTrick(int const & x, int const & y, const int val = -1){
            RM::realContainer.push_back(val);
            auto sz = RM::realContainer.size();
            matrix.push_back(std::tie(x,y,--sz));
        }

        T & operator () (int const & x, int const & y) {
            if(matrix.size() != 0)
                for(auto iter : matrix){
                    if(std::get<0>(iter) == x && std::get<1>(iter) == y)
                        return RM::realContainer.at(std::get<2>(iter));
                    else{
                        insertTrick(x,y);
                        return RM::realContainer.at(std::get<2>(iter));
                    }
                }
            else {
                insertTrick(x,y);

                return RM::realContainer.at(std::get<2>(matrix.at(0)));
            }
        }

        std::size_t size(){
            return RM::realContainer.size();
        }

    };
}

