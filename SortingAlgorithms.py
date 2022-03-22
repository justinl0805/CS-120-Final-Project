import time
import subprocess
from subprocess import Popen, PIPE, check_output

print("Let's see how long it takes Python to sort 10,000 random integers from a file!")
print("Enter 1 for BubbleSort, 2 for SelectionSort, 3 for InsertionSort.")
choice = input("Enter an input: ")

while (choice != "1") and (choice != "2") and (choice != "3"):
    print("Invalid input.")
    print("Enter 1 for BubbleSort, 2 for SelectionSort, 3 for InsertionSort.")
    choice = input("Enter an input: ")
else:
    print(choice)


# Start the clock
tic = time.time()

# Read numbers from file
nums = []
with open('numbers.txt') as file:
    for number in file:
        nums.append(int(number))

print("Vector size: " + str(len(nums)))

if choice == "1":
    # Bubble Sort
    haveSwapped = True
    maxIndex = len(nums) - 1
    while haveSwapped:
        haveSwapped = False
        for i in range(maxIndex):
            if nums[i+1] < nums[i]:
                temp = nums[i]
                nums[i] = nums[i+1]
                nums[i+1] = temp
                haveSwapped = True
        maxIndex -= 1

elif choice == "2":
    # Selection Sort
    minIndex = 0
    swapIndex = 0
    temp = None
    maxIndex = len(nums) - 1
    while swapIndex < maxIndex:
        minIndex = swapIndex
        for i in range(swapIndex + 1, maxIndex):
            if nums[i] < nums[minIndex]:
                minIndex = i
        if swapIndex != minIndex:
            temp = nums[swapIndex]
            nums[swapIndex] = nums[minIndex]
            nums[minIndex] = temp
        swapIndex = swapIndex + 1
elif choice == "3":
    # Insertion Sort
    i = None
    insertionIndex = 1
    toBeInserted = None
    maxIndex = len(nums) - 1
    for insertionIndex in range(maxIndex):
        toBeInserted = nums[insertionIndex]
        i = insertionIndex - 1
        while i >= 0 and nums[i] > toBeInserted:
            nums[i + 1] = nums[i]
            i = i - 1
        nums[i + 1] = toBeInserted

print("To show that it worked, here are the first ten and last ten numbers:")
print(nums[:10])
print("...")
print(nums[-10:])

# End clock
toc = time.time()

if choice == "1":
    print("Python Bubble Sort finished in %0.6f seconds" % (toc - tic))
elif choice == "2":
    print("Python Selection Sort finished in %0.6f seconds" % (toc - tic))
elif choice == "3":
    print("Python Insertion Sort finished in %0.6f seconds" % (toc - tic))

print("\nNow let's do it in C++ and compare!")

# Start the clock again
tic2 = time.time()

try:
    # This is Python's way of calling the command line. We use it to compile the C++ files.
    if choice == "1":
        subprocess.check_output("g++ -std=c++1y BubbleSort.cpp",stdin=None,stderr=subprocess.STDOUT,shell=True)
    elif choice == "2":
        subprocess.check_output("g++ -std=c++1y SelectionSort.cpp",stdin=None,stderr=subprocess.STDOUT,shell=True)
    elif choice == "3":
        subprocess.check_output("g++ -std=c++1y InsertionSort.cpp",stdin=None,stderr=subprocess.STDOUT,shell=True)
except subprocess.CalledProcessError as e:
    # There were compiler errors in test_cases.cpp. Print out the error message and exit the program.
    print("<p>",e.output,"</p>")
    raise SystemExit

p = Popen(['a.exe'], shell=True, stdout=PIPE, stdin=PIPE)
print(p.stdout.read())

# End clock
toc2 = time.time()
if choice == "1":
    print("C++ Bubble Sort finished in %0.6f seconds" % (toc2 - tic2))
elif choice == "2":
    print("C++ Selection Sort finished in %0.6f seconds" % (toc2 - tic2))
elif choice == "3":
    print("C++ Insertion Sort finished in %0.6f seconds" % (toc2 - tic2))
