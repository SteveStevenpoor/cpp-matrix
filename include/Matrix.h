#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
    vector<vector<double>> buf_;
    int cols_, rows_;

    public:
        Matrix(const vector<double>& vec);
        Matrix(const vector<vector<double>>& buf);
        Matrix(const int& rows, const int& cols);

        Matrix operator+(const Matrix& other) const;
        void operator+=(const Matrix& other);

        Matrix operator*(const Matrix& other) const;
        void operator*=(const Matrix& other);

        Matrix operator*(const double& val) const;
        void operator*=(const double& val);

        vector<double>& operator[](const int& at);
        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const;
        
        explicit operator double() const;

        void print() const;

};

#endif // MATRIX_H
