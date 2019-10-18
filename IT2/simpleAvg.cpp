//
// Created by arthur on 18.10.2019.
//

#include "simpleAvg.h"

int simpleAvgVector(Vector_t *avg_vector, Vector_t vectors[], size_t size)
{
    if ((avg_vector == NULL)
       ||  (vectors == NULL))   return EXIT_NULL_REC;

    if (size == 0)              return EXIT_ZERO_SIZ;

    Vector_bt sum_x = 0;
    Vector_bt sum_y = 0;
    Vector_bt sum_z = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum_x += vectors[i].x;
        sum_y += vectors[i].y;
        sum_z += vectors[i].z;
    }

    sum_x /= size;
    sum_y /= size;
    sum_z /= size;

    avg_vector->x = (Vector_lt) sum_x;
    avg_vector->y = (Vector_lt) sum_y;
    avg_vector->z = (Vector_lt) sum_z;

    return EXIT_SUCCESS;
}
