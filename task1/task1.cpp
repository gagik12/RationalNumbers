// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Rational.h"


int _tmain(int /*argc*/, _TCHAR* /*argv*/[])
{
    CRational rational1(1, 2);
    CRational rational2(1, 6);
    auto result = 21 + rational1;
    std::cout << result.ToDouble() << std::endl;

	return 0;
}

