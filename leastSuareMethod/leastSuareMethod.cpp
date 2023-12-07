#include "Method.h"
#include "Gauss.h"

int main()
{
    vector<double> x = { 1.1, 1.4, 1.7, 2.1, 2.6, 4.7, 6.1, 7.0, 10.0, 12.8, 16.5, 20.8, 40.6 };
    vector<double> y = { 25.0, 22.7, 22.1, 19.8, 17.0, 12.3, 10.7, 10.0, 8.2, 6.7, 5.6, 5.0, 3.5 };
    double n = x.size();
    for (int i = 0; i < n; ++i) {
        y[i] = log(y[i]);
        x[i] = log(x[i]);
    }
    vector<double> coef = minimal_square_method(x, y, 1);
    coef[1] = -1 / coef[1];
    coef[0] = exp(coef[0]);
    print_vector(coef);
    return 0;
}