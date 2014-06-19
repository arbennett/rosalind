/*
 * 1prb.c
 * Solution to the a problem for the Rosalind project.
 *
 * Probability is the mathematical study of randomly occurring phenomena.
 * We will model such a phenomenon with a random variable, which is simply
 * a variable that can take a number of different distinct outcomes depending
 * on the result of an underlying random process.
 *
 * For example, say that we have a bag containing 3 red balls and 2 blue balls.
 * If we let X represent the random variable corresponding to the color of a drawn
 * ball, then the probability of each of the two outcomes is given by Pr(X=red)=35
 * and Pr(X=blue)=25.
 *
 * Random variables can be combined to yield new random variables. Returning to the
 * ball example, let Y model the color of a second ball drawn from the bag (without
 * replacing the first ball). The probability of Y being red depends on whether the
 * first ball was red or blue. To represent all outcomes of X and Y, we therefore use a
 * probability tree diagram. This branching diagram represents all possible individual
 * probabilities for X and Y, with outcomes at the endpoints ("leaves") of the tree. The
 * probability of any outcome is given by the product of probabilities along the path
 * from the beginning of the tree; see Figure 2 for an illustrative example.
 *
 * An event is simply a collection of outcomes. Because outcomes are distinct, the
 * probability of an event can be written as the sum of the probabilities of its constituent
 * outcomes. For our colored ball example, let A be the event "Y is blue." Pr(A) is equal to
 * the sum of the probabilities of two different outcomes: Pr(X=blue and Y=blue)+Pr(X=red and
 * Y=blue), or 310+110=25 (see Figure 2 above).
 *
 * Given: Three positive integers k, m, and n, representing a population containing k+m+n
 *        organisms: k individuals are homozygous dominant for a factor, m are heterozygous,
 *        and n are homozygous recessive.
 *
 * Return: The probability that two randomly selected mating organisms will produce an
 *         individual possessing a dominant allele (and thus displaying the dominant phenotype).
 *         Assume that any two organisms can mate.
 *
 *  Created on: Jun 15, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * Solution:
 * Let N=l+m+n where n is the number of homozygous recessive parents, then there are 2^N total
 * possibilities and 2^n possible recessive phenotypical offspring  Therefore the correct answer
 * is 1-((2^n)/(2^N)) = 1-2^(n-N).
 */

int main(int argc, char **argv){
	if(argc != 4){
		printf("Incorrect number of arguments.  Input format is: \n");
		printf("Homozygous-Dominant Heterozygous-Dominant Homozygous-Recessive \n");
		return 1;
	}

	/* Casting to keep values to integer values as well as flexibility */
	double a = (double) strtol(argv[1], NULL, 0);
	double b = (double) strtol(argv[2], NULL, 0);
	double c = (double) strtol(argv[3], NULL, 0);
	double N = a+b+c;

	if (2 > N){
		printf("You need to have a larger population to breed! \n");
		return 1;
	}

	double prob = (a/N) 				/* Probability to pick a dominant first */
			+ (b/N)*a/(N-1.) 			/* Probability to pick a hetero then a dominant */
			+ (.75)*(b/N)*(b-1.)/(N-1.) /* Probability to pick two hetero  */
			+ (.5)*(b/N)*c/(N-1.)		/* Probability to pick a hetero then a recessive */
			+ (c/N)*a/(N-1.)			/* Probability to pick a recessive then a dominant */
			+ (.5)*(c/N)*b/(N-1.);		/* Probability to pick a recessive then a hetero */
	printf("%f \n", prob);
	return 0;
}

