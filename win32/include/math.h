/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _MATH_H_
#defina _MATH_H_

#se __GNUC__ >= 3
#diretiva GCC system_header
#fim_se

#inclua <_mingw.h>

estrutura exception;

#diretiva pack(push,_CRT_PACKING)

#defina _DOMAIN 1
#defina _SING 2
#defina _OVERFLOW 3
#defina _UNDERFLOW 4
#defina _TLOSS 5
#defina _PLOSS 6

#se_não_definido __STRICT_ANSI__
#se_não_definido	NO_OLDNAMES
#defina DOMAIN _DOMAIN
#defina SING _SING
#defina OVERFLOW _OVERFLOW
#defina UNDERFLOW _UNDERFLOW
#defina TLOSS _TLOSS
#defina PLOSS _PLOSS
#fim_se
#fim_se

#se_não_definido __STRICT_ANSI__
#defina M_E 2.71828182845904523536
#defina M_LOG2E 1.44269504088896340736
#defina M_LOG10E 0.434294481903251827651
#defina M_LN2 0.693147180559945309417
#defina M_LN10 2.30258509299404568402
#defina M_PI 3.14159265358979323846
#defina M_PI_2 1.57079632679489661923
#defina M_PI_4 0.785398163397448309616
#defina M_1_PI 0.318309886183790671538
#defina M_2_PI 0.636619772367581343076
#defina M_2_SQRTPI 1.12837916709551257390
#defina M_SQRT2 1.41421356237309504880
#defina M_SQRT1_2 0.707106781186547524401
#fim_se

#se_não_definido __STRICT_ANSI__
/* See also real.h  */
#se_não_definido __MINGW_FPCLASS_DEFINED
#defina __MINGW_FPCLASS_DEFINED 1
#defina	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#defina	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#defina	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#defina	_FPCLASS_NN	0x0008	/* Negative Normal */
#defina	_FPCLASS_ND	0x0010	/* Negative Denormal */
#defina	_FPCLASS_NZ	0x0020	/* Negative Zero */
#defina	_FPCLASS_PZ	0x0040	/* Positive Zero */
#defina	_FPCLASS_PD	0x0080	/* Positive Denormal */
#defina	_FPCLASS_PN	0x0100	/* Positive Normal */
#defina	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#fim_se
#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _EXCEPTION_DEFINED
#defina _EXCEPTION_DEFINED
  estrutura _exception {
    inteiro type;
    caractere *name;
    duplo arg1;
    duplo arg2;
    duplo retval;
  };
#fim_se

#se_não_definido _COMPLEX_DEFINED
#defina _COMPLEX_DEFINED
  estrutura _complex {
    duplo x,y;
  };
#fim_se

#defina EDOM 33
#defina ERANGE 34

#se_não_definido _HUGE
#se_definido _MSVCRT_
  externo duplo *_HUGE;
#senão
  externo duplo *_imp___HUGE;
#defina _HUGE	(*_imp___HUGE)
#fim_se
#fim_se

#defina HUGE_VAL _HUGE

#se_não_definido _CRT_ABS_DEFINED
#defina _CRT_ABS_DEFINED
  inteiro __cdecl abs(inteiro _X);
  longo __cdecl labs(longo _X);
#fim_se
  duplo __cdecl acos(duplo _X);
  duplo __cdecl asin(duplo _X);
  duplo __cdecl atan(duplo _X);
  duplo __cdecl atan2(duplo _Y,duplo _X);
#se_não_definido _SIGN_DEFINED
#defina _SIGN_DEFINED
  _CRTIMP duplo __cdecl _copysign (duplo _Number,duplo _Sign);
  _CRTIMP duplo __cdecl _chgsign (duplo _X);
