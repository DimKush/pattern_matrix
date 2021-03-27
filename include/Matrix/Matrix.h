//
// Created by dim on 3/27/21.
//

#pragma once

#include "RealMatrix/RealMatrix.h"

namespace pattern_matrix {

    template<typename T, int Val>
    class Matrix : protected RealMatrix<T,Val> {
    public:
        using RM = RealMatrix<T,Val>;
        Matrix(){}
    };
}

