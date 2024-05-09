#include <vector>
#include "HeaderFiles/rowOperations.hh"

using std::vector;

double _determinant(vector<vector<double>> matrix, int nrOfRowsAndColumns)
{
    double determinant = 1;
    double determinantMultiplier = 1;
    
    for (int i = 0; i < nrOfRowsAndColumns; i++) // find ref
    {
        int pivotX = i, pivotY = i;
        double pivotElement = 0;
        bool foundPivot = true;

        while (pivotElement == 0)
        {
            if (pivotX != nrOfRowsAndColumns - 1) // search for the first non-zero element
            {
                pivotElement = matrix[pivotX++][pivotY];

                if (pivotElement != 0)
                {
                    pivotX--;
                    break;
                }
            }
            else if (pivotY != nrOfRowsAndColumns - 1)
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
            SwapRows(matrix[i], matrix[pivotX], nrOfRowsAndColumns);
            determinantMultiplier *= -1;
            pivotX = i;
        }

        for (int j = pivotX + 1; j < nrOfRowsAndColumns; j++)
        {
            double element = matrix[j][pivotY];
            double multiplier = (double)element / pivotElement;

            if (multiplier != 0)
            {
                SubstractRowFromAnother(matrix[j], matrix[pivotX], multiplier, nrOfRowsAndColumns);
            }
        }
    }

    for (int i = 0; i < nrOfRowsAndColumns; i++)
    {
        for (int j = 0; j < nrOfRowsAndColumns; j++)
        {
            if (i == j)
            {
                determinant *= matrix[i][j];
            }
            
        }
    }

    return determinantMultiplier * determinant;
}