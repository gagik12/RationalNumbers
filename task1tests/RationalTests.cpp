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

void VerifyCompoundFraction(std::pair<int, CRational> const& result, int num, int expectedNumerator, int expectedDenominator)
{
    BOOST_CHECK_EQUAL(result.first, num);
    BOOST_CHECK_EQUAL(result.second.GetNumerator(), expectedNumerator);
    BOOST_CHECK_EQUAL(result.second.GetDenominator(), expectedDenominator);
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


    BOOST_AUTO_TEST_SUITE(ToCompoundFraction_function)
        BOOST_AUTO_TEST_CASE(is_as_a_sum_of_int_number_and_proper_fraction)
        {
            VerifyCompoundFraction(CRational(9, 4).ToCompoundFraction(), 2, 1, 4);
            VerifyCompoundFraction(CRational(-9, 4).ToCompoundFraction(), -2, -1, 4);
            VerifyCompoundFraction(CRational(1, 4).ToCompoundFraction(), 0, 1, 4);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(unary_operator)
        BOOST_AUTO_TEST_CASE(unary_plus_returns_the_rational_number_equal_to_the_current)
        {
            VerifyRational(+CRational(3, 5), 3, 5);
        }

        BOOST_AUTO_TEST_CASE(unary_minus_returns_the_rational_number_with_the_opposite_sign)
        {
            VerifyRational(-CRational(3, 5), -3, 5);
            VerifyRational(-CRational(-3, 5), 3, 5);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(binary_operator_plus)
        BOOST_AUTO_TEST_CASE(returns_the_result_of_adding_two_rational_numbers)
        {
            VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_adding_a_rational_number_with_an_integer)
        {
            VerifyRational(CRational(1, 2) + 9, 19, 2);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_adding_integer_with_a_rational_number)
        {
            VerifyRational(10 + CRational(1, 2), 21, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(binary_operator_minus)
        BOOST_AUTO_TEST_CASE(returns_the_result_of_difference_two_rational_numbers)
        {
            VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_difference_a_rational_number_with_an_integer)
        {
            VerifyRational(CRational(1, 2) - 9, -17, 2);
        }

        BOOST_AUTO_TEST_CASE(returns_the_result_of_difference_integer_with_a_rational_number)
        {
            VerifyRational(9 - CRational(1, 2), 17, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(plus_equal_operator)
        BOOST_AUTO_TEST_CASE(can_add_a_rational_number)
        {
            VerifyRational(CRational(1, 6) += CRational(1, 6), 1, 3);
        }

        BOOST_AUTO_TEST_CASE(can_add_by_the_number)
        {
            VerifyRational(CRational(1, 2) += 1, 3, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(minus_equal_operator)
        BOOST_AUTO_TEST_CASE(can_subtract_a_rational_number)
        {
            VerifyRational(CRational(1, 3) -= CRational(1, 6), 1, 6);
        }

        BOOST_AUTO_TEST_CASE(can_subtract_by_the_number)
        {
            VerifyRational(CRational(1, 2) -= 1, -1, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(multiplication_operator)
        BOOST_AUTO_TEST_CASE(can_multiply_a_rational_number)
        {
            VerifyRational(CRational(1, 2) + CRational(1, 3), 5, 6);
            VerifyRational(CRational(3, 4) + CRational(1, 3), 13, 12);
        }

        BOOST_AUTO_TEST_CASE(can_multiply_by_the_number)
        {
            VerifyRational(CRational(1, 2) * 10, 5, 1);
            VerifyRational(-3 * CRational(1, 2), -3, 2);
            VerifyRational(3 * CRational(1, 2), 3, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(division_operator)
        BOOST_AUTO_TEST_CASE(can_divide)
        {
            VerifyRational(CRational(1, 2) / CRational(2, 3), 3, 4);
            VerifyRational(CRational(1, 2) / 5, 1, 10);
            VerifyRational(7 / CRational(2, 3), 21, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(multiplication_equal_operator)
        BOOST_AUTO_TEST_CASE(can_multiply_the_value_of_the_first_rational_number_by_another_number)
        {
            VerifyRational(CRational(1, 2) *= CRational(2, 3), 1, 3);
            VerifyRational(CRational(1, 2) *= 3, 3, 2);
        }
    BOOST_AUTO_TEST_SUITE_END()



    BOOST_AUTO_TEST_SUITE(division_equal_operator)
        BOOST_AUTO_TEST_CASE(can_divide_the_value_of_the_first_rational_number_by_another_number)
        {
            VerifyRational(CRational(1, 2) /= CRational(2, 3), 3, 4);
            VerifyRational(CRational(1, 2) /= 2, 1, 4);
        }
    BOOST_AUTO_TEST_SUITE_END()




    BOOST_AUTO_TEST_SUITE(comparison_operators)
        BOOST_AUTO_TEST_CASE(compare_the_numbers)
        {
            BOOST_CHECK(CRational(1, 2) == CRational(1, 2));
            BOOST_CHECK(CRational(6, 3) == 2);
            BOOST_CHECK(4 == CRational(4, 1));
            BOOST_CHECK(CRational(4, 8) != CRational(4, 16));
            BOOST_CHECK(4 != CRational(4, 2));
            BOOST_CHECK(CRational(5, 2) != CRational(1, 2));

            BOOST_CHECK(CRational(1, 2) > CRational(1, 3));
            BOOST_CHECK(CRational(6, 3) >= 2);
            BOOST_CHECK(CRational(1, 4) < CRational(1, 2));
            BOOST_CHECK(CRational(1, 4) <= CRational(1, 2));
            BOOST_CHECK(CRational(1, 4) <= CRational(1, 4));
        }
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(output_operator)
        BOOST_AUTO_TEST_CASE(can_output_rational_number)
        {
            boost::test_tools::output_test_stream output;
            output << CRational(10, 3);
            BOOST_CHECK(output.is_equal("10/3"));
        }
    BOOST_AUTO_TEST_SUITE_END()


    BOOST_AUTO_TEST_SUITE(input_operator)
        BOOST_AUTO_TEST_CASE(can_input_rational_number)
        {
            std::istringstream stream("4/3");
            CRational rational;
            stream >> rational;
            VerifyRational(rational, 4, 3);
        }
    BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE_END()
