#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../src/evalexpr.h"

Test(test_evalexpr, simple_1, .init=cr_redirect_stdout)
{

    RPN("1 1 + ");
    
    //mettre le bon truc
    char *exp = "2\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_2, .init=cr_redirect_stdout)
{

    RPN("111 11 - ");
    
    //mettre le bon truc
    char *exp = "100\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_3, .init=cr_redirect_stdout)
{

    RPN("12 3 1 2 + + *");
    
    //mettre le bon truc
    char *exp = "72\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_4, .init=cr_redirect_stdout)
{

    RPN("1 1+ 10 2*-  ");
    
    //mettre le bon truc
    char *exp = "-18\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_5)
{

    int actual = RPN("12 2 +1 0 / ");
    int expected = 3; 
    //mettre le bon truc
    cr_assert_eq(actual, expected, "Expected %d. Got %d",expected,actual );
}

Test(test_evalexpr, simple_6)
{

    int actual = RPN("12 2 +1 0 % 12 +");
    int expected = 3; 
    //mettre le bon truc
    cr_assert_eq(actual, expected, "Expected %d. Got %d",expected,actual );
}


Test(test_evalexpr, simple_7)
{

    int actual = RPN("");
    int expected = 0; 
    //mettre le bon truc
    cr_assert_eq(actual, expected, "Expected %d. Got %d",expected,actual );
}

Test(test_evalexpr, simple_8, .init=cr_redirect_stdout)
{

    RPN("1 2 2 + - 50 * 2 2 ^ + ");
    
    //mettre le bon truc
    char *exp = "-146\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_9, .init=cr_redirect_stdout)
{

    RPN("9");
    
    //mettre le bon truc
    char *exp = "9\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}


Test(test_evalexpr, simple_to_rpn1, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("1 + 9\n",str));
    //mettre le bon truc
    char *exp = "10\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn2, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("10 +10\n",str));
    //mettre le bon truc
    char *exp = "20\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn3, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("100 -10+ 1\n",str));
    //mettre le bon truc
    char *exp = "91\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn4, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("100 / 20 + 3\n",str));
    //mettre le bon truc
    char *exp = "8\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn5, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("100/20+3^2\n",str));
    //mettre le bon truc
    char *exp = "14\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn6, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("100 % 20 + 55  \n",str));
    //mettre le bon truc
    char *exp = "55\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn7, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("10 * 5 + 3\n",str));
    //mettre le bon truc
    char *exp = "53\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

Test(test_evalexpr, simple_to_rpn8, .init=cr_redirect_stdout)
{
    char str[100];
    RPN(NormalToRPN("10\n",str));
    //mettre le bon truc
    char *exp = "10\n";
    fflush(stdout);

    cr_assert_stdout_eq_str(exp);
}

