// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
    BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
    BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
    BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
    BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
    BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
    BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
    BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
    BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
    BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
    BOOST_AUTO_TEST_CASE(is_0_by_default)
    {
        VerifyRational(CRational(), 0, 1);
    }
    BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
    {
        VerifyRational(CRational(10), 10, 1);
        VerifyRational(CRational(-10), -10, 1);
        VerifyRational(CRational(0), 0, 1);
    }
    BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
    {
        VerifyRational(CRational(5, 2), 5, 2);
        VerifyRational(CRational(-5, 2), -5, 2);
        VerifyRational(CRational(5, -2), -5, 2);
        VerifyRational(CRational(-5, -2), 5, 2);
    }
    BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
    {
        VerifyRational(CRational(6, 8), 3, 4);
        VerifyRational(CRational(6, -8), -3, 4);
        VerifyRational(CRational(-6, 8), -3, 4);
        VerifyRational(CRational(-6, -8), 3, 4);
        VerifyRational(CRational(-10, 20), -1, 2);
    }
    BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
    {
        BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
    }



    BOOST_AUTO_TEST_SUITE(ToDouble_function)
        BOOST_AUTO_TEST_CASE(rational_can_be_converted_to_double)
        {
            CRational rational(3, 5);
            BOOST_CHECK_CLOSE_FRACTION(rational.ToDouble(), 0.6, DBL_EPSILON);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(unary_operator)
        BOOST_AUTO_TEST_CASE(unary_plus_returns_the_rational_number_equal_to_the_current)
        {
            CRational rational(3, 5);
            CRational rational2 = +rational;
            VerifyRational(rational2, 3, 5);
        }

        BOOST_AUTO_TEST_CASE(unary_minus_returns_the_rational_number_with_the_opposite_sign)
        {
            CRational rational(3, 5);
            CRational rational2 = -rational;
            VerifyRational(rational2, -3, 5);
            VerifyRational(-rational2, 3, 5);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(binary_operator_plus)
        BOOST_AUTO_TEST_CASE(returns_the_result_of_adding_two_rational_numbers)
        {
            CRational rational1(1, 2);
            CRational rational2(1, 6);
            auto result = rational1 + rational2;
            VerifyRational(result, 2, 3);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_adding_a_rational_number_with_an_integer)
        {
            CRational rational(1, 2);
            auto result = rational + 9;
            VerifyRational(result, 19, 2);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_adding_integer_with_a_rational_number)
        {
            CRational rational(1, 2);
            auto result = 9 + rational;
            VerifyRational(result, 19, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(binary_operator_minus)
        BOOST_AUTO_TEST_CASE(returns_the_result_of_difference_two_rational_numbers)
        {
            CRational rational1(1, 2);
            CRational rational2(1, 6);
            auto result = rational1 - rational2;
            VerifyRational(result, 1, 3);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_difference_a_rational_number_with_an_integer)
        {
            CRational rational(1, 2);
            auto result = rational - 9;
            VerifyRational(result, -17, 2);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_difference_integer_with_a_rational_number)
        {
            CRational rational(1, 2);
            auto result = 9 - rational;
            VerifyRational(result, 17, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(plus_equal_operator)
        BOOST_AUTO_TEST_CASE(can_add_a_rational_number)
        {
            CRational rational1(1, 6);
            CRational rational2(1, 6);
            rational1 += rational2;
            VerifyRational(rational1, 1, 3);
        }

        BOOST_AUTO_TEST_CASE(can_add_by_the_number)
        {
            CRational rational(1, 2);
            rational += 1;
            VerifyRational(rational, 3, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(minus_equal_operator)
        BOOST_AUTO_TEST_CASE(can_subtract_a_rational_number)
        {
            CRational rational1(1, 3);
            CRational rational2(1, 6);
            rational1 -= rational2;
            VerifyRational(rational1, 1, 6);
        }

        BOOST_AUTO_TEST_CASE(can_subtract_by_the_number)
        {
            CRational rational(1, 2);
            rational -= 1;
            VerifyRational(rational, -1, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(multiplication_operator)
        BOOST_AUTO_TEST_CASE(can_multiply_a_rational_number)
        {
            CRational rational1(1, 2);
            CRational rational2(1, 3);
            VerifyRational(rational1 + rational2, 5, 6);
            VerifyRational(rational2 + rational1, 5, 6);
        }

        BOOST_AUTO_TEST_CASE(can_multiply_by_the_number)
        {
            CRational rational(1, 2);
            VerifyRational(rational * 10, 5, 1);
            VerifyRational(-3 * rational, -3, 2);
            VerifyRational(3 * rational, 3, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(division_operator)
        BOOST_AUTO_TEST_CASE(can_divide)
        {
            CRational rational1(1, 2);
            CRational rational2(2, 3);
            VerifyRational(rational1 / rational2, 3, 4);
            VerifyRational(rational1 / 5, 1, 10);
            VerifyRational(7 / rational2, 21, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(multiplication_equal_operator)
        BOOST_AUTO_TEST_CASE(can_multiply_the_value_of_the_first_rational_number_by_another_number)
        {
            CRational rational1(1, 2);
            CRational rational2(2, 3);
            VerifyRational(rational1 *= rational2, 1, 3);
            VerifyRational(rational1 *= 3, 1, 1);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(division_equal_operator)
        BOOST_AUTO_TEST_CASE(can_divide_the_value_of_the_first_rational_number_by_another_number)
        {
            CRational rational1(1, 2);
            CRational rational2(2, 3);
            VerifyRational(rational1 /= rational2, 3, 4);
            VerifyRational(rational1 /= 3, 1, 4);
        }
    BOOST_AUTO_TEST_SUITE_END()



//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////

    BOOST_AUTO_TEST_SUITE(comparison_operator)
        BOOST_AUTO_TEST_CASE(can_divide_the_value_of_the_first_rational_number_by_another_number)
        {
            CRational rational1(1, 2);
            CRational rational2(2, 3);
            VerifyRational(rational1 /= rational2, 3, 4);
            VerifyRational(rational1 /= 3, 1, 4);
        }
    BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
//	(1/2) >= (1/3) → true
//	(1/2) <= (1/3) → false
//	(3/1) > 2      → true
//	(1/2) < 7      → true
//	3 <= (7/2)     → true
//	3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////



BOOST_AUTO_TEST_SUITE_END()
