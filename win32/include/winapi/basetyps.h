/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se !definido(_BASETYPS_H_)
#defina _BASETYPS_H_

#se_definido __cplusplus
#defina EXTERN_C externo "C"
#senão
#defina EXTERN_C externo
#fim_se

#defina STDMETHODCALLTYPE WINAPI
#defina STDMETHODVCALLTYPE __cdecl

#defina STDAPICALLTYPE WINAPI
#defina STDAPIVCALLTYPE __cdecl

#defina STDAPI EXTERN_C HRESULT WINAPI
#defina STDAPI_(type) EXTERN_C type WINAPI

#defina STDMETHODIMP HRESULT WINAPI
#defina STDMETHODIMP_(type) type WINAPI

#defina STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#defina STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#defina STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#defina STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#se definido(__cplusplus) && !definido(CINTERFACE)

#defina __STRUCT__ estrutura
#defina STDMETHOD(method) virtual HRESULT WINAPI method
#defina STDMETHOD_(type,method) virtual type WINAPI method
#defina STDMETHODV(method) virtual HRESULT STDMETHODVCALLTYPE method
#defina STDMETHODV_(type,method) virtual type STDMETHODVCALLTYPE method
#defina PURE = 0
#defina THIS_
#defina THIS vazio
#defina DECLARE_INTERFACE(iface) __STRUCT__ iface
#defina DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : public baseiface
#senão

#se_não_definido __OBJC__
#defina interface estrutura
#fim_se

#defina STDMETHOD(method) HRESULT (WINAPI *method)
#defina STDMETHOD_(type,method) type (WINAPI *method)
#defina STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#defina STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#defina PURE
#defina THIS_ INTERFACE *This,
#defina THIS INTERFACE *This
#se_definido CONST_VTABLE
#defina DECLARE_INTERFACE(iface) defina_tipo estrutura iface { \
  constante estrutura iface##Vtbl *lpVtbl; } iface; \
  defina_tipo constante estrutura iface##Vtbl iface##Vtbl; \
  constante estrutura iface##Vtbl
#senão
#defina DECLARE_INTERFACE(iface) defina_tipo estrutura iface { \
    estrutura iface##Vtbl *lpVtbl; \
  } iface; \
  defina_tipo estrutura iface##Vtbl iface##Vtbl; \
  estrutura iface##Vtbl
#fim_se
#defina DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#fim_se

#inclua <guiddef.h>

#se_não_definido _ERROR_STATUS_T_DEFINED
#defina _ERROR_STATUS_T_DEFINED
defina_tipo sem_sinal longo error_status_t;
#fim_se

#se_não_definido _WCHAR_T_DEFINED
defina_tipo sem_sinal curto wchar_t;
#defina _WCHAR_T_DEFINED
#fim_se
#fim_se
