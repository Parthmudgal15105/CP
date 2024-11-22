long long int right(long long int n)
{
    return 63 - __builtin_clzll(n);
}