#include <iostream>
#include <chrono>
#include <iomanip>
#include "f.h"

using namespace std;

int main()
{
    int n = 0, b = 0, c = 100000;
    cout << "Enter n: ";
    cin >> n;

    // 1. Создаем два массива
    int *a_old = new int[n];
    int *a_new = new int[n];
    int *a_new_new = new int[n];

    // 2. Заполняем первый массив случайными числами
    f(a_old, n, b, c);

    // 3. Копируем данные вручную из первого во второй (без алгоритмов)
    for (int i = 0; i < n; i++) {
        a_new[i] = a_old[i];
        a_new_new[i] = a_old[i];
    }

    // --- ТЕСТ СТАРОГО MERGE (2 временных массива) ---
    // Сначала подготавливаем данные (сортируем половины)
    auto s1 = std::chrono::steady_clock::now();
    f_sort(a_old, n / 2);
    f_sort(a_old + n / 2, n / 2);
    f_merge(a_old, n); // Старая функция
    auto e1 = std::chrono::steady_clock::now();
    auto t1 = std::chrono::duration_cast<std::chrono::nanoseconds>(e1 - s1).count();
    cout << fixed << setprecision(9);
    cout << "------------------------------------------" << endl;
    cout << "Merge 1 (2 arrays) time: " << t1 / 1e9 << " sec" << endl;


    auto s2 = std::chrono::steady_clock::now();
    f_sort(a_new, n / 2);
    f_sort(a_new + n / 2, n / 2);
    f_new_merge(a_new, n); // Твоя новая функция
    auto e2 = std::chrono::steady_clock::now();
    auto t2 = std::chrono::duration_cast<std::chrono::nanoseconds>(e2 - s2).count();
    cout << "Merge 2 (1 array)  time: " << t2 / 1e9 << " sec" << endl;

    auto s3 = std::chrono::steady_clock::now();
    f_sort(a_new_new, n / 3);
    f_sort(a_new_new + n / 3, n / 3);
    f_sort(a_new_new + n / 3, 2*n / 3);
    f_new_merge_div3(a_new_new, n); // Твоя новая функция
    auto e3 = std::chrono::steady_clock::now();
    auto t3 = std::chrono::duration_cast<std::chrono::nanoseconds>(e3 - s3).count();
    cout << "Merge 3 (1 + div3) time: " << t3 / 1e9 << " sec" << endl;
    cout << "------------------------------------------" << endl;

    cout << "Comparison (relative to default Merge):" << endl;
    cout << "New Merge (div2) is " << (double)t1 / t2 << "x speedup" << endl;
    cout << "New Merge (div3) is " << (double)t1 / t3 << "x speedup" << endl;


    cout << "\nFirst 10 elements of each array:" << endl;
    cout << "Array 1: ";
    for(int i = 0; i < (n < 10 ? n : 10); i++) cout << a_old[i] << " ";
    cout << endl;
    cout << "Array 2: ";
    for(int i = 0; i < (n < 10 ? n : 10); i++) cout << a_new[i] << " ";
    cout << endl;
    cout << "Array 3: ";
    for(int i = 0; i < (n < 10 ? n : 10); i++) cout << a_new_new[i] << " ";
    cout << endl << endl;

    delete[] a_old;
    delete[] a_new;
    delete[] a_new_new;

    return 0;
}