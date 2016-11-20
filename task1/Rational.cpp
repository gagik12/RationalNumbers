#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
    : m_numerator(numerator)
    , m_denominator(denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator must not be equal to zero");
    }
    if (denominator < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = -m_denominator;
    }
    Normalize();
}

int CRational::GetNumerator() const
{
    return m_numerator;
}

int CRational::GetDenominator() const
{
    return m_denominator;
}

void CRational::Normalize()
{
    const int gcd = GCD(abs(m_numerator), m_denominator);
    m_numerator /= gcd;
    m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
    while (b != 0)
    {
        std::swap(a, b);
        b = b % a;
    }
    return (a != 0) ? a : 1;
}



double CRational::ToDouble() const
{
    return static_cast<double>(m_numerator) / m_denominator;
}



CRational const CRational::operator +() const
{
    return *this;
}

CRational const CRational::operator -() const
{
    return CRational(-m_numerator, m_denominator);
}


CRational const operator +(CRational const& rational1, CRational const& rational2)
{
    int numerator = rational1.GetNumerator() * rational2.GetDenominator() +
        rational2.GetNumerator() * rational1.GetDenominator();
    int denominator = rational1.GetDenominator() * rational2.GetDenominator();
    return CRational(numerator, denominator);
}



CRational const operator -(CRational const& rational1, CRational const& rational2)
{
    int numerator = rational1.GetNumerator() * rational2.GetDenominator() -
        rational2.GetNumerator() * rational1.GetDenominator();
    int denominator = rational1.GetDenominator() * rational2.GetDenominator();
    return CRational(numerator, denominator);
}


CRational const CRational::operator +=(CRational const& rational)
{
    if (rational.GetNumerator() == 0)
    {
        return *this;
    }
    *this = *this + rational;
    Normalize();
    return *this;
}


CRational const CRational::operator -=(CRational const& rational)
{
    if (rational.GetNumerator() == 0)
    {
        return *this;
    }
    *this = *this - rational;
    Normalize();
    return *this;
}




CRational const operator *(CRational const& rational1, CRational const& rational2)
{
    int numerator = rational1.GetNumerator() * rational2.GetNumerator();
    int denominator = rational1.GetDenominator() * rational2.GetDenominator();
    return CRational(numerator, denominator);
}



CRational const operator /(CRational const& rational1, CRational const& rational2)
{
    int numerator = rational1.GetNumerator() * rational2.GetDenominator();
    int denominator = rational1.GetDenominator() * rational2.GetNumerator();
    return CRational(numerator, denominator);
}



CRational const CRational::operator *=(CRational const& rational)
{
    if (rational.GetNumerator() == 0)
    {
        return *this;
    }
    *this = *this * rational;
    Normalize();
    return *this;
}

CRational const CRational::operator /=(CRational const& rational)
{
    if (rational.GetNumerator() == 0)
    {
        return *this;
    }
    *this = *this / rational;
    Normalize();
    return *this;
}




//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////

bool const operator ==(CRational const& rational1, CRational const& rational2)
{
    return (rational1.GetNumerator() == rational2.GetNumerator()) &&
        (rational1.GetDenominator() == rational2.GetDenominator());
}

bool const operator !=(CRational const& rational1, CRational const& rational2)
{
    return (rational1.GetNumerator() != rational2.GetNumerator()) ||
        (rational1.GetDenominator() != rational2.GetDenominator());
}


bool const operator <(CRational const& rational1, CRational const& rational2)
{
    return rational1.GetNumerator() * rational2.GetDenominator() <
        rational1.GetDenominator() * rational2.GetNumerator();
}

bool const operator >(CRational const& rational1, CRational const& rational2)
{
    return rational1.GetNumerator() * rational2.GetDenominator() >
        rational1.GetDenominator() * rational2.GetNumerator();
}

bool const operator <=(CRational const& rational1, CRational const& rational2)
{
    return !(rational1 > rational2);
}

bool const operator >=(CRational const& rational1, CRational const& rational2)
{
    return !(rational1 < rational2);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////


