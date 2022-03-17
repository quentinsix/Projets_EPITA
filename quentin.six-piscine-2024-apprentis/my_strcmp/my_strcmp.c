int ReturnCase(char a, char b)
{
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    return 0;
}

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return ReturnCase(*s1, *s2);
        s1++;
        s2++;
    }
    return ReturnCase(*s1, *s2);
}
