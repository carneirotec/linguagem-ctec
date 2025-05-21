#inclua <stdio.h>
#inclua <stdlib.h>	// atoi()

inteiro fib(n)
{
	se (n <= 2)
		retorne 1;
	senão
		retorne fib(n-1) + fib(n-2);
}

inteiro main(inteiro argc, caractere **argv) 
{
	inteiro n;
	se (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		retorne 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	retorne 0;
}
