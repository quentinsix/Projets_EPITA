#include <criterion/criterion.h>

#include "../src/my_fnmatch.h"

Test(test_qmark, qmark_simple)
{
    int actual = my_fnmatch("ez[[a-z]R[[a-z]", "ezaR[");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_qmark, qmark_simple2)
{
    int actual = my_fnmatch("ez?[[a-z]R?[[a-z]", "ez1aRR[");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_qmark, qmark_end)
{
    int actual = my_fnmatch("ez[[a-z]R[[a-z]?", "ezaR[");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_qmark, qmark_not_match_hard)
{
    int actual = my_fnmatch("ze[!!]z?e???", "ez!zretre");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_qmark, qmark_not_match_had)
{
    int actual = my_fnmatch("??ze[!!]z?e???", "?ez!zretre");
    int expected = 1;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}
