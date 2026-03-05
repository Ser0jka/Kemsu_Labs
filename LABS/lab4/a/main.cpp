#include <iostream>
#include "vect.hpp"
#include "calc_vect.hpp"
#define n 3

using namespace std;

int main()
{
    double res=0;
    double result[3] = {0};

    double *v1 = new double[n];
    double *v2 = new double[n];
    double *v3 = new double[n];

    InputDescVect(v1,n);
    InputDescVect(v2,n);
    InputDescVect(v3,n);

    cout<<"Vector v1:\t";
    OutputDescVect(v1,n);

    cout<<"Vector v2:\t";
    OutputDescVect(v2,n);

    cout<<"Vector v3:\t";
    OutputDescVect(v3,n);

    cout<<"\n-----------------------------------------------\n";

    // cout<<"\n-----------------------------------------------\n";
    // res=0;
    // res=ScalarProduct_1(v1,v2,n);
    // cout<<"Result of ScalarProduct_1: \t"<< res<<endl;

    // cout<<"\n-----------------------------------------------\n";

    // res=0;
    // ScalarProduct_2(v1,v2,n,res);
    // cout<<"Result of ScalarProduct_2: \t"<< res<<endl;

    // cout<<"\n-----------------------------------------------\n";

    // res=0;
    // ScalarProduct_3(v1,v2,n,&res);
    // cout<<"Result of ScalarProduct_3: \t"<< res<<endl;

    // cout<<"\n-----------------------------------------------\n";

    if (n != 3){
        cout<<"Vector product func cant give res with n="<< n <<endl;
        cout<<"\n-----------------------------------------------\n";
        cout<<"Smeshanoe product func cant give res with n="<< n <<endl;
        cout<<"\n-----------------------------------------------\n";
    }
    else{
        Vector3D vecResult = VectorProduct(v1, v2);
        cout << "Vector product: (" 
            << vecResult.x << ", " 
            << vecResult.y << ", " 
            << vecResult.z << ")" << endl;

        cout<<"\n-----------------------------------------------\n";

        res=0;
        SmeshanoeProduct(v1,v2,v3,&res);
        cout<<"Result of Smeshanoe Product: \t"<< res<<endl;

        cout<<"\n-----------------------------------------------\n";
    }

    res=0;
    res=VectorLen(v1,n);
    cout<<"Result of VectorLen: \t"<< res<<endl;
    cout<<"\n-----------------------------------------------\n";

    res = 0;
    Cosinus(v1, v2,n, res);
    cout<<"Result of Cosinus: \t"<< res<<endl;

    delete []v1; v1=NULL;
    delete []v2; v2=NULL;
    delete []v3; v3=NULL;
}

