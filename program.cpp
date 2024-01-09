#include <iostream>
#include <vector>
#include "ref.hh"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
/*
3
3
1
1
2
3
5
7
9
4
4
5
*/

/*
4
4
1
1
2
3
4
5
6
7
8
9
1
2
3
4
5
6
7
*/

/*
3
4
1
1
5
7
6
1
2
3
4
1
2
3
4
*/

/*
3
4
1
0
5
7
6
0
2
3
7
0
2
3
4
*/

void PrintMatrix(double **matrix, int nrOfRows, int nrOfColumns)
{
    for (int i = 0; i < nrOfRows; i++)
    {
        for (int j = 0; j < nrOfColumns; j++)
        {
            cout << matrix[i][j] << "   ";
        }

        cout << endl;
    }

    cout << endl;
}

int main()
{
    int nrOfRows, nrOfColumns;

    cout << "Enter the number of rows: ";
    cin >> nrOfRows;

    cout << "Enter the number of columns: ";
    cin >> nrOfColumns; //TODO CASES WHEN MATRIX IS 1xn OR mx1

    int ans;
    bool toRREF;

    cout << "Calculate to RREF (1) or to REF (2): ";
    cin >> ans;

    std::vector<vector<int>> matrixV;
    double **matrix = new double*[nrOfRows];

    for (int i = 0; i < nrOfRows; i++)
    {
        matrix[i] = new double[nrOfColumns];
    }

    switch (ans)
    {
    case 1:
        toRREF = true;
        break;
    case 2:
        toRREF = false;
        break;
    }

    for (int i = 0; i < nrOfRows; i++)
    {
        for (int j = 0; j < nrOfColumns; j++)
        {
            cout << "Enter element " << j + 1 << " of row " << i + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    ref(matrix, nrOfRows, nrOfColumns);

    cout << "The REF is: \n";
    PrintMatrix(matrix, nrOfRows, nrOfColumns);

    if (toRREF)
    {
        rref(matrix, nrOfRows, nrOfColumns);
        cout << "The RREF is: \n";
        PrintMatrix(matrix, nrOfRows, nrOfColumns);
    }
    
    return 0;
}