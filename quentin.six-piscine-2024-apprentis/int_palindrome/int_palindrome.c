int int_palindrome(int n)
{
    if (n < 0)
        return 0;
    int result = 0;
    int tmp = n;
    while (n != 0)
    {
        result *= 10;
        result += (n % 10);
        n = n / 10;
    }
    if (tmp - result == 0)
        return 1;
    return 0;
}
