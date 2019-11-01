#pragma once

#include "errcodes.h"
#include "my_vector.h"
#include "optimisation.h"

#include <cstdlib>

int simple_avg_vector(little_vector_t avg_vector,
                      const little_vector_t *vectors, size_t size);

