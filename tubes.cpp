#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

// mengatur  angka dari baris + kolom pada matrix
#define N 3
#define P 2
#define M 3

int main (int argc, char *argv[] )
{
	int tid, nthreads, i, j, k;
	double a[N][P], b[P][M], c[N][M];
	nthreads = 8;
	
#pragma omp parallel shared(a,b,c,nthreads) private(tid,i,j,k)
{	
	#pragma omp for
	for(i=0; i<N; i++)
		for(j=0; j<P; j++)
			a[i][j]= i+j;
			
	#pragma omp for		
	for(i=0; i<P; i++)
		for(j=0; j<M; j++)
			b[i][j]= i*j;
			
	#pragma omp for
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			c[i][j] += 0;
			
}

	printf("Thread : %d \n",tid);
	#pragma omp for	
	for (i=0; i<N; i++)

	{
		printf("Thread : %d menghasilkan Baris : %d \n",tid,i);
		for(j=0; j<M; j++)
			for(k=0; k<P; k++)
			 	c[i][j] += a[i][j] * b[i][j]; 
			}
		return -1;
printf("___________________________\n");	
printf("Result Matrix:\n");
for (i=0; i<N; i++)
  {
	int tid = omp_get_thread_num();
	printf("Hello world from omp thread %d\n", tid);
  for (j=0; j<M; j++) 
    printf("%6.2f  ", c[i][j]);
  printf("\n"); 
}

return (0);
}
	