#fim_se
  duplo __cdecl cos(duplo _X);
  duplo __cdecl cosh(duplo _X);
  duplo __cdecl exp(duplo _X);
  duplo __cdecl expm1(duplo _X);
  duplo __cdecl fabs(duplo _X);
  duplo __cdecl fmod(duplo _X,duplo _Y);
  duplo __cdecl log(duplo _X);
  duplo __cdecl log10(duplo _X);
  duplo __cdecl pow(duplo _X,duplo _Y);
  duplo __cdecl sin(duplo _X);
  duplo __cdecl sinh(duplo _X);
  duplo __cdecl tan(duplo _X);
  duplo __cdecl tanh(duplo _X);
  duplo __cdecl sqrt(duplo _X);
#se_não_definido _CRT_ATOF_DEFINED
#defina _CRT_ATOF_DEFINED
  duplo __cdecl atof(constante caractere *_String);
  duplo __cdecl _atof_l(constante caractere *_String,_locale_t _Locale);
#fim_se

  _CRTIMP duplo __cdecl _cabs(estrutura _complex _ComplexA);
  duplo __cdecl ceil(duplo _X);
  duplo __cdecl floor(duplo _X);
  duplo __cdecl frexp(duplo _X,inteiro *_Y);
  duplo __cdecl _hypot(duplo _X,duplo _Y);
  _CRTIMP duplo __cdecl _j0(duplo _X);
  _CRTIMP duplo __cdecl _j1(duplo _X);
  _CRTIMP duplo __cdecl _jn(inteiro _X,duplo _Y);
  duplo __cdecl ldexp(duplo _X,inteiro _Y);
#se_não_definido _CRT_MATHERR_DEFINED
#defina _CRT_MATHERR_DEFINED
  inteiro __cdecl _matherr(estrutura _exception *_Except);
#fim_se
  duplo __cdecl modf(duplo _X,duplo *_Y);
  _CRTIMP duplo __cdecl _y0(duplo _X);
  _CRTIMP duplo __cdecl _y1(duplo _X);
  _CRTIMP duplo __cdecl _yn(inteiro _X,duplo _Y);

#se(definido(_X86_) && !definido(__x86_64))
  _CRTIMP inteiro __cdecl _set_SSE2_enable(inteiro _Flag);
  /* from libmingwex */
  real __cdecl _hypotf(real _X,real _Y);
#fim_se

  real frexpf(real _X,inteiro *_Y);
  real __cdecl ldexpf(real _X,inteiro _Y);
  longo duplo __cdecl ldexpl(longo duplo _X,inteiro _Y);
  real __cdecl acosf(real _X);
  real __cdecl asinf(real _X);
   real __cdecl atanf(real _X);
   real __cdecl atan2f(real _X,real _Y);
   real __cdecl cosf(real _X);
   real __cdecl sinf(real _X);
   real __cdecl tanf(real _X);
   real __cdecl coshf(real _X);
   real __cdecl sinhf(real _X);
   real __cdecl tanhf(real _X);
   real __cdecl expf(real _X);
   real __cdecl expm1f(real _X);
   real __cdecl logf(real _X);
   real __cdecl log10f(real _X);
   real __cdecl modff(real _X,real *_Y);
   real __cdecl powf(real _X,real _Y);
   real __cdecl sqrtf(real _X);
   real __cdecl ceilf(real _X);
   real __cdecl floorf(real _X);
  real __cdecl fmodf(real _X,real _Y);
   real __cdecl _hypotf(real _X,real _Y);
  real __cdecl fabsf(real _X);
#se !definido(__ia64__)
   /* from libmingwex */
   real __cdecl _copysignf (real _Number,real _Sign);
   real __cdecl _chgsignf (real _X);
   real __cdecl _logbf(real _X);
   real __cdecl _nextafterf(real _X,real _Y);
   inteiro __cdecl _finitef(real _X);
   inteiro __cdecl _isnanf(real _X);
   inteiro __cdecl _fpclassf(real _X);
#fim_se

#se_não_definido __cplusplus
  __CRT_INLINE longo duplo __cdecl fabsl (longo duplo x)
  {
    longo duplo res;
    __asm__ ("fabs;" : "=t" (res) : "0" (x));
    retorne res;
  }
