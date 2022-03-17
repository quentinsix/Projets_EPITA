unsigned int digit(int n, int k)
{
    int r = 0;
    if (n <= 0 || k <= 0)
        return r;
    while (k != 0 && n != 0)
    {
        r = n % 10;
        n = n / 10;
        k--;
        if (n == 0 && k != 0)
            return 0;
    }
    return r;
}
