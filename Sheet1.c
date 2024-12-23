#include <stdio.h>
#include <stdlib.h>
#define MAX -2147483648 // Minimum possible integer value
#define MIN 2147483647  // Maximum possible integer value

// Function to calculate the sum of all numbers between x and y (exclusive)
int sum(int x, int y)
{
    int result = 0;
    // Check if x is less than y, iterate from x+1 to y-1
    if (x < y)
    {
        for (x = x + 1; x < y; x++)
            result = result + x;
    }
    else
        // If y is less than x, iterate from y+1 to x-1
        for (y = y + 1; y < x; y++)
        {
            result = result + y;
        }
    return result;
}

// Function to find the maximum and minimum numbers entered by the user
void maxMin()
{
    int totalNum = 0, num = 0;
    int max = MAX, min = MIN; // Initialize max and min to extreme values
    printf("Enter the number of numbers to compare: ");
    scanf("%d", &totalNum);

    // Loop to read all numbers and determine max and min
    for (int i = 1; i <= totalNum; i++)
    {
        printf("Number %d = ", i);
        scanf("%d", &num);

        // Update max and min if necessary
        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }
    }
    // Print the final max and min values
    printf("The Max number = %d\nThe Min number = %d\n", max, min);
}

// Function to calculate the sum of user-input numbers
int SUM()
{
    int totalNum = 0, num = 0, result = 0;
    printf("Enter the number of numbers to sum: ");
    scanf("%d", &totalNum);

    // Loop to read all numbers and calculate the sum
    for (int i = 1; i <= totalNum; i++)
    {
        printf("Number %d = ", i);
        scanf("%d", &num);
        result = result + num;
    }
    return result; // Return the final sum
}

// Function to multiply two numbers without using the * operator
int multiply1(int x, int y)
{
    int mul = 0;
    printf("Enter the numbers to multiply: \n%d\n%d\n", x, y);

    // Handle different combinations of positive and negative values for x and y
    if (x > 0 && y > 0)
    {
        for (int i = 1; i <= y; i++)
        {
            mul = mul + x;
        }
    }
    else if (x < 0 && y < 0)
    {
        for (int i = 1; y < 0; y--)
        {
            mul = mul - x;
        }
    }
    else if (x < 0 && y > 0)
    {
        for (int i = 1; i <= y; i++)
        {
            mul = mul + x;
        }
    }
    else if (x > 0 && y < 0)
    {
        for (int i = 1; i <= x; i++)
        {
            mul = mul + y;
        }
    }

    return mul; // Return the multiplication result
}

// Function to multiply two numbers without using the * operator (alternative method)
int multiply2(int x, int y)
{
    int mul = 0;
    printf("Enter the numbers to multiply: \n%d\n%d\n", x, y);

    // Use a while loop to perform multiplication
    if (y > 0 && x > 0)
    {
        while (y > 0)
        {
            mul = mul + x;
            y--;
        }
    }
    else if (y < 0 && x < 0)
    {
        while (y < 0)
        {
            mul = mul - x;
            y++;
        }
    }
    else if ((y > 0 && x < 0))
    {
        while (y > 0)
        {
            mul = mul + x;
            y--;
        }
    }
    else if (y < 0 && x > 0)
    {
        while (x > 0)
        {
            mul = mul + y;
            x--;
        }
    }

    return mul; // Return the multiplication result
}

// Recursive function to multiply two numbers without using the * operator
int multiply3(int x, int y)
{
    // Base case for positive y
    if (y > 0)
    {
        return (x + multiply3(x, y - 1));
    }
    // Case for negative y
    else if (y < 0)
    {
        return -multiply3(x, -y);
    }
    // If y is 0 or x is 0, return 0
    else if (y == 0 || x == 0)
        return 0;
}

// Function to calculate the remainder without using the % operator
void reminder(int x, int y)
{
    int count = 0;
    int num = x;
    // Loop to find the remainder by subtracting multiples of y
    for (; (x / y) * y != x;)
    {
        count++;
        x--;
    }
    printf("The reminder of %d from %d = %d", num, y, count); // Print the result
}