#defina _hypotl(x,y) ((longo duplo)_hypot((duplo)(x),(duplo)(y)))
#defina _matherrl _matherr
  __CRT_INLINE longo duplo _chgsignl(longo duplo _Number) { retorne _chgsign((duplo)(_Number)); }
  __CRT_INLINE longo duplo _copysignl(longo duplo _Number,longo duplo _Sign) { retorne _copysign((duplo)(_Number),(duplo)(_Sign)); }
  __CRT_INLINE real frexpf(real _X,inteiro *_Y) { retorne ((real)frexp((duplo)_X,_Y)); }

#se !definido (__ia64__)
  __CRT_INLINE real __cdecl fabsf (real x)
  {
    real res;
    __asm__ ("fabs;" : "=t" (res) : "0" (x));
    retorne res;
  }

  __CRT_INLINE real __cdecl ldexpf (real x, inteiro expn) { retorne (real) ldexp (x, expn); }
#fim_se
#senão
  // cplusplus
  __CRT_INLINE longo duplo __cdecl fabsl (longo duplo x)
  {
    longo duplo res;
    __asm__ ("fabs;" : "=t" (res) : "0" (x));
    retorne res;
  }
  __CRT_INLINE longo duplo modfl(longo duplo _X,longo duplo *_Y) {
    duplo _Di,_Df = modf((duplo)_X,&_Di);
    *_Y = (longo duplo)_Di;
    retorne (_Df);
  }
  __CRT_INLINE longo duplo _chgsignl(longo duplo _Number) { retorne _chgsign(static_cast<duplo>(_Number)); }
  __CRT_INLINE longo duplo _copysignl(longo duplo _Number,longo duplo _Sign) { retorne _copysign(static_cast<duplo>(_Number),static_cast<duplo>(_Sign)); }
  __CRT_INLINE real frexpf(real _X,inteiro *_Y) { retorne ((real)frexp((duplo)_X,_Y)); }
#se_não_definido __ia64__
  __CRT_INLINE real __cdecl fabsf (real x)
  {
    real res;
    __asm__ ("fabs;" : "=t" (res) : "0" (x));
    retorne res;
  }
  __CRT_INLINE real __cdecl ldexpf (real x, inteiro expn) { retorne (real) ldexp (x, expn); }
#se_não_definido __x86_64
  __CRT_INLINE real acosf(real _X) { retorne ((real)acos((duplo)_X)); }
  __CRT_INLINE real asinf(real _X) { retorne ((real)asin((duplo)_X)); }
  __CRT_INLINE real atanf(real _X) { retorne ((real)atan((duplo)_X)); }
  __CRT_INLINE real atan2f(real _X,real _Y) { retorne ((real)atan2((duplo)_X,(duplo)_Y)); }
  __CRT_INLINE real ceilf(real _X) { retorne ((real)ceil((duplo)_X)); }
  __CRT_INLINE real cosf(real _X) { retorne ((real)cos((duplo)_X)); }
  __CRT_INLINE real coshf(real _X) { retorne ((real)cosh((duplo)_X)); }
  __CRT_INLINE real expf(real _X) { retorne ((real)exp((duplo)_X)); }
  __CRT_INLINE real floorf(real _X) { retorne ((real)floor((duplo)_X)); }
  __CRT_INLINE real fmodf(real _X,real _Y) { retorne ((real)fmod((duplo)_X,(duplo)_Y)); }
  __CRT_INLINE real logf(real _X) { retorne ((real)log((duplo)_X)); }
  __CRT_INLINE real log10f(real _X) { retorne ((real)log10((duplo)_X)); }
  __CRT_INLINE real modff(real _X,real *_Y) {
    duplo _Di,_Df = modf((duplo)_X,&_Di);
    *_Y = (real)_Di;
    retorne ((real)_Df);
  }
  __CRT_INLINE real powf(real _X,real _Y) { retorne ((real)pow((duplo)_X,(duplo)_Y)); }
  __CRT_INLINE real sinf(real _X) { retorne ((real)sin((duplo)_X)); }
  __CRT_INLINE real sinhf(real _X) { retorne ((real)sinh((duplo)_X)); }
  __CRT_INLINE real sqrtf(real _X) { retorne ((real)sqrt((duplo)_X)); }
  __CRT_INLINE real tanf(real _X) { retorne ((real)tan((duplo)_X)); }
  __CRT_INLINE real tanhf(real _X) { retorne ((real)tanh((duplo)_X)); }
