int my_pow(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result *= a;
        b = b >> 1;
        a *= a;
    }
    return result;
}
