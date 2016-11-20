#pragma once


/*
Класс, моделирующий рациональное число
*/
class CRational final
{
public:
    CRational(int numerator = 0, int denominator = 1);

    // Возвращает числитель
    int GetNumerator() const;

    // Возвращает знаменатель
    int GetDenominator() const;

    double ToDouble() const;



    CRational const operator +() const;
    CRational const operator -() const;

    friend CRational const operator +(CRational const& rational1, CRational const& rational2);
    friend CRational const operator -(CRational const& rational1, CRational const& rational2);

    CRational const operator +=(CRational const& rational);
    CRational const operator -=(CRational const& rational);

    friend CRational const operator *(CRational const& rational1, CRational const& rational2);
    friend CRational const operator /(CRational const& rational1, CRational const& rational2);

    CRational const operator *=(CRational const& rational);
    CRational const operator /=(CRational const& rational);

    friend bool const operator ==(CRational const& rational1, CRational const& rational2);
    friend bool const operator !=(CRational const& rational1, CRational const& rational2);

    friend bool const operator <(CRational const& rational1, CRational const& rational2);
    friend bool const operator >(CRational const& rational1, CRational const& rational2);
    friend  bool const operator <=(CRational const& rational1, CRational const& rational2);
    friend  bool const operator >=(CRational const& rational1, CRational const& rational2);

    friend std::ostream & operator<<(std::ostream &stream, CRational const& rational);
    friend std::istream & operator>>(std::istream &stream, CRational & rational);


private:
    int m_numerator;
    int m_denominator;

    // Нормализует рациональное число
    void Normalize();
};

// Вычисляет наибольший общий делитель (greatest common denominator) чисел a и b
unsigned GCD(unsigned a, unsigned b);
