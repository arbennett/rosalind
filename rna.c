/*
 * dna.c
 * Solution to the second problem for the Rosalind project.
 *
 * An RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.
 * Given a DNA string t corresponding to a coding strand, its transcribed RNA string u
 * is formed by replacing all occurrences of 'T' in t with 'U' in u.
 *
 * Given: A DNA string t having length at most 1000 nt.
 * Return: The transcribed RNA string of t.
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
	FILE *out = fopen("output.txt", "w");

	/*  Make sure the file exists	 */
	if(in == NULL || out == NULL){
		printf("Error opening input/output files.  Make sure you have the files correctly named and in the working directory.\n");
		return 1;
	}

	printf("Input: \n ");
	/*  Iterate through BUFFER_SIZE characters at a time */
	while (fgets(dna,BUFFER_SIZE - 1, in)!=NULL){
		printf("%s", dna);
		size = strlen(dna);
		for(i = 0 ; i < size ; i++){
			if( dna[i] == 'T'){
				dna[i]='U';
			}
		}
		fputs(dna, out);
	}
	printf("Output written to output.txt! \n");
	/* Print out the results */
	fclose(in);
	fclose(out);
	return 0;
}