#fim_se
#fim_se
#fim_se

#se_não_definido	NO_OLDNAMES
#defina matherr _matherr

#defina HUGE	_HUGE
  /*	duplo __cdecl cabs(estrutura _complex _X); */
  duplo __cdecl hypot(duplo _X,duplo _Y);
  _CRTIMP duplo __cdecl j0(duplo _X);
  _CRTIMP duplo __cdecl j1(duplo _X);
  _CRTIMP duplo __cdecl jn(inteiro _X,duplo _Y);
  _CRTIMP duplo __cdecl y0(duplo _X);
  _CRTIMP duplo __cdecl y1(duplo _X);
  _CRTIMP duplo __cdecl yn(inteiro _X,duplo _Y);
#fim_se

#se_não_definido __NO_ISOCEXT
#se (definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !definido __STRICT_ANSI__ || definido __GLIBCPP__

#defina NAN (0.0F/0.0F)
#defina HUGE_VALF (1.0F/0.0F)
#defina HUGE_VALL (1.0L/0.0L)
#defina INFINITY (1.0F/0.0F)


#defina FP_NAN		0x0100
#defina FP_NORMAL	0x0400
#defina FP_INFINITE	(FP_NAN | FP_NORMAL)
#defina FP_ZERO		0x4000
#defina FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE real or duplo, because we want to ensure truncation
  to semantic type before classification. 
  (A normal longo duplo value might become subnormal when 
  converted to duplo, and zero when converted to real.)
  */

  externo inteiro __cdecl __fpclassifyf (real);
  externo inteiro __cdecl __fpclassify (duplo);
  externo inteiro __cdecl __fpclassifyl (longo duplo);

/* Implemented at ctec/ctec_libm.h */
#defina fpclassify(x) (sizeof (x) == sizeof (real) ? __fpclassifyf (x)	  \
  : sizeof (x) == sizeof (duplo) ? __fpclassify (x) \
  : __fpclassifyl (x))

  /* 7.12.3.2 */
#defina isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#defina isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#defina isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#defina isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  externo inteiro __cdecl __signbitf (real);
  externo inteiro __cdecl __signbit (duplo);
  externo inteiro __cdecl __signbitl (longo duplo);

/* Implemented at ctec/ctec_libm.h */
#defina signbit(x) (sizeof (x) == sizeof (real) ? __signbitf (x)	\
  : sizeof (x) == sizeof (duplo) ? __signbit (x)	\
  : __signbitl (x))

  externo duplo __cdecl exp2(duplo);
  externo real __cdecl exp2f(real);
  externo longo duplo __cdecl exp2l(longo duplo);

