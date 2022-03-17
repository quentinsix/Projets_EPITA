#include <criterion/criterion.h>

#include "../src/my_fnmatch.h"

Test(test_etoile, simple)
{
    int actual = my_fnmatch("\\a\\zer*T", "azerqsjhdfklhqsdlfhT");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_etoile, simple1)
{
    int actual = my_fnmatch("*", "azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_etoile, simple2)
{
    int actual = my_fnmatch("***", "azer");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_etoile, simple3)
{
    int actual = my_fnmatch("*", "");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}

Test(test_etoile, simple_but_marche_pas_ptn)
{
    int actual = my_fnmatch("*ba", "bbbba");
    int expected = 0;
    cr_assert_eq(actual, expected, "Expected %d. Got %d", expected, actual);
}
