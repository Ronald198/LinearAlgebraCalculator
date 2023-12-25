#ifndef _ROWOPERATIONS_HH_
#define _ROWOPERATIONS_HH_
void SwapRows(double *originRow, double *destinationRow, int nrOfColumns);
void MultiplyRowByScalar(double *row, double scalar, int nrOfColumns);
void SubstractRowFromAnother(double *minuendRow, double *subtrahendRow, double multiplier,int nrOfColumns);
#endif