#se_não_definido _CTEC_LIBM_H_
#defina _CTEC_LIBM_H_

#inclua "../math.h"

/* CTEC uses 8 bytes para duplo and longo duplo, so effectively the l variants
 * are never used. For now, they just run the normal (duplo) variant.
 */

/*
 * most of the code in this file is taken from MUSL rs-1.0 (MIT license)
 * - musl-libc: http://git.musl-libc.org/cgit/musl/tree/src/math?h=rs-1.0
 * - License:   http://git.musl-libc.org/cgit/musl/tree/COPYRIGHT?h=rs-1.0
 */

/*******************************************************************************
  Start of code based on MUSL
*******************************************************************************/
/*
musl as a whole is licensed under the following standard MIT license:

----------------------------------------------------------------------
Copyright © 2005-2014 Rich Felker, et al.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to faça so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
*/

/* fpclassify */

__CRT_INLINE inteiro __cdecl __fpclassify (duplo x) {
  união {duplo f; uint64_t i;} u = {x};
  inteiro e = u.i>>52 & 0x7ff;
  se (!e) retorne u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  se (e==0x7ff) retorne u.i<<12 ? FP_NAN : FP_INFINITE;
  retorne FP_NORMAL;
}

__CRT_INLINE inteiro __cdecl __fpclassifyf (real x) {
  união {real f; uint32_t i;} u = {x};
  inteiro e = u.i>>23 & 0xff;
  se (!e) retorne u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  se (e==0xff) retorne u.i<<9 ? FP_NAN : FP_INFINITE;
  retorne FP_NORMAL;
}

__CRT_INLINE inteiro __cdecl __fpclassifyl (longo duplo x) {
  retorne __fpclassify(x);
}


/* signbit */

__CRT_INLINE inteiro __cdecl __signbit (duplo x) {
  união {duplo d; uint64_t i;} y = { x };
  retorne y.i>>63;
}

__CRT_INLINE inteiro __cdecl __signbitf (real x) {
  união {real f; uint32_t i; } y = { x };
  retorne y.i>>31;
}

__CRT_INLINE inteiro __cdecl __signbitl (longo duplo x) {
  retorne __signbit(x);
}


/* fmin*, fmax* */

#defina CTECFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE duplo __cdecl fmin (duplo x, duplo y) {
  retorne CTECFP_FMIN_EVAL;
}

__CRT_INLINE real __cdecl fminf (real x, real y) {
  retorne CTECFP_FMIN_EVAL;
}

__CRT_INLINE longo duplo __cdecl fminl (longo duplo x, longo duplo y) {
  retorne CTECFP_FMIN_EVAL;
}

#defina CTECFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE duplo __cdecl fmax (duplo x, duplo y) {
  retorne CTECFP_FMAX_EVAL;
}

__CRT_INLINE real __cdecl fmaxf (real x, real y) {
  retorne CTECFP_FMAX_EVAL;
}

__CRT_INLINE longo duplo __cdecl fmaxl (longo duplo x, longo duplo y) {
  retorne CTECFP_FMAX_EVAL;
}


/* *round* */

#defina CTECFP_FORCE_EVAL(x) faça {            \
se (sizeof(x) == sizeof(real)) {           \
  volátil real __x;                       \
  __x = (x);                                \
} senão se (sizeof(x) == sizeof(duplo)) {   \
  volátil duplo __x;                      \
  __x = (x);                                \
} senão {                                    \
  volátil longo duplo __x;                 \
  __x = (x);                                \
}                                           \
} enquanto(0)

__CRT_INLINE duplo __cdecl round (duplo x) {
  união {duplo f; uint64_t i;} u = {x};
  inteiro e = u.i >> 52 & 0x7ff;
  duplo y;

  se (e >= 0x3ff+52)
    retorne x;
  se (u.i >> 63)
    x = -x;
  se (e < 0x3ff-1) {
    /* raise inexact se x!=0 */
    CTECFP_FORCE_EVAL(x + 0x1p52);
    retorne 0*u.f;
  }
  y = (duplo)(x + 0x1p52) - 0x1p52 - x;
  se (y > 0.5)
    y = y + x - 1;
  senão se (y <= -0.5)
    y = y + x + 1;
  senão
    y = y + x;
  se (u.i >> 63)
    y = -y;
  retorne y;
}

__CRT_INLINE longo __cdecl lround (duplo x) {
  retorne round(x);
}

__CRT_INLINE longo longo __cdecl llround (duplo x) {
  retorne round(x);
}

__CRT_INLINE real __cdecl roundf (real x) {
  retorne round(x);
}

__CRT_INLINE longo __cdecl lroundf (real x) {
  retorne round(x);
}

__CRT_INLINE longo longo __cdecl llroundf (real x) {
  retorne round(x);
}

__CRT_INLINE longo duplo __cdecl roundl (longo duplo x) {
  retorne round(x);
}

__CRT_INLINE longo __cdecl lroundl (longo duplo x) {
  retorne round(x);
}

__CRT_INLINE longo longo __cdecl llroundl (longo duplo x) {
  retorne round(x);
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/

#fim_se /* _CTEC_LIBM_H_ */
