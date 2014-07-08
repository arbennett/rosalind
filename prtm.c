/*
 * prtm.c
 * Solution to the a problem for the Rosalind project.
 *
 * In a weighted alphabet, every symbol is assigned a positive
 * real number called a weight. A string formed from a weighted
 * alphabet is called a weighted string, and its weight is equal
 * to the sum of the weights of its symbols.
 *
 * The standard weight assigned to each member of the 20-symbol
 * amino acid alphabet is the monoisotopic mass of the
 * corresponding amino acid.
 *
 * Given: A protein string P of length at most 1000 aa.
 *
 * Return: The total weight of P. Consult the monoisotopic mass table.
 *
 *  Created on: Jul 7, 2014
 *      Author: Andrew Bennett
 */

/* These are all of the weights
 A 71.03711
 C 103.00919
 D 115.02694
 E 129.04259
 F 147.06841
 G 57.02146
 H 137.05891
 I 113.08406
 K 128.09496
 L 113.08406
 M 131.04049
 N 114.04293
 P 97.05276
 Q 128.05858
 R 156.10111
 S 87.03203
 T 101.04768
 V 99.06841
 W 186.07931
 Y 163.06333
*/
#define BUFFER_SIZE 2000

#include <stdio.h>
#include <string.h>

double getWeight(int aa);

int main(){
	char aa[BUFFER_SIZE];
	int i;
	double weight = 0.0;
	printf("Loading input.txt...\n");
	FILE *in = fopen("input.txt", "r");

	/*  Make sure the file exists	 */
	if(in == NULL){
		printf("Error reading input.txt.  Make sure you have the file correctly named and in the working directory.\n");
		return 1;
	}

	/*  Iterate through BUFFER_SIZE characters at a time */
	while (fgets(aa,BUFFER_SIZE - 1, in)!=NULL){
		for(i=0; i<strlen(aa); i++){
			weight+=getWeight(aa[i]-65); // offset 65 for ascii
		}
	}

	/* Print out the results */
	printf("%f \n", weight);
	fclose(in);
	return 0;
}

/* Gross, but should be fast.  Made it a function
 * to keep the bulk of the code clean. */
double getWeight(int aa){
	double weights[26];
	weights[0] = 71.03711;   // a
	weights[1] = 0.000000;    // b - doesn't exist
	weights[2] = 103.00919;  // c
	weights[3] = 115.02694;  // d
	weights[4] = 129.04259;  // e
	weights[5] = 147.06841;  // f
	weights[6] = 57.02146;   // g
	weights[7] = 137.05891;  // h
	weights[8] = 113.08406;  // i
	weights[9] = 0.000000;    // j - doesn't exist
	weights[10] = 128.09496; // k
	weights[11] = 113.08406; // l
	weights[12] = 131.04049; // m
	weights[13] = 114.04293; // n
	weights[14] = 0.000000;   // o - doesn't exist
	weights[15] = 97.05276;  // p
	weights[16] = 128.05858; // q
	weights[17] = 156.10111; // r
	weights[18] = 87.03203;  // s
	weights[19] = 101.04768; // t
	weights[20] = 0.000000;   // u - doesn't exist
	weights[21] = 99.06841;  // v
	weights[22] = 186.07931; // w
	weights[23] = 0.00000;   // x - doesn't exist
	weights[24] = 163.06333; // y
	weights[25] = 0.000000;   // z - doesn't exist

	/* return the weight */
	if( aa < 26 && aa > -1){
		return weights[aa];
	}else{
		printf("Error: input was %i.", aa);
		return 0.00; // we just wont count invalid input
	}
}
