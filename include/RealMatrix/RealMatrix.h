//
// Created by dim on 3/26/21.
//

#ifndef PATTERN_MATRIX_MATRIX_H
#define PATTERN_MATRIX_MATRIX_H

#include <vector>

template <typename T, int DEF>
class RealMatrix {
protected:
    int default_val = DEF;
    std::vevtor<std::vector<T>> matrix;
public:
    virtual ~RealMatrix() = default;
    virtual std::size_t size() = 0;
};

template <typename T, int DEF>
class Matrix : public RealMatrix{
public:
    Matrix(){
        matrix.resize(0);
        matrix.push_back();
    }

};

#endif //PATTERN_MATRIX_MATRIX_H
