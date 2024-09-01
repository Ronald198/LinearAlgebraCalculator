#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cctype> // for isspace
#include "HeaderFiles/ref.hh"
#include "HeaderFiles/matrix.hh"

using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;

map<string, Matrix> matrices;
map<string, double> scalars;

void AnalysePrompt(const string prompt)
{
    size_t equalPos = prompt.find('=');

    if (equalPos == string::npos) // no '=' in the string
    {
        size_t paranethesisOpeningPos = prompt.find('(');

        if (paranethesisOpeningPos == string::npos) // no '(' in the string then print
        {
            if (matrices.find(prompt) == matrices.end())
            {
                if (prompt != "")
                    cout << "Undefined operation!\n";
            }
            else
            {
                Matrix toOperate = matrices[prompt];

                toOperate.printMatrix();
            }
        }
        else // function check
        {
            size_t paranethesisClosingPos = prompt.find(')');

            if (paranethesisClosingPos == string::npos) // no ')' in the string then print
            {
                cout << "Invalid function call! Are you missing any ')'?\n";
            }
            else
            {
                string varName;
                size_t detPos = prompt.find("det(");

                if (detPos != string::npos)
                {
                    varName = prompt.substr(4, prompt.length() - 5);

                    if (matrices.find(varName) == matrices.end())
                    {
                       cout << "'" << varName << "' is undefined!\n";
                    }
                    else
                    {
                        Matrix toOperate = matrices[varName];

                        if (toOperate.rowsNr == toOperate.colsNr)
                        {
                            cout << "\t" << toOperate.determinant() << endl;
                        }
                        else
                        {
                            cout << "Determinant can't be found! This matrix is non-square!" << endl; 
                        }
                    }

                    return;
                }

                size_t rrefPos = prompt.find("rref(");

                if (rrefPos != string::npos)
                {
                    varName = prompt.substr(5, prompt.length() - 6);

                    if (matrices.find(varName) == matrices.end())
                    {
                       cout << "'" << varName << "' is undefined!\n";
                    }
                    else
                    {
                        Matrix toOperate = matrices[varName];
                        toOperate.rref();
                    }

                    return;
                }

                size_t refPos = prompt.find("ref(");

                if (refPos != string::npos)
                {
                    varName = prompt.substr(4, prompt.length() - 5);

                    if (matrices.find(varName) == matrices.end())
                    {
                       cout << "'" << varName << "' is undefined!\n";
                    }
                    else
                    {
                        Matrix toOperate = matrices[varName];
                        toOperate.ref();
                    }

                    return;
                }
                
                size_t diagPos = prompt.find("diag(");
            }
        }
    }
    else
    {
        string varName;
        vector<vector<double>> result;
        std::stringstream ss(prompt);
        int rows = 0;
        int cols = 0;
        int colsCheck = 0;

        char c;
        while (ss >> c)
        {
            if (c == '[')
            {
                vector<double> row;
                double num;

                while (ss >> c)
                {
                    if (isdigit(c) || c == '-')
                    {
                        ss.putback(c);
                        if (ss >> num) {
                            row.push_back(num);

                            if (rows == 0)
                            {
                                cols++;
                                colsCheck++;
                            }
                            else
                            {
                                colsCheck++;
                            }
                        }
                    }
                    else if (c == ']')
                    {
                        break;
                    }
                }

                if (colsCheck != cols)
                {
                    cout << "Column size is inconsistent! Check the input!\n";
                    return;
                }
                
                result.push_back(row);
                rows++;
                colsCheck = 0;
            }
        }

        varName = prompt.substr(0, equalPos);

        if (matrices.find(varName) == matrices.end()) // if variable doesnt exist
        {
            // varName.erase(varName.find_last_not_of(" \n\r\t") + 1); // Trim whitespace from the name
            Matrix newMatrix = Matrix();
            newMatrix.matrix = result;
            newMatrix.rowsNr = rows;
            newMatrix.colsNr = cols;
            newMatrix.printMatrix();

            matrices.insert({varName, newMatrix});
        }
        else // if it exists, override it
        {
            matrices[varName].matrix = result;
            matrices[varName].rowsNr = rows;
            matrices[varName].colsNr = cols;
            matrices[varName].printMatrix();
        }
    }
}