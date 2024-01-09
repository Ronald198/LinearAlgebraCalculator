#include <iostream>
#include <vector>
#include <map>
#include "ref.hh"

using std::string;
using std::vector;
using std::map;
using std::cout;
using std::endl;

map<string, vector<vector<double>>> matrices;
map<string, double> scalars;

void AnalysePrompt(string prompt)
{
    int indexStart = prompt.find('(');
    int indexEnd = prompt.find(')');
    prompt.replace(prompt.begin(), prompt.end(), " ", ""); //remove spaces

    if (indexStart == string::npos && indexEnd != string::npos)
    {
        cout << ">>> Unknown function. Do you miss '('?" << endl;
    }
    else if (indexStart != string::npos && indexEnd == string::npos)
    {
        cout << ">>> Unknown function. Do you miss ')'?" << endl;
    }
    else //todo print or declare matrix
    {
        if (prompt.find("*") != string::npos)
        {
            if (prompt.find("=") == string::npos)
            {
                // misses =
            }
        }
        else if (prompt.find("+") != string::npos)
        {
            if (prompt.find("=") == string::npos)
            {
                // misses =
            }
        }
        else if (prompt.find("-") != string::npos)
        {
            if (prompt.find("=") == string::npos)
            {
                // misses =
            }
        }
        else if (prompt.find("=") != string::npos)
        {
            int nrOfRows, nrOfColumns;

            vector<vector<double>> matrix(nrOfRows, vector<double>(nrOfColumns));
        }
        
        return;
    }    

    string variableName = "";

    for (int i = indexStart + 1; i < indexEnd; i++)
    {
        variableName += prompt[i];
    }

    std::cout << variableName;
    map<string, vector<vector<double>>> tempMatrices;
    map<string ,double> tempScalars;

    // >>> diag = inv(P) * A * P
    // order is function, *, *
    // general order is functions saved in tempMatrices and scalars. //need to determine order of variables (maybe save in a map string tuple idk)  

    if (prompt.find("rref") != string::npos)
    {
        // ref(variableName);
        // rref(variableName);
    }
    else if (prompt.find("ref") != string::npos)
    {
        // ref(variableName);
    }
    else if (prompt.find("det") != string::npos)
    {
        
    }
    else if (prompt.find("inv") != string::npos)
    {
        
    }
    else if (prompt.find("diag") != string::npos)
    {
        
    }
    else if (prompt.find("+") != string::npos)
    {
        
    }
    else if (prompt.find("-") != string::npos)
    {
        
    }
    else if (prompt.find("*") != string::npos)
    {
        
    }
}