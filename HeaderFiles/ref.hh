#include <vector>
using std::vector;

#ifndef _REF_HH_
#define _REF_HH_
void MakeLeadingVaribalesOnes(vector<vector<double>> &matrix, int nrOfRows, int nrOfColumns);
vector<vector<double>> _ref(vector<vector<double>> matrix, int nrOfRows, int nrOfColumns);
vector<vector<double>> _rref(vector<vector<double>> matrix, int nrOfRows, int nrOfColumns);
#endif