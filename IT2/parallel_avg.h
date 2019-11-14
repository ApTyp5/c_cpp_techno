#pragma once

#include "errcodes.h"
#include "my_vector.h"
#include "optimisation.h"
#include "simple_avg.h"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <pthread.h>

#define MAX_CORES   100

int parallel_avg_vector(little_vector_t avg_vector,
                        const little_vector_t *vectors, size_t size);

