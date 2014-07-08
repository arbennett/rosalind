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

int main(){
	char aa[BUFFER_SIZE];
	int i;
	float weight = 0.0;
	float item;
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
			item = 'S';
			printf("%f\n", item);
			weight+=1.0*aa[i]; // add em up
		}
	}

	/* Print out the results */
	printf("%f \n", weight);
	fclose(in);
	return 0;
}
