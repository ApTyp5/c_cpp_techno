//
// Created by arthur on 14.11.2019.
//

#include "simple_avg.h"
#include "parallel_avg.h"

#include <chrono>
#include <fstream>
#include <random>
#include <string>
#include <iostream>

static std::random_device generator; // NOLINT(cert-err58-cpp)
static std::uniform_real_distribution<float> distribution(-2000, 2000); // NOLINT(cert-err58-cpp)

void make_experiment(int, int, int, std::string);

int main() {
  make_experiment(1000, 1000000, 1000, "100000_1000000expRes");
}

long long measure_alg_time(int (*alg)(little_vector_t, const little_vector_t *, size_t),
                           little_vector_t ans, little_vector_t *vectors, size_t size);

little_vector_t *create_vectors(int size);

void make_experiment(int start, int stop, int step, std::string fnam) {
  using namespace std;

  ofstream fout;
  fout.open(fnam);
  if (!fout.is_open()) return;

  little_vector_t ans;
  little_vector_t *vectors = create_vectors(stop);

  for (size_t cur_len = start; cur_len <= stop; cur_len += step) {
    size_t exp_number = 16;
    unsigned long para_time = 0;
    unsigned long simp_time = 0;
    for (size_t i = 0; i < exp_number; i++){
      para_time += measure_alg_time(parallel_avg_vector, ans, vectors, cur_len);
      simp_time += measure_alg_time(simple_avg_vector, ans, vectors, cur_len);
    }

    para_time >>= 4;
    simp_time >>= 4;

    fout << cur_len << " " << para_time << " " << simp_time << endl;
  }

  fout.close();
}

long long measure_alg_time(int (*alg)(little_vector_t, const little_vector_t *, size_t),
                           little_vector_t ans, little_vector_t *vectors, size_t size) {

  using namespace std::chrono;

  auto begin = high_resolution_clock::now();
  alg(ans, vectors, size);
  auto end = high_resolution_clock::now();

  return duration_cast<microseconds>(end - begin).count();
}

little_vector_t *create_vectors(int size) {
  little_vector_t *ans = new little_vector_t[size];
  for (int i = 0; i < size; i++) {
    for (size_t j = 0; j < vec_size; j++) {
      ans[i][j] = distribution(generator);
    }
  }
  return ans;
}
