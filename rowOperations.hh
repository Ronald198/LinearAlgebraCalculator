#include <vector>
using std::vector;

#ifndef _ROWOPERATIONS_HH_
#define _ROWOPERATIONS_HH_
void SwapRows(vector<double> &originRow, vector<double> &destinationRow, int nrOfColumns);
void MultiplyRowByScalar(vector<double> &row, double scalar, int nrOfColumns);
void SubstractRowFromAnother(vector<double> &minuendRow, vector<double> &subtrahendRow, double multiplier,int nrOfColumns);
#endif