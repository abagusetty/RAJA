/*
 * Copyright (c) 2016, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 *
 * All rights reserved.
 *
 * This source code cannot be distributed without permission and
 * further review from Lawrence Livermore National Laboratory.
 */

/*!
 ******************************************************************************
 *
 * \file
 *
 * \brief   RAJA header file for simple comparison operations used in tests.
 *     
 ******************************************************************************
 */

#ifndef RAJA_Compare_HXX
#define RAJA_Compare_HXX

namespace RAJA {

//
// Test approximate equality of floating point numbers. Borrowed from Knuth.
//
template <typename T>
bool equal(T a, T b)
{
   return (abs(a-b) <= ( ( abs(a) < abs(b) ? abs(a) : abs(b) ) * 10e-12 ) );
}

//
// Equality for integers.  Mainly here for consistent usage with above.
//
bool equal(int a, int b)
{
   return a == b ;
}

template <typename T>
bool array_equal(T ref_result,
                 T to_check,
                 Index_type alen)
{
   bool is_correct = true;
   for (Index_type i = 0 ; i < alen && is_correct; ++i) {
      is_correct &= equal(ref_result[i], to_check[i]);
   }

   return is_correct;
}


}  // closing brace for RAJA namespace

#endif  // closing endif for header file include guard