#include <iostream>
#include <string>
#include <vector>
#include <fstream>     // for reading and writing to files
#include <cassert>     // for using assert
#include <chrono>      // for finding the runtime

using namespace std;
using namespace std::chrono;

// Grabs data from the input file:
void grab_data(string file_name, vector<int> &sequence) {
    string line;
    ifstream myfile("inputs/" + file_name + ".txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            sequence.push_back(stoi(line));
        }
    myfile.close();
    }
}

// Overload << for printing vectors of integers:
ostream & operator<<(ostream &output, vector<int> vec) {
    assert (vec.size() > 0);
    for (int i : vec) {
        output << i << " ";
    }
    return output;
}

// Returns the number of inversions in the given sequence:
int count_inversions(vector<int> &sequence) {
    int num_inversions = 0;
    for (int i = 0; i < sequence.size() - 1; i++) {
        for (int j = i + 1; j < sequence.size(); j++) {
            if (sequence.at(i) > sequence.at(j)) {
                num_inversions++;
            }
        }
    }
    return num_inversions;
}

// Returns the minimum entry in the given sequence:
int get_min_entry(vector<int> &sequence) {
    int min_entry = sequence.at(0);
    for (int i : sequence) {
        if (i < min_entry) {
            min_entry = i;
        }
    }
    return min_entry;
}

// Returns the maximum entry in the given sequence:
int get_max_entry(vector<int> &sequence) {
    int max_entry = sequence.at(0);
    for (int i : sequence) {
        if (i > max_entry) {
            max_entry = i;
        }
    }
    return max_entry;
}

// This is the algorithm that Dave described in his original email:
void linear_sort(vector<int> &sequence) {
    // First, determine the minimum and maximum entries:
    int min_entry = 0;
    min_entry = get_min_entry(sequence);
    int max_entry = 0;
    max_entry = get_max_entry(sequence);
    // Calculate the "middle entry":
    int middle_entry = int((min_entry + max_entry) / 2);
    // Now iterate through the sequence, using middle_entry as a pivot:
    vector<int> first_half;
    vector<int> second_half;
    for (int i : sequence) {
        if (i < middle_entry) {
            first_half.push_back(i);
        } else {
            second_half.push_back(i);
        }
    }
    // Overwrite sequence using these newly created halfs:
    sequence.clear();
    for (int i = 0; i < first_half.size(); i++) {
        sequence.push_back(first_half.at(i)); 
    }
    for (int i = 0; i < second_half.size(); i++) {
        sequence.push_back(second_half.at(i));
    }
}

int main(int argc, char **argv) {
    // Read the filename from the command line:
    string file_name(argv[1]);

    // Grab the graph data from the input file:
    vector<int> sequence;
    grab_data(file_name, sequence);

    cout << sequence << endl;
    cout << "number of inversions in original sequence: " << count_inversions(sequence) << endl;

    auto start = high_resolution_clock::now();
    linear_sort(sequence);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << sequence << endl;
    cout << "number of inversions in new sequence: " << count_inversions(sequence) << endl;
    cout << "running time: " << duration.count() << " ms" << endl;
}
