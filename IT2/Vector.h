//
// Created by arthur on 18.10.2019.
//

#ifndef IT2_RVECTOR_H
#define IT2_RVECTOR_H

typedef float Vector_lt; // little type
typedef double Vector_bt; // big type

typedef struct Vector Vector_t;
struct Vector{
    Vector_lt x;
    Vector_lt y;
    Vector_lt z;
};

#endif //IT2_RVECTOR_H
