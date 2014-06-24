/*
 * prot.c
 * Solution to the a problem for the Rosalind project.
 *
 * The 20 commonly occurring amino acids are abbreviated by using 20
 * letters from the English alphabet (all letters except for B, J, O,
 * U, X, and Z). Protein strings are constructed from these 20 symbols.
 * Henceforth, the term genetic string will incorporate protein strings
 * along with DNA strings and RNA strings.
 *
 * The RNA codon table dictates the details regarding the encoding of
 * specific codons into the amino acid alphabet.
 *
 * Given: An RNA string s corresponding to a strand of mRNA (of length at most 10 kbp).
 *
 * Return: The protein string encoded by s.
 *
 *  Created on: Jun 15, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2000

int main(){
	char dna[BUFFER_SIZE];
	int i, size;
	char *nt = NULL;
	printf("Loading input.txt...\n");
	FILE *in = fopen("input.txt", "r");

	/*  Make sure the file exists	 */
	if(in == NULL){
		printf("Error reading input.txt.  Make sure you have the file correctly named and in the working directory.\n");
		return 1;
	}

	/*  Iterate through BUFFER_SIZE characters at a time */
	while (fgets(dna,BUFFER_SIZE - 1, in)!=NULL){
		/* Go through 3 at a time and look it up in the table */
		/* proteins[i]=rnaLookup('abc');
	}

	/* Print out the results */
	fclose(in);
	return 0;
}

char rnaLookup(char rna[]){
	/* Big switch case goes here */
	return 'Z';
}

