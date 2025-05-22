#se_não_definido LIBCTEC_H
#defina LIBCTEC_H

#se_não_definido LIBCTECAPI
# defina LIBCTECAPI
#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se

estrutura CTECState;

defina_tipo estrutura CTECState CTECState;

/* create a new CTEC compilation context */
LIBCTECAPI CTECState *ctec_new(vazio);

/* free a CTEC compilation context */
LIBCTECAPI vazio ctec_delete(CTECState *s);

/* set CONFIG_CTECDIR at runtime */
LIBCTECAPI vazio ctec_set_lib_path(CTECState *s, constante caractere *path);

/* set erro/aviso display callback */
LIBCTECAPI vazio ctec_set_error_func(CTECState *s, vazio *error_opaque,
    vazio (*error_func)(vazio *opaque, constante caractere *msg));

/* set options as from command linha (multiple supported) */
LIBCTECAPI vazio ctec_set_options(CTECState *s, constante caractere *str);

/*****************************/
/* preprocessor */

/* add inclua path */
LIBCTECAPI inteiro ctec_add_include_path(CTECState *s, constante caractere *pathname);

/* add in system inclua path */
LIBCTECAPI inteiro ctec_add_sysinclude_path(CTECState *s, constante caractere *pathname);

/* defina preprocessor symbol 'sym'. Can put optional value */
LIBCTECAPI vazio ctec_define_symbol(CTECState *s, constante caractere *sym, constante caractere *value);

/* undefine preprocess symbol 'sym' */
LIBCTECAPI vazio ctec_undefine_symbol(CTECState *s, constante caractere *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 se erro. */
LIBCTECAPI inteiro ctec_add_file(CTECState *s, constante caractere *filename);

/* compile a string containing a C source. Return -1 se erro. */
LIBCTECAPI inteiro ctec_compile_string(CTECState *s, constante caractere *buf);

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBCTECAPI inteiro ctec_set_output_type(CTECState *s, inteiro output_type);
#defina CTEC_OUTPUT_MEMORY   1 /* output will be run in memory (padrão) */
#defina CTEC_OUTPUT_EXE      2 /* executable file */
#defina CTEC_OUTPUT_DLL      3 /* dynamic library */
#defina CTEC_OUTPUT_OBJ      4 /* object file */
#defina CTEC_OUTPUT_PREPROCESS 5 /* only preprocess (used internally) */

/* equivalent to -Lpath option */
LIBCTECAPI inteiro ctec_add_library_path(CTECState *s, constante caractere *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBCTECAPI inteiro ctec_add_library(CTECState *s, constante caractere *libraryname);

/* add a symbol to the compiled program */
LIBCTECAPI inteiro ctec_add_symbol(CTECState *s, constante caractere *name, constante vazio *val);

/* output an executable, library or object file. DO NOT call
   ctec_relocate() before. */
LIBCTECAPI inteiro ctec_output_file(CTECState *s, constante caractere *filename);

/* link and run main() function and retorne its value. DO NOT call
   ctec_relocate() before. */
LIBCTECAPI inteiro ctec_run(CTECState *s, inteiro argc, caractere **argv);

/* faça all relocations (needed before using ctec_get_symbol()) */
LIBCTECAPI inteiro ctec_relocate(CTECState *s1, vazio *ptr);
/* possible values para 'ptr':
   - CTEC_RELOCATE_AUTO : Allocate and manage memory internally
   - NULL              : retorne required memory size para the step below
   - memory address    : copy code to memory passed by the caller
   returns -1 se erro. */
#defina CTEC_RELOCATE_AUTO (vazio*)1

/* retorne symbol value or NULL se not found */
LIBCTECAPI vazio *ctec_get_symbol(CTECState *s, constante caractere *name);

#se_definido __cplusplus
}
#fim_se

#fim_se
