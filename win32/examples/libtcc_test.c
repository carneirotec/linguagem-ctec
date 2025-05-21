/*
 * Simple Test program para libctec
 *
 * libctec can be useful to use ctec as a "backend" para a code generator.
 */
#inclua <stdlib.h>
#inclua <stdio.h>
#inclua <string.h>

#inclua <libctec.h>

/* this function is called by the generated code */
inteiro add(inteiro a, inteiro b)
{
    retorne a + b;
}

/* this strinc is referenced by the generated code */
constante caractere hello[] = "Hello World!";

caractere my_program[] =
"#inclua <cteclib.h>\n" /* inclua the "Simple libc header para CTEC" */
"externo inteiro add(inteiro a, inteiro b);\n"
"#se_definido _WIN32\n" /* dynamically linked data needs 'dllimport' */
" __attribute__((dllimport))\n"
"#fim_se\n"
"externo constante caractere hello[];\n"
"inteiro fib(inteiro n)\n"
"{\n"
"    se (n <= 2)\n"
"        retorne 1;\n"
"    senão\n"
"        retorne fib(n-1) + fib(n-2);\n"
"}\n"
"\n"
"inteiro foo(inteiro n)\n"
"{\n"
"    printf(\"%s\\n\", hello);\n"
"    printf(\"fib(%d) = %d\\n\", n, fib(n));\n"
"    printf(\"add(%d, %d) = %d\\n\", n, 2 * n, add(n, 2 * n));\n"
"    retorne 0;\n"
"}\n";

inteiro main(inteiro argc, caractere **argv)
{
    CTECState *s;
    inteiro i;
    inteiro (*func)(inteiro);

    s = ctec_new();
    se (!s) {
        fprintf(stderr, "Could not create ctec state\n");
        exit(1);
    }

    /* se cteclib.h and libctec1.a are not installed, where can we find them */
    para (i = 1; i < argc; ++i) {
        caractere *a = argv[i];
        se (a[0] == '-') {
            se (a[1] == 'B')
                ctec_set_lib_path(s, a+2);
            senão se (a[1] == 'I')
                ctec_add_include_path(s, a+2);
            senão se (a[1] == 'L')
                ctec_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    ctec_set_output_type(s, CTEC_OUTPUT_MEMORY);

    se (ctec_compile_string(s, my_program) == -1)
        retorne 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with ctec_add_dll() and use symbols from that */
    ctec_add_symbol(s, "add", add);
    ctec_add_symbol(s, "hello", hello);

    /* relocate the code */
    se (ctec_relocate(s, CTEC_RELOCATE_AUTO) < 0)
        retorne 1;

    /* get entry symbol */
    func = ctec_get_symbol(s, "foo");
    se (!func)
        retorne 1;

    /* run the code */
    func(32);

    /* delete the state */
    ctec_delete(s);

    retorne 0;
}
