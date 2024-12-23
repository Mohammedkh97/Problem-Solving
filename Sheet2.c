#include <stdio.h>
#include <stdlib.h>
#define MAX -2147483648
#define MIN 2147483647
#define PI 3.14159265359
/*
(1) Write a program that reads the radius of a circle and calculates the area and circumference.
*/
/*
(1) Function to calculate the area and circumference of a circle given its radius.
The formula for area: area = π * radius²
The formula for circumference: circumference = 2 * π * radius
*/
void circle(float radius)
{
    float area = 0.0, circumference = 0.0;
    area = PI * radius * radius;                                           // Calculate area
    printf("The area of this circle (%f R)= %f\n", radius, area);          // Print area
    circumference = 2 * PI * radius;                                       // Calculate circumference
    printf("The area of this circle (%f R)= %f\n", radius, circumference); // Print circumference
}

/*
(2) Function to take a number and a character from user.
If the number is even, print the same character.
If the number is odd, print the opposite case of the character (a->A, B->b).
*/
void num_char()
{
    int num;
    char ch;

    printf("Enter a number: ");
    scanf("%d", &num); // Input number
    fflush(stdin);
    printf("Enter a character: ");
    scanf("%c", &ch); // Input character
    fflush(stdin);

    if (num % 2 != 0) // If number is odd
    {
        if (ch >= 'a' && ch <= 'z') // If character is lowercase
        {
            ch = ch - 32; // Convert to uppercase
            printf("Your Number = %d and char = %c", num, ch);
        }
        else if (ch >= 'A' && ch <= 'Z') // If character is uppercase
        {
            ch = ch + 32; // Convert to lowercase
            printf("Your Number = %d and char = %c", num, ch);
        }
        else // If character is not a letter
            printf("The char %c is NOT a Letter\n", ch);
    }
    else
        printf("Your Number = %d and char = %c", num, ch); // Print for even numbers
}

/*
(3) Function to reverse the digits of a number.
For example, for input 1205, output will be 5021.
*/
int reverseDecimal(int num)
{
    int x = num, reminder = 0, result = 0;
    while (x > 0)
    {
        reminder = x % 10;               // Get the last digit
        result = result * 10 + reminder; // Build reversed number
        x = x / 10;                      // Remove last digit
    }
    printf("The entered number = %d\nThe reverse of the number = %d", num, result); // Print reversed number
    return result;
}

/*
(4) Function to count the number of 1's in the binary representation of a 32-bit unsigned integer.
*/
int ones_in_bits(unsigned int num)
{
    int count = 0, n = num;
    for (int i = 0; i < 31; i++) // Iterate through all bits
    {
        if (n & 1)   // Check if the least significant bit is 1
            count++; // Increment the count
        n = n >> 1;  // Shift the number to the right
    }
    printf("The number of ones in %d = %d\n", num, count); // Print the count
    return count;
}

/*
Alternative version of the above function using different bit-shifting.
*/
int ones_inBits(unsigned int num)
{
    int count = 0;
    for (int i = 0; i < 31; i++) // Iterate through all bits
    {
        if ((num >> i) & 1) // Check if the i-th bit is 1
            count++;        // Increment the count
    }
    printf("The number of ones in %d = %d\n", num, count); // Print the count
    return count;
}

/*
(5) Function to print the binary representation of a number without leading zeros.
For example, for input 5, output will be 101.
*/
void Dec_Bin(int num)
{
    int flag = 0;
    for (int i = 31; i >= 0; i--) // Loop through all 32 bits
    {
        if ((num >> i) & 1) // Check if the i-th bit is 1
        {
            flag = 1;
            printf("%d", 1); // Print 1
        }
        else
        {
            if (flag == 1) // Print 0 only after the first 1 is encountered
                printf("%d", 0);
        }
    }
    printf("\n");
}

/*
Alternative version of the above function using an array for binary representation.
*/
void Dec2Bin(int num)
{
    int n = num, bin[8], i = 0;
    while (n > 0)
    {
        bin[i] = n % 2; // Store the remainder (binary digit)
        n = n / 2;      // Divide by 2
        i++;
    }
    for (int j = i - 1; j >= 0; j--) // Print in reverse order
    {
        printf("%d", bin[j]);
    }
    printf("\n");
}

/*
(6) Function to reverse the bits in an 8-bit number.
For example, for input 149, output will be 169.
*/
int reverse_bits(int num)
{
    for (int i = 0; i < sizeof(int); i++) // Iterate through all bits of the integer
    {
        if ((num >> i) & 1)  // Check if the i-th bit is 1
            printf("%d", 1); // Print 1
        else
            printf("%d", 0); // Print 0
    }
    printf("\n");
}

/*
(7) Function to sum the numbers from 1 to a given number (without using loops).
The formula for sum of first n numbers: sum = (n * (n + 1)) / 2
*/
int sum(int num)
{
    int sum = 0;
    sum = (num * (num + 1) / 2); // Calculate sum
    return sum;
}

/*
Alternative version using bitwise operations to calculate the sum.
*/
int sum2(int n)
{
    int sum = 0;
    sum = (n >> 1) * (n + 1) + (n & 1); // Use bitwise operations to calculate sum
    return sum;
}

