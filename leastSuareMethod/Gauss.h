#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

vector<double>  gaussMetod(vector<vector<double>>& solvation, const int epsilon);
void swap_rows_for_not_null_diagonal(vector<vector<double>>& matrix);