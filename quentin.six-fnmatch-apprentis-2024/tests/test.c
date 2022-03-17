#include <criterion/criterion.h>

#include "../src/my_fnmatch.h"

Test(test_my_fnmatch, simple)
{
    int actual = my_fnmatch("azer", "azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, simple1)
{
    int actual = my_fnmatch("a[ze&r", "a[ze&r");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, no_match_simple)
{
    int actual = my_fnmatch("zer", "zer]");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, no_match_simple1)
{
    int actual = my_fnmatch("azer", "");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, no_match_simple3)
{
    int actual = my_fnmatch("[!aze]", "z");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, simple3)
{
    int actual = my_fnmatch("[a-z]zer", "azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}
Test(test_my_fnmatch, simple4bis)
{
    int actual = my_fnmatch("([d]zko)", "(dzko)");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, simple4)
{
    int actual = my_fnmatch("[[]", "[");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, range1)
{
    int actual = my_fnmatch("[a-z][s][!a]", "asb");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}
Test(test_my_fnmatch, range2)
{
    int actual = my_fnmatch("[!a-e][--1]", "z-");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, range3)
{
    int actual = my_fnmatch("[!!]", "a");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, range4)
{
    int actual = my_fnmatch("ez[[a-z]R[[a-z]", "ezaR[");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_my_fnmatch, no_match_range4)
{
    int actual = my_fnmatch("ze[!!]ze", "ez!ze");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}
