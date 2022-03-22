#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long> nums;
    
    // Read numbers from file
    ifstream inFile("numbers.txt");
    long num;
    while (inFile) {
        inFile >> num;
        if (inFile) {
            nums.emplace_back(num);
        }
    }
    inFile.close();
    cout << "Vector size: " << nums.size() << endl;
    
    // Insertion Sort
    int insertionIndex, i;
    int toBeInserted;
    for (insertionIndex = 1; insertionIndex < nums.size(); ++insertionIndex) {
        toBeInserted = nums[insertionIndex];
        i = insertionIndex - 1;
        while (i >= 0 && nums[i] > toBeInserted) {
            // slide the larger element over
            nums[i + 1] = nums[i];
            --i;
        }
        // Reinsert the item back into the vector
        nums[i + 1] = toBeInserted;
    }


    cout << "To show that InsertionSort worked, here are the first ten and last ten numbers:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << nums[i] << ", ";
    }
    cout << endl << "..." << endl;
    for (int i = nums.size() - 10; i < nums.size(); ++i) {
        cout << nums[i] << ", ";
    }
    cout << endl;

    return 0;
}
