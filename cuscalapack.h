#ifndef _CUSCALAPACK_H_
#define _CUSCALAPACK_H_

#include <mpi.h>
#include <cuda.h>
#include <cuda_runtime.h>

#if defined(c_plusplus) || defined(__cplusplus)
extern "C" {
#endif

  void init_cuscalapack();

#if defined(c_plusplus) || defined(__cplusplus)
}
#endif

#endif /* _CUSCALAPACK_H_ */
