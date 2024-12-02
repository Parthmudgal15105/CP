#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <climits>

using namespace std;

int main()
{
    // Input: N = number of available substrings
    int N;
    cin >> N;

    // Store the available substrings and collect all unique characters
    vector<string> substrings(N);
    set<char> chars_in_substrings;
    for (int i = 0; i < N; ++i)
    {
        cin >> substrings[i];
        for (char c : substrings[i])
        {
            chars_in_substrings.insert(c);
        }
    }

    // Input: main string to be formed and max allowed deletions K
    string main_string;
    cin >> main_string;
    int K;
    cin >> K;

    // Validate if all characters in main string can be found in available substrings
    // If any character is missing, it's impossible to form the string
    for (char c : main_string)
    {
        if (chars_in_substrings.find(c) == chars_in_substrings.end())
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    // Dynamic Programming approach
    // dp[i] represents minimum deletions needed to form string up to index i
    int L = main_string.length();
    vector<int> dp(L + 1, INT_MAX);
    dp[0] = 0; // Base case: empty string needs 0 deletions

    // For each position in main string
    for (int i = 0; i < L; ++i)
    {
        if (dp[i] == INT_MAX)
            continue; // Skip if current position is unreachable

        // Try each available substring
        for (const string &sub : substrings)
        {
            // Count required deletions to match substring with main string
            int deletions = 0;
            int j = 0; // Index for substring
            int k = i; // Index for main string

            // Try to match substring with main string starting from position i
            while (j < sub.length())
            {
                if (k < L && sub[j] == main_string[k])
                {
                    j++;
                    k++; // Characters match, move both pointers
                }
                else
                {
                    j++; // Character doesn't match, count as deletion
                    deletions++;
                }
            }

            // Update dp if we found a better way to reach position k
            if (dp[k] > dp[i] + deletions)
            {
                dp[k] = dp[i] + deletions;
            }
        }
    }

    // Final output based on dp result
    if (dp[L] <= K)
    {
        // Entire string can be formed within K deletions
        cout << "Possible" << endl;
    }
    else
    {
        // Find longest possible prefix that can be formed
        int pos = L;
        while (pos > 0 && dp[pos] > K)
        {
            pos--;
        }

        // Output result based on what's possible
        if (pos == 0)
        {
            cout << "Nothing" << endl; // Can't form any prefix
        }
        else
        {
            cout << main_string.substr(0, pos) << endl; // Output maximum possible prefix
        }
    }
    return 0;
}