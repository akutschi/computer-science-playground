// C++ program to multiply two very large numbers

#include <iostream>

// Function to multiply two numbers represented as strings
std::string multiplication(std::string num1, std::string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    // Create string for solution with maximum possible length
    std::string result(len1 + len2, '0');

    // Go from right to left in num1
    for (int i = len1 - 1; i >= 0; i--)
    {
        // Go from right to left in num2
        for (int j = len2 - 1; j >= 0; j--)
        {
            int p = (num1[i] - '0') * (num2[j] - '0');

            // Calculate carry and store in i+j
            result[i + j] = ((result[i + j] - '0') + ((p + (result[i + j + 1] - '0')) / 10)) + '0';

            // Calculate and store the result for position i+j+1
            result[i + j + 1] = ((p + (result[i + j + 1] - '0')) % 10) + '0';
        }
    }

    return result;
}

// Driver code
int main()
{
    std::string num1 = "3141592653589793238462643383279502884197169399375105820974944592";
    std::string num2 = "2718281828459045235360287471352662497757247093699959574966967627";

    std::cout << "Result: " << multiplication(num1, num2) << std::endl;
    // Correct result: 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184

    return 0;
}
