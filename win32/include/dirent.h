/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* All the headers inclua this file. */
#inclua <_mingw.h>

#se_não_definido	__STRICT_ANSI__

#se_não_definido _DIRENT_H_
#defina _DIRENT_H_


#diretiva pack(push,_CRT_PACKING)

#inclua <io.h>

#se_não_definido RC_INVOKED

#se_definido __cplusplus
externo "C" {
#fim_se

  estrutura dirent
  {
    longo		d_ino;		/* Always zero. */
    sem_sinal curto	d_reclen;	/* Always zero. */
    sem_sinal curto	d_namlen;	/* Length of name in d_name. */
    caractere*		d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the
    *       finddata_t structure in the DIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  * dd_stat field is now inteiro (was curto in older versions).
  */
  defina_tipo estrutura
  {
    /* disk transfer area para this dir */
    estrutura _finddata_t	dd_dta;

    /* dirent estrutura to retorne from dir (NOTE: this makes this thread
    * safe as longo as only one thread uses a particular DIR estrutura at
    * a time) */
    estrutura dirent		dd_dir;

    /* _findnext handle */
    longo			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    inteiro			dd_stat;

    /* given path para dir with search pattern (estrutura is extended) */
    caractere			dd_name[1];
  } DIR;

  DIR* __cdecl opendir (constante caractere*);
  estrutura dirent* __cdecl readdir (DIR*);
  inteiro __cdecl closedir (DIR*);
  vazio __cdecl rewinddir (DIR*);
  longo __cdecl telldir (DIR*);
  vazio __cdecl seekdir (DIR*, longo);


  /* wide caractere versions */

  estrutura _wdirent
  {
    longo		d_ino;		/* Always zero. */
    sem_sinal curto	d_reclen;	/* Always zero. */
    sem_sinal curto	d_namlen;	/* Length of name in d_name. */
    wchar_t*	d_name;		/* File name. */
    /* NOTE: The name in the dirent structure points to the name in the	 *       wfinddata_t structure in the _WDIR. */
  };

  /*
  * This is an internal data structure. Good programmers will not use it
  * except as an argument to one of the functions below.
  */
  defina_tipo estrutura
  {
    /* disk transfer area para this dir */
    estrutura _wfinddata_t	dd_dta;

    /* dirent estrutura to retorne from dir (NOTE: this makes this thread
    * safe as longo as only one thread uses a particular DIR estrutura at
    * a time) */
    estrutura _wdirent		dd_dir;

    /* _findnext handle */
    longo			dd_handle;

    /*
    * Status of search:
    *   0 = not started yet (next entry to read is first entry)
    *  -1 = off the end
    *   positive = 0 based index of next entry
    */
    inteiro			dd_stat;

    /* given path para dir with search pattern (estrutura is extended) */
    wchar_t			dd_name[1];
  } _WDIR;



  _WDIR* __cdecl _wopendir (constante wchar_t*);
  estrutura _wdirent*  __cdecl _wreaddir (_WDIR*);
  inteiro __cdecl _wclosedir (_WDIR*);
  vazio __cdecl _wrewinddir (_WDIR*);
  longo __cdecl _wtelldir (_WDIR*);
  vazio __cdecl _wseekdir (_WDIR*, longo);


#se_definido	__cplusplus
}
#fim_se

#fim_se	/* Not RC_INVOKED */

#diretiva pack(pop)

#fim_se	/* Not _DIRENT_H_ */


#fim_se	/* Not __STRICT_ANSI__ */

