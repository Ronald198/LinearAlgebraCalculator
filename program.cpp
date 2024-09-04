#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm> // For std::remove_if
#include "HeaderFiles/promptAnalysis.hh"
#include<string> // For std::getline in windows machines

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    string prompt;

    // AA = [[1,2,3],[4,5,6],[7,8,10]]

    while (true)
    {
        cout << ">>> ";
        std::getline(cin, prompt);

        prompt.erase(std::remove_if(prompt.begin(), prompt.end(), ::isspace), prompt.end());

        if (prompt == "quit")
        {
            return 0;
        }

        AnalysePrompt(prompt);
    }

    return 0;
}