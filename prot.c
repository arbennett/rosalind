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

#define BUFFER_SIZE 3

char rnaLookup(char rna[]);
void printError();

int main(){
	char rna[BUFFER_SIZE];
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
	while (fgets(rna,BUFFER_SIZE+1, in)!=NULL){
		char prot = rnaLookup(rna);
		printf("%c", prot);
	}
    printf("\n");
	/* Print out the results */
	fclose(in);
	return 0;
}

/**
 * Putting this in a nested switch-case leads to
 * log base 4 order lookup tree.
 */
char rnaLookup(char *rna){
	char prot;
	switch (rna[0]){
	// First nucleotide is U
	case 'U':
		switch (rna[1]){
		// UU
		case 'U':
			switch (rna[2]){
			// UUU
			case 'U':
				prot = 'F';
				break;
			// UUC
			case 'C':
				prot = 'F';
				break;
			// UUA
			case 'A':
				prot = 'L';
				break;
			// UUG
			case 'G':
				prot = 'L';
				break;
			default:
				printError();
				break;
			}
			break;
		// UC
		case 'C':
			prot = 'S';
			break;
		// UA
		case 'A':
			switch (rna[2]){
			// UAU
			case 'U':
				prot = 'Y';
				break;
			// UAC
			case 'C':
				prot = 'Y';
				break;
			// UAA
			case 'A':
				prot = '\n';
				break;
			// UAG
			case 'G':
				prot = '\n';
				break;
			default:
				printError();
				break;
			}
			break;
		// UG
		case 'G':
			switch (rna[2]){
			// UGU
			case 'U':
				prot = 'C';
				break;
			// UGC
			case 'C':
				prot = 'C';
				break;
			// UGA
			case 'A':
				prot = '\n';
				break;
			// UGG
			case 'G':
				prot = 'W';
				break;
			default:
				printError();
				break;
			}
			break;
		default:
			printError();
			break;
		}
		break;
	// First nucleotide is C
	case 'C':
		switch (rna[1]){
		// CU
		case 'U':
			prot = 'L';
			break;
		// CC
		case 'C':
			prot = 'P';
			break;
		// UA
		case 'A':
			switch (rna[2]){
			// CAU
			case 'U':
				prot = 'H';
				break;
			// CAC
			case 'C':
				prot = 'H';
				break;
			// CAA
			case 'A':
				prot = 'Q';
				break;
			// CAG
			case 'G':
				prot = 'Q';
				break;
			default:
				printError();
				break;
			}
			break;
		// CG
		case 'G':
			prot = 'R';
			break;
		default:
			printError();
			break;
		}
		break;
	// First nucleotide is A
	case 'A':
		switch (rna[1]){
		// AU
		case 'U':
			switch (rna[2]){
			// AUU
			case 'U':
				prot = 'I';
				break;
			// AUC
			case 'C':
				prot = 'I';
				break;
			// AUA
			case 'A':
				prot = 'I';
				break;
			// AUG
			case 'G':
				prot = 'M';
				break;
			default:
				printError();
				break;
			}
			break;
		// AC
		case 'C':
			prot = 'T';
			break;
		// AA
		case 'A':
			switch (rna[2]){
			// AAU
			case 'U':
				prot = 'N';
				break;
			// AAC
			case 'C':
				prot = 'N';
				break;
			// AAA
			case 'A':
				prot = 'K';
				break;
			// AAG
			case 'G':
				prot = 'K';
				break;
			default:
				printError();
				break;
			}
			break;
		// AG
		case 'G':
			switch (rna[2]){
			// AGU
			case 'U':
				prot = 'S';
				break;
			// AGC
			case 'C':
				prot = 'S';
				break;
			// AGA
			case 'A':
				prot = 'R';
				break;
			// AGG
			case 'G':
				prot = 'R';
				break;
			default:
				printError();
				break;
			}
			break;
		default:
			printError();
			break;
		}
		break;
	// First nucleotide is G
	case 'G':
		switch (rna[1]){
		// GU
		case 'U':
			prot = 'V';
			break;
		// GC
		case 'C':
			prot = 'A';
			break;
		// GA
		case 'A':
			switch (rna[2]){
			// GAU
			case 'U':
				prot = 'D';
				break;
			// GAC
			case 'C':
				prot = 'D';
				break;
			// GAA
			case 'A':
				prot = 'E';
				break;
			// GAG
			case 'G':
				prot = 'E';
				break;
			default:
				printError();
				break;
			}
			break;
		// CG
		case 'G':
			prot = 'G';
			break;
		default:
			printError();
			break;
		}
		break;
	default:
		printError();
		break;
	}
	return prot;
}

void printError(){
	return;
}
