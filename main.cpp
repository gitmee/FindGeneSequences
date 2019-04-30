/** ------------------------------------------------------------------------
    FindGeneSequences
    main.cpp
    Purpose: Displays possible gene sequences from a genome string.

    @author Fion Chan
    @since Apr 29, 2019

    Notes:
        - Output gene sequences exclude start and stop codons
        - Frameshifts are not predicted
        - UTRs are not removed
--------------------------------------------------------------------------*/

#include <iostream>
#include <string>

using namespace std;


// VARIABLES
static const string STOP_CODONS[3] = { "TAG", "TAA", "TGA" };

// FUNCTIONS
bool verifyGene(const string& sequence);
string geneBuilder(int start, int stop, const string& sequence);
void geneFinder(const string& sequence);


int main()
{
    string genome;

	cout << "Enter a DNA string:" << endl;
    getline(cin, genome);

    cout << "Possible gene sequences found:" << endl;
    geneFinder(genome);

    return 0;
}


/**
    Purpose: Checks the sequence for nucleotide length divisible by 3,
    and checks for the exclusion of start and stop codons.
    @param sequence is a DNA sequence
    @return true if sequence satisfies described purpose
    @return false if sequence does not satisfy described purpose
*/
bool verifyGene(const string& sequence) {
    if ((sequence.length() % 3) != 0) return false;
    if (sequence.find("ATG") != -1) return false;
    for (int i = 0; i < STOP_CODONS->size(); i++) {
        if (sequence.find(STOP_CODONS[i]) != -1)
            return false;
    }
    return true;
}

/**
    Purpose: Builds a potential gene string, and checks it using verifyGene.
    @param start is the start codon's starting position
    @param stop is the stop codon's starting position
    @param sequence is a DNA sequence
    @return gene string if verifyGene returns true
    @return empty string if verifyGene returns false
*/
string geneBuilder(int start, int stop, const string& sequence) {
    int length = stop - start - 3;
    string gene = sequence.substr(start + 3, length);
    if (verifyGene(gene)) return gene;
    return "";
}

/**
    Purpose: Searches for and prints possible gene sequences from input.
    @param sequence is a DNA sequence
*/
void geneFinder(const string& sequence) {
    int start = sequence.find("ATG");
    int stop;
    string gene;

    while (start != -1) {
        for (int i = 0; i < STOP_CODONS->size(); i++) {
            stop = sequence.find(STOP_CODONS[i], start + 3);
            if (stop != -1) {
                gene = geneBuilder(start, stop, sequence);
                if (!gene.empty()) cout << gene << endl;
            }
        }
        start = sequence.find("ATG", start + 1);
    }
}
