unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned int res = (value >> (n - 1));
    if ((res & 1) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
