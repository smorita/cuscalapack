#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cublas_v2.h>

#ifndef		__INCLUDE_PB_CUBLAS_H__
#define		__INCLUDE_PB_CUBLAS_H__

#define		NG	0
#define		OK	1

#define 	checkCudaErrors(err)	__checkCudaErrors( err, #err, __FILE__, __LINE__ )
#define		checkCublasErrors(err)	__checkCublasErrors( err, #err, __FILE__, __LINE__ )

typedef void  (*FUNCPTR)( char* transa, char* transb,
		                  int m, int n, int k, char* alpha, char* beta,
						  char* A, int lda, char* B, int ldb,
						  char* C, int idc );

static cublasOperation_t cublas_trans_const(char* key)
{
	switch(*key)
	{
		case 'N':	return CUBLAS_OP_N;
		case 'T':	return CUBLAS_OP_T;
		case 'C':	return CUBLAS_OP_C;
	}
	return CUBLAS_OP_N;
}

static char* cublasGetErrorString(cublasStatus_t status)
{
	switch(status)
	{
		case CUBLAS_STATUS_NOT_INITIALIZED:	return "CUBLAS_STATUS_NOT_INITIALIZED";
		case CUBLAS_STATUS_ALLOC_FAILED:	return "CUBLAS_STATUS_ALLOC_FAILED";
		case CUBLAS_STATUS_INVALID_VALUE:	return "CUBLAS_STATUS_INVALID_VALUE";
		case CUBLAS_STATUS_ARCH_MISMATCH:	return "CUBLAS_STATUS_ARCH_MISMATCH";
		case CUBLAS_STATUS_MAPPING_ERROR:	return "CUBLAS_STATUS_MAPPING_ERROR";
		case CUBLAS_STATUS_EXECUTION_FAILED:return "CUBLAS_STATUS_EXECUTION_FAILED";
		case CUBLAS_STATUS_INTERNAL_ERROR:	return "CUBLAS_STATUS_INTERNAL_ERROR";
		case CUBLAS_STATUS_NOT_SUPPORTED:	return "CUBLAS_STATUS_NOT_SUPPORTED";
		case CUBLAS_STATUS_LICENSE_ERROR:	return "CUBLAS_STATUS_LICENSE_ERROR";
	}
	return "unknown error";
}

static inline int __checkCudaErrors(int err, const char* func, const char* file, const int line)
{
	if( CUDA_SUCCESS != err )
	{
		printf("CUDA error at %s:%d code=%d(%s) \"%s\" \n",
				file, line, (int)err, cudaGetErrorString(err), func);
		return NG;
	}
	return OK;
}

static inline int __checkCublasErrors(int err, const char* func, const char* file, const int line)
{
	if( CUBLAS_STATUS_SUCCESS != err )
	{
		char* cublasStatus = cublasGetErrorString(err);
		printf("CUBLAS error at %s:%d code=%d(%s) \"%s\" \n",
				file, line, (int)err, cublasStatus, func);
		return NG;
	}
	return OK;
}

#endif		// __INCLUDE_PB_CUBLAS_H__

