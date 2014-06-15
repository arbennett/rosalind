/*
 * dna.c
 * Solution to the first problem for the Rosalind project.
 *
 * Given: A DNA string s of length at most 1000 nucleotides.
 * Return: Four integers (separated by spaces) counting
 * 		   the respective number of times that the symbols
 * 		   'A', 'C', 'G', and 'T' occur in s.
 *
 *  Created on: Jun 13, 2014
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

	/* Initialize the nucleotide count */
	int counts[4] = {0, 0, 0, 0};

	/*  Make sure the file exists	 */
	if(in == NULL){
		printf("Error reading input.txt.  Make sure you have the file correctly named and in the working directory.\n");
		return 1;
	}

	printf("Input: \n ");
	/*  Iterate through BUFFER_SIZE characters at a time */
	while (fgets(dna,BUFFER_SIZE - 1, in)!=NULL){
		printf("%s", dna);
		size = strlen(dna);
		for(i = 0 ; i < size ; i++){
			if( dna[i] == 'A'){
				printf("Counting A , %c found\n", dna[i]);
				++counts[0];
			}else if( dna[i] == 'C'){
				printf("Counting C , %c found \n", dna[i]);
				++counts[1];
			}else if( dna[i] == 'G'){
				printf("Counting G , %c found \n", dna[i]);
				++counts[2];
			}else if( dna[i] == 'T'){
				printf("Counting T , %c found\n", dna[i]);
				++counts[3];
			}
		}
	}
	/* Print out the results */
	printf("\nResult: \n A: %d, C: %d, G: %d, T: %d \n", counts[0], counts[1], counts[2], counts[3]);
	fclose(in);
	return 0;
}

