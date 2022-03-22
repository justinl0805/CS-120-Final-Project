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
    
    // Selection Sort
    int i, minIndex, swapIndex = 0;
    int temp;
    while (swapIndex < nums.size() - 1) {
        // Find the minimum value
        minIndex = swapIndex;
        for (i = swapIndex + 1; i < nums.size(); ++i) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
        }
        // See if we need to swap minimum into place
        if (swapIndex != minIndex) {
            temp = nums[swapIndex];
            nums[swapIndex] = nums[minIndex];
            nums[minIndex] = temp;
        }
        // Update swapIndex
        ++swapIndex;

    }

    cout << "To show that SelectionSort worked, here are the first ten and last ten numbers:" << endl;
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
