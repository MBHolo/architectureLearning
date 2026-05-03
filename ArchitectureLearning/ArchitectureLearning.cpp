
#include <iostream>
#include <vector>
#include "../src/MathFunc/MathFunc.h" 

int main()
{
    MathFunc mf;

    std::vector<double> result = mf.solve(1.0, 0.0, -4.0);

    for (int i = 0; i < result.size(); i++)
    {

        std::cout << fabs(result[i]);
    }
    
    return 0;
}

