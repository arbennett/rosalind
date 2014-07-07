/**
 * subs.c
 * Solution to a problem for the Rosalind project.
 *
 * Given two strings s and t, t is a substring of s if t is contained as a
 * contiguous collection of symbols in s (as a result, t must be no longer than s).
 *
 * The position of a symbol in a string is the total number of symbols found
 * to its left, including itself (e.g., the positions of all occurrences of 'U'
 * in "AUGCUUCAGAAAGGUCUUACG" are 2, 5, 6, 15, 17, and 18). The symbol at position
 * i of s is denoted by s[i].
 *
 * A substring of s can be represented as s[j:k], where j and k represent the
 * starting and ending positions of the substring in s; for example, if
 * s = "AUGCUUCAGAAAGGUCUUACG", then s[2:5] = "UGCU".
 *
 * The location of a substring s[j:k] is its beginning position j; note that t
 * will have multiple locations in s if it occurs more than once as a substring
 * of s.
 *
 * Given: Two DNA strings s and t (each of length at most 1 kbp).
 *
 * Return: All locations of t as a substring of s.
 *
 *  Created on: Jul 7, 2014
 *      Author: Andrew Bennett
 */
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 2000

	/**********************************************************************************************
	 * * TODO:
	 * An alternate method I would like to consider is using a hash of the motif so that
	 * we could just sum up the next N nucleotide hashes to check instead of doing it
	 * as a characterwise search.  If we assume only the four (or even 5 if we wanted to inclue
	 * rna) it shouldn't be too difficult to do something like 4 primes * 10^n where n is the
	 * index
	 *********************************************************************************************/

int main(int argc, char **argv){
	char dna[BUFFER_SIZE];
	int i;
	printf("Loading input.txt...\n");
	FILE *in = fopen("input.txt", "r");

	/* Make sure we have a motif to look for */
	if(argc != 2){
		printf("Incorrect number of arguments.  Make sure you add a motif to look for.\n");
		return 1;
	}

	/*  Make sure the files exist	 */
	if(in == NULL ){
		printf("Error reading input.txt.  Make sure you have the file correctly named and in the working directory.\n");
		return 1;
	}

	/* Read in parameters */
	char *motif  = argv[1];
	int motif_len = strlen(motif);;

	/* Look for the motif */
	/* An assumption: the dna string fits in the buffer. (otherwise we have to worry about
	 * a motif overlapping the reader and that would just get messy while doing characer checks)*/
	if(fgets(dna,BUFFER_SIZE-1,in)!=NULL){
		int idx, temp_i;
		int dna_len = strlen(dna);
		for(i=0; i<dna_len-motif_len; i++){
			idx=0;
			/* Check the front and back simultaneously for a little optimization */
			while(dna[i+idx]==motif[idx] && dna[i-idx+motif_len-1]==motif[motif_len-1-idx]){
				++idx;
			}
			if(2*idx>=motif_len){
				printf("%i ", i+1); // print out where the motif began
			}
		}
	}
	printf("\n");
	/* Print the result */
	fclose(in);
	return 0;
}

