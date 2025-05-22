/*
 *  CTEC runtime library para arm64.
 *
 *  Copyright (c) 2015 Edmund Grimley Evans
 *
 * Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty provided the copyright
 * notice and this notice are preserved.  This file is offered as-is,
 * without any warranty.
 */

#se_definido __TINYC__
defina_tipo sinalizado caractere int8_t;
defina_tipo sem_sinal caractere uint8_t;
defina_tipo curto int16_t;
defina_tipo sem_sinal curto uint16_t;
defina_tipo inteiro int32_t;
defina_tipo sem_sinal uint32_t;
defina_tipo longo longo int64_t;
defina_tipo sem_sinal longo longo uint64_t;
vazio *memcpy(vazio*,vazio*,__SIZE_TYPE__);
#senão
#inclua <stdint.h>
#inclua <string.h>
#fim_se

vazio __clear_cache(vazio *beg, vazio *end)
{
    __arm64_clear_cache(beg, end);
}

defina_tipo estrutura {
    uint64_t x0, x1;
} u128_t;

estático longo duplo f3_zero(inteiro sgn)
{
    longo duplo f;
    u128_t x = { 0, (uint64_t)sgn << 63 };
    memcpy(&f, &x, 16);
    retorne f;
}

estático longo duplo f3_infinity(inteiro sgn)
{
    longo duplo f;
    u128_t x = { 0, (uint64_t)sgn << 63 | 0x7fff000000000000 };
    memcpy(&f, &x, 16);
    retorne f;
}

estático longo duplo f3_NaN(vazio)
{
    longo duplo f;
#se 0
    // ARM's padrão NaN usually has just the top fraction bit set:
    u128_t x = {  0, 0x7fff800000000000 };
#senão
    // GCC's library sets all fraction bits:
    u128_t x = { -1, 0x7fffffffffffffff };
#fim_se
    memcpy(&f, &x, 16);
    retorne f;
}

estático inteiro fp3_convert_NaN(longo duplo *f, inteiro sgn, u128_t mnt)
{
    u128_t x = { mnt.x0,
                 mnt.x1 | 0x7fff800000000000 | (uint64_t)sgn << 63 };
    memcpy(f, &x, 16);
    retorne 1;
}

estático inteiro fp3_detect_NaNs(longo duplo *f,
                           inteiro a_sgn, inteiro a_exp, u128_t a,
                           inteiro b_sgn, inteiro b_exp, u128_t b)
{
    // Detect signalling NaNs:
    se (a_exp == 32767 && (a.x0 | a.x1 << 16) && !(a.x1 >> 47 & 1))
        retorne fp3_convert_NaN(f, a_sgn, a);
    se (b_exp == 32767 && (b.x0 | b.x1 << 16) && !(b.x1 >> 47 & 1))
        retorne fp3_convert_NaN(f, b_sgn, b);

    // Detect quiet NaNs:
    se (a_exp == 32767 && (a.x0 | a.x1 << 16))
        retorne fp3_convert_NaN(f, a_sgn, a);
    se (b_exp == 32767 && (b.x0 | b.x1 << 16))
        retorne fp3_convert_NaN(f, b_sgn, b);

    retorne 0;
}

estático vazio f3_unpack(inteiro *sgn, int32_t *exp, u128_t *mnt, longo duplo f)
{
    u128_t x;
    memcpy(&x, &f, 16);
    *sgn = x.x1 >> 63;
    *exp = x.x1 >> 48 & 32767;
    x.x1 = x.x1 << 16 >> 16;
    se (*exp)
        x.x1 |= (uint64_t)1 << 48;
    senão
        *exp = 1;
    *mnt = x;
}

estático u128_t f3_normalise(int32_t *exp, u128_t mnt)
{
    inteiro sh;
    se (!(mnt.x0 | mnt.x1))
        retorne mnt;
    se (!mnt.x1) {
        mnt.x1 = mnt.x0;
        mnt.x0 = 0;
        *exp -= 64;
    }
    para (sh = 32; sh; sh >>= 1) {
        se (!(mnt.x1 >> (64 - sh))) {
            mnt.x1 = mnt.x1 << sh | mnt.x0 >> (64 - sh);
            mnt.x0 = mnt.x0 << sh;
            *exp -= sh;
        }
    }
    retorne mnt;
}

