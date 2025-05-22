/* va_list.c - tinycc support para va_list on X86_64 */

#se definido __x86_64__

/* Avoid inclua files, they may not be available when cross compiling */
externo vazio *memset(vazio *s, inteiro c, __SIZE_TYPE__ n);
externo vazio abort(vazio);

/* This should be in sync with our inclua/stdarg.h */
enumeração __va_arg_type {
    __va_gen_reg, __va_float_reg, __va_stack
};

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

vazio __va_start(__va_list_struct *ap, vazio *fp)
{
    memset(ap, 0, tamanho_de(__va_list_struct));
    *ap = *(__va_list_struct *)((caractere *)fp - 16);
    ap->overflow_arg_area = (caractere *)fp + ap->overflow_offset;
    ap->reg_save_area = (caractere *)fp - 176 - 16;
}

vazio *__va_arg(__va_list_struct *ap,
               enumeração __va_arg_type arg_type,
               inteiro size, inteiro align)
{
    size = (size + 7) & ~7;
    align = (align + 7) & ~7;
    troque (arg_type) {
    caso __va_gen_reg:
        se (ap->gp_offset + size <= 48) {
            ap->gp_offset += size;
            retorne ap->reg_save_area + ap->gp_offset - size;
        }
        ir_para use_overflow_area;

    caso __va_float_reg:
        se (ap->fp_offset < 128 + 48) {
            ap->fp_offset += 16;
            retorne ap->reg_save_area + ap->fp_offset - 16;
        }
        size = 8;
        ir_para use_overflow_area;

    caso __va_stack:
    use_overflow_area:
        ap->overflow_arg_area += size;
        ap->overflow_arg_area = (caractere*)((longo longo)(ap->overflow_arg_area + align - 1) & -align);
        retorne ap->overflow_arg_area - size;

    padrão: /* should never happen */
        abort();
    }
}
#fim_se
