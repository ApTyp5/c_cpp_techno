//
// Created by arthur on 14.11.2019.
//

#include "simple_avg.h"
#include "parallel_avg.h"

#include <chrono>
#include <fstream>
#include <string>
#include <iostream>

void make_experiment(int,int,int,std::string);

int main(){
  std::string fnam = "1000_10000_1000_expRes";
  make_experiment(1000000, 100000000, 1000000, fnam);
}

long long measure_alg_time(int (*alg)(little_vector_t, const little_vector_t *, size_t),
                           little_vector_t ans, little_vector_t *vectors, size_t size);

void make_experiment(int start, int stop, int step, std::string fnam){
  using namespace std;

  ofstream fout;
  fout.open(fnam);
  if (!fout.is_open()) return;

  little_vector_t ans;
  little_vector_t *vectors = new little_vector_t[stop];

  for (size_t cur_len = start; cur_len <= stop; cur_len += step){
    cout << cur_len << endl;

    long long para_time = measure_alg_time(parallel_avg_vector, ans, vectors, cur_len);
    long long simp_time = measure_alg_time(simple_avg_vector, ans, vectors, cur_len);

    fout << cur_len << " " << para_time << " " << simp_time << endl;
  }

  fout.close();
}

long long measure_alg_time(int (*alg)(little_vector_t, const little_vector_t *, size_t),
    little_vector_t ans, little_vector_t *vectors, size_t size){

  using namespace std::chrono;

  auto begin = high_resolution_clock::now();
  parallel_avg_vector(ans, vectors, size);
  auto end = high_resolution_clock::now();

  return duration_cast<microseconds>(end - begin).count();
}
