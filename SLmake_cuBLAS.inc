
#
#  C preprocessor definitions:  set CDEFS to one of the following:
#
#     -DNoChange (fortran subprogram names are lower case without any suffix)
#     -DUpCase   (fortran subprogram names are upper case without any suffix)
#     -DAdd_     (fortran subprogram names are lower case with "_" appended)

CDEFS         = -DAdd_

#
#  The fortran and C compilers, loaders, and their flags
#

FC            = /home/app/mpt/mpt-2.12-p11218/bin/mpif90
CC            = /home/app/mpt/mpt-2.12-p11218/bin/mpicc
NOOPT         = -O0
FCFLAGS       = -O2
CCFLAGS       = -O2
SRCFLAG       =
FCLOADER      = $(FC)
CCLOADER      = $(CC)
FCLOADFLAGS   = -lgfortran 
CCLOADFLAGS   = 

#
#  The archiver and the flag(s) to use when building archive (library)
#  Also the ranlib routine.  If your system has no ranlib, set RANLIB = echo
#

ARCH          = ar
ARCHFLAGS     = cr
RANLIB        = /usr/bin/ranlib

#
#  The name of the ScaLAPACK library to be created
#

SCALAPACKLIB  = libcuscalapack.a

#
#  BLAS, LAPACK (and possibly other) libraries needed for linking test programs
#

CUDAINC       = -I/home/app/cuda/cuda-7.0/include
CUDALIB       = -L/home/app/cuda/cuda-7.0/lib64
CUDALIBS      = $(CUDALIB) -lcudart -lcublas
CCFLAGS      += $(CUDAINC)

#LIBS          = $(LAPACKLIB) $(BLASLIB)
LIBS          = $(LAPACKLIB) $(BLASLIB) $(CUDALIBS)

