#include <vector>
using std::vector;

void SwapRows(vector<double> &originRow, vector<double> &destinationRow, int nrOfColumns)
{
    int temp[nrOfColumns];

    for (int i = 0; i < nrOfColumns; i++)
    {
        temp[i] = originRow[i];
        originRow[i] = destinationRow[i];
    }
    
    for (int i = 0; i < nrOfColumns; i++)
    {
        destinationRow[i] = temp[i];
    }
}

void MultiplyRowByScalar(vector<double> &row, double scalar, int nrOfColumns)
{
    for (int i = 0; i < nrOfColumns; i++)
    {
        row[i] *= scalar;
    }
}

/// minuend - subtrahend = difference
void SubstractRowFromAnother(vector<double> &minuendRow, vector<double> &subtrahendRow, double multiplier,int nrOfColumns)
{
    for (int i = 0; i < nrOfColumns; i++)
    {
        minuendRow[i] = (double)minuendRow[i] - multiplier * subtrahendRow[i];
    }
}
