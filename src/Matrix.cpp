#include "Matrix.h"
#include <cmath>
#include <limits>
#include <iostream>

Matrix::Matrix(const vector<double>& vec) {
    rows_ = vec.size();
    cols_ = rows_;
    buf_ = vector<vector<double>>(rows_);
    for (int i = 0; i < cols_; i++) {
        buf_[i] = vector<double>(cols_, 0.0);
        buf_[i][i] = vec[i];
    }
}

Matrix::Matrix(const int& rows, const int& cols) : rows_(rows), cols_(cols) {
    buf_ = vector<vector<double>>(rows_);
    for (int i = 0; i < cols_; i++) {
        buf_[i] = vector<double>(cols_, 0.0);
    }
}

Matrix::Matrix(const vector<vector<double>>& buf) {
    rows_ = buf.size();
    cols_ = buf[0].size();
    buf_ = buf;
}

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix sum{rows_, cols_};
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            sum.buf_[i][j] = buf_[i][j] + other.buf_[i][j];
        }
    }

    return sum;
}

void Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            buf_[i][j] += other.buf_[i][j];
        }
    }
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix mul{rows_, cols_};
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            for (int k = 0; k < cols_; k++) {
                mul.buf_[i][j] += buf_[i][k]*other.buf_[k][j];
            }
        }
    }

    return mul;
}

void Matrix::operator*=(const Matrix& other) {
    Matrix mul{rows_, cols_};
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            for (int k = 0; k < cols_; k++) {
                mul.buf_[i][j] += buf_[i][k]*other.buf_[k][j];
            }
        }
    }

    *this = mul;
}

Matrix Matrix::operator*(const double& val) const {
    Matrix mul{rows_, cols_};
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            mul.buf_[i][j] = buf_[i][j] * val;
        }
    }

    return mul;
}

void Matrix::operator*=(const double& val) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            buf_[i][j] *= val;
        }
    }
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            double left  = buf_[i][j];
            double right = other.buf_[i][j];

            if (fabs(left - right) > numeric_limits<double>::epsilon()) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

Matrix::operator double() const {
    double sum = 0.0;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            sum += buf_[i][j];
        }
    }
    
    return sum;
}

// TODO: out of bound
vector<double>& Matrix::operator[](const int& at) {
    return buf_[at];
}

void Matrix::print() const {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            cout << buf_[i][j] << " ";
        }
        cout << endl;
    }
}