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
    //================================TASK 1==========================================
    /*Identify number of observations and unknowns
    n = 20
    u = 11
    r = m = n - u = 9
    */



    MatrixXd B(9,20);
    B.row(0) << 1,0,0,0,0, 0,0,1,0,1, -1,0,0,0,0, 0,0,0,0,0;
    B.row(1) << 0,1,0,0,0, 1,1,-1,0,0, 0,0,0,0,0, 0,0,0,0,0;
    B.row(2) << 0,0,1,1,1, -1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    B.row(3) << 0,0,0,0,0, 0,0,0,0,-1, 0,-1,-1,1,0, 0,0,0,0,0;
    B.row(4) << 0,0,0,0,0, 0,-1,0,0,0, 0,0,0,-1,-1, 0,1,0,0,0;
    B.row(5) << 0,0,0,0,-1, 0,0,0,0,0, 0,0,0,0,0, 0,-1,0,-1,1;
    B.row(6) << 1,0,0,0,0, 0,0,1,-1,0, 0,0,0,0,0, 0,0,0,0,0;
    B.row(7) << 0,0,0,0,0, 0,-1,0,0,0, 0,0,0,0,0, -1,1,0,0,0;
    B.row(8) << 0,0,0,0,-1, 0,0,0,0,0, 0,0,0,0,0, 0,-1,1,0,0;

    MatrixXd l = readToMat("dhs_2026.txt");

    MatrixXd w = B*l;

    //cout << w;

    MatrixXd stdevs = readToMat("stdevs_2026.txt");
    MatrixXd Cl(20,20);

    for (int i = 0; i < 20; i++)
    {
        Cl(i,i) = pow(stdevs(i,0),2);
    }

    MatrixXd P = Cl.inverse();

    //---------------------------FINDING VCAP and ADJUSTING OBS---------------------------
    MatrixXd M = B*P.inverse()*B.transpose();

    MatrixXd kHat = M.inverse()*w;

    MatrixXd vCap = -P.inverse()*B.transpose()*kHat;

    MatrixXd lCap = l + vCap;

    //----------------------------VCM-------------------------------
    MatrixXd CvCap = P.inverse()*B.transpose()*M.inverse()*B*P.inverse();

    MatrixXd ClCap = Cl - CvCap;

    //---------------------------CHECK---------------------------
    MatrixXd check = B*lCap;

    cout << check << endl;

    cout << endl << vCap << endl;

    //=============================PART 2==============================
    //-----------------------------COMPUTE UNKNOWNS----------------------------
    MatrixXd J(12,20);
    J.row(0) << 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(1) << 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(2) << 1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(3) << 1,1,1,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(4) << 1,1,1,1,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(5) << 1,1,0,0,0, 1,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(6) << 1,0,0,0,0, 0,0,1,0,0, 0,0,0,0,0, 0,0,0,0,0;
    J.row(7) << 0,0,0,0,0, 0,0,0,0,0, 1,0,0,0,0, 0,0,0,0,0;
    J.row(8) << 0,0,0,0,0, 0,0,0,0,0, 1,1,0,0,0, 0,0,0,0,0;
    J.row(9) << 0,0,0,0,0, 0,0,0,0,0, 1,1,1,0,0, 0,0,0,0,0;
    J.row(10) << 0,0,0,0,0, 0,0,0,1,0, 0,0,0,0,0, 1,0,0,0,0;
    J.row(11) << 0,0,0,0,0, 0,0,0,1,0, 0,0,0,0,0, 1,0,0,1,0;

    MatrixXd constants(12,1);

    for (int i = 0; i < 12; i++)
    {
        constants(i) = 135.961;
    }

    MatrixXd xCap = J*lCap + constants;

    cout << endl << xCap << endl;

    //-------------------VCM FOR UNKNOWNS---------------------
    MatrixXd CxCap = J*ClCap*J.transpose();







    return 0;
}