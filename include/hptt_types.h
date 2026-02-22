#pragma once

#include <complex>
#include <complex.h>

#define REGISTER_BITS 256 // AVX
#ifdef HPTT_ARCH_ARM
#undef REGISTER_BITS 
#define REGISTER_BITS 128 // ARM
#endif

#ifndef HPTT_C_FLT_COMPLEX
#ifdef _MSC_VER
  #include <complex.h>
  #define HPTT_C_FLT_COMPLEX _Fcomplex
  #define HPTT_C_DBL_COMPLEX _Dcomplex
#else
  #define HPTT_C_FLT_COMPLEX float _Complex
  #define HPTT_C_DBL_COMPLEX double _Complex
#endif
#endif

namespace hptt {

/**
 * \brief Determines the duration of the auto-tuning process.
 *
 * * ESTIMATE: 0 seconds (i.e., no auto-tuning)
 * * MEASURE: 10 seconds
 * * PATIENT: 60 seconds
 * * CRAZY : 3600 seconds
 */
enum SelectionMethod { ESTIMATE, MEASURE, PATIENT, CRAZY };

using FloatComplex = std::complex<float>;
using DoubleComplex = std::complex<double>;

}

