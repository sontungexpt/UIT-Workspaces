#include "CMatrix.h"

CMatrix::CMatrix()
{
    this->row = 0;
    this->col = 0;
    this->matrix = nullptr;
}

CMatrix::CMatrix(int row, int col)
{
    this->row = row;
    this->col = col;
    this->matrix = new int *[row];
    for (int i = 0; i < row; i++)
        this->matrix[i] = new int[col];
}

CMatrix::CMatrix(const CMatrix &matrix)
{
    this->row = matrix.row;
    this->col = matrix.col;
    this->matrix = nullptr;
    if (matrix.matrix != nullptr)
    {
        this->matrix = new int* [row];
        for (int i = 0; i < row; i++)
            this->matrix[i] = new int[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                this->matrix[i][j] = matrix.matrix[i][j];
    }
}

CMatrix::~CMatrix()
{
    if (this->matrix != nullptr)
    {
        for (int i = 0; i < row; i++)
            delete[] this->matrix[i];
        delete[] this->matrix;
        this->matrix = nullptr;
        this->row = 0;
        this->col = 0;
    }
}

bool CMatrix::IsNull() const
{
    return this->matrix == nullptr ? true : false;
}

istream &operator>>(istream &is, CMatrix &x)
{
    if (x.matrix != nullptr)
    {
        for (int i = 0; i < x.row; i++)
            delete[] x.matrix[i];
        delete[] x.matrix;
        x.matrix = nullptr;
    }

    cout << "\nEnter the row: ";
    is >> x.row;
    cout << "Enter the column: ";
    is >> x.col;
    x.matrix = new int *[x.row];
    for (int i = 0; i < x.row; i++)
        x.matrix[i] = new int[x.col];
    cout << "Enter the matrix: ";
    for (int i = 0; i < x.row; i++)
        for (int j = 0; j < x.col; j++)
        {
            cout << "\nMatrix[" << i << "][" << j << "] = ";
            is >> x.matrix[i][j];
        }
    return is;
}

ostream &operator<<(ostream &os, CMatrix &x)
{
    os << endl;
    if (x.matrix != nullptr)
    {
        for (int i = 0; i < x.row; i++)
        {
            for (int j = 0; j < x.col; j++)
                os << x.matrix[i][j] << "\t";
            os << endl;
        }
    }
    return os;
}

CMatrix CMatrix::operator+(const CMatrix &matrix) const
{
    CMatrix result;
    if (this->row == matrix.row and this->col == matrix.col)
    {
        result = *this;
        for (int i = 0; i < result.row; i++)
            for (int j = 0; j < result.col; j++)
                result.matrix[i][j] += matrix.matrix[i][j];
    }
    return result; 
}

CMatrix CMatrix::operator-(const CMatrix &matrix) const
{
    CMatrix result;
    if (this->row == matrix.row and this->col == matrix.col)
    {
        result = *this;
        for (int i = 0; i < result.row; i++)
            for (int j = 0; j < result.col; j++)
                result.matrix[i][j] -= matrix.matrix[i][j];
    } 
    return result;  
}

CMatrix CMatrix::operator*(const CMatrix &matrix) const
{
    CMatrix result(row, matrix.col);
    if (this->col == matrix.row)
    {
        for (int i = 0; i < result.row; i++)
            for (int j = 0; j < result.col; j++)
                for (int k = 0; k < this->row; k++)
                    result.matrix[i][j] = this->matrix[i][k] * matrix.matrix[k][j];
    }
    else
        result.~CMatrix();
    return result;
}

CMatrix CMatrix::operator*(long number) const
{
    CMatrix result;
    if (this->matrix != nullptr)
    {
        result = *this;
        for (int i = 0; i < result.row; i++)
            for (int j = 0; j < result.col; j++)
                result.matrix[i][j] *= number;
    }
    return result;
}

CMatrix operator*(long number, const CMatrix &matrix)
{
    return matrix * number;
}

void CMatrix::operator+=(const CMatrix &matrix)
{
    *this = *this + matrix;
}

void CMatrix::operator-=(const CMatrix &matrix)
{
    *this = *this - matrix;
}

void CMatrix::operator*=(const CMatrix &matrix)
{
    *this = *this * matrix;
}

void CMatrix::operator*=(long number)
{
    *this = *this * number;
}

CMatrix CMatrix::operator=(const CMatrix &matrix)
{
    //Remove the existed value to assign new value;
    this->~CMatrix();
    
    if (matrix.matrix != nullptr)
    {
        this->row = matrix.row;
        this->col = matrix.col;
        this->matrix = new int* [row];
        for (int i = 0; i < row; i++)
            this->matrix[i] = new int[col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                this->matrix[i][j] = matrix.matrix[i][j];
    }
    return *this;
}

bool CMatrix::operator==(const CMatrix &matrix) const
{
    if (matrix.matrix == nullptr)
        throw new exception("The matrix in the right side of operator == is not defined");
    if (this->matrix == nullptr)
        throw new exception("The matrix in the left side of operator == is not defined");
    if (this->row == matrix.row and this->col == matrix.col)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (this->matrix[i][j] != matrix.matrix[i][j])
                    return false;
        return true;
    }
    return false;
}

bool CMatrix::operator!=(const CMatrix &matrix) const
{
    if (matrix.matrix == nullptr)
        throw new exception("The matrix in the right side of operator == is not defined");
    if (this->matrix == nullptr)
        throw new exception("The matrix in the left side of operator == is not defined");
    if (this->row == matrix.row and this->col == matrix.col)
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (this->matrix[i][j] != matrix.matrix[i][j])
                    return true;
        return false;
    }
    return true;
}
