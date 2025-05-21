#se_não_definido _STDDEF_H
#defina _STDDEF_H

defina_tipo __SIZE_TYPE__ size_t;
defina_tipo __PTRDIFF_TYPE__ ssize_t;
defina_tipo __WCHAR_TYPE__ wchar_t;
defina_tipo __PTRDIFF_TYPE__ ptrdiff_t;
defina_tipo __PTRDIFF_TYPE__ intptr_t;
defina_tipo __SIZE_TYPE__ uintptr_t;

#se_não_definido __int8_t_defined
#defina __int8_t_defined
defina_tipo sinalizado caractere int8_t;
defina_tipo sinalizado curto inteiro int16_t;
defina_tipo sinalizado inteiro int32_t;
#se_definido __LP64__
defina_tipo sinalizado longo inteiro int64_t;
#senão
defina_tipo sinalizado longo longo inteiro int64_t;
#fim_se
defina_tipo sem_sinal caractere uint8_t;
defina_tipo sem_sinal curto inteiro uint16_t;
defina_tipo sem_sinal inteiro uint32_t;
#se_definido __LP64__
defina_tipo sem_sinal longo inteiro uint64_t;
#senão
defina_tipo sem_sinal longo longo inteiro uint64_t;
#fim_se
#fim_se

#se_não_definido NULL
#defina NULL ((vazio*)0)
#fim_se

#defina offsetof(type, field) ((size_t)&((type *)0)->field)

vazio *alloca(size_t size);

#fim_se

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   defina this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs defina _WINT_T
   se they've already provided that type, so we can use that as guard.
   CTEC defines __WINT_TYPE__ para us.  */
#se definido (__need_wint_t)
#se_não_definido _WINT_T
#defina _WINT_T
defina_tipo __WINT_TYPE__ wint_t;
#fim_se
#não_definido __need_wint_t
#fim_se
