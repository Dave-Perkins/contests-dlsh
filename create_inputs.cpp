#include <iostream>
#include <string>
#include <fstream>     // for reading and writing to files
#include <ctime>       // for randomness
using namespace std;

int main(int argc, char **argv) {
    // Setup for randomness:
    srand(time(0));

    // Grab filename, desired number of entries, and maximum entry from command line:
    string file_name(argv[1]);
    int num_entries;
    num_entries = stoi(argv[2]);
    int max_entry;
    max_entry = stoi(argv[3]);

    // Write the entries to a .txt file:
    ofstream myfile("inputs/" + file_name + ".txt");
    for (int i = 0; i < num_entries; i++) {
        myfile << rand() % max_entry + 1 << endl;
    }
    myfile.close();
}
