###############################################################################
# Copyright (c) 2016-19, Lawrence Livermore National Security, LLC
# and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
###############################################################################

set(RAJA_COMPILER "RAJA_COMPILER_XLC" CACHE STRING "")

set(CMAKE_CXX_FLAGS_RELEASE "-O3 -qxlcompatmacros -qlanglvl=extended0x -qalias=noansi -qsmp=omp -qhot -qnoeh" CACHE STRING "")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g -qxlcompatmacros -qlanglvl=extended0x -qalias=noansi -qsmp=omp -qhot -qnoeh" CACHE STRING "")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -qsmp=omp:noopt " CACHE STRING "")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-z,muldefs" CACHE STRING "")

set(RAJA_RANGE_ALIGN 4 CACHE STRING "")
set(RAJA_RANGE_MIN_LENGTH 32 CACHE STRING "")
set(RAJA_DATA_ALIGN 64 CACHE STRING "")

set(RAJA_HOST_CONFIG_LOADED On CACHE BOOL "")

