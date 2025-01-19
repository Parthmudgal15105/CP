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
int timeToMinutes(string t)
{
    // Remove the last two characters (AM/PM)
    // Note: one pop_back() was already called; call again.
    t.pop_back();
    // Now t has no suffix, e.g. "9:01A" -> "9:01"
    // ...parse HH:MM...
    // For brevity, assume HH:MM plus an already-trimmed 'A' or 'P' somewhere:
    int hour = stoi(t.substr(0, t.find(':')));
    int minute = stoi(t.substr(t.find(':') + 1));

    // If original suffix was "PM" and hour != 12, add 12
    // If original suffix was "AM" and hour == 12, set hour = 0
    // (Use your existing logic or adapt accordingly)
    return hour * 60 + minute;
}

void solve()
{
    int N;
    cin >> N;
    cin.ignore();

    map<int, vector<pair<string, int>>> logs; // EmployeeID -> (Activity, Time)
    while (N--)
    {
        int id;
        string activity, location, time;
        cin >> id >> activity >> location >> time;
        time.pop_back(); // Remove "AM" or "PM" suffix
        logs[id].emplace_back(activity + " " + location, timeToMinutes(time));
    }

    int suspectID;
    cin >> suspectID;

    map<int, int> workTime; // EmployeeID -> Total work time
    for (auto it = logs.begin(); it != logs.end(); ++it)
    {
        int id = it->first;
        vector<pair<string, int>> &entries = it->second;
        stack<int> entryTimes; // Stack to track enter times for rooms
        int totalWorkTime = 0;

        for (auto &entry : entries)
        {
            string actionLoc = entry.first;
            int timestamp = entry.second;
            string action = actionLoc.substr(0, 6);
            string location = actionLoc.substr(7);

            if (location.find("room") != string::npos)
            {
                if (action == "enters")
                {
                    entryTimes.push(timestamp);
                }
                else if (action == "exits" && !entryTimes.empty())
                {
                    totalWorkTime += timestamp - entryTimes.top();
                    entryTimes.pop();
                }
            }
        }

        workTime[id] = totalWorkTime;
    }

    // Find the employee with the least work time
    int minWorkTime = INT_MAX;
    vector<int> leastWorkEmployees;
    for (auto it = workTime.begin(); it != workTime.end(); ++it)
    {
        int id = it->first;
        int time = it->second;

        if (time < minWorkTime)
        {
            minWorkTime = time;
            leastWorkEmployees = {id};
        }
        else if (time == minWorkTime)
        {
            leastWorkEmployees.push_back(id);
        }
    }

    // Determine the output
    if (find(leastWorkEmployees.begin(), leastWorkEmployees.end(), suspectID) != leastWorkEmployees.end())
    {
        cout << "Yes" << '\n';
    }
    else if (leastWorkEmployees.size() == 1)
    {
        cout << "No" << '\n';
    }
    else
    {
        cout << "Cannot be determined" << '\n';
    }
}

/*
Min Office Hours
Problem Description
An IT organization is trying to improve employee productivity by implementing mandatory work hours. However, employees are finding ways to avoid these hours, such as taking extended breaks or "tailgating" (following others through entry systems without swiping their ID cards). This leads to difficulties in accurately tracking work time.

The manager of a specific project wants to identify the employee who spends the least amount of time working to implement a penalty system. He suspects one employee but needs help verifying if this suspicion is accurate.

Data:

Log Records: A daily log on a particular day of employee ID card swipes at various locations, including:
Rooms (e.g., room1, room2...roomN)
Cafeterias (e.g., cafeteria1, cafeteria2...cafeteriaM)
Pantries (e.g., pantry1, pantry2...pantryN)
Challenge: Analyse the log data to determine:

Actual Work Time: Calculate the time spent working by each employee in any room, excluding breaks and time spent in pantries and cafeterias.
Suspect Verification: Confirm if the suspected employee truly spends the least amount of time working compared to all other project members.
Constraints
5 < N < 200

10 < Employee ID < 1000

Input
Line 1: N - This integer represents the total number of log entries recorded by the system.
Lines 2 to N+1: Log Entries - Each line describes a single employee activity and follows this structure:
EmployeeID: An integer representing the unique ID of the employee.
Activity: A string indicating either "enters" or "exits".
Location: A string specifying where the activity occurred (e.g., "room1", "cafeteria2", "pantry3").
Time: A string representing the time of the activity in 12-hour format (e.g., "10:30 AM").
Line N+2: Suspect EmployeeID - This line contains a single integer, the ID of the employee the manager is suspicious about.
Output
Single line consisting of 'Yes/No/Cannot be determined'.

Yes - if the manager's suspicion is correct

No - if the manager's suspicion is incorrect

Cannot be determined - if it is not possible to determine whether the suspected employee had worked for the least duration or not.

Time Limit (secs)
1

Examples
Example 1

Input

10

101 enters cafeteria1 9:01AM

101 exits cafeteria1 10:17AM

154 enters room5 9:15AM

153 exits room4 11:40AM

153 enters pantry2 2:00PM

101 enters room4 12:01PM

154 exits room5 1:05PM

153 exits pantry2 4:00PM

153 enters room4 10:16AM

101 exits room4 1:25PM

153

Output

Yes

Explanation

Analysis:

Based on the 10 log entries provided, employees with ID 101 and 153 have the shortest working duration at 1 hour and 24 minutes. This calculation only considers time spent in workrooms (e.g., "room1", "room3") and excludes time in cafeterias or pantries.
The manager is specifically questioning employee ID 153's actual work time.
Answer: Yes, the manager has a valid reason to doubt EmployeeID 153 as being the one with least working hours.

Example 2

Input

10

101 enters cafeteria1 9:01AM

101 exits cafeteria1 10:17AM

154 enters room5 9:15AM

153 exits room4 11:20AM

153 enters pantry2 2:00PM

101 enters room6 12:01PM

154 exits room5 1:05PM

153 exits pantry2 4:00PM

153 enters room4 10:16AM

101 exits room4 1:49PM

153

Output

Cannot be determined

Explanation

Analysis:

The system recorded only 10 logs in total.
Employee ID 101's work time is unreliable due to missing entry and exit logs.
We only have records of them entering room 4 and exiting room 6, suggesting potential tailgating (following another employee through the entry system without swiping their own ID card).
Conclusion:

Because of incomplete log data for EmployeeID 101, we cannot definitively determine whether they worked for the shortest duration compared to other employees. The missing logs raise questions about their actual work time.
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;

    while (t--)
        solve();
}
