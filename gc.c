/**
 * gc.c
 * Solution to a problem for the Rosalind project.
 *
 * The GC-content of a DNA string is given by the percentage of symbols in the string
 * that are 'C' or 'G'. For example, the GC-content of "AGCTATAG" is 37.5%. Note that
 * the reverse complement of any DNA string has the same GC-content.
 *
 * DNA strings must be labeled when they are consolidated into a database. A commonly
 * used method of string labeling is called FASTA format. In this format, the string
 * is introduced by a line that begins with '>', followed by some labeling information.
 * Subsequent lines contain the string itself; the first line to begin with '>' indicates
 * the label of the next string.
 *
 * In Rosalind's implementation, a string in FASTA format will be labeled by the ID
 * "Rosalind_xxxx", where "xxxx" denotes a four-digit code between 0000 and 9999.
 *
 * Given: At most 10 DNA strings in FASTA format (of length at most 1 kbp each).
 *
 * Return: The ID of the string having the highest GC-content, followed by the GC-content
 * 		   of that string. Rosalind allows for a default error of 0.001 in all decimal
 * 		   answers unless otherwise stated; please see the note on absolute error below.
 *
 *  Created on: Jun 28, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2000
#define LABEL_SIZE 13

int main(){
	char dna[BUFFER_SIZE], label[LABEL_SIZE], tempLabel[LABEL_SIZE+1], ind[2];
	int i, size, totalCount, gcCount;
	double currentGC = 0.0;
	double maxGC = 0.0;
	char *maxGC_label = "Rosalind_XXXX";
	printf("Loading input.txt...\n");
	FILE *in = fopen("input.txt", "r");

	/*  Make sure the file exists	 */
	if(in == NULL){
		printf("Error reading input.txt.  Make sure you have the file correctly named and in the working directory.\n");
		return 1;
	}

	/*  Iterate one character to check if it's a label */
	while (fgets(ind, 2, in)!=NULL){
		/* Check if we are starting a new label */
		if(ind[0] == '>'){
			currentGC=gcCount/(double)totalCount;
			if( currentGC > maxGC ){
				maxGC = currentGC;
				maxGC_label = tempLabel;
			}
			totalCount = 0;
			gcCount = 0;
			/* If it is, record the label */
			printf("\n%f",currentGC);
			if (fgets(tempLabel, LABEL_SIZE+1, in)==NULL){
				printf("Error getting label.");
			} else {
				printf("\n\n%s : \n", tempLabel);
			}
		/* Otherwise it might contribute to GC-Content */
		} else {
			printf("%c", ind[0]);
			if (ind[0]=='G' || ind[0]=='C') {
				gcCount++;
				totalCount++;
			}
			/* Now read in the data and do the computation of the GC content */
			if (fgets(dna, BUFFER_SIZE, in	)!=NULL){
				size = strlen(dna);
				totalCount+=size;
				for( i=0; i<size; i++){
					printf("%c",dna[i]);
					if(dna[i]=='G' || dna[i]=='C'){
						gcCount++;
					}
				}
			} else {
				printf("Error reading nucleotides.");
				return 1;
			}
		}
	}
// Need to calculate gc for final dna string - make it a function for ease
	maxGC=100.0*maxGC;
	printf("%s \n%f \n", maxGC_label, maxGC);
	/* Print out the results */
	fclose(in);
	return 0;
}

