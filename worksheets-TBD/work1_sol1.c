//
// saxpy in parallel.
//
// Compile with: gcc -fopenmp -Wall -o work1_sol1 work1_sol1.c
//


//
// Includes.
//
#include <stdio.h>
#include <stdlib.h>					// For EXIT_FAILURE and EXIT_SUCCESS
#include <math.h>					// Needed for fabs
#include <omp.h>					// For messaging and debugging; not required for the actual saxpy operation.


//
// Parameters.
//
const int   n = 20; 				// The vector size
const float a = 2.0;				// The parameter a (float since this is saxpy)


//
// Main
//
int main()
{
	// Allocate the arrays x and y. Note this is saxpy, so single precision (floats) are required.
	float
		*x = (float*) malloc( n*sizeof(float) ),
		*y = (float*) malloc( n*sizeof(float) );

	// Initialise the x and y arrays to something we can use to check the answer later.
	int i;
	for( i=0; i<n; i++ )
	{
		x[i] = i;
		y[i] = 2*i;
	}

	// saxpy in parallel. Some messaging has been included for small n.
	#pragma omp parallel for
	for( i=0; i<n; i++ )
	{
		if( n<100 ) printf( "Index %.2d calculated by thread %d (of %d).\n", i, omp_get_thread_num(), omp_get_max_threads() );
		y[i] = a*x[i] + y[i];
	}

	// Check the answer (in serial; it's just a check, after all).
	// For this simple example, y[i] should be 4*i.
	for( i=0; i<n; i++ )
		if( fabs(y[i]-4.0f*i)>1e-3 )
		{
			printf( "saxpy failed starting at index %d.\n", i );
			free(x);
			free(y);
			return EXIT_FAILURE;
		}

	// If reached here, it was successful.
	printf( "saxpy successful.\n" );
	free(x);
	free(y);

	return EXIT_SUCCESS;
}
