/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido GUID_DEFINED
#defina GUID_DEFINED
defina_tipo estrutura _GUID {
  sem_sinal longo Data1;
  sem_sinal curto Data2;
  sem_sinal curto Data3;
  sem_sinal caractere Data4[8 ];
} GUID;
#fim_se

#se_não_definido UUID_DEFINED
#defina UUID_DEFINED
defina_tipo GUID UUID;
#fim_se

#se_não_definido FAR
#defina FAR
#fim_se

#se_não_definido DECLSPEC_SELECTANY
#defina DECLSPEC_SELECTANY __declspec(selectany)
#fim_se

#se_não_definido EXTERN_C
#se_definido __cplusplus
#defina EXTERN_C externo "C"
#senão
#defina EXTERN_C externo
#fim_se
#fim_se

#se_definido DEFINE_GUID
#não_definido DEFINE_GUID
#fim_se

#se_definido INITGUID
#se_definido __cplusplus
#defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C constante GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#senão
#defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) constante GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#fim_se
#senão
#defina DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C constante GUID name
#fim_se

#defina DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#se_não_definido _GUIDDEF_H_
#defina _GUIDDEF_H_

#se_não_definido __LPGUID_DEFINED__
#defina __LPGUID_DEFINED__
defina_tipo GUID *LPGUID;
#fim_se

#se_não_definido __LPCGUID_DEFINED__
#defina __LPCGUID_DEFINED__
defina_tipo constante GUID *LPCGUID;
#fim_se

#se_não_definido __IID_DEFINED__
#defina __IID_DEFINED__

defina_tipo GUID IID;
defina_tipo IID *LPIID;
#defina IID_NULL GUID_NULL
#defina IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
defina_tipo GUID CLSID;
defina_tipo CLSID *LPCLSID;
#defina CLSID_NULL GUID_NULL
#defina IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
defina_tipo GUID FMTID;
defina_tipo FMTID *LPFMTID;
#defina FMTID_NULL GUID_NULL
#defina IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#se_definido __midl_proxy
#defina __MIDL_CONST
#senão
#defina __MIDL_CONST constante
#fim_se

#se_não_definido _REFGUID_DEFINED
#defina _REFGUID_DEFINED
#se_definido __cplusplus
#defina REFGUID constante GUID &
#senão
#defina REFGUID constante GUID *__MIDL_CONST
#fim_se
#fim_se

#se_não_definido _REFIID_DEFINED
#defina _REFIID_DEFINED
#se_definido __cplusplus
#defina REFIID constante IID &
#senão
#defina REFIID constante IID *__MIDL_CONST
#fim_se
#fim_se

#se_não_definido _REFCLSID_DEFINED
#defina _REFCLSID_DEFINED
#se_definido __cplusplus
#defina REFCLSID constante IID &
#senão
#defina REFCLSID constante IID *__MIDL_CONST
#fim_se
#fim_se

#se_não_definido _REFFMTID_DEFINED
#defina _REFFMTID_DEFINED
#se_definido __cplusplus
#defina REFFMTID constante IID &
#senão
#defina REFFMTID constante IID *__MIDL_CONST
#fim_se
#fim_se
#fim_se

#se_não_definido _SYS_GUID_OPERATORS_
#defina _SYS_GUID_OPERATORS_
#inclua <string.h>

#se_definido __cplusplus
__inline inteiro InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  retorne (((sem_sinal longo *) &rguid1)[0]==((sem_sinal longo *) &rguid2)[0] && ((sem_sinal longo *) &rguid1)[1]==((sem_sinal longo *) &rguid2)[1] &&
    ((sem_sinal longo *) &rguid1)[2]==((sem_sinal longo *) &rguid2)[2] && ((sem_sinal longo *) &rguid1)[3]==((sem_sinal longo *) &rguid2)[3]);
}
__inline inteiro IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { retorne !memcmp(&rguid1,&rguid2,sizeof(GUID)); }
#senão
#defina InlineIsEqualGUID(rguid1,rguid2) (((sem_sinal longo *) rguid1)[0]==((sem_sinal longo *) rguid2)[0] && ((sem_sinal longo *) rguid1)[1]==((sem_sinal longo *) rguid2)[1] && ((sem_sinal longo *) rguid1)[2]==((sem_sinal longo *) rguid2)[2] && ((sem_sinal longo *) rguid1)[3]==((sem_sinal longo *) rguid2)[3])
#defina IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,sizeof(GUID)))
#fim_se

#se_definido __INLINE_ISEQUAL_GUID
#não_definido IsEqualGUID
#defina IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#fim_se

#defina IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#defina IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#se !definido _SYS_GUID_OPERATOR_EQ_ && !definido _NO_SYS_GUID_OPERATOR_EQ_
#defina _SYS_GUID_OPERATOR_EQ_
#se_definido __cplusplus
__inline inteiro operator==(REFGUID guidOne,REFGUID guidOther) { retorne IsEqualGUID(guidOne,guidOther); }
__inline inteiro operator!=(REFGUID guidOne,REFGUID guidOther) { retorne !(guidOne==guidOther); }
#fim_se
#fim_se
#fim_se
#fim_se
