//
// Created by ltran on 2026-02-25.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "functions.h"
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

MatrixXd readToMat(const string filename)
{
    //Open file and check that it was opened correctly
    ifstream rawData;
    rawData.open(filename);

    if (!rawData.is_open())
    {
        cout << "Error opening file" << endl;
    }

    //Make vector to store data
    vector<double> data;

    //Read data into row struct and add row to vector
    double tempNum;
    int numRows = 0;
    while (rawData >> tempNum)
    {
        data.push_back(tempNum);
        numRows ++;
    }

    rawData.close();

    MatrixXd A;
    A.resize(numRows,1);

    //Iterate through the vector of rows to populate A, units [none, none, none]
    for (int r = 0; r < data.size(); r++)
    {
        A(r,0) = data[r];

    }


    return A;
}