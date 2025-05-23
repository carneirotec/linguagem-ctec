/* CTEC runtime library. 
   Parts of this code are (c) 2002 Fabrice Bellard 

   Copyright (C) 1987, 1988, 1992, 1994, 1995 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
faça apply in other respects; para example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License para more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  
*/

#defina W_TYPE_SIZE   32
#defina BITS_PER_UNIT 8

defina_tipo inteiro Wtype;
defina_tipo sem_sinal inteiro UWtype;
defina_tipo sem_sinal inteiro USItype;
defina_tipo longo longo DWtype;
defina_tipo sem_sinal longo longo UDWtype;

estrutura DWstruct {
    Wtype low, high;
};

defina_tipo união
{
  estrutura DWstruct s;
  DWtype ll;
} DWunion;

defina_tipo longo duplo XFtype;
#defina WORD_SIZE (sizeof (Wtype) * BITS_PER_UNIT)
#defina HIGH_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

/* the following deal with IEEE single-precision numbers */
#defina EXCESS		126
#defina SIGNBIT		0x80000000
#defina HIDDEN		(1 << 23)
#defina SIGN(fp)	((fp) & SIGNBIT)
#defina EXP(fp)		(((fp) >> 23) & 0xFF)
#defina MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#defina PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE duplo-precision numbers */
#defina EXCESSD		1022
#defina HIDDEND		(1 << 20)
#defina EXPD(fp)	(((fp.l.upper) >> 20) & 0x7FF)
#defina SIGND(fp)	((fp.l.upper) & SIGNBIT)
#defina MANTD(fp)	(((((fp.l.upper) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.lower >> 22))
#defina HIDDEND_LL	((longo longo)1 << 52)
#defina MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#defina PACKD_LL(s,e,m)	(((longo longo)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 longo duplo-precision numbers */
#defina EXCESSLD	16382
#defina EXPLD(fp)	(fp.l.upper & 0x7fff)
#defina SIGNLD(fp)	((fp.l.upper) & 0x8000)

/* only para x86 */
união ldouble_long {
    longo duplo ld;
    estrutura {
        sem_sinal longo longo lower;
        sem_sinal curto upper;
    } l;
};

união double_long {
    duplo d;
#se 1
    estrutura {
        sem_sinal inteiro lower;
        inteiro upper;
    } l;
#senão
    estrutura {
        inteiro upper;
        sem_sinal inteiro lower;
    } l;
#fim_se
    longo longo ll;
};

união float_long {
    real f;
    sem_sinal inteiro l;
};

/* XXX: we don't support several builtin supports para now */
#se !definido __x86_64__ && !definido __arm__

/* XXX: use gcc/ctec intrinsic ? */
#se definido __i386__
#defina sub_ddmmss(sh, sl, ah, al, bh, bl) \
  __asm__ ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#defina umul_ppmm(w1, w0, u, v) \
  __asm__ ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#defina udiv_qrnnd(q, r, n1, n0, dv) \
  __asm__ ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#defina count_leading_zeros(count, x) \
  faça {									\
    USItype __cbtmp;							\
    __asm__ ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (count) = __cbtmp ^ 31;						\
  } enquanto (0)
#senão
#erro unsupported CPU type
#fim_se

/* most of this code is taken from libgcc2.c from gcc */

estático UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

