#include <iostream>
#include <vector>
#include "rowOperations.hh"

using std::cout;
using std::vector;

int refSteps = 1;

void MakeLeadingVaribalesOnes(vector<vector<double>> &matrix, int nrOfRows, int nrOfColumns)
{
    for (int i = 0; i < nrOfRows; i++)  //make all leading variables ones
    {
        bool foundLeadingVar = false;
        double leadingVar;

        for (int j = 0; j < nrOfColumns; j++)
        {
            if (!foundLeadingVar)
            {
                if (matrix[i][j] != 0)
                {
                    foundLeadingVar = true;
                    leadingVar = 1 / matrix[i][j];
                }
            }
        }

        if (foundLeadingVar && leadingVar != 1)
        {
            MultiplyRowByScalar(matrix[i], leadingVar, nrOfColumns);
            cout << refSteps++ << ". Multiply R" << i + 1 << " with " << leadingVar << ".\n";
        }
    }
}

void ref(vector<vector<double>> &matrix, int nrOfRows, int nrOfColumns)
{
    for (int i = 0; i < nrOfRows; i++)
    {
        int pivotX = i, pivotY = i;
        double pivotElement = 0;
        bool foundPivot = true;

        while (pivotElement == 0)
        {
            if (pivotX != nrOfRows - 1) // search for the first non-zero element
            {
                pivotElement = matrix[pivotX++][pivotY];

                if (pivotElement != 0)
                {
                    pivotX--;
                    break;
                }
            }
            else if (pivotY != nrOfColumns - 1)
            {
                pivotY++; // switch to next column
                pivotX = i;
            }
            else // implies row full of zeros
            {
                foundPivot = false;
                break;
            }
        }

        if (pivotX != i && foundPivot)
        {
            SwapRows(matrix[i], matrix[pivotX], nrOfColumns);
            std::cout << refSteps++ << ". Swap R" << i + 1 << " with R" << pivotX + 1 << ".\n";
            pivotX = i;
        }

        for (int j = pivotX + 1; j < nrOfRows; j++)
        {
            double element = matrix[j][pivotY];
            double multiplier = (double)element / pivotElement;

            if (multiplier != 0)
            {
                SubstractRowFromAnother(matrix[j], matrix[pivotX], multiplier, nrOfColumns);

                if (multiplier == 1)
                {
                    std::cout << refSteps++ << ". Subtract R" << pivotX + 1 << " from R" << j + 1 << ".\n";
                }
                else
                {
                    std::cout << refSteps++ << ". Subtract " << multiplier << " * R" << pivotX + 1 << " from R" << j + 1 << ".\n";
                }   
            }
        }
    }
}

void rref(vector<vector<double>> &matrix, int nrOfRows, int nrOfColumns)
{
    for (int i = nrOfRows - 1; i >= 0; i--)
    {
        int posY;
        bool foundLeadingVar = false;
        double leadingVar;

        for (int j = 0; j < nrOfColumns; j++)
        {
            if (matrix[i][j] != 0)
            {
                foundLeadingVar = true;
                leadingVar = matrix[i][j];
                posY = j;
                break;
            }
        }

        if (foundLeadingVar) // else there is a row full of zeros if no var is found
        {
            if (leadingVar != 1)
            {
                double multiplier = 1 / leadingVar;
                MultiplyRowByScalar(matrix[i], multiplier, nrOfColumns);
                cout << refSteps++ << ". Multiply R" << i + 1 << " with " << multiplier << ".\n";
            }

            for (int j = i - 1; j >= 0; j--)
            {
                double element = matrix[j][posY];

                SubstractRowFromAnother(matrix[j], matrix[i], element, nrOfColumns);

                if (element == 1)
                {
                    std::cout << refSteps++ << ". Subtract R" << i + 1 << " from R" << j + 1 << ".\n";
                }
                else
                {
                    std::cout << refSteps++ << ". Subtract " << element << " * R" << i + 1 << " from R" << j + 1 << ".\n";
                }   
            }
        }
    }
}