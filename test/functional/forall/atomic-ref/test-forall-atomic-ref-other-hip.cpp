//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC
// and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

///
/// Source file containing tests for logical, accessor, min/max, and cas atomic operations
///

#include "tests/test-forall-atomic-ref-other.hpp"

#include "../test-forall-execpol.hpp"

#include "../test-forall-atomic-utils.hpp"

#if defined(RAJA_ENABLE_HIP)
using HipAtomicForallRefOtherTypes = Test< camp::cartesian_product<
                                                                  HipForallExecPols,
                                                                  HipAtomicPols,
                                                                  HipResourceList,
                                                                  AtomicDataTypeList >
                                        >::Types;

INSTANTIATE_TYPED_TEST_SUITE_P( HipTest,
                                ForallAtomicRefOtherFunctionalTest,
                                HipAtomicForallRefOtherTypes );
#endif
