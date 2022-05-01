#include <iostream>
#include <string>
using namespace std;
struct Fraccion
{
    double num1;
    double den1;
    double num2;
    double den2;
};
Fraccion fraccion(double num1, double den1, double num2, double den2)
{
    return {num1, den1, num2, den2};
}
double sumaFraccion(Fraccion f)
{
    return (f.num1 / f.den1) + (f.num2 / f.den2);
}
double restaFraccion(Fraccion f)
{
    return (f.num1 / f.den1) - (f.num2 / f.den2);
}
double productoFraccion(Fraccion f)
{
    return (f.num1 / f.den1) * (f.num2 / f.den2);
}
double cocienteFraccion(Fraccion f)
{
    return (f.num1 / f.den1) / (f.num2 / f.den2);
}
// int restaFraccion(Fraccion f)
// {
//     return f.n1 - f.n2;
// }
// int productoFraccion(Fraccion f)
// {
//     return f.n1 * f.n2;
// }
// int cocienteFraccion(Fraccion f)
// {
//     if (f.n2 != 0)
//     {
//         return f.n1 / f.n2;
//     }
// }