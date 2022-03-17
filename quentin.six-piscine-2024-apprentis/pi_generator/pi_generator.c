double pi_generator(int precision)
{
    if (precision == 0)
        return 0.0;
    double r = 1, p = 1;
    for (int i = 1; i < precision + 1; i++)
    {
        double a = i / ((i * 2.0) + 1.0);
        r += p * a;
        p *= a;
    }
    r *= 2;
    return r;
}
