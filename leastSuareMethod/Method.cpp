#include "Method.h"
#include "Gauss.h"


void print_vector(const vector<double>& const_vector) {
    double length = const_vector.size();
    for (int i = 0; i < length; ++i) {
        cout << setw(outwidth) << const_vector.at(i);
    }
    cout << endl;
}


void print_matrix(const vector<vector<double>>& matrix) {
    const double rows_num = matrix.size();
    const double column_num = matrix.at(0).size();
    for (int i = 0; i < rows_num; ++i) {
        for (int j = 0; j < column_num; ++j) {
            cout << setw(outwidth) << matrix.at(i).at(j);
        }
        cout << endl;
    }
}

vector<vector<double>> fill_rectangle_matrix(const vector<vector<double>>& matrix, const vector<double>& const_vector) {
    vector<vector<double>> solvation_matrix;
    const double rows_num = matrix.size();
    for (int i = 0; i < rows_num; ++i) {
        vector<double> row;
        for (int j = 0; j <= rows_num; ++j) {
            if (j < rows_num) {
                row.push_back(matrix.at(i).at(j));
            }
            else {
                row.push_back(const_vector.at(i));
            }
        }
        solvation_matrix.push_back(row);
    }
    return solvation_matrix;
}



vector<double> minimal_square_method(const vector<double>& x, vector<double>& y, const double& M) {
    double m = M + 1;
    double N = x.size();
    vector<double> POWERX;
    for (int i = 1; i <= 2 * (m - 1); ++i) {
        double staff = 0;
        for (int j = 0; j < N; ++j) {
            staff += pow(x.at(j), i);//N-ный икс возводим в i-тую степень и суммируем
        }
        POWERX.push_back(staff);
    }
    cout << "POWERX:\n";
    print_vector(POWERX);
    vector<vector<double>> SUMX(m, vector<double>(m, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!i && !j) {
                SUMX.at(0).at(0) = N;
            }
            else {
                SUMX.at(i).at(j) = POWERX.at(i + j - 1);
            }
        }
    }
    cout << "\nSUMX:\n";
    print_matrix(SUMX);
    cout << "\n";
    vector<double> right_part;
    for (int i = 0; i < m; ++i) {
        double staff = 0;
        for (int j = 0; j < N; ++j) {
            staff += y.at(j) * pow(x.at(j), i);
        }
        right_part.push_back(staff);
    }
    cout << "\nright_part:\n";
    print_vector(right_part);
    vector<vector<double>> rectangle = fill_rectangle_matrix(SUMX, right_part);
    vector<double> answers = gaussMetod(rectangle, 0);
    double remaining_variance = 0;
    for (int i = 0; i < N; ++i) {//сумма от 1 до N (yi - a0 -a1xi)
        double staff = y.at(i);
        for (int j = 0; j < m; ++j) {
            staff -= answers.at(j) * pow(x.at(i), j);
        }
        remaining_variance += pow(staff, 2);
    }
    cout << " \nremaining variance = " << remaining_variance / (N - m - 1) << endl; //остаточная дисперсия
    cout << " \nstandard deviation = " << sqrt(remaining_variance / (N - m - 1)) << endl; //стандартное отклонение
    return answers;
}