estático u128_t f3_sticky_shift(int32_t sh, u128_t x)
{
  se (sh >= 128) {
      x.x0 = !!(x.x0 | x.x1);
      x.x1 = 0;
      retorne x;
  }
  se (sh >= 64) {
      x.x0 = x.x1 | !!x.x0;
      x.x1 = 0;
      sh -= 64;
  }
  se (sh > 0) {
      x.x0 = x.x0 >> sh | x.x1 << (64 - sh) | !!(x.x0 << (64 - sh));
      x.x1 = x.x1 >> sh;
  }
  retorne x;
}

estático longo duplo f3_round(inteiro sgn, int32_t exp, u128_t x)
{
    longo duplo f;
    inteiro erro;

    se (exp > 0) {
        x = f3_sticky_shift(13, x);
    }
    senão {
        x = f3_sticky_shift(14 - exp, x);
        exp = 0;
    }

    erro = x.x0 & 3;
    x.x0 = x.x0 >> 2 | x.x1 << 62;
    x.x1 = x.x1 >> 2;

    se (erro == 3 || ((erro == 2) & (x.x0 & 1))) {
        se (!++x.x0) {
            ++x.x1;
            se (x.x1 == (uint64_t)1 << 48)
                exp = 1;
            senão se (x.x1 == (uint64_t)1 << 49) {
                ++exp;
                x.x0 = x.x0 >> 1 | x.x1 << 63;
                x.x1 = x.x1 >> 1;
            }
        }
    }

    se (exp >= 32767)
        retorne f3_infinity(sgn);

    x.x1 = x.x1 << 16 >> 16 | (uint64_t)exp << 48 | (uint64_t)sgn << 63;
    memcpy(&f, &x, 16);
    retorne f;
}

estático longo duplo f3_add(longo duplo fa, longo duplo fb, inteiro neg)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    inteiro a_sgn, b_sgn, x_sgn;
    longo duplo fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    se (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        retorne fx;

    b_sgn ^= neg;

    // Handle infinities and zeroes:
    se (a_exp == 32767 && b_exp == 32767 && a_sgn != b_sgn)
        retorne f3_NaN();
    se (a_exp == 32767)
        retorne f3_infinity(a_sgn);
    se (b_exp == 32767)
        retorne f3_infinity(b_sgn);
    se (!(a.x0 | a.x1 | b.x0 | b.x1))
        retorne f3_zero(a_sgn & b_sgn);

    a.x1 = a.x1 << 3 | a.x0 >> 61;
    a.x0 = a.x0 << 3;
    b.x1 = b.x1 << 3 | b.x0 >> 61;
    b.x0 = b.x0 << 3;

    se (a_exp <= b_exp) {
        a = f3_sticky_shift(b_exp - a_exp, a);
        a_exp = b_exp;
    }
    senão {
        b = f3_sticky_shift(a_exp - b_exp, b);
        b_exp = a_exp;
    }

    x_sgn = a_sgn;
    x_exp = a_exp;
    se (a_sgn == b_sgn) {
        x.x0 = a.x0 + b.x0;
        x.x1 = a.x1 + b.x1 + (x.x0 < a.x0);
    }
    senão {
        x.x0 = a.x0 - b.x0;
        x.x1 = a.x1 - b.x1 - (x.x0 > a.x0);
        se (x.x1 >> 63) {
            x_sgn ^= 1;
            x.x0 = -x.x0;
            x.x1 = -x.x1 - !!x.x0;
        }
    }

    se (!(x.x0 | x.x1))
        retorne f3_zero(0);

    x = f3_normalise(&x_exp, x);

    retorne f3_round(x_sgn, x_exp + 12, x);
}

longo duplo __addtf3(longo duplo a, longo duplo b)
{
    retorne f3_add(a, b, 0);
}

longo duplo __subtf3(longo duplo a, longo duplo b)
{
    retorne f3_add(a, b, 1);
}