// Function to calculate the power of a number
int powerNum(int num, int power)
{
    int res = 1;
    // Loop to calculate the result of num raised to the power of 'power'
    for (int i = 1; i <= power; i++)
    {
        res = res * num;
    }
    printf("The power of number %d = %d", num, res); // Print the result
    return res;                                      // Return the result
}

// Function to calculate the factorial of a number
int factorial(int num)
{
    int fact = 1;
    // Loop to calculate factorial
    for (int i = 1; i <= num; i++)
        fact = fact * i;
    printf("The factorial of the number %d = %d\n", num, fact); // Print the result
    return fact;                                                // Return the factorial
}

// Function to check if a number is prime
void isPrime(int num)
{
    int flag = 0;
    // Loop to check for divisibility
    for (int i = 2; i < num; i++)
    {
        flag = 0;
        if (num % i == 0)
        {
            flag = 1;
            i = num; // Exit the loop early if a divisor is found
        }
    }
    // Check if the number is prime
    if ((flag == 0 && num != 1) || num == 2)
    {
        printf("The number %d is a Prime number\n", num);
    }
    else
        printf("The number %d is not a Prime number\n", num);
}

// Function to check if a number is a perfect square
void isPerfectSquare(int num)
{
    int i = 0, flag = 0;
    // Loop to check if the square root of the number is an integer
    for (i = 1; i < num; i++)
    {
        if (i * i == num)
        {
            flag = 1;
            i = num; // Exit the loop early if a perfect square is found
        }
    }
    // Print if the number is a perfect square
    if (flag == 1)
    {
        printf("The number %d is a Perfect Square number\n", num);
    }
    else
        printf("The number %d is NOT a Perfect Square number\n", num);
}

// Function to check if a number is a perfect number (sum of divisors equals the number)
void isPerfectNumber(int num)
{
    int reminder = 0, result = 0;
    if (num > 0)
    {
        // Loop to sum divisors of num
        for (int i = 1; i < num; i++)
        {
            reminder = num % i;
            if (reminder == 0)
                result = result + i;
        }
    }
    // Check if the number is perfect
    if (result == num)
    {
        printf("The number %d is a Perfect number\n", num);
    }
    else
        printf("The number %d is not a Perfect number\n", num);
}

// Function to check if a number is a power of two (Method 1)
void baseOfTwo1(int num)
{
    int x = num, count = 0, n = 1;
    // Loop to check if the number is a power of two
    for (int i = 1; x >= 2; i++)
    {
        x = x / 2;
        count++;
    }
    for (int i = 1; i <= count; i++)
    {
        n = n * 2;
    }
    // Print the result
    if (n == num)
    {
        printf("The number %d is a base of two\n", num);
    }
    else
        printf("The number %d is not a base of two\n", num);
}

// Function to check if a number is a power of two (Method 2)
void baseOfTwo2(int num)
{
    int n = num;
    // Loop to check if the number is a power of two
    if (n % 2 == 0 || n / 2 == 0)
    {
        while (n >= 1 && n % 2 == 0)
        {
            n = n / 2;
        }
        if (n == 1)
            printf("The number %d is a base of two\n", num);
    }
    else
        printf("The number %d is not a base of two\n", num);
}

// Function to check if a number is a power of two (Method 3, using bitwise operation)
void baseOfTwo3(int num)
{
    if (num <= 0)
        printf("The number %d is not a base of two\n", num);
    // Check if the number is a power of two using bitwise operation
    if ((num & (num - 1)) == 0)
    {
        printf("The number %d is a base of two\n", num);
    }
    else
        printf("The number %d is not a base of two\n", num);
}

// Function to sum the digits of a number
void digitNum(int num)
{
    int x = num, reminder = 0, result = 0;
    // Loop to sum the digits
    while (x > 0)
    {
        reminder = x % 10;
        result = result + reminder;
        x = x / 10;
    }
    printf("The sum of the digits = %d", result); // Print the sum
}

