//
// Created by dim on 3/26/21.
//

#ifndef PATTERN_MATRIX_MATRIX_H
#define PATTERN_MATRIX_MATRIX_H

#include <vector>

namespace pattern_matrix {

    template<typename T, int DEF>
    class RealMatrix {
    protected:
        int default_val = DEF;
        std::vector<T> realContainer;
    public:
        RealMatrix(){

        }
        virtual ~RealMatrix() = default;
        virtual std::size_t size() = 0;
    };
}

#endif //PATTERN_MATRIX_MATRIX_H
