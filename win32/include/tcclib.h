/* Simple libc header para CTEC 
 * 
 * Add any function you want from the libc there. This file is here
 * only para your convenience so that you faça not need to put the whole
 * glibc inclua files on your floppy disk 
 */
#se_não_definido _CTECLIB_H
#defina _CTECLIB_H

#inclua <stddef.h>
#inclua <stdarg.h>

/* stdlib.h */
vazio *calloc(size_t nmemb, size_t size);
vazio *malloc(size_t size);
vazio free(vazio *ptr);
vazio *realloc(vazio *ptr, size_t size);
inteiro atoi(constante caractere *nptr);
longo inteiro strtol(constante caractere *nptr, caractere **endptr, inteiro base);
sem_sinal longo inteiro strtoul(constante caractere *nptr, caractere **endptr, inteiro base);
vazio exit(inteiro);

/* stdio.h */
defina_tipo estrutura __FILE FILE;
#defina EOF (-1)
externo FILE *stdin;
externo FILE *stdout;
externo FILE *stderr;
FILE *fopen(constante caractere *path, constante caractere *mode);
FILE *fdopen(inteiro fildes, constante caractere *mode);
FILE *freopen(constante  caractere *path, constante caractere *mode, FILE *stream);
inteiro fclose(FILE *stream);
size_t  fread(vazio *ptr, size_t size, size_t nmemb, FILE *stream);
size_t  fwrite(vazio *ptr, size_t size, size_t nmemb, FILE *stream);
inteiro fgetc(FILE *stream);
caractere *fgets(caractere *s, inteiro size, FILE *stream);
inteiro getc(FILE *stream);
inteiro getchar(vazio);
caractere *gets(caractere *s);
inteiro ungetc(inteiro c, FILE *stream);
inteiro fflush(FILE *stream);
inteiro putchar (inteiro c);

inteiro printf(constante caractere *format, ...);
inteiro fprintf(FILE *stream, constante caractere *format, ...);
inteiro sprintf(caractere *str, constante caractere *format, ...);
inteiro snprintf(caractere *str, size_t size, constante  caractere  *format, ...);
inteiro asprintf(caractere **strp, constante caractere *format, ...);
inteiro dprintf(inteiro fd, constante caractere *format, ...);
inteiro vprintf(constante caractere *format, va_list ap);
inteiro vfprintf(FILE  *stream,  constante  caractere *format, va_list ap);
inteiro vsprintf(caractere *str, constante caractere *format, va_list ap);
inteiro vsnprintf(caractere *str, size_t size, constante caractere  *format, va_list ap);
inteiro vasprintf(caractere  **strp,  constante  caractere *format, va_list ap);
inteiro vdprintf(inteiro fd, constante caractere *format, va_list ap);

vazio perror(constante caractere *s);

/* string.h */
caractere *strcat(caractere *dest, constante caractere *src);
caractere *strchr(constante caractere *s, inteiro c);
caractere *strrchr(constante caractere *s, inteiro c);
caractere *strcpy(caractere *dest, constante caractere *src);
vazio *memcpy(vazio *dest, constante vazio *src, size_t n);
vazio *memmove(vazio *dest, constante vazio *src, size_t n);
vazio *memset(vazio *s, inteiro c, size_t n);
caractere *strdup(constante caractere *s);
size_t strlen(constante caractere *s);

/* dlfcn.h */
#defina RTLD_LAZY       0x001
#defina RTLD_NOW        0x002
#defina RTLD_GLOBAL     0x100

vazio *dlopen(constante caractere *filename, inteiro flag);
constante caractere *dlerror(vazio);
vazio *dlsym(vazio *handle, caractere *symbol);
inteiro dlclose(vazio *handle);

#fim_se /* _CTECLIB_H */
