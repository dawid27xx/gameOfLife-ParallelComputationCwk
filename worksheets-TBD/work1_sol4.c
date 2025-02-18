//
// Specimen solution.
//
// Compile with:
//
//  gcc -fopenmp -Wall -o work1_sol work1_sol.c
//


//
// Includes
//
#include <stdio.h>
#include <stdlib.h>


// The problem (i.e. array) size.
#define n 20


// Utility routine to print a vector of given size.
void printVector( int size, float *x )
{
	int i;
	for( i=0; i<size; i++ )
	{
		if( i%20==0 ) printf( "\n" );
		printf( "%.1f\t", x[i] );
	}
	printf( "\n" );
}


//
// Main
//
int main()
{
	int i;

	// Allocate memory for the array and initialise it.
	float *a = (float*) malloc( n*sizeof(float) );
	for( i=0; i<n; i++ ) a[i] = i;

	// Display the initial vector.
	printf( "Initial vector a:" );
	printVector( n, a );

	// Make a copy of the vector a, using the method described in the lecture.
	float *atemp = (float*) malloc( n*sizeof(float) );
	#pragma omp parallel for
	for( i=0; i<n; i++ ) atemp[i] = a[i];

	// Leave the lines with the temporary variable temp alone as it is still necessary in the parallel version.
	// Since this is one calculation out of n, and n is potentially large, it should not affect performance.
	#pragma omp parallel for
	for( i=n-1; i>0; i-- ) a[i] = atemp[i-1];
	a[0] = atemp[n-1];

	// Display the final vector.
	printf( "Final vector a:" );
	printVector( n, a );

	// Clear up and quit.
	free( a );
	free( atemp );
	return EXIT_SUCCESS;
}



