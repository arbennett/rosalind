/*
 * fib.c
 * Solution to the a problem for the Rosalind project.
 *
 * A sequence is an ordered collection of objects (usually numbers),
 * which are allowed to repeat. Sequences can be finite or infinite.
 * Two examples are the finite sequence (π,−2√,0,π) and the infinite
 * sequence of odd numbers (1,3,5,7,9,…). We use the notation an to
 * represent the n-th term of a sequence.
 *
 * A recurrence relation is a way of defining the terms of a sequence
 * with respect to the values of previous terms. In the case of Fibonacci's
 * rabbits from the introduction, any given month will contain the rabbits
 * that were alive the previous month, plus any new offspring. A key
 * observation is that the number of offspring in any month is equal to the
 * number of rabbits that were alive two months prior. As a result, if Fn
 * represents the number of rabbit pairs alive after the n-th month, then we
 * obtain the Fibonacci sequence having terms Fn that are defined by the
 * recurrence relation Fn=Fn−1+Fn−2 (with F1=F2=1 to initiate the sequence).
 * Although the sequence bears Fibonacci's name, it was known to Indian
 * mathematicians over two millennia ago.
 *
 * When finding the n-th term of a sequence defined by a recurrence relation,
 * we can simply use the recurrence relation to generate terms for progressively
 * larger values of n. This problem introduces us to the computational technique
 * of dynamic programming, which successively builds up solutions by using the
 * answers to smaller cases.
 *
 * Given: Positive integers n≤40 and k≤5.
 *
 * Return: The total number of rabbit pairs that will be present after n months
 * 		   if we begin with 1 pair and in each generation, every pair of
 * 		   reproduction-age rabbits produces a litter of k rabbit pairs
 * 		   (instead of only 1 pair).
 *
 *  Created on: Jun 15, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>

int main(int argc, char **argv){
	if(argc != 3){
		printf("Incorrect number of arguments.  Input format is: \n");
		printf("Number-Months Number-Offspring \n");
		return 1;
	}

	/* Read in parameters */
	long N = strtol(argv[1], NULL, 0);
	long k = strtol(argv[2], NULL, 0);
	long long result[N];
	result[0]=1;
	result[1]=1;
	printf("%d \n", result[0]);
	printf("%d \n", result[1]);
	int i;
	/* Might as well store them all and print them all*/
	for(i = 2; i < N ; i++){
		result[i] = result[i-1] + k*result[i-2];
		printf("%lld \n", result[i]);
	}

	return 0;
}

