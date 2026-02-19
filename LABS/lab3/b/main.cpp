#include <iostream>


size_t get_len(int n){
    int len;
    int crnt;
    while (n > 0){
        crnt = n % 10;
        n = n / 10;
        len++;
    }
    return len;
}

void fillArray(unsigned long long* array, size_t n){
    for(size_t index = 0; index < n; ++index){
        array[index] = factorial(index + 1);
    }
}

int main(){
    int N;
    size_t len = get_len(N);
    std::cout << "N = ";
    std::cin >> N;
}