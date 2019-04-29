/** Displays gene sequences from a genome string
    Author: Fion Chan

    TODO:
        - Add check to exclude sequences that include stop and start codons
        - Optimize/encapsulate code
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string genome;

	cout << "Enter a genome string: ";
    getline(cin, genome);

    int start = genome.find("ATG");
    int stop, length;
    string gene("");

    while (start > -1) {
        //cout << "start: " << start << endl;
        stop = genome.find("TAG", start + 3);
        if (stop > -1) {
            //cout << "stop: " << stop << endl;
            length = stop - start - 3;
            gene = genome.substr(start + 3, length);
            if (gene.length() % 3 == 0)
                cout << "at TAG: " << gene << endl;
        }
        stop = genome.find("TGA", start + 3);
        if (stop > -1) {
            length = stop - start - 3;
            //cout << "stop: " << stop << endl;
            gene = genome.substr(start + 3, length);
            if (gene.length() % 3 == 0)
                cout << "at TGA: " <<  gene << endl;
        }
        stop = genome.find("TAA", start + 3);
        if (stop > -1) {
            //cout << "stop: " << stop << endl;
            length = stop - start - 3;
            gene = genome.substr(start + 3, length);
            if (gene.length() % 3 == 0)
                cout << "at TAA: " <<  gene << endl;
        }
        start = genome.find("ATG", start + 1);
    }

    return 0;
}
