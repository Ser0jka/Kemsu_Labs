//----------calc_vect.cpp-----------------

#include "vect.hpp"
#include "calc_vect.hpp"
#include <cmath>

double ScalarProduct_1(double* v1, double* v2, int n)
{
    double res=0;

    for(int i=0; i<n; i++)
        res+=v1[i]*v2[i];

    return res;
}

void ScalarProduct_2(double* v1, double* v2, int n, double& res)
{
    res=0;

    for(int i=0; i<n; i++)
        res+=v1[i]*v2[i];
}

void ScalarProduct_3(double* v1, double* v2, int n, double* res)
{
    *res=0;

    for(int i=0; i<n; i++)
        (*res)+=v1[i]*v2[i];
}


Vector3D VectorProduct(double* v1, double* v2)
{
    Vector3D result;
    result.x = v1[1] * v2[2] - v1[2] * v2[1];
    result.y = v1[2] * v2[0] - v1[0] * v2[2];
    result.z = v1[0] * v2[1] - v1[1] * v2[0];
    return result;  // возвращаем структуру ПО ЗНАЧЕНИЮ
}

void SmeshanoeProduct(double* v1, double* v2, double* v3, double* res){

    *res = v1[0] * (v2[1] * v3[2] - v2[2] * v3[1]) +
        v1[1] * (v2[2] * v3[0] - v2[0] * v3[2]) +
        v1[2] * (v2[0] * v3[1] - v2[1] * v3[0]);
}

double VectorLen(double* v, int n){
    double res = 0;
    for(int i=0; i<n; i++){
        res+= pow(v[i],2);
    }
    return sqrt(res);
}

void Cosinus(double* v1, double* v2, int n, double& res){
    res = ScalarProduct_1(v1,v2,n) / (VectorLen(v1,n) * VectorLen(v2,n));
}