/*
 * revc.c
 * Solution to the third problem for the Rosalind project.
 *
 * In DNA strings, symbols 'A' and 'T' are complements of each other, as are 'C' and 'G'.
 * The reverse complement of a DNA string s is the string sc formed by reversing the symbols
 * of s, then taking the complement of each symbol (e.g., the reverse complement of "GTCA" is "TGAC").
 *
 * Given: A DNA string s of length at most 1000 bp.
 * Return: The reverse complement sc of s.
 *
 *  Created on: Jun 15, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1000

int main(){
	char dna[BUFFER_SIZE], complement[BUFFER_SIZE-1];
	int i, size;
	char *nt = NULL;
	FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	/*  Make sure the file exists	 */
	if(in == NULL || out == NULL){
		printf("Error opening input/output files.  Make sure you have the files correctly named and in the working directory.\n");
		return 1;
	}

	/*  Iterate through BUFFER_SIZE characters at a time */
	while (fgets(dna,BUFFER_SIZE-1, in)!=NULL){
		size = strlen(dna);
		for(i = 0 ; i < size ; i++){
			if( dna[size-i-1] == 'A'){
				complement[i] = 'T';
			}else if( dna[size-i-1] == 'C'){
				complement[i] = 'G';
			}else if( dna[size-i-1] == 'G'){
				complement[i] = 'C';
			}else if( dna[size-i-1] == 'T'){
				complement[i] = 'A';
			}
		}
		printf("%s", complement);
		fputs(complement,out);
	}
	/* Print out the results */
	printf("\nOutput written to output.txt!\n");
	fclose(in);
	fclose(out);
	return 0;
}

