/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#se_não_definido _INC_SIGNAL
#defina _INC_SIGNAL

#inclua <_mingw.h>

#se_definido __cplusplus
externo "C" {
#fim_se

#se_não_definido _SIG_ATOMIC_T_DEFINED
#defina _SIG_ATOMIC_T_DEFINED
  defina_tipo inteiro sig_atomic_t;
#fim_se

#defina NSIG 23

#defina	SIGHUP	1	/* hangup */
#defina SIGINT 2
#defina	SIGQUIT	3	/* quit */
#defina SIGILL 4
#defina	SIGTRAP	5	/* trace trap (not reset when caught) */
#defina	SIGIOT	6	/* IOT instruction */
#defina	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#defina	SIGEMT	7	/* EMT instruction */
#defina SIGFPE 8
#defina	SIGKILL	9	/* kill (cannot be caught or ignored) */
#defina	SIGBUS	10	/* bus erro */
#defina SIGSEGV 11
#defina	SIGSYS	12	/* bad argument to system call */
#defina	SIGPIPE	13	/* write on a pipe with no one to read it */
#se_definido __USE_MINGW_ALARM
#defina	SIGALRM	14	/* alarm clock */
#fim_se
#defina SIGTERM 15
#defina SIGBREAK 21
#defina SIGABRT2 22

#defina SIGABRT_COMPAT 6

  defina_tipo	vazio (*__p_sig_fn_t)(inteiro);

#defina SIG_DFL (__p_sig_fn_t)0
#defina SIG_IGN (__p_sig_fn_t)1
#defina SIG_GET (__p_sig_fn_t)2
#defina SIG_SGE (__p_sig_fn_t)3
#defina SIG_ACK (__p_sig_fn_t)4
#defina SIG_ERR (__p_sig_fn_t)-1

  externo vazio **__cdecl __pxcptinfoptrs(vazio);
#defina _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl signal(inteiro _SigNum,__p_sig_fn_t _Func);
  inteiro __cdecl raise(inteiro _SigNum);

#se_definido __cplusplus
}
#fim_se
#fim_se
