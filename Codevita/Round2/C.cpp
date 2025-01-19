#include <bits/stdc++.h>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)

// Types of declarations /////////////////////////////////
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

// Odd Even /////////////////////////////////////////////
bool odd(ll num) { return ((num & 1) == 1); }
bool even(ll num) { return ((num & 1) == 0); }

//////////////////////////////////////////////////////// Prime

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

///////////////////////////////////////////////////////// LCM GCD
long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}
////////////////////////////////////////////////////////// SQR ROOT

long long sqrt(long long x)
{
    long long s = 0, e = 2e9, res = s;
    while (s <= e)
    {
        long long m = (s + e) / 2;
        if (m * m <= x)
            res = m, s = m + 1;
        else
            e = m - 1;
    }
    return res;
}

/*
check all edge cases
check for integer overflow
check for corner cases
check for constraints
check for time complexity
check for array bounds
check for negative values
*/

/*----------------------------------------------------------------------------*/
vector<string> digits = {
    " _ | ||_|",  // 0
    "     |  |",  // 1
    " _  _||_ ",  // 2
    " _  _| _|",  // 3
    "   |_|  |",  // 4
    " _ |_  _|",  // 5
    " _ |_ |_|",  // 6
    " _   |  |",  // 7
    " _ |_||_|",  // 8
    " _ |_| _|"}; // 9

map<string, char> segments = {
    {" _ | ||_|", '0'}, {"     |  |", '1'}, {" _  _||_ ", '2'}, {" _  _| _|", '3'}, {"   |_|  |", '4'}, {" _ |_  _|", '5'}, {" _ |_ |_|", '6'}, {" _   |  |", '7'}, {" _ |_||_|", '8'}, {" _ |_| _|", '9'}, {"     |   ", '+'}, {"     | _ ", '-'}, {" _  | |  ", '*'}, {" _   |  |", '/'}, {"     |   ", '('}, {"     |   ", ')'}, {"         ", '='}};

string evaluate(const string &expr)
{
    // 1. Convert expr to postfix or use a direct recursive approach.
    // 2. Evaluate with correct precedence (BODMAS).
    // 3. Return the numeric result as a string.
    // Example (infix-to-postfix + stack eval):
    // ...implementation...
    return "";
}

bool validate_equation(string lhs, string rhs)
{
    return evaluate(lhs) == rhs;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> rows(3);
    for (int i = 0; i < 3; ++i)
        cin >> rows[i];

    // Parse the display to get the characters
    vector<string> blocks(n);
    for (int i = 0; i < n; ++i)
    {
        string block = "";
        for (int j = 0; j < 3; ++j)
        {
            block += rows[j].substr(i * 3, 3);
        }
        blocks[i] = block;
    }

    string expression = "";
    for (const auto &block : blocks)
    {
        if (segments.count(block))
        {
            expression += segments[block];
        }
        else
        {
            expression += '?'; // Unknown or faulty character
        }
    }

    // Split into LHS and RHS
    auto equal_pos = expression.find('=');
    string lhs = expression.substr(0, equal_pos);
    string rhs = expression.substr(equal_pos + 1);

    // Check if equation is valid
    if (validate_equation(lhs, rhs))
    {
        cout << "Perfect" << '\n';
        return;
    }

    // Toggle LEDs to find the faulty character
    for (int i = 0; i < n; ++i)
    {
        if (blocks[i] == "=" || i >= equal_pos)
            continue;

        for (int j = 0; j < 9; ++j)
        { // Toggle each LED
            string toggled = blocks[i];
            toggled[j] = (toggled[j] == ' ' ? '_' : ' ');

            if (segments.count(toggled))
            {
                string fixed_expression = expression;
                fixed_expression[i] = segments[toggled];

                // Revalidate
                string fixed_lhs = fixed_expression.substr(0, equal_pos);
                if (validate_equation(fixed_lhs, rhs))
                {
                    cout << i << '\n';
                    return;
                }
            }
        }
    }

    cout << "Perfect" << '\n';
}

/*
Kumar's calculator has developed a glitch, and he needs your help to fix it!

His calculator uses a seven-segment display to show characters. Each character is represented as a 3x3 matrix. The problem is one of the LEDs in the display is malfunctioning.

To find the faulty LED, Kumar entered an equation on his calculator. The left-hand side (LHS) of the equation includes brackets, numbers, and operators, while the right-hand side (RHS) has a single value.

He knows that only one LED is faulty, and the LEDs for brackets are working fine. Can you help Kumar figure out the zero-based index of the character with the faulty LED? Remember to include operators and brackets when counting from left to right.

The arrangement of 7 segment display for each number from 0-9 is shown below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@cd7f1ae:image1.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@cd7f1ae:image2.png


Fig. 1 Fig. 2

The arrangement of 7 segment display for the 5 mathematical operations is shown below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@cd7f1ae:image3.png

Fig. 3

The arrangement of 7 segment display for the opening and closing brackets is shown below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@cd7f1ae:image4.png

Fig. 4

Given the seven-segment display of the entire equation (including LHS, RHS and "="), find the index of the faulty character.

Constraints
1 <= N <= 50

Follow BODMAS rules while performing the calculations.

Equal to symbol and RHS will never be faulty.

It is guaranteed that there will be only one solution possible.

Input
First line consists of an integer N denoting the number of characters in the given entire equation.

Next 3 lines consists of the matrix of size 3*(N*3) representing the seven-segment display of the equation.

Output
Print a single integer denoting the zero-basis index of the character that is faulty. If the equation is perfect and do not have any faulty characters, print "Perfect".

Time Limit (secs)
1

Examples
Example 1

Input

9

_ | _ _ | _

_| _|| | _||_| | _ _|

|_ || | ||_| | _ |_

Output

5

Explanation

The equation given in the input is -

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@cd7f1ae:image5.png

which represents 2+[1*8]=2

Upon evaluation, the LHS value is 10, while the RHS value is 2, resulting in an invalid equation. To fix this, toggle the middle LED of the digit 8. The equation then becomes 2+[1*0]=2, where both LHS and RHS are equal. Since the index of the faulty character is 5, output 5.

Example 2

Input

28

| _ _ | | _ | _ | | _ _ _ _ | _ _ | _ _ _

| | _| _| | _|| | _| _| | _|| | _| _| _| _||_ | _| || | | _ |_||_||_|

| | ||_ | || | ||_ | || | |_ | _| | _| | | ||_| | _ _| _| _|

Output

7

Explanation

The equation given in the input is -

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@cd7f1ae:image6.png

which is [7+2]+[1+2]*[[2*3+5]*10]=999

Upon evaluation, the LHS value is 339, while the RHS value is 999, resulting in an invalid equation. To fix this, toggle the one LED of the digit at index 7 to make it 7. The equation then becomes [7+2]+[7+2]*[[2*3+5]*10]=999, where both LHS and RHS are equal. Since the index of the faulty character is 7, output 7.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();
}
