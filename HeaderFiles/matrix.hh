#ifndef _MATRIX_HH_
#define _MATRIX_HH

class Matrix
{
    public:
        vector<vector<double>> matrix;
        int rowsNr;
        int colsNr;
    
        vector<vector<double>> ref();
        vector<vector<double>> rref();
        double determinant();
        void printMatrix();
    
    private:
        void printRef(vector<vector<double>> rrefMatrix);
};

#endif