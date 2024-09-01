#include "HeaderFiles/ref.hh"
#include "HeaderFiles/determinant.hh"
#include "HeaderFiles/matrix.hh"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


vector<vector<double>> Matrix::ref()
{
    vector<vector<double>> refMatrix = _ref(matrix, rowsNr, colsNr);
    printRef(refMatrix);
    return refMatrix;
}

vector<vector<double>> Matrix::rref()
{
    vector<vector<double>> rrefMatrix = _rref(matrix, rowsNr, colsNr);
    printRef(rrefMatrix);
    return rrefMatrix;
}

double Matrix::determinant()
{
    return _determinant(matrix, rowsNr);
}

void Matrix::printMatrix()
{
    for (int i = 0; i < rowsNr; i++)
    {
        for (int j = 0; j < colsNr; j++)
        {
            cout << matrix[i][j] << "  \t";
        }

        cout << endl;
    }
}

void Matrix::printRef(vector<vector<double>> rrefMatrix)
{
    for (int i = 0; i < rowsNr; i++)
    {
        for (int j = 0; j < colsNr; j++)
        {
            cout << rrefMatrix[i][j] << "  \t";
        }

        cout << endl;
    }
}