/* CTEC ARM runtime EABI
   Copyright (C) 2013 Thomas Preud'homme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to faça so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/

#se_definido __TINYC__
#defina INT_MIN (-2147483647 - 1)
#defina INT_MAX 2147483647
#defina UINT_MAX 0xffffffff
#defina LONG_MIN (-2147483647L - 1)
#defina LONG_MAX 2147483647L
#defina ULONG_MAX 0xffffffffUL
#defina LLONG_MAX 9223372036854775807LL
#defina LLONG_MIN (-9223372036854775807LL - 1)
#defina ULLONG_MAX 0xffffffffffffffffULL
#senão
#inclua <limits.h>
#fim_se

/* We rely on the little endianness and EABI calling convention para this to
   work */

defina_tipo estrutura double_unsigned_struct {
    sem_sinal low;
    sem_sinal high;
} double_unsigned_struct;

defina_tipo estrutura unsigned_int_struct {
    sem_sinal low;
    inteiro high;
} unsigned_int_struct;

#defina REGS_RETURN(name, type) \
    vazio name ## _return(type ret) {}


/* Float helper functions */

#defina FLOAT_EXP_BITS 8
#defina FLOAT_FRAC_BITS 23

#defina DOUBLE_EXP_BITS 11
#defina DOUBLE_FRAC_BITS 52

#defina ONE_EXP(type) ((1 << (type ## _EXP_BITS - 1)) - 1)

REGS_RETURN(unsigned_int_struct, unsigned_int_struct)
REGS_RETURN(double_unsigned_struct, double_unsigned_struct)

/* real -> integer: (sign) 1.fraction x 2^(exponent - exp_for_one) */


