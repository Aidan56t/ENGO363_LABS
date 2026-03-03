//
// Created by ltran on 2026-02-25.
//

#ifndef ENGO363_LABS_FUNCTIONS_H
#define ENGO363_LABS_FUNCTIONS_H

#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Eigen/Dense>
#include <cmath>

using namespace std;
using namespace Eigen;

MatrixXd readToMat(const string filename);

#endif //ENGO363_LABS_FUNCTIONS_H