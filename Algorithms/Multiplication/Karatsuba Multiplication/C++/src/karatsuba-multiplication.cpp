// C++ program to multiply two very large numbers with the
// Karatsuba algorithm

#include <iostream>
#include <string>
#include <math.h> // Required for std::ceil

// Function to equalize two strings
void string_equalize(std::string &string1, std::string &string2)
{
    int len1 = string1.size();
    int len2 = string2.size();

    // Make both strings of equal length
    while (len1 < len2)
    {
        string1 = "0" + string1;
        len1 = string1.size();
    }
    while (len2 < len1)
    {
        string2 = "0" + string2;
        len2 = string2.size();
    }
}

// Function to add two strings
std::string string_add(std::string add1, std::string add2)
{
    // Make both strings of equal length
    string_equalize(add1, add2);

    int len1 = add1.size();

    // Create result string with maximum possible length
    std::string result(len1 + 1, '0');

    for (int i = len1 - 1; i >= 0; i--)
    {
        int sum = (result[i + 1] - '0') + (add1[i] - '0') + (add2[i] - '0');

        // Calculate carry and store in i+j
        result[i] = (sum / 10) + '0';

        // Calculate and store the result for position i+j+1
        result[i + 1] = (sum % 10) + '0';
    }

    // Remove leading zeros and return string
    return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
}

// Function to subtract two strings
std::string string_sub(std::string sub1, std::string sub2)
{
    // Make both strings of equal length
    string_equalize(sub1, sub2);

    int len1 = sub1.size();

    // Create result string with maximum possible length
    std::string result(len1, '0');

    int carry = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int diff = (sub1[i] - '0') - (sub2[i] - '0') - carry;

        if (diff < 0)
        {
            diff += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        // Calculate and store the result for position i
        result[i] = (diff % 10) + '0';
    }

    // Remove leading zeros and return string
    return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
}

// Function to multiply two numbers represented as strings
std::string karatsuba(std::string num1, std::string num2)
{
    // Make both strings of equal length
    if (num1.size() != num2.size())
    {
        string_equalize(num1, num2);
    }

    int len1 = num1.size();
    int len2 = num2.size();

    // Create string for solution
    std::string result;

    // Base case
    if (len1 < 2 && len2 < 2)
    {
        //std::string result(len1 + len2, '0');
        int base_case = ((num1[0] - '0') * (num2[0] - '0'));
        // Calculate ten's place
        result = (base_case / 10) + '0';
        // Calculate one's place
        result.push_back((base_case % 10) + '0');
        return result;
    }

    // Get middle of the two strings
    int n_half = std::ceil((float)len1 / 2);
    int center = len1 - n_half;

    // Create substrings, separated in the center
    std::string num1_high = num1.substr(0, center); // Substring starts at position 0 from num1 and ends after n_half characters
    std::string num1_low = num1.substr(center);     // Substring starts at position n_half and includes all charcaters until the end of the string
    std::string num2_high = num2.substr(0, center);
    std::string num2_low = num2.substr(center);

    std::string res_low = karatsuba(num1_low, num2_low);   // Recursive call
    std::string res_hig = karatsuba(num1_high, num2_high); // Recursive call

    std::string mix1 = string_add(num1_low, num1_high);
    std::string mix2 = string_add(num2_low, num2_high);
    std::string res_mix = karatsuba(mix1, mix2); // Recursive call

    // "Final components" of the Karatsuba multiplication
    std::string first = res_hig + std::string(2 * n_half, '0');
    std::string second = string_sub(string_sub(res_mix, res_hig), res_low) + std::string(n_half, '0');
    std::string third = res_low;

    // Return the result of the multiplication by adding all "final components"
    return string_add(first, string_add(second, third));
}

// Driver code
int main()
{
    std::string num1 = "314159265358979323846264338327950288419716939937510582097494459";
    std::string num2 = "271828182845904523536028747135266249775724709369995957496696762";
    
    std::cout << "Result: \n"
              << karatsuba(num1, num2) << std::endl;
    // Correct result: 85397342226735670654635508695465744950348885357651149618796010996400308128465617086587964465544038881186949128462929098241758
    // Compare with Wolfram Alpha:
    // https://www.wolframalpha.com/input/?i=314159265358979323846264338327950288419716939937510582097494459*271828182845904523536028747135266249775724709369995957496696762

    return 0;
}