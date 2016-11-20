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
private:
    int m_numerator;
    int m_denominator;

    // Нормализует рациональное число
    void Normalize();
};

// Вычисляет наибольший общий делитель (greatest common denominator) чисел a и b
unsigned GCD(unsigned a, unsigned b);