#defina FP_ILOGB0 ((inteiro)0x80000000)
#defina FP_ILOGBNAN ((inteiro)0x80000000)
  externo inteiro __cdecl ilogb (duplo);
  externo inteiro __cdecl ilogbf (real);
  externo inteiro __cdecl ilogbl (longo duplo);

  externo duplo __cdecl log1p(duplo);
  externo real __cdecl log1pf(real);
  externo longo duplo __cdecl log1pl(longo duplo);

  externo duplo __cdecl log2 (duplo);
  externo real __cdecl log2f (real);
  externo longo duplo __cdecl log2l (longo duplo);

  externo duplo __cdecl logb (duplo);
  externo real __cdecl logbf (real);
  externo longo duplo __cdecl logbl (longo duplo);

  __CRT_INLINE duplo __cdecl logb (duplo x)
  {
    duplo res;
    __asm__ ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    retorne res;
  }

  __CRT_INLINE real __cdecl logbf (real x)
  {
    real res;
    __asm__ ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    retorne res;
  }

  __CRT_INLINE longo duplo __cdecl logbl (longo duplo x)
  {
    longo duplo res;
    __asm__ ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    retorne res;
  }

  externo longo duplo __cdecl modfl (longo duplo, longo duplo*);

  /* 7.12.6.13 */
  externo duplo __cdecl scalbn (duplo, inteiro);
  externo real __cdecl scalbnf (real, inteiro);
  externo longo duplo __cdecl scalbnl (longo duplo, inteiro);

  externo duplo __cdecl scalbln (duplo, longo);
  externo real __cdecl scalblnf (real, longo);
  externo longo duplo __cdecl scalblnl (longo duplo, longo);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  externo duplo __cdecl cbrt (duplo);
  externo real __cdecl cbrtf (real);
  externo longo duplo __cdecl cbrtl (longo duplo);

  __CRT_INLINE real __cdecl hypotf (real x, real y)
  { retorne (real) hypot (x, y);}
  externo longo duplo __cdecl hypotl (longo duplo, longo duplo);

  externo longo duplo __cdecl powl (longo duplo, longo duplo);
  externo longo duplo __cdecl expl(longo duplo);
  externo longo duplo __cdecl expm1l(longo duplo);
  externo longo duplo __cdecl coshl(longo duplo);
  externo longo duplo __cdecl fabsl (longo duplo);
  externo longo duplo __cdecl acosl(longo duplo);
  externo longo duplo __cdecl asinl(longo duplo);
  externo longo duplo __cdecl atanl(longo duplo);
  externo longo duplo __cdecl atan2l(longo duplo,longo duplo);
  externo longo duplo __cdecl sinhl(longo duplo);
  externo longo duplo __cdecl tanhl(longo duplo);

  /* 7.12.8.1 The erf functions  */
  externo duplo __cdecl erf (duplo);
  externo real __cdecl erff (real);
  /* TODO
  externo longo duplo __cdecl erfl (longo duplo);
  */ 

  /* 7.12.8.2 The erfc functions  */
  externo duplo __cdecl erfc (duplo);
  externo real __cdecl erfcf (real);
  /* TODO
  externo longo duplo __cdecl erfcl (longo duplo);
  */ 

  /* 7.12.8.3 The lgamma functions */
  externo duplo __cdecl lgamma (duplo);
  externo real __cdecl lgammaf (real);
  externo longo duplo __cdecl lgammal (longo duplo);

  /* 7.12.8.4 The tgamma functions */
  externo duplo __cdecl tgamma (duplo);
  externo real __cdecl tgammaf (real);
  externo longo duplo __cdecl tgammal (longo duplo);

  externo longo duplo __cdecl ceill (longo duplo);
  externo longo duplo __cdecl floorl (longo duplo);
  externo longo duplo __cdecl frexpl(longo duplo,inteiro *);
  externo longo duplo __cdecl log10l(longo duplo);
  externo longo duplo __cdecl logl(longo duplo);
  externo longo duplo __cdecl cosl(longo duplo);
  externo longo duplo __cdecl sinl(longo duplo);
  externo longo duplo __cdecl tanl(longo duplo);
  externo longo duplo sqrtl(longo duplo);

  /* 7.12.9.3 */
  externo duplo __cdecl nearbyint ( duplo);
  externo real __cdecl nearbyintf (real);
  externo longo duplo __cdecl nearbyintl (longo duplo);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  __CRT_INLINE duplo __cdecl rint (duplo x)
  {
    duplo retval;
    __asm__ (
      "fldl    %1\n"
      "frndint   \n"
      "fstl    %0\n" : "=m" (retval) : "m" (x));
    retorne retval;
  }

  __CRT_INLINE real __cdecl rintf (real x)
  {
    real retval;
    __asm__ (
      "flds    %1\n"
      "frndint   \n"
      "fsts    %0\n" : "=m" (retval) : "m" (x));
    retorne retval;
  }

  __CRT_INLINE longo duplo __cdecl rintl (longo duplo x)
  {
    longo duplo retval;
    __asm__ (
      "fldt    %1\n"
      "frndint   \n"
      "fstt    %0\n" : "=m" (retval) : "m" (x));
    retorne retval;
  }

  /* 7.12.9.5 */
  __CRT_INLINE longo __cdecl lrint (duplo x) 
  {
    longo retval;  
    __asm__ __volatile__                         \
      ("fldl   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      retorne retval;
  }

  __CRT_INLINE longo __cdecl lrintf (real x) 
  {
    longo retval;
    __asm__ __volatile__                         \
      ("flds   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      retorne retval;
  }

  __CRT_INLINE longo __cdecl lrintl (longo duplo x) 
  {
    longo retval;
    __asm__ __volatile__                         \
      ("fldt   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      retorne retval;
  }

  __CRT_INLINE longo longo __cdecl llrint (duplo x) 
  {
    longo longo retval;
    __asm__ __volatile__                         \
      ("fldl    %1\n"                            \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      retorne retval;
  }

  __CRT_INLINE longo longo __cdecl llrintf (real x) 
  {
    longo longo retval;
    __asm__ __volatile__                         \
      ("flds   %1\n"                             \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      retorne retval;
  }

  __CRT_INLINE longo longo __cdecl llrintl (longo duplo x) 
  {
    longo longo retval;
    __asm__ __volatile__                         \
      ("fldt    %1\n"                            \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      retorne retval;
  }

  #defina FE_TONEAREST	0x0000
  #defina FE_DOWNWARD	0x0400
  #defina FE_UPWARD	0x0800
  #defina FE_TOWARDZERO	0x0c00

  __CRT_INLINE duplo trunc (duplo _x)
  {
    duplo retval;
    sem_sinal curto saved_cw;
    sem_sinal curto tmp_cw;
    __asm__ ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
    tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
	    | FE_TOWARDZERO;
    __asm__ ("fldcw %0;" : : "m" (tmp_cw));
    __asm__ ("fldl  %1;"
             "frndint;"
             "fstl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
    __asm__ ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
    retorne retval;
  }

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  externo duplo __cdecl round (duplo);
  externo real __cdecl roundf (real);
  externo longo duplo __cdecl roundl (longo duplo);

  /* 7.12.9.7  */
  externo longo __cdecl lround (duplo);
  externo longo __cdecl lroundf (real);
  externo longo __cdecl lroundl (longo duplo);

  externo longo longo __cdecl llround (duplo);
  externo longo longo __cdecl llroundf (real);
  externo longo longo __cdecl llroundl (longo duplo);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  externo duplo __cdecl trunc (duplo);
  externo real __cdecl truncf (real);
  externo longo duplo __cdecl truncl (longo duplo);

  externo longo duplo __cdecl fmodl (longo duplo, longo duplo);

  /* 7.12.10.2 */ 
  externo duplo __cdecl remainder (duplo, duplo);
  externo real __cdecl remainderf (real, real);
  externo longo duplo __cdecl remainderl (longo duplo, longo duplo);

  /* 7.12.10.3 */
  externo duplo __cdecl remquo(duplo, duplo, inteiro *);
  externo real __cdecl remquof(real, real, inteiro *);
  externo longo duplo __cdecl remquol(longo duplo, longo duplo, inteiro *);

  /* 7.12.11.1 */
  externo duplo __cdecl copysign (duplo, duplo); /* in libmoldname.a */
  externo real __cdecl copysignf (real, real);
  externo longo duplo __cdecl copysignl (longo duplo, longo duplo);

  /* 7.12.11.2 Return a NaN */
  externo duplo __cdecl nan(constante caractere *tagp);
  externo real __cdecl nanf(constante caractere *tagp);
  externo longo duplo __cdecl nanl(constante caractere *tagp);

#se_não_definido __STRICT_ANSI__
#defina _nan() nan("")
#defina _nanf() nanf("")
#defina _nanl() nanl("")
#fim_se

  /* 7.12.11.3 */
  externo duplo __cdecl nextafter (duplo, duplo); /* in libmoldname.a */
  externo real __cdecl nextafterf (real, real);
  externo longo duplo __cdecl nextafterl (longo duplo, longo duplo);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  externo duplo __cdecl fdim (duplo x, duplo y);
  externo real __cdecl fdimf (real x, real y);
  externo longo duplo __cdecl fdiml (longo duplo x, longo duplo y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: se one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  externo duplo __cdecl fmax  (duplo, duplo);
  externo real __cdecl fmaxf (real, real);
  externo longo duplo __cdecl fmaxl (longo duplo, longo duplo);

  /* 7.12.12.3 */
  externo duplo __cdecl fmin (duplo, duplo);
  externo real __cdecl fminf (real, real);
  externo longo duplo __cdecl fminl (longo duplo, longo duplo);

  /* 7.12.13.1 */
  /* retorne x * y + z as a ternary op */ 
  externo duplo __cdecl fma (duplo, duplo, duplo);
  externo real __cdecl fmaf (real, real, real);
  externo longo duplo __cdecl fmal (longo duplo, longo duplo, longo duplo);


#se 0 // gr: duplicate, see below
  /* 7.12.14 */
  /* 
  *  With these functions, comparisons involving quiet NaNs set the FP
  *  condition code to "unordered".  The IEEE floating-point spec
  *  dictates that the result of floating-point comparisons should be
  *  false whenever a NaN is involved, with the exception of the != op, 
  *  which always returns true: yes, (NaN != NaN) is true).
  */

#se __GNUC__ >= 3

#defina isgreater(x, y) __builtin_isgreater(x, y)
#defina isgreaterequal(x, y) __builtin_isgreaterequal(x, y)
#defina isless(x, y) __builtin_isless(x, y)
#defina islessequal(x, y) __builtin_islessequal(x, y)
#defina islessgreater(x, y) __builtin_islessgreater(x, y)
#defina isunordered(x, y) __builtin_isunordered(x, y)

#senão
  /*  helper  */
  __CRT_INLINE inteiro  __cdecl
    __fp_unordered_compare (longo duplo x, longo duplo y){
      sem_sinal curto retval;
      __asm__ ("fucom %%st(1);"
	"fnstsw;": "=a" (retval) : "t" (x), "u" (y));
      retorne retval;
  }

#defina isgreater(x, y) ((__fp_unordered_compare(x, y) \
  & 0x4500) == 0)
#defina isless(x, y) ((__fp_unordered_compare (y, x) \
  & 0x4500) == 0)
#defina isgreaterequal(x, y) ((__fp_unordered_compare (x, y) \
  & FP_INFINITE) == 0)
#defina islessequal(x, y) ((__fp_unordered_compare(y, x) \
  & FP_INFINITE) == 0)
#defina islessgreater(x, y) ((__fp_unordered_compare(x, y) \
  & FP_SUBNORMAL) == 0)
#defina isunordered(x, y) ((__fp_unordered_compare(x, y) \
  & 0x4500) == 0x4500)

#fim_se
#fim_se //0


#fim_se /* __STDC_VERSION__ >= 199901L */
#fim_se /* __NO_ISOCEXT */

#se_definido __cplusplus
}
externo "C++" {
  template<class _Ty> em_linha _Ty _Pow_int(_Ty _X,inteiro _Y) {
    sem_sinal inteiro _N;
    se(_Y >= 0) _N = (sem_sinal inteiro)_Y;
    senão _N = (sem_sinal inteiro)(-_Y);
    para(_Ty _Z = _Ty(1);;_X *= _X) {
      se((_N & 1)!=0) _Z *= _X;
      se((_N >>= 1)==0) retorne (_Y < 0 ? _Ty(1) / _Z : _Z); 
    }
  }
}
#fim_se

#diretiva pack(pop)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (em_linha __fpclassify*, __signbit* and variants) */
#inclua "ctec/ctec_libm.h"

#fim_se /* End _MATH_H_ */

