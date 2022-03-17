#include <criterion/criterion.h>

#include "../src/my_fnmatch.h"

Test(test_echap, simple)
{
    int actual = my_fnmatch("\\a\\zer", "azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, simple1)
{
    int actual = my_fnmatch("aze\\r", "azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, not_match_simple0)
{
    int actual = my_fnmatch("\\\\\\", "\\\\a\\");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, not_match_simple)
{
    int actual = my_fnmatch("aze\\n", "azer");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, match_hard)
{
    int actual = my_fnmatch("[!!\\cb]aze\\r", "aazer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, not_match_hard)
{
    int actual = my_fnmatch("\\[a-z]ze\\r", "azer");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, match_hard1)
{
    int actual = my_fnmatch("\\\\a[\\]\\[!aze\\r", "\\a\\[!azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_echap, match_hard2)
{
    int actual = my_fnmatch("[!\\]\\az\\e\\r", "aazer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}