// Function to sum even numbers entered by the user until two odd numbers are entered
int sumEven()
{
    int num = 0, odd = 0, sum = 0;
    // Loop to read numbers and sum even numbers until two odd numbers are entered
    for (int i = 1; odd != 2; i++)
    {
        printf("Number %d = ", i);
        scanf("%d", &num);
        if (num % 2 != 0)
        {
            odd++;
            num = 0; // Reset the number if odd
            printf("The Number of odd numbers = %d\n", odd);
        }
        sum = sum + num; // Add the even number to the sum
    }
    printf("The sum = %d", sum); // Print the final sum
    return sum;                  // Return the sum
}

// The function holesNum calculates the number of "holes" in a given number
void holesNum(int num)
{
    int n = num, reminder = 0, holes = 0; // Initialize n with the input number, reminder for storing the current digit, and holes to count the total number of holes

    // Iterate through each digit of the number while n is greater than 0
    while (n > 0)
    {
        reminder = n % 10; // Extract the last digit of the current number by using modulo operation (n % 10)

        // Check the digit and determine how many holes it has
        if (reminder == 1 || reminder == 2 || reminder == 3 || reminder == 5 || reminder == 7)
        {
            holes = holes + 0; // Digits 1, 2, 3, 5, and 7 have no holes
        }
        else if (reminder == 0 || reminder == 4 || reminder == 6 || reminder == 9)
        {
            holes = holes + 1; // Digits 0, 4, 6, and 9 each have one hole
        }
        else if (reminder == 8)
        {
            holes = holes + 2; // Digit 8 has two holes
        }

        n = n / 10; // Remove the last digit from n by integer division
    }

    printf("Number of holes = %d", holes); // Print the total number of holes calculated
}

int main()
{
    // (1) Write a program to take 2 numbers from user and calculate sum of all numbers between them.
    // int res = sum(1, 6);
    // printf("%d", res);

    /* (2) Write a program to take numbers from user and find the max and min from them
    (let users choose the No of numbers.*/
    // maxMin();

    /* (3) Write a program to take numbers from user and calculate the sum of them
    (let users choose the No of numbers*/
    // int res = SUM();
    // printf("The result of sum the numbers = %d\n", res);

    /* (4) Write a program that take two numbers and multiply them without using * operation.*/
    /*int a = 4, b = -4;

    int mul = multiply1(a, b);
    printf("The result of multiply of the two numbers %d and %d = %d\n", a, b, mul);
    int mul2 = multiply2(a, b);
    printf("The result of multiply of the two numbers %d and %d = %d\n", a, b, mul2);
    int mul3 = multiply3(a, b);
    printf("The result of multiply of the two numbers %d and %d = %d\n", a, b, mul3);*/

    /*(5) Write a program that take two numbers and calculate the reminder without using % operation.*/
    // reminder(8, 5);

    /*(6) Write a program to calculate the power of a number. The number and its power are input from user.*/
    // powerNum(3,4);

    /*(7) Write a program that reads a positive integer and computes the factorial.*/
    // factorial(5);

    //(8) Write a program that reads a positive integer and checks if it is a prime.
    // for (int i = 1; i <= 140; i++)
    isPrime(137);

    //(9) Write a program that reads a positive integer and checks if it is a perfect square.
    // isPerfectSquare(25);

    /*(10) Write a program that reads a positive integer and check if this number is a base of 2
        like 1,2,4,8,16,32,*/
    /*for (int i = 1; i <= 129; i++)
        baseOfTwo2(i);*/

    //(11) Write a program to sum the digits in a decimal number
    // digitNum(12345);

    /*(12) write a program to take even numbers from user and print the sum of them after each entry if
            the user enters 2 odd number the program print "bye" and stopped.*/
    // sumEven();

    /* (13) Example if number 3824->3 has 0 holes,8 has 2 holes,4 has 1hole sum=0+2+1=3.*/
    // holesNum(3824);

    return 0;
}