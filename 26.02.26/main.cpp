#include <iostream>
using namespace std;

// 1.1 Возврат через return
double func_return(double a[], double b[], int n) {
    double res = 0;
    for (int i = 0; i < n; i++) res += a[i] * b[i];
    return res;
}

// 1.2 Возврат через ссылку
void func_ref(double a[], double b[], int n, double& res) {
    res = 0;
    for (int i = 0; i < n; i++) res += a[i] * b[i];
}

// 1.3 Возврат через указатель
void func_ptr(double a[], double b[], int n, double* res) {
    *res = 0;
    for (int i = 0; i < n; i++) *res += a[i] * b[i];
}

// 1.4 Возврат по значению (копия)
void func_val(double a[], double b[], int n, double res) {
    res = 0;
    for (int i = 0; i < n; i++) res += a[i] * b[i];
}

int main() {
    int n;
    cout << "Vvedite n: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Oshibka. Vvedite chislo > 0: ";
        cin.clear(); cin.ignore(10000, '\n');
    }

    double v1[100], v2[100];  // Простые массивы
    for (int i = 0; i < n; i++) {
        v1[i] = 1.0;
        v2[i] = 1.0;
    }

    double res = 0;

    // 1.1
    res = func_return(v1, v2, n);
    cout << "1.1 (Return): " << res << endl;

    // 1.2
    func_ref(v1, v2, n, res);
    cout << "1.2 (Reference): " << res << endl;

    // 1.3
    func_ptr(v1, v2, n, &res);
    cout << "1.3 (Pointer): " << res << endl;

    // 1.4
    res = 0;
    func_val(v1, v2, n, res);
    cout << "1.4 (Value): " << res << endl;

    cout << "\nAnaliz: 1.4 ne rabotaet (kopiya peredaetsya)." << endl;
    return 0;
}