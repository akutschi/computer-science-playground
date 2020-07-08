// C++ merge sort implementation

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


// Function for the merge sort algorithm
long int count_inversions(std::vector<int> list)
{
    long int inversions = 0;

    for (uint i = 0; i < list.size() - 1; i++) 
        for (uint j = i + 1; j < list.size(); j++) 
            if (list[i] > list[j]) 
                inversions++; 


    return inversions;
}

// Driver code
int main()
{
    // Read the file with the unsorted numbers
    std::ifstream file_input;  // Create input stream object
    std::vector<int> unsorted; // Create vector for number that come from the file
    file_input.open("IntegerArray.txt");
    if (file_input.is_open()) // Check if file is open
    {
        std::string value; // Create a temporary variable for streaming numbers
        while (std::getline(file_input, value))
        {
            unsorted.push_back(std::stoi(value)); // Fill the vector with the values from the temporary variable
        }
    }
    else
    {
        std::cout << "File is closed." << std::endl;
    }
    file_input.close(); // Close the file

    // Call merge-sort function
    long int inversions = count_inversions(unsorted);

    std::cout << "Number of inversions: " << inversions << std::endl;

    return 0;
}
