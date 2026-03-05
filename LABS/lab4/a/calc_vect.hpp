//----------calc_vect.h-----------------
#pragma once
#include "vect.hpp"

struct Vector3D {double x, y, z;};

double ScalarProduct_1(double* v1, double* v2, int n);
void   ScalarProduct_2(double* v1, double* v2, int n, double& res);
void   ScalarProduct_3(double* v1, double* v2, int n, double* res);

//DZ
Vector3D VectorProduct(double* v1, double* v2);
void   SmeshanoeProduct(double* v1, double* v2, double* v3, double* res);
double VectorLen(double* v, int n);
void   Cosinus(double* v1, double* v2, int n, double& res);

