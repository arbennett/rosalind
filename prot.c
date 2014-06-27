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
	switch (rna){
	case 'UUU':
		return 'F';
	case 'UUC':
		return 'F';
	case 'UUA':
		return 'L';
	case 'UUG':
		return 'L';
	case 'CUU':
		return 'L';
	case 'CUC':
		return 'L';
	case 'CUA':
		return 'L';
	case 'CUG':
		return 'L';
	case 'AUU':
		return 'I';
	case 'AUC':
		return 'I';
	case 'AUA':
		return 'I';
	case 'AUG':
		return 'M';
	case 'GUU':
		return 'V';
	case 'GUC':
		return 'V';
	case 'GUA':
		return 'V';
	case 'GUG':
		return 'V';
	case 'UCU':
		return 'S';
	case 'UCC':
		return 'S';
	case 'UCA':
		return 'S';
	case 'UCG':
		return 'S';
	case 'CCU':
		return 'P';
	case 'CCC':
		return 'P';
	case 'CCA':
		return 'P';
	case 'CCG':
		return 'P';
	case 'ACU':
		return 'T';
	case 'ACC':
		return 'T';
	case 'ACA':
		return 'T';
	case 'ACG':
		return 'T';
	case 'GCU':
		return 'A';
	case 'GCC':
		return 'A';
	case 'GCA':
		return 'A';
	case 'GCG':
		return 'A';
	case 'UAU':
		return 'Y';
	case 'UAC':
		return 'Y';
	case 'UAA':
		return '\n';
	case 'UAG':
		return '\n';
	case 'CAU':
		return 'H';
	case 'CAC':
		return 'H';
	case 'CAA':
		return 'Q';
	case 'CAG':
		return 'Q';
	case 'AAU':
		return 'N';
	case 'AAC':
		return 'N';
	case 'AAA':
		return 'K';
	case 'AAG':
		return 'K';
	case 'GAU':
		return 'D';
	case 'GAC':
		return 'D';
	case 'GAA':
		return 'E';
	case 'GAG':
		return 'E';
	case 'UGU':
		return 'C';
	case 'UGC':
		return 'C';
	case 'UGA':
		return '\n';
	case 'UGG':
		return 'W';
	case 'CGU':
		return 'R';
	case 'CGC':
		return 'R';
	case 'CGA':
		return 'R';
	case 'CGG':
		return 'R';
	case 'AGU':
		return 'S';
	case 'AGC':
		return 'S';
	case 'AGA':
		return 'R';
	case 'AGG':
		return 'R';
	case 'GGU':
		return 'G';
	case 'GGC':
		return 'G';
	case 'GGA':
		return 'G';
	case 'GGG':
		return 'G';
	default:
		printf("ERROR: Incorrect RNA string.  Check your input file for errors.");
		break;
	}
	return 'Z';
}

