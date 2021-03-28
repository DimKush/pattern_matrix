//
// Created by dim on 3/28/21.
//
#pragma once

#include "Matrix/Matrix.h"

namespace pattern_matrix{
    template<typename T, int DEF>
    class MatrixProxy : public Matrix<T,DEF>{
        using MatrixFly = Matrix<T,DEF>;
    private:
        MatrixFly * object_ = nullptr ;

    public:
        MatrixProxy() = delete;
        MatrixProxy(MatrixFly * real_object) : object_(new MatrixFly(*real_object)){}

        T & operator () (int const & x, int const & y) {
            return object_->operator()(x,y);
        }

        T & operator [] (int const & x){

        }
        std::size_t size() {
            return object_->size();
        }
        ~MatrixProxy(){
            delete object_;
        }

    };


}