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
        std::vector<std::vector<T>> matrix;
    public:
        RealMatrix(){
            for(auto i = 0 ; i < 1000; i++)
                matrix.emplace_back(std::vector<T>(100,default_val));
        }
        virtual ~RealMatrix() = default;
        virtual std::size_t size() = 0;
    };
}

#endif //PATTERN_MATRIX_MATRIX_H
