//
// Example of red-black Gauss-Seidel applied (for one iteration only) to a 1D vector.
// Compile with:
//
// gcc -fopenmp -Wall -o redBlackGaussSeidel redBlackGaussSeidel.c
//


//
// Includes
//
#include <stdio.h>
#include <stdlib.h>


// Problem size
#define n 10


// Displays the vector with a maximum of 20 elements per line.
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
	int i, redBlack;

	// Initialise the array and initialise.
	float *a = (float*) malloc( n*sizeof(float) );
	for( i=0; i<n; i++ ) a[i] = i*i;

	// Show thew initial state of the vector.
	printf( "The initial vector a:" );
	printVector( n, a );

	// The main loop. Performs a single iteration of red-black Gauss-Seidel in serial.
	for( redBlack=0; redBlack<2; redBlack++ )
	{
		for( i=1; i<n-1; i++ )
			if( i%2 == redBlack )
				a[i] = 0.5f * ( a[i-1] + a[i+1] );

		// For this demonstration, display the vector after each of the 'red' (even) and 'black' (odd) loops.	
		printf( "The vector after the redBlack=%d loop:", redBlack );
		printVector( n, a );
	}

	// Clear up and quit.
	return EXIT_SUCCESS;
}

