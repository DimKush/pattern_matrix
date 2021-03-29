//
// Created by dim on 3/27/21.
//

#pragma once

#include "RealMatrix/RealMatrix.h"

#include <iostream>
#include <algorithm>
#include <tuple>

namespace pattern_matrix {

    template<typename T, int Val>
    class Matrix : protected RealMatrix<T,Val> {
        using RM = RealMatrix<T,Val>;
        std::vector<std::tuple<std::size_t,std::size_t, std::size_t>> matrix;
    public:
        Matrix(){}
        virtual ~Matrix(){}

        void insertTrick(int const & x, int const & y, const int val = Val){
            RM::realContainer.push_back(val);
            auto sz = RM::realContainer.size();
            matrix.push_back(std::tie(x,y,--sz));
        }

        T & operator () (int const x, int const y) {
            if(matrix.size() != 0) {
                auto iter = std::find_if(matrix.begin(),matrix.end(),[=](const auto & element){
                    return std::get<0>(element) == x && std::get<1>(element) == y;
                });

                if (iter != matrix.end()) {
                    std::size_t pos = std::get<2>(*iter);
                    return RM::realContainer.at(pos);
                }
                else {
                    insertTrick(x, y);
                    std::size_t pos = RM::realContainer.size() - 1;
                    return RM::realContainer.at(pos);
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
        void showAll(){
            std::cout << "SHOW ALL" << std::endl;
            for(auto i : RM::realContainer){

                std::cout << i << std::endl;
            }
            std::cout << "==SHOW ALL==" << std::endl;
        }

        class MatrixProxy {
        public:

            T & operator [] (int col){
                return matrix_ptr_->operator()(row_,col);
            }

            Matrix<T,Val> * matrix_ptr_ = nullptr;
            int row_ = 0;
            MatrixProxy(Matrix<T, Val>* obj, int row){
                matrix_ptr_ = obj;
                row_ = row;
            }
        };

        MatrixProxy operator[](int row){
            //std::cout << "row = " << row << std::endl;
            return MatrixProxy(this,row);
        }

    };
}

