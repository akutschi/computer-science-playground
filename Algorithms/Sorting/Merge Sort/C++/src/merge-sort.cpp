// C++ merge sort implementation

#include <iostream>
#include <vector>
#include <math.h> // Required for std::ceil

// Function to merge two sorted arrays
std::vector<int> merge(std::vector<int> vector1, std::vector<int> vector2)
{
    // Vector to store the result of the merge
    std::vector<int> sorted_list;

    uint i = 0; // Counter for split1
    uint j = 0; // Counter for split2

    // Compare values of both vectors and store in result vector
    while (i < vector1.size() && j < vector2.size())
    {
        if (vector1[i] <= vector2[j])
        {
            sorted_list.push_back(vector1[i]);
            i++;
        }
        else
        {
            sorted_list.push_back(vector2[j]);
            j++;
        }
    }
    while (i < vector1.size()) // Store remaining values in result vector
    {
        sorted_list.push_back(vector1[i]);
        i++;
    }
    while (j < vector2.size()) // Store remaining values in result vector
    {
        sorted_list.push_back(vector2[j]);
        j++;
    }

    return sorted_list;
}

// Function for the merge sort algorithm
std::vector<int> merge_sort(std::vector<int> list)
{
    int length = list.size();

    // Base case
    if (length == 1)
    {
        return list;
    }

    // Recursive case
    int center = std::ceil((float)length / 2);

    std::vector<int> split1(list.begin(), list.begin() + center); // "Left" part of the unsorted list
    std::vector<int> split2(list.begin() + center, list.end());   // "Right" part of the unsorted list

    std::vector<int> sublist1 = merge_sort(split1); // Recursive call
    std::vector<int> sublist2 = merge_sort(split2); // Recursice call
    list = merge(sublist1, sublist2);               // Call merge function

    return list;
}

// Driver code
int main()
{
    std::vector<int> unsorted = {6, 15, 33, 1, 8, 7, 2, 4, 10, 12, 23, 56, 5};

    // Print unsorted list
    std::cout << "Unsorted list: ";
    for (auto i : unsorted)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    // Call merge-sort function
    std::vector<int> sorted = merge_sort(unsorted);

    // Print sorted list
    std::cout << "Sorted list:   ";
    for (auto i : sorted)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}
