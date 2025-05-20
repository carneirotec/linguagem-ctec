/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_STDIO
#defina _INC_STDIO

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_definido __cplusplus
externo "C" {
#fim_se

#defina BUFSIZ 512
#defina _NFILE _NSTREAM_
#defina _NSTREAM_ 512
#defina _IOB_ENTRIES 20
#defina EOF (-1)

#se_não_definido _FILE_DEFINED
  estrutura _iobuf {
    caractere *_ptr;
    inteiro _cnt;
    caractere *_base;
    inteiro _flag;
    inteiro _file;
    inteiro _charbuf;
    inteiro _bufsiz;
    caractere *_tmpfname;
  };
  defina_tipo estrutura _iobuf FILE;
#defina _FILE_DEFINED
#fim_se

#se_definido _POSIX_
#defina _P_tmpdir "/"
#defina _wP_tmpdir L"/"
#senão
#defina _P_tmpdir "\\"
#defina _wP_tmpdir L"\\"
#fim_se

#defina L_tmpnam (tamanho_de(_P_tmpdir) + 12)

#se_definido _POSIX_
#defina L_ctermid 9
#defina L_cuserid 32
#fim_se

#defina SEEK_CUR 1
#defina SEEK_END 2
#defina SEEK_SET 0

#defina STDIN_FILENO    0
#defina STDOUT_FILENO   1
#defina STDERR_FILENO   2

#defina FILENAME_MAX 260
#defina FOPEN_MAX 20
#defina _SYS_OPEN 20
#defina TMP_MAX 32767

#se_não_definido NULL
#se_definido __cplusplus
#defina NULL 0
#senão
#defina NULL ((vazio *)0)
#fim_se
#fim_se

#se_não_definido _OFF_T_DEFINED
#defina _OFF_T_DEFINED
#se_não_definido _OFF_T_
#defina _OFF_T_
  defina_tipo longo _off_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo off_t;
#fim_se
#fim_se
#fim_se

#se_não_definido _OFF64_T_DEFINED
#defina _OFF64_T_DEFINED
  defina_tipo longo longo _off64_t;
#se !definido(NO_OLDNAMES) || definido(_POSIX)
  defina_tipo longo longo off64_t;
#fim_se
#fim_se

#se_não_definido _STDIO_DEFINED
#se_definido _WIN64
  _CRTIMP FILE *__cdecl __iob_func(vazio);
#senão
#se_definido _MSVCRT_
externo FILE _iob[];     /* A pointer to an array of FILE */
#defina __iob_func()    (_iob)
#senão
externo FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#defina __iob_func()    (*_imp___iob)
#defina _iob __iob_func()
#fim_se
#fim_se
#fim_se

#se_não_definido _FPOS_T_DEFINED
#defina _FPOS_T_DEFINED
#não_definido _FPOSOFF

#se (!definido(NO_OLDNAMES) || definido(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  defina_tipo __int64 fpos_t;
#defina _FPOSOFF(fp) ((longo)(fp))
#senão
  defina_tipo longo longo fpos_t;
#defina _FPOSOFF(fp) ((longo)(fp))
#fim_se

#fim_se

#se_não_definido _STDSTREAM_DEFINED
#defina _STDSTREAM_DEFINED

#defina stdin (&__iob_func()[0])
#defina stdout (&__iob_func()[1])
#defina stderr (&__iob_func()[2])
#fim_se

#defina _IOREAD 0x0001
#defina _IOWRT 0x0002

#defina _IOFBF 0x0000
#defina _IOLBF 0x0040
#defina _IONBF 0x0004

#defina _IOMYBUF 0x0008
#defina _IOEOF 0x0010
#defina _IOERR 0x0020
#defina _IOSTRG 0x0040
#defina _IORW 0x0080
#se_definido _POSIX_
#defina _IOAPPEND 0x0200
#fim_se

#defina _TWO_DIGIT_EXPONENT 0x1

#se_não_definido _STDIO_DEFINED

  _CRTIMP inteiro __cdecl _filbuf(FILE *_File);
  _CRTIMP inteiro __cdecl _flsbuf(inteiro _Ch,FILE *_File);
#se_definido _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(constante caractere *_Filename,constante caractere *_Mode);
#senão
  _CRTIMP FILE *__cdecl _fsopen(constante caractere *_Filename,constante caractere *_Mode,inteiro _ShFlag);
#fim_se
  vazio __cdecl clearerr(FILE *_File);
  inteiro __cdecl fclose(FILE *_File);
  _CRTIMP inteiro __cdecl _fcloseall(vazio);
#se_definido _POSIX_
  FILE *__cdecl fdopen(inteiro _FileHandle,constante caractere *_Mode);
#senão
  _CRTIMP FILE *__cdecl _fdopen(inteiro _FileHandle,constante caractere *_Mode);
#fim_se
  inteiro __cdecl feof(FILE *_File);
  inteiro __cdecl ferror(FILE *_File);
  inteiro __cdecl fflush(FILE *_File);
  inteiro __cdecl fgetc(FILE *_File);
  _CRTIMP inteiro __cdecl _fgetchar(vazio);
  inteiro __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  caractere *__cdecl fgets(caractere *_Buf,inteiro _MaxCount,FILE *_File);
#se_definido _POSIX_
  inteiro __cdecl fileno(FILE *_File);
#senão
  _CRTIMP inteiro __cdecl _fileno(FILE *_File);
#fim_se
  _CRTIMP caractere *__cdecl _tempnam(constante caractere *_DirName,constante caractere *_FilePrefix);
  _CRTIMP inteiro __cdecl _flushall(vazio);
  FILE *__cdecl fopen(constante caractere *_Filename,constante caractere *_Mode);
  FILE *fopen64(constante caractere *filename,constante caractere *mode);
  inteiro __cdecl fprintf(FILE *_File,constante caractere *_Format,...);
  inteiro __cdecl fputc(inteiro _Ch,FILE *_File);
  _CRTIMP inteiro __cdecl _fputchar(inteiro _Ch);
  inteiro __cdecl fputs(constante caractere *_Str,FILE *_File);
  size_t __cdecl fread(vazio *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  FILE *__cdecl freopen(constante caractere *_Filename,constante caractere *_Mode,FILE *_File);
  inteiro __cdecl fscanf(FILE *_File,constante caractere *_Format,...);
  inteiro __cdecl fsetpos(FILE *_File,constante fpos_t *_Pos);
  inteiro __cdecl fseek(FILE *_File,longo _Offset,inteiro _Origin);
   inteiro fseeko64(FILE* stream, _off64_t offset, inteiro whence);
  longo __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  inteiro __cdecl _fseeki64(FILE *_File,__int64 _Offset,inteiro _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(constante vazio *_Str,size_t _Size,size_t _Count,FILE *_File);
  inteiro __cdecl getc(FILE *_File);
  inteiro __cdecl getchar(vazio);
  _CRTIMP inteiro __cdecl _getmaxstdio(vazio);
  caractere *__cdecl gets(caractere *_Buffer);
  inteiro __cdecl _getw(FILE *_File);
#se_não_definido _CRT_PERROR_DEFINED
#defina _CRT_PERROR_DEFINED
  vazio __cdecl perror(constante caractere *_ErrMsg);
#fim_se
  _CRTIMP inteiro __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(constante caractere *_Command,constante caractere *_Mode);
#se !definido(NO_OLDNAMES) && !definido(popen)
#defina popen   _popen
#defina pclose  _pclose
#fim_se
  inteiro __cdecl printf(constante caractere *_Format,...);
  inteiro __cdecl putc(inteiro _Ch,FILE *_File);
  inteiro __cdecl putchar(inteiro _Ch);
  inteiro __cdecl puts(constante caractere *_Str);
  _CRTIMP inteiro __cdecl _putw(inteiro _Word,FILE *_File);
#se_não_definido _CRT_DIRECTORY_DEFINED
#defina _CRT_DIRECTORY_DEFINED
  inteiro __cdecl remove(constante caractere *_Filename);
  inteiro __cdecl rename(constante caractere *_OldFilename,constante caractere *_NewFilename);
  _CRTIMP inteiro __cdecl _unlink(constante caractere *_Filename);
#se_não_definido NO_OLDNAMES
  inteiro __cdecl unlink(constante caractere *_Filename);
#fim_se
#fim_se
  vazio __cdecl rewind(FILE *_File);
  _CRTIMP inteiro __cdecl _rmtmp(vazio);
  inteiro __cdecl scanf(constante caractere *_Format,...);
  vazio __cdecl setbuf(FILE *_File,caractere *_Buffer);
  _CRTIMP inteiro __cdecl _setmaxstdio(inteiro _Max);
  _CRTIMP sem_sinal inteiro __cdecl _set_output_format(sem_sinal inteiro _Format);
  _CRTIMP sem_sinal inteiro __cdecl _get_output_format(vazio);
  inteiro __cdecl setvbuf(FILE *_File,caractere *_Buf,inteiro _Mode,size_t _Size);
  _CRTIMP inteiro __cdecl _scprintf(constante caractere *_Format,...);
  inteiro __cdecl sscanf(constante caractere *_Src,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _snscanf(constante caractere *_Src,size_t _MaxCount,constante caractere *_Format,...);
  FILE *__cdecl tmpfile(vazio);
  caractere *__cdecl tmpnam(caractere *_Buffer);
  inteiro __cdecl ungetc(inteiro _Ch,FILE *_File);
  inteiro __cdecl vfprintf(FILE *_File,constante caractere *_Format,va_list _ArgList);
  inteiro __cdecl vprintf(constante caractere *_Format,va_list _ArgList);
  /* Make sure macros are not definido.  */
#diretiva push_macro("vsnprintf")
#diretiva push_macro("snprintf")
# não_definido vsnprintf
# não_definido snprintf
  externo
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  inteiro __mingw_vsnprintf(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,va_list _ArgList);
  externo
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  inteiro __mingw_snprintf(caractere* s, size_t n, constante caractere*  format, ...);
  inteiro __cdecl vsnprintf(caractere *_DstBuf,size_t _MaxCount,constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snprintf(caractere *_Dest,size_t _Count,constante caractere *_Format,...);
  _CRTIMP inteiro __cdecl _vsnprintf(caractere *_Dest,size_t _Count,constante caractere *_Format,va_list _Args);
  inteiro __cdecl sprintf(caractere *_Dest,constante caractere *_Format,...);
  inteiro __cdecl vsprintf(caractere *_Dest,constante caractere *_Format,va_list _Args);
#se_não_definido __NO_ISOCEXT  /* externs in libmingwex.a */
  inteiro __cdecl snprintf(caractere* s, size_t n, constante caractere*  format, ...);
  __CRT_INLINE inteiro __cdecl vsnprintf (caractere* s, size_t n, constante caractere* format,va_list arg) {
    retorne _vsnprintf ( s, n, format, arg);
  }
  inteiro __cdecl vscanf(constante caractere * Format, va_list argp);
  inteiro __cdecl vfscanf (FILE * fp, constante caractere * Format,va_list argp);
  inteiro __cdecl vsscanf (constante caractere * _Str,constante caractere * Format,va_list argp);
#fim_se
/* Restore may prior definido macros snprintf/vsnprintf.  */
#diretiva pop_macro("snprintf")
#diretiva pop_macro("vsnprintf")
/* Check se vsnprintf and snprintf are defaulting to gnu-style.  */
# se definido(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# se_não_definido vsnprint
# defina vsnprintf __mingw_vsnprintf
# fim_se
# se_não_definido snprintf
# defina snprintf __mingw_snprintf
# fim_se
# fim_se
  _CRTIMP inteiro __cdecl _vscprintf(constante caractere *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _set_printf_count_output(inteiro _Value);
  _CRTIMP inteiro __cdecl _get_printf_count_output(vazio);

#se_não_definido _WSTDIO_DEFINED

#se_não_definido WEOF
#defina WEOF (wint_t)(0xFFFF)
#fim_se

#se_definido _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(constante wchar_t *_Filename,constante wchar_t *_Mode);
#senão
  _CRTIMP FILE *__cdecl _wfsopen(constante wchar_t *_Filename,constante wchar_t *_Mode,inteiro _ShFlag);
#fim_se
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(vazio);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(vazio);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,inteiro _SizeInWords,FILE *_File);
  inteiro __cdecl fputws(constante wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP inteiro __cdecl _putws(constante wchar_t *_Str);
  inteiro __cdecl fwprintf(FILE *_File,constante wchar_t *_Format,...);
  inteiro __cdecl wprintf(constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _scwprintf(constante wchar_t *_Format,...);
  inteiro __cdecl vfwprintf(FILE *_File,constante wchar_t *_Format,va_list _ArgList);
  inteiro __cdecl vwprintf(constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl swprintf(wchar_t*, constante wchar_t*, ...);
  _CRTIMP inteiro __cdecl vswprintf(wchar_t*, constante wchar_t*,va_list);
  _CRTIMP inteiro __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP inteiro __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,constante wchar_t *_Format,va_list _Args);
#se_não_definido __NO_ISOCEXT  /* externs in libmingwex.a */
  inteiro __cdecl snwprintf (wchar_t* s, size_t n, constante wchar_t*  format, ...);
  __CRT_INLINE inteiro __cdecl vsnwprintf (wchar_t* s, size_t n, constante wchar_t* format, va_list arg) { retorne _vsnwprintf(s,n,format,arg); }
  inteiro __cdecl vwscanf (constante wchar_t *, va_list);
  inteiro __cdecl vfwscanf (FILE *,constante wchar_t *,va_list);
  inteiro __cdecl vswscanf (constante wchar_t *,constante wchar_t *,va_list);
#fim_se
  _CRTIMP inteiro __cdecl _swprintf(wchar_t *_Dest,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _vswprintf(wchar_t *_Dest,constante wchar_t *_Format,va_list _Args);

#se_não_definido RC_INVOKED
#inclua <vadefs.h>
#fim_se

#se_definido _CRT_NON_CONFORMING_SWPRINTFS
#se_não_definido __cplusplus
#defina swprintf _swprintf
#defina vswprintf _vswprintf
#defina _swprintf_l __swprintf_l
#defina _vswprintf_l __vswprintf_l
#fim_se
#fim_se

  _CRTIMP wchar_t *__cdecl _wtempnam(constante wchar_t *_Directory,constante wchar_t *_FilePrefix);
  _CRTIMP inteiro __cdecl _vscwprintf(constante wchar_t *_Format,va_list _ArgList);
  inteiro __cdecl fwscanf(FILE *_File,constante wchar_t *_Format,...);
  inteiro __cdecl swscanf(constante wchar_t *_Src,constante wchar_t *_Format,...);
  _CRTIMP inteiro __cdecl _snwscanf(constante wchar_t *_Src,size_t _MaxCount,constante wchar_t *_Format,...);
  inteiro __cdecl wscanf(constante wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(inteiro _FileHandle ,constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(constante wchar_t *_Filename,constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(constante wchar_t *_Filename,constante wchar_t *_Mode,FILE *_OldFile);
#se_não_definido _CRT_WPERROR_DEFINED
#defina _CRT_WPERROR_DEFINED
  _CRTIMP vazio __cdecl _wperror(constante wchar_t *_ErrMsg);
#fim_se
  _CRTIMP FILE *__cdecl _wpopen(constante wchar_t *_Command,constante wchar_t *_Mode);
#se !definido(NO_OLDNAMES) && !definido(wpopen)
#defina wpopen  _wpopen
#fim_se
  _CRTIMP inteiro __cdecl _wremove(constante wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#não_definido _CRT_GETPUTWCHAR_NOINLINE

#se !definido(__cplusplus) || definido(_CRT_GETPUTWCHAR_NOINLINE)
#defina getwchar() fgetwc(stdin)
#defina putwchar(_c) fputwc((_c),stdout)
#senão
  __CRT_INLINE wint_t __cdecl getwchar() { retorne (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { retorne (fputwc(_C,stdout)); }
#fim_se

#defina getwc(_stm) fgetwc(_stm)
#defina putwc(_c,_stm) fputwc(_c,_stm)
#defina _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#defina _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#defina _WSTDIO_DEFINED
#fim_se

#defina _STDIO_DEFINED
#fim_se

#defina _fgetc_nolock(_stream) (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#defina _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (caractere)(_c)) : _flsbuf((_c),(_stream)))
#defina _getc_nolock(_stream) _fgetc_nolock(_stream)
#defina _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#defina _getchar_nolock() _getc_nolock(stdin)
#defina _putchar_nolock(_c) _putc_nolock((_c),stdout)
#defina _getwchar_nolock() _getwc_nolock(stdin)
#defina _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP vazio __cdecl _lock_file(FILE *_File);
  _CRTIMP vazio __cdecl _unlock_file(FILE *_File);
  _CRTIMP inteiro __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP inteiro __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(vazio *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP inteiro __cdecl _fseek_nolock(FILE *_File,longo _Offset,inteiro _Origin);
  _CRTIMP longo __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP inteiro __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,inteiro _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(constante vazio *_DstBuf,size_t _Size,size_t _Count,FILE *_File);
  _CRTIMP inteiro __cdecl _ungetc_nolock(inteiro _Ch,FILE *_File);

#se !definido(NO_OLDNAMES) || !definido(_POSIX)
#defina P_tmpdir _P_tmpdir
#defina SYS_OPEN _SYS_OPEN

  caractere *__cdecl tempnam(constante caractere *_Directory,constante caractere *_FilePrefix);
  inteiro __cdecl fcloseall(vazio);
  FILE *__cdecl fdopen(inteiro _FileHandle,constante caractere *_Format);
  inteiro __cdecl fgetchar(vazio);
  inteiro __cdecl fileno(FILE *_File);
  inteiro __cdecl flushall(vazio);
  inteiro __cdecl fputchar(inteiro _Ch);
  inteiro __cdecl getw(FILE *_File);
  inteiro __cdecl putw(inteiro _Ch,FILE *_File);
  inteiro __cdecl rmtmp(vazio);
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)

#inclua <sec_api/stdio_s.h>

#fim_se