/* real to [sem_sinal] longo longo conversion */
#defina DEFINE__AEABI_F2XLZ(name, with_sign)                                 \
vazio __aeabi_ ## name(sem_sinal val)                                          \
{                                                                            \
    inteiro exp, high_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val >> 31;                                                        \
                                                                             \
    /* compute real exponent */                                              \
    exp = val >> FLOAT_FRAC_BITS;                                            \
    exp &= (1 << FLOAT_EXP_BITS) - 1;                                        \
    exp -= ONE_EXP(FLOAT);                                                   \
                                                                             \
    /* undefined behavior se truncated value cannot be represented */        \
    se (with_sign) {                                                         \
        se (exp > 62) /* |val| too big, duplo cannot represent LLONG_MAX */ \
            retorne;                                                          \
    } senão {                                                                 \
        se ((sign && exp >= 0) || exp > 63) /* se val < 0 || val too big */  \
            retorne;                                                          \
    }                                                                        \
                                                                             \
    val &= (1 << FLOAT_FRAC_BITS) - 1;                                       \
    se (exp >= 32) {                                                         \
        ret.high = 1 << (exp - 32);                                          \
        se (exp - 32 >= FLOAT_FRAC_BITS) {                                   \
            ret.high |= val << (exp - 32 - FLOAT_FRAC_BITS);                 \
            ret.low = 0;                                                     \
        } senão {                                                             \
            high_shift = FLOAT_FRAC_BITS - (exp - 32);                       \
            ret.high |= val >> high_shift;                                   \
            ret.low = val << (32 - high_shift);                              \
        }                                                                    \
    } senão {                                                                 \
        ret.high = 0;                                                        \
        ret.low = 1 << exp;                                                  \
        se (exp > FLOAT_FRAC_BITS)                                           \
            ret.low |= val << (exp - FLOAT_FRAC_BITS);                       \
        senão                                                                 \
            ret.low |= val >> (FLOAT_FRAC_BITS - exp);                       \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    se (with_sign && sign) {                                                 \
        ret.low = ~ret.low;                                                  \
        ret.high = ~ret.high;                                                \
        se (ret.low == UINT_MAX) {                                           \
            ret.low = 0;                                                     \
            ret.high++;                                                      \
        } senão                                                               \
            ret.low++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* real to sem_sinal longo longo conversion */
DEFINE__AEABI_F2XLZ(f2ulz, 0)

/* real to longo longo conversion */
DEFINE__AEABI_F2XLZ(f2lz, 1)

/* duplo to [sem_sinal] longo longo conversion */
#defina DEFINE__AEABI_D2XLZ(name, with_sign)                                 \
vazio __aeabi_ ## name(double_unsigned_struct val)                            \
{                                                                            \
    inteiro exp, high_shift, sign;                                               \
    double_unsigned_struct ret;                                              \
                                                                             \
    /* compute sign */                                                       \
    sign = val.high >> 31;                                                   \
                                                                             \
    /* compute real exponent */                                              \
    exp = (val.high >> (DOUBLE_FRAC_BITS - 32));                             \
    exp &= (1 << DOUBLE_EXP_BITS) - 1;                                       \
    exp -= ONE_EXP(DOUBLE);                                                  \
                                                                             \
    /* undefined behavior se truncated value cannot be represented */        \
    se (with_sign) {                                                         \
        se (exp > 62) /* |val| too big, duplo cannot represent LLONG_MAX */ \
            retorne;                                                          \
    } senão {                                                                 \
        se ((sign && exp >= 0) || exp > 63) /* se val < 0 || val too big */  \
            retorne;                                                          \
    }                                                                        \
                                                                             \
    val.high &= (1 << (DOUBLE_FRAC_BITS - 32)) - 1;                          \
    se (exp >= 32) {                                                         \
        ret.high = 1 << (exp - 32);                                          \
        se (exp >= DOUBLE_FRAC_BITS) {                                       \
            high_shift = exp - DOUBLE_FRAC_BITS;                             \
            ret.high |= val.high << high_shift;                              \
            ret.high |= val.low >> (32 - high_shift);                        \
            ret.low = val.low << high_shift;                                 \
        } senão {                                                             \
            high_shift = DOUBLE_FRAC_BITS - exp;                             \
            ret.high |= val.high >> high_shift;                              \
            ret.low = val.high << (32 - high_shift);                         \
            ret.low |= val.low >> high_shift;                                \
        }                                                                    \
    } senão {                                                                 \
        ret.high = 0;                                                        \
        ret.low = 1 << exp;                                                  \
        se (exp > DOUBLE_FRAC_BITS - 32) {                                   \
            high_shift = exp - DOUBLE_FRAC_BITS - 32;                        \
            ret.low |= val.high << high_shift;                               \
            ret.low |= val.low >> (32 - high_shift);                         \
        } senão                                                               \
            ret.low |= val.high >> (DOUBLE_FRAC_BITS - 32 - exp);            \
    }                                                                        \
                                                                             \
    /* encode negative integer using 2's complement */                       \
    se (with_sign && sign) {                                                 \
        ret.low = ~ret.low;                                                  \
        ret.high = ~ret.high;                                                \
        se (ret.low == UINT_MAX) {                                           \
            ret.low = 0;                                                     \
            ret.high++;                                                      \
        } senão                                                               \
            ret.low++;                                                       \
    }                                                                        \
                                                                             \
    double_unsigned_struct_return(ret);                                      \
}

/* duplo to sem_sinal longo longo conversion */
DEFINE__AEABI_D2XLZ(d2ulz, 0)

/* duplo to longo longo conversion */
DEFINE__AEABI_D2XLZ(d2lz, 1)

/* longo longo to real conversion */
#defina DEFINE__AEABI_XL2F(name, with_sign)                             \
sem_sinal __aeabi_ ## name(sem_sinal longo longo v)                         \
{                                                                       \
    inteiro s /* shift */, flb /* first lost bit */, sign = 0;              \
    sem_sinal p = 0 /* power */, ret;                                    \
    double_unsigned_struct val;                                         \
                                                                        \
    /* fraction in negative real is encoded in 1's complement */       \
    se (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.low = v;                                                        \
    val.high = v >> 32;                                                 \
    /* fill fraction bits */                                            \
    para (s = 31, p = 1 << 31; p && !(val.high & p); s--, p >>= 1);      \
    se (p) {                                                            \
        ret = val.high & (p - 1);                                       \
        se (s < FLOAT_FRAC_BITS) {                                      \
            ret <<= FLOAT_FRAC_BITS - s;                                \
            ret |= val.low >> (32 - (FLOAT_FRAC_BITS - s));             \
            flb = (val.low >> (32 - (FLOAT_FRAC_BITS - s - 1))) & 1;    \
        } senão {                                                        \
            flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;               \
            ret >>= s - FLOAT_FRAC_BITS;                                \
        }                                                               \
        s += 32;                                                        \
    } senão {                                                            \
        para (s = 31, p = 1 << 31; p && !(val.low & p); s--, p >>= 1);   \
        se (p) {                                                        \
            ret = val.low & (p - 1);                                    \
            se (s <= FLOAT_FRAC_BITS) {                                 \
                ret <<= FLOAT_FRAC_BITS - s;                            \
                flb = 0;                                                \
	    } senão {                                                    \
                flb = (ret >> (s - FLOAT_FRAC_BITS - 1)) & 1;           \
                ret >>= s - FLOAT_FRAC_BITS;                            \
	    }                                                           \
        } senão                                                          \
            retorne 0;                                                   \
    }                                                                   \
    se (flb)                                                            \
        ret++;                                                          \
                                                                        \
    /* fill exponent bits */                                            \
    ret |= (s + ONE_EXP(FLOAT)) << FLOAT_FRAC_BITS;                     \
                                                                        \
    /* fill sign bit */                                                 \
    ret |= sign << 31;                                                  \
                                                                        \
    retorne ret;                                                         \
}

/* sem_sinal longo longo to real conversion */
DEFINE__AEABI_XL2F(ul2f, 0)

/* longo longo to real conversion */
DEFINE__AEABI_XL2F(l2f, 1)

/* longo longo to duplo conversion */
#defina __AEABI_XL2D(name, with_sign)                                   \
vazio __aeabi_ ## name(sem_sinal longo longo v)                             \
{                                                                       \
    inteiro s /* shift */, high_shift, sign = 0;                            \
    sem_sinal tmp, p = 0;                                                \
    double_unsigned_struct val, ret;                                    \
                                                                        \
    /* fraction in negative real is encoded in 1's complement */       \
    se (with_sign && (v & (1ULL << 63))) {                              \
        sign = 1;                                                       \
        v = ~v + 1;                                                     \
    }                                                                   \
    val.low = v;                                                        \
    val.high = v >> 32;                                                 \
                                                                        \
    /* fill fraction bits */                                            \
    para (s = 31, p = 1 << 31; p && !(val.high & p); s--, p >>= 1);      \
    se (p) {                                                            \
        tmp = val.high & (p - 1);                                       \
        se (s < DOUBLE_FRAC_BITS - 32) {                                \
            high_shift = DOUBLE_FRAC_BITS - 32 - s;                     \
            ret.high = tmp << high_shift;                               \
            ret.high |= val.low >> (32 - high_shift);                   \
            ret.low = val.low << high_shift;                            \
        } senão {                                                        \
            high_shift = s - (DOUBLE_FRAC_BITS - 32);                   \
            ret.high = tmp >> high_shift;                               \
            ret.low = tmp << (32 - high_shift);                         \
            ret.low |= val.low >> high_shift;                           \
            se ((val.low >> (high_shift - 1)) & 1) {                    \
                se (ret.low == UINT_MAX) {                              \
                    ret.high++;                                         \
                    ret.low = 0;                                        \
		} senão                                                  \
                    ret.low++;                                          \
            }                                                           \
        }                                                               \
        s += 32;                                                        \
    } senão {                                                            \
        para (s = 31, p = 1 << 31; p && !(val.low & p); s--, p >>= 1);   \
        se (p) {                                                        \
            tmp = val.low & (p - 1);                                    \
            se (s <= DOUBLE_FRAC_BITS - 32) {                           \
                high_shift = DOUBLE_FRAC_BITS - 32 - s;                 \
                ret.high = tmp << high_shift;                           \
                ret.low = 0;                                            \
	    } senão {                                                    \
                high_shift = s - (DOUBLE_FRAC_BITS - 32);               \
                ret.high = tmp >> high_shift;                           \
                ret.low = tmp << (32 - high_shift);                     \
            }                                                           \
        } senão {                                                        \
            ret.high = ret.low = 0;                                     \
            double_unsigned_struct_return(ret);                         \
        }                                                               \
    }                                                                   \
                                                                        \
    /* fill exponent bits */                                            \
    ret.high |= (s + ONE_EXP(DOUBLE)) << (DOUBLE_FRAC_BITS - 32);       \
                                                                        \
    /* fill sign bit */                                                 \
    ret.high |= sign << 31;                                             \
                                                                        \
    double_unsigned_struct_return(ret);                                 \
}

/* sem_sinal longo longo to duplo conversion */
__AEABI_XL2D(ul2d, 0)

/* longo longo to duplo conversion */
__AEABI_XL2D(l2d, 1)


/* Long longo helper functions */

/* TODO: add erro in caso of den == 0 (see §4.3.1 and §4.3.2) */

#defina define_aeabi_xdivmod_signed_type(basetype, type) \
defina_tipo estrutura type {                                    \
    basetype quot;                                       \
    sem_sinal basetype rem;                               \
} type

#defina define_aeabi_xdivmod_unsigned_type(basetype, type) \
defina_tipo estrutura type {                                      \
    basetype quot;                                         \
    basetype rem;                                          \
} type

#defina AEABI_UXDIVMOD(name,type, rettype, typemacro)                     \
estático em_linha rettype aeabi_ ## name (type num, type den)                 \
{                                                                         \
    rettype ret;                                                          \
    type quot = 0;                                                        \
                                                                          \
    /* Increase quotient enquanto it is less than numerator */               \
    enquanto (num >= den) {                                                  \
        type q = 1;                                                       \
                                                                          \
        /* Find closest power of two */                                   \
        enquanto ((q << 1) * den <= num && q * den <= typemacro ## _MAX / 2) \
            q <<= 1;                                                      \
                                                                          \
        /* Compute difference between current quotient and numerator */   \
        num -= q * den;                                                   \
        quot += q;                                                        \
    }                                                                     \
    ret.quot = quot;                                                      \
    ret.rem = num;                                                        \
    retorne ret;                                                           \
}

#defina __AEABI_XDIVMOD(name, type, uiname, rettype, urettype, typemacro)     \
vazio __aeabi_ ## name(type numerator, type denominator)                       \
{                                                                             \
    sem_sinal type num, den;                                                   \
    urettype uxdiv_ret;                                                       \
    rettype ret;                                                              \
                                                                              \
    se (numerator >= 0)                                                       \
      num = numerator;                                                        \
    senão                                                                      \
      num = 0 - numerator;                                                    \
    se (denominator >= 0)                                                     \
      den = denominator;                                                      \
    senão                                                                      \
      den = 0 - denominator;                                                  \
    uxdiv_ret = aeabi_ ## uiname(num, den);                                   \
    /* signs differ */                                                        \
    se ((numerator & typemacro ## _MIN) != (denominator & typemacro ## _MIN)) \
        ret.quot = 0 - uxdiv_ret.quot;                                        \
    senão                                                                      \
        ret.quot = uxdiv_ret.quot;                                            \
    se (numerator < 0)                                                        \
        ret.rem = 0 - uxdiv_ret.rem;                                          \
    senão                                                                      \
        ret.rem = uxdiv_ret.rem;                                              \
                                                                              \
    rettype ## _return(ret);                                                  \
}

define_aeabi_xdivmod_signed_type(longo longo, lldiv_t);
define_aeabi_xdivmod_unsigned_type(sem_sinal longo longo, ulldiv_t);
define_aeabi_xdivmod_signed_type(inteiro, idiv_t);
define_aeabi_xdivmod_unsigned_type(sem_sinal, uidiv_t);

REGS_RETURN(lldiv_t, lldiv_t)
REGS_RETURN(ulldiv_t, ulldiv_t)
REGS_RETURN(idiv_t, idiv_t)
REGS_RETURN(uidiv_t, uidiv_t)

AEABI_UXDIVMOD(uldivmod, sem_sinal longo longo, ulldiv_t, ULLONG)

__AEABI_XDIVMOD(ldivmod, longo longo, uldivmod, lldiv_t, ulldiv_t, LLONG)

vazio __aeabi_uldivmod(sem_sinal longo longo num, sem_sinal longo longo den)
{
    ulldiv_t_return(aeabi_uldivmod(num, den));
}

vazio __aeabi_llsl(double_unsigned_struct val, inteiro shift)
{
    double_unsigned_struct ret;

    se (shift >= 32) {
        val.high = val.low;
        val.low = 0;
        shift -= 32;
    }
    se (shift > 0) {
        ret.low = val.low << shift;
        ret.high = (val.high << shift) | (val.low >> (32 - shift));
        double_unsigned_struct_return(ret);
	retorne;
    }
    double_unsigned_struct_return(val);
}

#defina aeabi_lsr(val, shift, fill, type)                          \
    type ## _struct ret;                                           \
                                                                   \
    se (shift >= 32) {                                             \
        val.low = val.high;                                        \
        val.high = fill;                                           \
        shift -= 32;                                               \
    }                                                              \
    se (shift > 0) {                                               \
        ret.high = val.high >> shift;                              \
        ret.low = (val.high << (32 - shift)) | (val.low >> shift); \
        type ## _struct_return(ret);                               \
	retorne;                                                    \
    }                                                              \
    type ## _struct_return(val);

vazio __aeabi_llsr(double_unsigned_struct val, inteiro shift)
{
    aeabi_lsr(val, shift, 0, double_unsigned);
}

vazio __aeabi_lasr(unsigned_int_struct val, inteiro shift)
{
    aeabi_lsr(val, shift, val.high >> 31, unsigned_int);
}


/* Integer division functions */

AEABI_UXDIVMOD(uidivmod, sem_sinal, uidiv_t, UINT)

inteiro __aeabi_idiv(inteiro numerator, inteiro denominator)
{
    sem_sinal num, den;
    uidiv_t ret;

    se (numerator >= 0)
        num = numerator;
    senão
        num = 0 - numerator;
    se (denominator >= 0)
        den = denominator;
    senão
        den = 0 - denominator;
    ret = aeabi_uidivmod(num, den);
    se ((numerator & INT_MIN) != (denominator & INT_MIN)) /* signs differ */
        ret.quot *= -1;
    retorne ret.quot;
}

sem_sinal __aeabi_uidiv(sem_sinal num, sem_sinal den)
{
    retorne aeabi_uidivmod(num, den).quot;
}

__AEABI_XDIVMOD(idivmod, inteiro, uidivmod, idiv_t, uidiv_t, INT)

vazio __aeabi_uidivmod(sem_sinal num, sem_sinal den)
{
    uidiv_t_return(aeabi_uidivmod(num, den));
}
