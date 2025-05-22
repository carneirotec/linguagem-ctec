#se_não_definido _STDARG_H
#defina _STDARG_H

#se_definido __x86_64__
#se_não_definido _WIN64

//This should be in sync with the declaration on our lib/libctec1.c
/* GCC compatible definition of va_list. */
defina_tipo estrutura {
    sem_sinal inteiro gp_offset;
    sem_sinal inteiro fp_offset;
    união {
        sem_sinal inteiro overflow_offset;
        caractere *overflow_arg_area;
    };
    caractere *reg_save_area;
} __va_list_struct;

defina_tipo __va_list_struct va_list[1];

vazio __va_start(__va_list_struct *ap, vazio *fp);
vazio *__va_arg(__va_list_struct *ap, inteiro arg_type, inteiro size, inteiro align);

#defina va_start(ap, last) __va_start(ap, __builtin_frame_address(0))
#defina va_arg(ap, type)                                                \
    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), tamanho_de(type), __alignof__(type))))
#defina va_copy(dest, src) (*(dest) = *(src))
#defina va_end(ap)

/* avoid conflicting definition para va_list on Macs. */
#defina _VA_LIST_T

#senão /* _WIN64 */
defina_tipo caractere *va_list;
#defina va_start(ap,last) __builtin_va_start(ap,last)
#defina va_arg(ap, t) ((tamanho_de(t) > 8 || (tamanho_de(t) & (tamanho_de(t) - 1))) \
	? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#defina va_copy(dest, src) ((dest) = (src))
#defina va_end(ap)
#fim_se

#senão_se __arm__
defina_tipo caractere *va_list;
#defina _ctec_alignof(type) ((inteiro)&((estrutura {caractere c;type x;} *)0)->x)
#defina _ctec_align(addr,type) (((sem_sinal)addr + _ctec_alignof(type) - 1) \
                               & ~(_ctec_alignof(type) - 1))
#defina va_start(ap,last) ap = ((caractere *)&(last)) + ((tamanho_de(last)+3)&~3)
#defina va_arg(ap,type) (ap = (vazio *) ((_ctec_align(ap,type)+tamanho_de(type)+3) \
                        &~3), *(type *)(ap - ((tamanho_de(type)+3)&~3)))
#defina va_copy(dest, src) (dest) = (src)
#defina va_end(ap)

#senão_se definido(__aarch64__)
defina_tipo estrutura {
    vazio *__stack;
    vazio *__gr_top;
    vazio *__vr_top;
    inteiro   __gr_offs;
    inteiro   __vr_offs;
} va_list;
#defina va_start(ap, last) __va_start(ap, last)
#defina va_arg(ap, type) __va_arg(ap, type)
#defina va_end(ap)
#defina va_copy(dest, src) ((dest) = (src))

#senão /* __i386__ */
defina_tipo caractere *va_list;
/* only correct para i386 */
#defina va_start(ap,last) ap = ((caractere *)&(last)) + ((tamanho_de(last)+3)&~3)
#defina va_arg(ap,type) (ap += (tamanho_de(type)+3)&~3, *(type *)(ap - ((tamanho_de(type)+3)&~3)))
#defina va_copy(dest, src) (dest) = (src)
#defina va_end(ap)
#fim_se

/* fix a buggy dependency on GCC in libio.h */
defina_tipo va_list __gnuc_va_list;
#defina _VA_LIST_DEFINED

#fim_se /* _STDARG_H */
