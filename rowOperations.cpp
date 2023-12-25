void SwapRows(double *originRow, double *destinationRow, int nrOfColumns)
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

void MultiplyRowByScalar(double *row, double scalar, int nrOfColumns)
{
    for (int i = 0; i < nrOfColumns; i++)
    {
        row[i] *= scalar;
    }
}

/// minuend - subtrahend = difference
void SubstractRowFromAnother(double *minuendRow, double *subtrahendRow, double multiplier,int nrOfColumns)
{
    for (int i = 0; i < nrOfColumns; i++)
    {
        minuendRow[i] = (double)minuendRow[i] - multiplier * subtrahendRow[i];
    }
}
