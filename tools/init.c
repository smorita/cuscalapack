#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include "../cuscalapack.h"

void init_cuscalapack() {
  int argc;
  char **argv;
  int is_initialized;
  MPI_Comm comm = MPI_COMM_WORLD;
  int mpirank;
  int mpisize;
  int numdevices;
  cudaError_t errorId;

  MPI_Initialized(&is_initialized);
  if(!is_initialized) {
    MPI_Init(&argc, &argv);
  }

  MPI_Comm_rank(MPI_COMM_WORLD, &mpirank);
  MPI_Comm_size(MPI_COMM_WORLD, &mpisize);

  errorId = cudaGetDeviceCount(&numdevices);
  if (errorId != cudaSuccess) {
    if (mpirank==0) {
      fprintf(stderr,"cudaGetDeviceCount returned [%d] %s\n", (int)errorId, cudaGetErrorString(errorId));
    }
    MPI_Finalize();
    exit(EXIT_FAILURE);
  }
  cudaSetDevice(mpirank%numdevices);

  return;
}
