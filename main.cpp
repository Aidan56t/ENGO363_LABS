/* ------------ Lab 3: Conditional least squares adjustment -----------
main.cpp written for ENGO 363 - Estimation and Statistical Testing
Written by Aidan Tran on Mar 10th, 2026
-----------------------------------------------------------------------------------------------*/

//---------------- Setup ------------------------------

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


//---------------- Main ------------------------------

int main()
{
    /*Identify number of observations and unknowns
    n = 20
    u = 11
    r = m = n - u = 9

    //Conditional equations
    1) h2_1 +
    2)
    3)
    4)
    5)
    6)
    7)
    8)
    9)
    */

    vector<string> l = {"h2_1","h3_2","h4_3"};

    MatrixXd B(9,20);
    B.row(0) << 1,0,0,0,0, 0,0,1,0,1, -1,0,0,0,0, 0,0,0,0,0;
    B.row(1) << 0,1,0,0,0, 1,1,-1,0,0, 0,0,0,0,0, 0,0,0,0,0;
    B.row(2) << 0,0,1,1,1, -1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    B.row(3) << 0,0,0,0,0, 0,0,0,0,-1, 0,-1,-1,1,0, 0,0,0,0,0;
    B.row(4) << 0,0,0,0,0, 0,-1,0,0,0, 0,0,0,0,-1, -1,1,0,0,0;
    B.row(5) << 0,0,0,0,-1, 0,0,0,0,0, 0,0,0,0,0, 0,-1,0,-1,1;
    B.row(6) << 1,0,0,0,0, 0,0,1,-1,0, 0,0,0,0,0, 0,0,0,0,0;
    B.row(7) << 0,0,0,0,0, 0,-1,0,0,0, 0,0,0,0,0, -1,1,0,0,0;
    B.row(8) << 0,0,0,0,-1, 0,0,0,0,0, 0,0,0,0,0, 0,-1,1,0,0;



    return 0;
}