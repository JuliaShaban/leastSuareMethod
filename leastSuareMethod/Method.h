#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
const double outwidth = 20;
const double round_error = pow(10, -6);

vector<double> minimal_square_method(const vector<double>& x, vector<double>& y, const double& M);
void print_matrix(const vector<vector<double>>& matrix);
void print_vector(const vector<double>& const_vector);
vector<vector<double>> fill_rectangle_matrix(const vector<vector<double>>& matrix, const vector<double>& const_vector);