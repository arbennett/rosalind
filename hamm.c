/**
 * gc.c
 * Solution to a problem for the Rosalind project.
 *
 * Given two strings s and t of equal length, the Hamming
 * distance between s and t, denoted dH(s,t), is the number
 * of corresponding symbols that differ in s and t. See Figure 2.
 *
 * Given: Two DNA strings s and t of equal length (not exceeding 1 kbp).
 *
 * Return: The Hamming distance dH(s,t).
 *
 *  Created on: Jul 7, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2000

int main(){
	char dna1[BUFFER_SIZE], dna2[BUFFER_SIZE];
	int i;
	int hamm = 0;
	printf("Loading input1.txt...\n");
	FILE *in1 = fopen("input1.txt", "r");
	printf("Loading input2.txt...\n");
	FILE *in2 = fopen("input2.txt", "r");

	/*  Make sure the files exist	 */
	if(in1 == NULL || in2 == NULL){
		printf("Error reading input.  Make sure you have the files correctly named and in the working directory.\n");
		return 1;
	}

	/* We will only go until one of them doesn't exist.
	 * Supposedly the inputs are guaranteed to be the same
	 * length so this assumption will do for this problem. */
	while(fgets(dna1,BUFFER_SIZE-1,in1)!=NULL && fgets(dna2,BUFFER_SIZE-1,in2)!=NULL){
		for(i=0; i<strlen(dna1); i++){
			if(dna1[i]!=dna2[i]){
				printf("\nDifference at location %i:\n%c %c \n", i, dna1[i],dna2[i]);
				hamm+=1;
			}
		}
	}

	/* Print the result */
	printf("%i\n",hamm);
	fclose(in1);
	fclose(in2);
	return 0;
}

