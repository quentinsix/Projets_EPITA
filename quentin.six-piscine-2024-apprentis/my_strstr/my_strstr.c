int my_strstr(const char *haystack, const char *needle)
{
    int len1 = 0;
    int len2 = 0;
    int index = 0;
    const char *s1 = haystack;
    const char *s2 = needle;
    while (s1[len1] != '\0')
    {
        index = len1;
        while (s1[len1] != '\0' && s2[len2] != '\0' && (s1[len1] == s2[len2]))
        {
            len1++;
            len2++;
        }
        if (s2[len2] == '\0')
            return index;
        len2 = 0;
        len1++;
    }
    if (haystack[0] == '\0' && needle[0] == '\0')
        return 0;
    return -1;
}
