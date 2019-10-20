//
// Created by arthur on 18.10.2019.
//

#ifndef IT2_PARALLELAVG_H
#define IT2_PARALLELAVG_H

#include "errcodes.h"
#include "optimisation.h"
#include "Vector.h"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <pthread.h>

#define MAX_CORES   100

int parallelAvgVector(littleVector_t avg_vector, littleVector_t vectors[], size_t size);

#endif //IT2_PARALLELAVG_H