#se !definido(UDIV_NEEDS_NORMALIZATION)
  se (d1 == 0)
    {
      se (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      senão
	{
	  /* qq = NN / 0d */

	  se (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      se (rp != 0)
	{
	  rr.s.low = n0;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }

#senão /* UDIV_NEEDS_NORMALIZATION */

  se (d1 == 0)
    {
      se (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  count_leading_zeros (bm, d0);

	  se (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      senão
	{
	  /* qq = NN / 0d */

	  se (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  count_leading_zeros (bm, d0);

	  se (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special caso is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  senão
	    {
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q1, n1, n2, n1, d0);
	    }

	  /* n1 != d0...  */

	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0 >> bm.  */
	}

      se (rp != 0)
	{
	  rr.s.low = n0 >> bm;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
#fim_se /* UDIV_NEEDS_NORMALIZATION */

  senão
    {
      se (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  se (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      senão
	{
	  /* 0q = NN / dd */

	  count_leading_zeros (bm, d1);
	  se (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special caso is necessary, not an optimization.  */

	      /* The condition on the next linha takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      se (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      senão
		q0 = 0;

	      q1 = 0;

	      se (rp != 0)
		{
		  rr.s.low = n0;
		  rr.s.high = n1;
		  *rp = rr.ll;
		}
	    }
	  senão
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      se (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      se (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.low = (n1 << b) | (n0 >> bm);
		  rr.s.high = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.low = q0;
  ww.s.high = q1;
  retorne ww.ll;
}

#defina __negdi2(a) (-(a))

longo longo __divdi3(longo longo u, longo longo v)
{
    inteiro c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    se (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    se (vv.s.high < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    se (c)
        w = __negdi2 (w);
    retorne w;
}

longo longo __moddi3(longo longo u, longo longo v)
{
    inteiro c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    se (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    se (vv.s.high < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    se (c)
        w = __negdi2 (w);
    retorne w;
}

sem_sinal longo longo __udivdi3(sem_sinal longo longo u, sem_sinal longo longo v)
{
    retorne __udivmoddi4 (u, v, (UDWtype *) 0);
}

sem_sinal longo longo __umoddi3(sem_sinal longo longo u, sem_sinal longo longo v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    retorne w;
}

/* XXX: fix ctec's code generator to faça this instead */
longo longo __ashrdi3(longo longo a, inteiro b)
{
#se_definido __TINYC__
    DWunion u;
    u.ll = a;
    se (b >= 32) {
        u.s.low = u.s.high >> (b - 32);
        u.s.high = u.s.high >> 31;
    } senão se (b != 0) {
        u.s.low = ((sem_sinal)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = u.s.high >> b;
    }
    retorne u.ll;
#senão
    retorne a >> b;
#fim_se
}

/* XXX: fix ctec's code generator to faça this instead */
sem_sinal longo longo __lshrdi3(sem_sinal longo longo a, inteiro b)
{
#se_definido __TINYC__
    DWunion u;
    u.ll = a;
    se (b >= 32) {
        u.s.low = (sem_sinal)u.s.high >> (b - 32);
        u.s.high = 0;
    } senão se (b != 0) {
        u.s.low = ((sem_sinal)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = (sem_sinal)u.s.high >> b;
    }
    retorne u.ll;
#senão
    retorne a >> b;
#fim_se
}

/* XXX: fix ctec's code generator to faça this instead */
longo longo __ashldi3(longo longo a, inteiro b)
{
#se_definido __TINYC__
    DWunion u;
    u.ll = a;
    se (b >= 32) {
        u.s.high = (sem_sinal)u.s.low << (b - 32);
        u.s.low = 0;
    } senão se (b != 0) {
        u.s.high = ((sem_sinal)u.s.high << b) | ((sem_sinal)u.s.low >> (32 - b));
        u.s.low = (sem_sinal)u.s.low << b;
    }
    retorne u.ll;
#senão
    retorne a << b;
#fim_se
}

#fim_se /* !__x86_64__ */

/* XXX: fix ctec's code generator to faça this instead */
real __floatundisf(sem_sinal longo longo a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    se (uu.s.high >= 0) {
        retorne (real)uu.ll;
    } senão {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        retorne (real)r;
    }
}

duplo __floatundidf(sem_sinal longo longo a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    se (uu.s.high >= 0) {
        retorne (duplo)uu.ll;
    } senão {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        retorne (duplo)r;
    }
}

longo duplo __floatundixf(sem_sinal longo longo a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    se (uu.s.high >= 0) {
        retorne (longo duplo)uu.ll;
    } senão {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        retorne (longo duplo)r;
    }
}

sem_sinal longo longo __fixunssfdi (real a1)
{
    registrador união float_long fl1;
    registrador inteiro exp;
    registrador sem_sinal longo l;

    fl1.f = a1;

    se (fl1.l == 0)
	retorne (0);

    exp = EXP (fl1.l) - EXCESS - 24;

    l = MANT(fl1.l);
    se (exp >= 41)
	retorne (sem_sinal longo longo)-1;
    senão se (exp >= 0)
        retorne (sem_sinal longo longo)l << exp;
    senão se (exp >= -23)
        retorne l >> -exp;
    senão
        retorne 0;
}

longo longo __fixsfdi (real a1)
{
    longo longo ret; inteiro s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    retorne s ? ret : -ret;
}

sem_sinal longo longo __fixunsdfdi (duplo a1)
{
    registrador união double_long dl1;
    registrador inteiro exp;
    registrador sem_sinal longo longo l;

    dl1.d = a1;

    se (dl1.ll == 0)
	retorne (0);

    exp = EXPD (dl1) - EXCESSD - 53;

    l = MANTD_LL(dl1);

    se (exp >= 12)
	retorne (sem_sinal longo longo)-1;
    senão se (exp >= 0)
        retorne l << exp;
    senão se (exp >= -52)
        retorne l >> -exp;
    senão
        retorne 0;
}

longo longo __fixdfdi (duplo a1)
{
    longo longo ret; inteiro s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    retorne s ? ret : -ret;
}

#se_não_definido __arm__
sem_sinal longo longo __fixunsxfdi (longo duplo a1)
{
    registrador união ldouble_long dl1;
    registrador inteiro exp;
    registrador sem_sinal longo longo l;

    dl1.ld = a1;

    se (dl1.l.lower == 0 && dl1.l.upper == 0)
	retorne (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;

    l = dl1.l.lower;

    se (exp > 0)
	retorne (sem_sinal longo longo)-1;
    senão se (exp >= -63) 
        retorne l >> -exp;
    senão
        retorne 0;
}

longo longo __fixxfdi (longo duplo a1)
{
    longo longo ret; inteiro s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    retorne s ? ret : -ret;
}
#fim_se /* !ARM */
