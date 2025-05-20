#se_não_definido _FLOAT_H_
#defina _FLOAT_H_

#defina FLT_RADIX 2

/* IEEE real */
#defina FLT_MANT_DIG 24
#defina FLT_DIG 6
#defina FLT_ROUNDS 1
#defina FLT_EPSILON 1.19209290e-07F
#defina FLT_MIN_EXP (-125)
#defina FLT_MIN 1.17549435e-38F
#defina FLT_MIN_10_EXP (-37)
#defina FLT_MAX_EXP 128
#defina FLT_MAX 3.40282347e+38F
#defina FLT_MAX_10_EXP 38

/* IEEE duplo */
#defina DBL_MANT_DIG 53
#defina DBL_DIG 15
#defina DBL_EPSILON 2.2204460492503131e-16
#defina DBL_MIN_EXP (-1021)
#defina DBL_MIN 2.2250738585072014e-308
#defina DBL_MIN_10_EXP (-307)
#defina DBL_MAX_EXP 1024
#defina DBL_MAX 1.7976931348623157e+308
#defina DBL_MAX_10_EXP 308

/* horrible intel longo duplo */
#se definido __i386__ || definido __x86_64__

#defina LDBL_MANT_DIG 64
#defina LDBL_DIG 18
#defina LDBL_EPSILON 1.08420217248550443401e-19L
#defina LDBL_MIN_EXP (-16381)
#defina LDBL_MIN 3.36210314311209350626e-4932L
#defina LDBL_MIN_10_EXP (-4931)
#defina LDBL_MAX_EXP 16384
#defina LDBL_MAX 1.18973149535723176502e+4932L
#defina LDBL_MAX_10_EXP 4932

#senão

/* same as IEEE duplo */
#defina LDBL_MANT_DIG 53
#defina LDBL_DIG 15
#defina LDBL_EPSILON 2.2204460492503131e-16
#defina LDBL_MIN_EXP (-1021)
#defina LDBL_MIN 2.2250738585072014e-308
#defina LDBL_MIN_10_EXP (-307)
#defina LDBL_MAX_EXP 1024
#defina LDBL_MAX 1.7976931348623157e+308
#defina LDBL_MAX_10_EXP 308

#fim_se

#fim_se /* _FLOAT_H_ */
