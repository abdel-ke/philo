/* FILE: hello.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Omara Aly
* LAST REVISED: 
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5

FILE	*file;

void	*PrintHello(void *threadid)
{
	file = fopen("/dev/ttys002", "w");
	long	tid;
	tid = (long)threadid;
	fprintf(file, "Hello World! It's me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	for(t = 0; t < NUM_THREADS; t++)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
