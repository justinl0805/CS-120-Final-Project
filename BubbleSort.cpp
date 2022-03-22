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
    
    // Bubble Sort
    bool haveSwapped = true;
    int maxIndex = nums.size() - 1;
    int i;
    long temp;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i < maxIndex; ++i) {
            // If the items are equal, do not swap (so that this algo is stable)
            if (nums[i+1] < nums[i]) {
                temp = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = temp;
                haveSwapped = true;
            }
        }
        // Update the maximum index
        --maxIndex;
    }
    
    cout << "To show that BubbleSort worked, here are the first ten and last ten numbers:" << endl;
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
