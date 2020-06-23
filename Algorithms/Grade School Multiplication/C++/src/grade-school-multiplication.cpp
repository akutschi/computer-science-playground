// C++ program to multiply two very large numbers

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

// Function to multiply two numbers represented as strings
std::string multiplication(std::string num1, std::string num2)
{
    std::vector<int> num1vec;
    std::vector<int> num2vec;

    // Convert string to vector of ints
    for (size_t i = 0; i < num1.size(); ++i)
    {
        num1vec.push_back(num1[i] - '0');
    }

    // Convert string to vector of ints
    for (size_t i = 0; i < num2.size(); ++i)
    {
        num2vec.push_back(num2[i] - '0');
    }

    int len1 = num1vec.size();
    int len2 = num2vec.size();
    // Create vector for solution with maximum possible length
    std::vector<int> resultvec(len1 + len2);

    // Go from right to left in num1vec
    for (int i = len1 - 1; i >= 0; i--)
    {
        // Go from right to left in num2vec
        for (int j = len2 - 1; j >= 0; j--)
        {
            int p = num1vec[i] * num2vec[j];
            // Calculates the "carry" and keeps the results from previous calculations in mind
            resultvec[i + j] = resultvec[i + j] + (resultvec[i + j + 1] + p) / 10;
            // Calculate and store the result for position i+j+1
            resultvec[i + j + 1] = (resultvec[i + j + 1] + p) % 10;
        }
    }

    // Converts the vector to a string
    std::stringstream resulttmp;
    std::copy(resultvec.begin(), resultvec.end(), std::ostream_iterator<int>(resulttmp, ""));
    std::string result = resulttmp.str();

    return result;
}

// Driver code
int main()
{
    std::string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
    std::string num2 = "2718281828459045235360287471352662497757247093699959574966967627";

    std::cout << "Result: " << multiplication(num1, num2) << std::endl;

    return 0;
}