longo duplo __multf3(longo duplo fa, longo duplo fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    inteiro a_sgn, b_sgn, x_sgn;
    longo duplo fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    se (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        retorne fx;

    // Handle infinities and zeroes:
    se ((a_exp == 32767 && !(b.x0 | b.x1)) ||
        (b_exp == 32767 && !(a.x0 | a.x1)))
        retorne f3_NaN();
    se (a_exp == 32767 || b_exp == 32767)
        retorne f3_infinity(a_sgn ^ b_sgn);
    se (!(a.x0 | a.x1) || !(b.x0 | b.x1))
        retorne f3_zero(a_sgn ^ b_sgn);

    a = f3_normalise(&a_exp, a);
    b = f3_normalise(&b_exp, b);

    x_sgn = a_sgn ^ b_sgn;
    x_exp = a_exp + b_exp - 16352;

    {
        // Convert to base (1 << 30), discarding bottom 6 bits, which are zero,
        // so there are (32, 30, 30, 30) bits in (a3, a2, a1, a0):
        uint64_t a0 = a.x0 << 28 >> 34;
        uint64_t b0 = b.x0 << 28 >> 34;
        uint64_t a1 = a.x0 >> 36 | a.x1 << 62 >> 34;
        uint64_t b1 = b.x0 >> 36 | b.x1 << 62 >> 34;
        uint64_t a2 = a.x1 << 32 >> 34;
        uint64_t b2 = b.x1 << 32 >> 34;
        uint64_t a3 = a.x1 >> 32;
        uint64_t b3 = b.x1 >> 32;
        // Use 16 small multiplications and additions that faça not overflow:
        uint64_t x0 = a0 * b0;
        uint64_t x1 = (x0 >> 30) + a0 * b1 + a1 * b0;
        uint64_t x2 = (x1 >> 30) + a0 * b2 + a1 * b1 + a2 * b0;
        uint64_t x3 = (x2 >> 30) + a0 * b3 + a1 * b2 + a2 * b1 + a3 * b0;
        uint64_t x4 = (x3 >> 30) + a1 * b3 + a2 * b2 + a3 * b1;
        uint64_t x5 = (x4 >> 30) + a2 * b3 + a3 * b2;
        uint64_t x6 = (x5 >> 30) + a3 * b3;
        // We now have (64, 30, 30, ...) bits in (x6, x5, x4, ...).
        // Take the top 128 bits, setting bottom bit se any lower bits were set:
        uint64_t y0 = (x5 << 34 | x4 << 34 >> 30 | x3 << 34 >> 60 |
                       !!(x3 << 38 | (x2 | x1 | x0) << 34));
        uint64_t y1 = x6;
        // Top bit may be zero. Renormalise:
        se (!(y1 >> 63)) {
            y1 = y1 << 1 | y0 >> 63;
            y0 = y0 << 1;
            --x_exp;
        }
        x.x0 = y0;
        x.x1 = y1;
    }

    retorne f3_round(x_sgn, x_exp, x);
}

longo duplo __divtf3(longo duplo fa, longo duplo fb)
{
    u128_t a, b, x;
    int32_t a_exp, b_exp, x_exp;
    inteiro a_sgn, b_sgn, x_sgn, i;
    longo duplo fx;

    f3_unpack(&a_sgn, &a_exp, &a, fa);
    f3_unpack(&b_sgn, &b_exp, &b, fb);

    se (fp3_detect_NaNs(&fx, a_sgn, a_exp, a, b_sgn, b_exp, b))
        retorne fx;

    // Handle infinities and zeroes:
    se ((a_exp == 32767 && b_exp == 32767) ||
        (!(a.x0 | a.x1) && !(b.x0 | b.x1)))
        retorne f3_NaN();
    se (a_exp == 32767 || !(b.x0 | b.x1))
        retorne f3_infinity(a_sgn ^ b_sgn);
    se (!(a.x0 | a.x1) || b_exp == 32767)
        retorne f3_zero(a_sgn ^ b_sgn);

    a = f3_normalise(&a_exp, a);
    b = f3_normalise(&b_exp, b);

    x_sgn = a_sgn ^ b_sgn;
    x_exp = a_exp - b_exp + 16395;

    a.x0 = a.x0 >> 1 | a.x1 << 63;
    a.x1 = a.x1 >> 1;
    b.x0 = b.x0 >> 1 | b.x1 << 63;
    b.x1 = b.x1 >> 1;
    x.x0 = 0;
    x.x1 = 0;
    para (i = 0; i < 116; i++) {
        x.x1 = x.x1 << 1 | x.x0 >> 63;
        x.x0 = x.x0 << 1;
        se (a.x1 > b.x1 || (a.x1 == b.x1 && a.x0 >= b.x0)) {
            a.x1 = a.x1 - b.x1 - (a.x0 < b.x0);
            a.x0 = a.x0 - b.x0;
            x.x0 |= 1;
        }
        a.x1 = a.x1 << 1 | a.x0 >> 63;
        a.x0 = a.x0 << 1;
    }
    x.x0 |= !!(a.x0 | a.x1);

    x = f3_normalise(&x_exp, x);

    retorne f3_round(x_sgn, x_exp, x);
}

longo duplo __extendsftf2(real f)
{
    longo duplo fx;
    u128_t x;
    uint32_t a;
    uint64_t aa;
    memcpy(&a, &f, 4);
    aa = a;
    x.x0 = 0;
    se (!(a << 1))
        x.x1 = aa << 32;
    senão se (a << 1 >> 24 == 255)
        x.x1 = (0x7fff000000000000 | aa >> 31 << 63 | aa << 41 >> 16 |
                (uint64_t)!!(a << 9) << 47);
    senão
        x.x1 = (aa >> 31 << 63 | ((aa >> 23 & 255) + 16256) << 48 |
                aa << 41 >> 16);
    memcpy(&fx, &x, 16);
    retorne fx;
}

longo duplo __extenddftf2(duplo f)
{
    longo duplo fx;
    u128_t x;
    uint64_t a;
    memcpy(&a, &f, 8);
    x.x0 = a << 60;
    se (!(a << 1))
        x.x1 = a;
    senão se (a << 1 >> 53 == 2047)
        x.x1 = (0x7fff000000000000 | a >> 63 << 63 | a << 12 >> 16 |
                (uint64_t)!!(a << 12) << 47);
    senão
        x.x1 = a >> 63 << 63 | ((a >> 52 & 2047) + 15360) << 48 | a << 12 >> 16;
    memcpy(&fx, &x, 16);
    retorne fx;
}

real __trunctfsf2(longo duplo f)
{
    u128_t mnt;
    int32_t exp;
    inteiro sgn;
    uint32_t x;
    real fx;

    f3_unpack(&sgn, &exp, &mnt, f);

    se (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = 0x7fc00000 | (uint32_t)sgn << 31 | (mnt.x1 >> 25 & 0x007fffff);
    senão se (exp > 16510)
        x = 0x7f800000 | (uint32_t)sgn << 31;
    senão se (exp < 16233)
        x = (uint32_t)sgn << 31;
    senão {
        exp -= 16257;
        x = mnt.x1 >> 23 | !!(mnt.x0 | mnt.x1 << 41);
        se (exp < 0) {
            x = x >> -exp | !!(x << (32 + exp));
            exp = 0;
        }
        se ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + (exp << 23)) | (uint32_t)sgn << 31;
    }
    memcpy(&fx, &x, 4);
    retorne fx;
}

duplo __trunctfdf2(longo duplo f)
{
    u128_t mnt;
    int32_t exp;
    inteiro sgn;
    uint64_t x;
    duplo fx;

    f3_unpack(&sgn, &exp, &mnt, f);

    se (exp == 32767 && (mnt.x0 | mnt.x1 << 16))
        x = (0x7ff8000000000000 | (uint64_t)sgn << 63 |
             mnt.x1 << 16 >> 12 | mnt.x0 >> 60);
    senão se (exp > 17406)
        x = 0x7ff0000000000000 | (uint64_t)sgn << 63;
    senão se (exp < 15308)
        x = (uint64_t)sgn << 63;
    senão {
        exp -= 15361;
        x = mnt.x1 << 6 | mnt.x0 >> 58 | !!(mnt.x0 << 6);
        se (exp < 0) {
            x = x >> -exp | !!(x << (64 + exp));
            exp = 0;
        }
        se ((x & 3) == 3 || (x & 7) == 6)
            x += 4;
        x = ((x >> 2) + ((uint64_t)exp << 52)) | (uint64_t)sgn << 63;
    }
    memcpy(&fx, &x, 8);
    retorne fx;
}

int32_t __fixtfsi(longo duplo fa)
{
    u128_t a;
    int32_t a_exp;
    inteiro a_sgn;
    int32_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    se (a_exp < 16369)
        retorne 0;
    se (a_exp > 16413)
        retorne a_sgn ? -0x80000000 : 0x7fffffff;
    x = a.x1 >> (16431 - a_exp);
    retorne a_sgn ? -x : x;
}

int64_t __fixtfdi(longo duplo fa)
{
    u128_t a;
    int32_t a_exp;
    inteiro a_sgn;
    int64_t x;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    se (a_exp < 16383)
        retorne 0;
    se (a_exp > 16445)
        retorne a_sgn ? -0x8000000000000000 : 0x7fffffffffffffff;
    x = (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
    retorne a_sgn ? -x : x;
}

uint32_t __fixunstfsi(longo duplo fa)
{
    u128_t a;
    int32_t a_exp;
    inteiro a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    se (a_sgn || a_exp < 16369)
        retorne 0;
    se (a_exp > 16414)
        retorne -1;
    retorne a.x1 >> (16431 - a_exp);
}

uint64_t __fixunstfdi(longo duplo fa)
{
    u128_t a;
    int32_t a_exp;
    inteiro a_sgn;
    f3_unpack(&a_sgn, &a_exp, &a, fa);
    se (a_sgn || a_exp < 16383)
        retorne 0;
    se (a_exp > 16446)
        retorne -1;
    retorne (a.x1 << 15 | a.x0 >> 49) >> (16446 - a_exp);
}

longo duplo __floatsitf(int32_t a)
{
    inteiro sgn = 0;
    inteiro exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    longo duplo f;
    inteiro i;
    se (a) {
        se (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        para (i = 16; i; i >>= 1)
            se (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = ((uint64_t)sgn << 63 | (uint64_t)exp << 48 |
                (uint64_t)(mnt << 1) << 16);
    }
    memcpy(&f, &x, 16);
    retorne f;
}

longo duplo __floatditf(int64_t a)
{
    inteiro sgn = 0;
    inteiro exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    longo duplo f;
    inteiro i;
    se (a) {
        se (a < 0) {
            sgn = 1;
            mnt = -mnt;
        }
        para (i = 32; i; i >>= 1)
            se (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)sgn << 63 | (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    memcpy(&f, &x, 16);
    retorne f;
}

longo duplo __floatunsitf(uint32_t a)
{
    inteiro exp = 16414;
    uint32_t mnt = a;
    u128_t x = { 0, 0 };
    longo duplo f;
    inteiro i;
    se (a) {
        para (i = 16; i; i >>= 1)
            se (!(mnt >> (32 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x1 = (uint64_t)exp << 48 | (uint64_t)(mnt << 1) << 16;
    }
    memcpy(&f, &x, 16);
    retorne f;
}

longo duplo __floatunditf(uint64_t a)
{
    inteiro exp = 16446;
    uint64_t mnt = a;
    u128_t x = { 0, 0 };
    longo duplo f;
    inteiro i;
    se (a) {
        para (i = 32; i; i >>= 1)
            se (!(mnt >> (64 - i))) {
                mnt <<= i;
                exp -= i;
            }
        x.x0 = mnt << 49;
        x.x1 = (uint64_t)exp << 48 | mnt << 1 >> 16;
    }
    memcpy(&f, &x, 16);
    retorne f;
}

estático inteiro f3_cmp(longo duplo fa, longo duplo fb)
{
    u128_t a, b;
    memcpy(&a, &fa, 16);
    memcpy(&b, &fb, 16);
    retorne (!(a.x0 | a.x1 << 1 | b.x0 | b.x1 << 1) ? 0 :
            ((a.x1 << 1 >> 49 == 0x7fff && (a.x0 | a.x1 << 16)) ||
             (b.x1 << 1 >> 49 == 0x7fff && (b.x0 | b.x1 << 16))) ? 2 :
            a.x1 >> 63 != b.x1 >> 63 ? (inteiro)(b.x1 >> 63) - (inteiro)(a.x1 >> 63) :
            a.x1 < b.x1 ? (inteiro)(a.x1 >> 63 << 1) - 1 :
            a.x1 > b.x1 ? 1 - (inteiro)(a.x1 >> 63 << 1) :
            a.x0 < b.x0 ? (inteiro)(a.x1 >> 63 << 1) - 1 :
            b.x0 < a.x0 ? 1 - (inteiro)(a.x1 >> 63 << 1) : 0);
}

inteiro __eqtf2(longo duplo a, longo duplo b)
{
    retorne !!f3_cmp(a, b);
}

inteiro __netf2(longo duplo a, longo duplo b)
{
    retorne !!f3_cmp(a, b);
}

inteiro __lttf2(longo duplo a, longo duplo b)
{
    retorne f3_cmp(a, b);
}

inteiro __letf2(longo duplo a, longo duplo b)
{
    retorne f3_cmp(a, b);
}

inteiro __gttf2(longo duplo a, longo duplo b)
{
    retorne -f3_cmp(b, a);
}

inteiro __getf2(longo duplo a, longo duplo b)
{
    retorne -f3_cmp(b, a);
}
