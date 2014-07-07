/*
 * fibd.c
 * Solution to the a problem for the Rosalind project.
 *
 * Given: Positive integers n≤40 and k≤5.
 *
 * Return: The total number of rabbit pairs that will be present after n months
 * 		   if we begin with 1 pair and in each generation, every pair of
 * 		   reproduction-age rabbits produces a litter of k rabbit pairs
 * 		   (instead of only 1 pair).
 *
 *  Created on: Jul 7, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>

long long sum(long long results[],long len);

int main(int argc, char **argv){
	if(argc != 3){
		printf("Incorrect number of arguments.  Input format is: \n");
		printf("Number-Months Lifespan \n");
		return 1;
	}

	/* Read in parameters */
	long N = strtol(argv[1], NULL, 0)+1;
	long k = strtol(argv[2], NULL, 0);
	long long popInAge[k], nOffspring;
	int i,j;

	/* initialize the populations */
	for( i=0 ; i < k ; i++){
		popInAge[i]=0;
	}
	popInAge[0]=1;

	/** Start counting - could probably make this quite a bit more
	 * efficient while still maintaining the ability to see the
	 * demographics, but it'll do for now.   */
	for(i = 1; i < N ; i++){
		printf("---------- Generation %i ----------\n",i);
		/* Determine the number of offspring */
		nOffspring = sum(popInAge, k);
		/* Age the population by shifting the array */
		for(j=k-1; j>-1; j--){
			popInAge[j] = popInAge[j-1];
		}
		/* Set the number of new offspring in the lowest age bin */
		popInAge[0]=nOffspring;
	}
	return 0;
}

/* Just a simple adder with pretty printing */
long long sum(long long results[],long len){
	int i;
	long long total = 0;
	printf("Population: %lld   Age: 0\n", results[0]);
	for( i=1; i<len; i++){
		printf("Population: %lld   Age: %i\n", results[i],i);
		total+=results[i];
	}
	printf("Total Population: %lld\n", total+results[0]);
	return total;
}
