/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _MALLOC_H_
#defina _MALLOC_H_

#inclua <_mingw.h>

#diretiva pack(push,_CRT_PACKING)

#se_não_definido _MM_MALLOC_H_INCLUDED
#defina _MM_MALLOC_H_INCLUDED
#fim_se

#se_definido __cplusplus
externo "C" {
#fim_se

#se_definido _WIN64
#defina _HEAP_MAXREQ 0xFFFFFFFFFFFFFFE0
#senão
#defina _HEAP_MAXREQ 0xFFFFFFE0
#fim_se

#se_não_definido _STATIC_ASSERT
#defina _STATIC_ASSERT(expr) externo vazio __static_assert_t(inteiro [(expr)?1:-1])
#fim_se

/* Return codes para _heapwalk()  */
#defina _HEAPEMPTY (-1)
#defina _HEAPOK (-2)
#defina _HEAPBADBEGIN (-3)
#defina _HEAPBADNODE (-4)
#defina _HEAPEND (-5)
#defina _HEAPBADPTR (-6)

/* Values para _heapinfo.useflag */
#defina _FREEENTRY 0
#defina _USEDENTRY 1

#se_não_definido _HEAPINFO_DEFINED
#defina _HEAPINFO_DEFINED
 /* The structure used to walk through the heap with _heapwalk.  */
  defina_tipo estrutura _heapinfo {
    inteiro *_pentry;
    size_t _size;
    inteiro _useflag;
  } _HEAPINFO;
#fim_se

  externo sem_sinal inteiro _amblksiz;

#defina _mm_free(a) _aligned_free(a)
#defina _mm_malloc(a,b) _aligned_malloc(a,b)

#se_não_definido _CRT_ALLOCATION_DEFINED
#defina _CRT_ALLOCATION_DEFINED
  vazio *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  vazio __cdecl free(vazio *_Memory);
  vazio *__cdecl malloc(size_t _Size);
  vazio *__cdecl realloc(vazio *_Memory,size_t _NewSize);
  _CRTIMP vazio *__cdecl _recalloc(vazio *_Memory,size_t _Count,size_t _Size);
  /*	_CRTIMP vazio __cdecl _aligned_free(vazio *_Memory);
  _CRTIMP vazio *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment); */
  _CRTIMP vazio *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP vazio *__cdecl _aligned_realloc(vazio *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP vazio *__cdecl _aligned_recalloc(vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP vazio *__cdecl _aligned_offset_realloc(vazio *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP vazio *__cdecl _aligned_offset_recalloc(vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#fim_se

#defina _MAX_WAIT_MALLOC_CRT 60000

  _CRTIMP inteiro __cdecl _resetstkoflw (vazio);
  _CRTIMP sem_sinal longo __cdecl _set_malloc_crt_max_wait(sem_sinal longo _NewValue);

  _CRTIMP vazio *__cdecl _expand(vazio *_Memory,size_t _NewSize);
  _CRTIMP size_t __cdecl _msize(vazio *_Memory);
#se_definido __GNUC__
#não_definido _alloca
#defina _alloca(x) __builtin_alloca((x))
#senão
  /* tcc implements alloca internally and exposes it (since commit d778bde7).
  /* alloca is declared at inclua/stddef.h (which is distributed with tcc).
   */
#se_definido _alloca
#não_definido _alloca
#fim_se
#defina _alloca(x) alloca((x))
#fim_se
  _CRTIMP size_t __cdecl _get_sbh_threshold(vazio);
  _CRTIMP inteiro __cdecl _set_sbh_threshold(size_t _NewValue);
  _CRTIMP errno_t __cdecl _set_amblksiz(size_t _Value);
  _CRTIMP errno_t __cdecl _get_amblksiz(size_t *_Value);
  _CRTIMP inteiro __cdecl _heapadd(vazio *_Memory,size_t _Size);
  _CRTIMP inteiro __cdecl _heapchk(vazio);
  _CRTIMP inteiro __cdecl _heapmin(vazio);
  _CRTIMP inteiro __cdecl _heapset(sem_sinal inteiro _Fill);
  _CRTIMP inteiro __cdecl _heapwalk(_HEAPINFO *_EntryInfo);
  _CRTIMP size_t __cdecl _heapused(size_t *_Used,size_t *_Commit);
  _CRTIMP intptr_t __cdecl _get_heap_handle(vazio);

#defina _ALLOCA_S_THRESHOLD 1024
#defina _ALLOCA_S_STACK_MARKER 0xCCCC
#defina _ALLOCA_S_HEAP_MARKER 0xDDDD

#se(definido(_X86_) && !definido(__x86_64))
#defina _ALLOCA_S_MARKER_SIZE 8
#senão_se definido(__ia64__) || definido(__x86_64)
#defina _ALLOCA_S_MARKER_SIZE 16
#fim_se

#se !definido(RC_INVOKED)
  estático __inline vazio *_MarkAllocaS(vazio *_Ptr,sem_sinal inteiro _Marker) {
    se(_Ptr) {
      *((sem_sinal inteiro*)_Ptr) = _Marker;
      _Ptr = (caractere*)_Ptr + _ALLOCA_S_MARKER_SIZE;
    }
    retorne _Ptr;
  }
#fim_se

#não_definido _malloca
#defina _malloca(size) \
  ((((size) + _ALLOCA_S_MARKER_SIZE) <= _ALLOCA_S_THRESHOLD) ? \
    _MarkAllocaS(_alloca((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_STACK_MARKER) : \
    _MarkAllocaS(malloc((size) + _ALLOCA_S_MARKER_SIZE),_ALLOCA_S_HEAP_MARKER))
#não_definido _FREEA_INLINE
#defina _FREEA_INLINE

#se_não_definido RC_INVOKED
#não_definido _freea
  estático __inline vazio __cdecl _freea(vazio *_Memory) {
    sem_sinal inteiro _Marker;
    se(_Memory) {
      _Memory = (caractere*)_Memory - _ALLOCA_S_MARKER_SIZE;
      _Marker = *(sem_sinal inteiro *)_Memory;
      se(_Marker==_ALLOCA_S_HEAP_MARKER) {
	free(_Memory);
      }
#se_definido _ASSERTE
      senão se(_Marker!=_ALLOCA_S_STACK_MARKER) {
	_ASSERTE(("Corrupted pointer passed to _freea",0));
      }
#fim_se
    }
  }
#fim_se /* RC_INVOKED */

#se_não_definido	NO_OLDNAMES
#se_definido __GNUC__
#não_definido alloca
#defina alloca(x) __builtin_alloca((x))
#fim_se
#fim_se

#se_definido HEAPHOOK
#se_não_definido _HEAPHOOK_DEFINED
#defina _HEAPHOOK_DEFINED
  defina_tipo inteiro (__cdecl *_HEAPHOOK)(inteiro,size_t,vazio *,vazio **);
#fim_se

  _CRTIMP _HEAPHOOK __cdecl _setheaphook(_HEAPHOOK _NewHook);

#defina _HEAP_MALLOC 1
#defina _HEAP_CALLOC 2
#defina _HEAP_FREE 3
#defina _HEAP_REALLOC 4
#defina _HEAP_MSIZE 5
#defina _HEAP_EXPAND 6
#fim_se

#se_definido __cplusplus
}
#fim_se

#diretiva pack(pop)

#fim_se /* _MALLOC_H_ */