/*
(8) Function to perform bitwise operations on a given number at a specified position:
1- Set bit
2- Clear bit
3- Toggle bit
4- Read bit
*/
int numOps(int num, int pos)
{
    int choice;
    printf("Choose an option:\n");
    printf("1- Set bit\n");
    printf("2- Clear bit\n");
    printf("3- Toggle bit\n");
    printf("4- Read bit\n");
    printf("Your Choice is: ");
    scanf("%d", &choice); // Input user choice
    switch (choice)
    {
    case 1:
        printf("%d\n", num | (1 << pos)); // Set the bit at the given position
        break;
    case 2:
        printf("%d\n", num & (~(1 << pos))); // Clear the bit at the given position
        break;
    case 3:
        return printf("%d", num ^ (1 << pos)); // Toggle the bit at the given position
        break;
    case 4:
        printf("The bit value = %d , which equivalent to: %d", (num & (1 << pos)) >> pos, num & (1 << pos)); // Read the bit value
        break;
    default:
        printf("Re-enter your choice\n"); // Invalid choice
        break;
    }
}

/*
(9) Function to draw different patterns using '*' based on user input.
Patterns include inverted triangle, triangle, X pattern, and pyramid.
*/
void Patterns()
{
    int choice = 0, rows = 0;
    printf("Please choose the number of pattern type you want: \n");
    printf("1 - Inverted_Triangle\n");
    printf("2 - Triangle\n");
    printf("3 - X Pattern\n");
    printf("4 - Completed Pyramid\n");
    printf("Your Choice is: ");
    scanf("%d", &choice); // Input user choice
    switch (choice)
    {
    case 1:
        printf("Enter the Number of rows: ");
        scanf("%d", &rows);             // Input number of rows for inverted triangle
        for (int i = 1; i <= rows; i++) // Print the inverted triangle
        {
            for (int j = i; j <= rows; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 2:
        printf("Enter the Number of rows: ");
        scanf("%d", &rows);             // Input number of rows for triangle
        for (int i = 1; i <= rows; i++) // Print the triangle
        {
            for (int j = 1; j <= i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    case 3:
        printf("Enter the Number of rows: ");
        scanf("%d", &rows); // Input number of rows for X pattern
        if (rows % 2 == 0)
            rows = rows + 1; // Make sure rows is odd
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= rows; j++)
            {
                if (j == i || j == (rows - i) + 1) // Print '*' at appropriate positions for X pattern
                    printf("* ");
                else
                    printf("  ");
            }
            printf("\n");
        }
        break;
    case 4:
        printf("Enter the Number of rows: ");
        scanf("%d", &rows);             // Input number of rows for pyramid
        for (int i = 1; i <= rows; i++) // Print pyramid
        {
            for (int space = i; space <= rows - 1; space++)
            {
                printf(" ");
            }
            for (int j = 1; j <= (2 * i) - 1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;
    default:
        printf("Re-enter your choice\n"); // Invalid choice
        break;
    }
}

/*
(10) Function to count the maximum number of consecutive zeros between ones in the binary representation of a number.
For example, for input 296384, output will be 4.
*/
int maxNumOfZeros(int num)
{
    char zeros = 0, max_zeros = 0, i = 0, j = 0;
    for (i = 31; i >= 0; i--) // Iterate through all bits
    {
        if (((num >> i) & 1)) // Check if bit is 1
        {
            zeros = 0;
            j = i - 1;
            while (j >= 0 && ((num >> j) & 1) == 0) // Count zeros between 1s
            {
                zeros++;
                j--;
            }
            i = j + 1;
            if (zeros > max_zeros && i != 0) // Update max zeros if necessary
                max_zeros = zeros;
        }
    }
    printf("Max number of zeros = %d\n", max_zeros); // Print max zeros
    return max_zeros;
}

/* (11) Given two integers: L and R, Find the maximal value of A xor B where A and B satisfy
the condition L =< A <= B <= R
Constrains: 1 <= L <= R <= 1000 Input format: the input contains two lines first line contains L and next
line contains R. Output format: The maximum value of Axor B */

// Function to find the maximum XOR value between any two numbers in the range [L, R]
int Max_XOR()
{
    int L = 0, R = 0, xor = 0, maxXor = 0; // Initialize variables: L (left range), R (right range), xor (XOR value), maxXor (maximum XOR found)

    // Prompt the user to enter the value for L (lower bound)
    printf("Enter the Value of L =  ");
    scanf("%d", &L); // Read the value of L from the user

    // Prompt the user to enter the value for R (upper bound)
    printf("Enter the Value of R = ");
    scanf("%d", &R); // Read the value of R from the user

    // Loop through all pairs of numbers A and B, where A is in the range [L, R] and B is in the range [A, R]
    for (int A = L; A >= L; A++) // Outer loop for A, starting from L and ending at R
    {
        for (int B = A; B <= R; B++) // Inner loop for B, starting from A and ending at R
        {
            xor = A ^ B;                         // Calculate the XOR of A and B
            printf("%d ^ %d = %d\n", A, B, xor); // Print the XOR of A and B

            // If the current XOR is greater than the previously found maximum XOR, update maxXor
            if (xor> maxXor)
                maxXor = xor; // Update maxXor with the new maximum XOR value
        }
    }

    // Print the maximum XOR value found
    printf("The maximum value of A xor B = %d", maxXor); // Output the maximum XOR value
}

int main()
{
    // num_char();
    //  reverseDecimal(1205);
    ones_in_bits(9); // 00000000000000000000001111 ==> 15
    ones_inBits(22);
    //  Dec_Bin(2560);
    //  Dec2Bin(149);
    reverse_bits(0b00000101); // 149->10010101 return 169-> 10101001

    // int x = 5;
    // printf("Sum from 1 to %d = %d\n", x, sum(x));
    // printf("Sum from 1 to %d = %d\n", x, sum2(x));
    // numOps(9, 3);
    // Patterns();
    maxNumOfZeros(0b1001000000101000); // 0b1001000000101000 // 296384-> {1001000010111000000}
    // Max_XOR();
}
