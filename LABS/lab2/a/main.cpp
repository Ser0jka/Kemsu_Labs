

#include <iostream>
using namespace std;
int main()
{

    int x = 10;
    int *y;
    y = &x;

    cout << "---->1 \n";
    y = &x; // начальные данные
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->2 y++ \n";
    y = &x; 
    x = 10;
    y++;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->3 ++y \n";
    y = &x; 
    x = 10;
    ++y;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->4 y-- \n";
    y = &x; 
    x = 10;
    y--;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->5 --y \n";
    y = &x; 
    x = 10;
    --y;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->6 *y++ \n";
    y = &x; 
    x = 10;
    *y++;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->7 ++*y \n";
    y = &x; 
    x = 10;
    ++*y;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->8 *y-- \n";
    y = &x; 
    x = 10;
    *y--;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->9 --*y \n";
    y = &x; 
    x = 10;
    --*y;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->10 (*y)++ \n";
    y = &x; 
    x = 10;
    (*y)++;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->11 ++(*y) \n";
    y = &x; 
    x = 10;
    ++(*y);
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->12 (*y)-- \n";
    y = &x; 
    x = 10;
    (*y)--;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->13 --(*y) \n";
    y = &x; 
    x = 10;
    --(*y);
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->14 *y+=1 \n";
    y = &x; 
    x = 10;
    *y+=1;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->15 *y+=2 \n";
    y = &x; 
    x = 10;
    *y+=2;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->16 y+=1 \n";
    y = &x; 
    x = 10;
    y+=1;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    cout << "---->17 y+=2 \n";
    y = &x; 
    x = 10;
    y+=2;
    cout << "adres x: " <<  &x << endl;
    cout << "value x: " << x << endl;
    cout << "adres y: " << y << endl;
    cout << "value y: " << *y << endl;

    // cout << "---->18 y=2 \n";
    // y = &x; 
    // x = 10;
    // y=2;
    // cout << "adres x: " <<  &x << endl;
    // cout << "value x: " << x << endl;
    // cout << "adres y: " << y << endl;
    // cout << "value y: " << *y << endl;
    
    return 0;
}