#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
#define pb push_back
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

vvvld dp1(101, vvld(101, vld(101, -1))); // initialize all to -1 meaning not yet computed
vvvld dp2(101, vvld(101, vld(101, -1)));
vvvld dp3(101, vvld(101, vld(101, -1)));

ld solve1(int r, int s, int p)
{
    if (dp1[r][s][p] != -1)
        return dp1[r][s][p]; // returning if dp1[r][s][p] has already been computed
    if (r == 0)
        return dp1[r][s][p] = 0; // Base Case Part 1
    if (r > 0 && s == 0 && p == 0)
        return dp1[r][s][p] = 1; // Base Case Part 2
    ld all = 0;                  // s or p can be 0 and hence all stores the possible meetings for 2 indivuals whose species are non empty
    if (r > 0 && s > 0)
        all += (ld)(r * s); // r and s can meet only when r > 0 and s > 0
    if (r > 0 && p > 0)
        all += (ld)(p * r);
    if (s > 0 && p > 0)
        all += (ld)(p * s);
    dp1[r][s][p] = 0; // reinitialize dp1[r][s][p] to 0
    if (s > 0)
        dp1[r][s][p] += ((ld)(r * s) / all) * solve1(r, s - 1, p); // r and s meet
    if (p > 0)
        dp1[r][s][p] += ((ld)(r * p) / all) * solve1(r - 1, s, p); // r and p meet
    if (s > 0 && p > 0)
        dp1[r][s][p] += ((ld)(s * p) / all) * solve1(r, s, p - 1); // s and p meet
    // dp1(r,s,p) = probability of any 2 meeting * next case
    return dp1[r][s][p];
}

ld solve2(int r, int s, int p)
{
    if (dp2[r][s][p] != -1)
        return dp2[r][s][p]; // only the base cases change
    if (s == 0)
        return dp2[r][s][p] = 0;
    if (s > 0 && r == 0 && p == 0)
        return dp2[r][s][p] = 1;
    ld all = 0;
    if (r > 0 && s > 0)
        all += (ld)(r * s);
    if (r > 0 && p > 0)
        all += (ld)(p * r);
    if (s > 0 && p > 0)
        all += (ld)(p * s);
    dp2[r][s][p] = 0;
    if (r > 0 && s > 0)
        dp2[r][s][p] += ((ld)(r * s) / all) * solve2(r, s - 1, p);
    if (r > 0 && p > 0)
        dp2[r][s][p] += ((ld)(r * p) / all) * solve2(r - 1, s, p);
    if (s > 0 && p > 0)
        dp2[r][s][p] += ((ld)(s * p) / all) * solve2(r, s, p - 1);
    return dp2[r][s][p];
}

ld solve3(int r, int s, int p)
{
    if (dp3[r][s][p] != -1)
        return dp3[r][s][p]; // only the base cases change
    if (p == 0)
        return dp3[r][s][p] = 0;
    if (p > 0 && r == 0 && s == 0)
        return dp3[r][s][p] = 1;
    ld all = 0;
    if (r > 0 && s > 0)
        all += (ld)(r * s);
    if (r > 0 && p > 0)
        all += (ld)(p * r);
    if (s > 0 && p > 0)
        all += (ld)(p * s);
    dp3[r][s][p] = 0;
    if (r > 0 && s > 0)
        dp3[r][s][p] += ((ld)(r * s) / all) * solve3(r, s - 1, p);
    if (r > 0 && p > 0)
        dp3[r][s][p] += ((ld)(r * p) / all) * solve3(r - 1, s, p);
    if (s > 0 && p > 0)
        dp3[r][s][p] += ((ld)(s * p) / all) * solve3(r, s, p - 1);
    return dp3[r][s][p];
}

int main()
{
    int r, s, p;
    cin >> r >> s >> p;
    cout << setprecision(12) << solve1(r, s, p) << " " << solve2(r, s, p) << " " << solve3(r, s, p);
    // do cout<<setprecision(12)<<real;
    // solve1 , solve2 , solve3 are the 3 recursive functions to compute the 3 DP tables
    return 0;
}