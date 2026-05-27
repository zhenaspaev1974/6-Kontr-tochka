#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 1) Сортировка вектора и вывод в обратном порядке
vector<int> sortVector(vector<int> v) {
    // Сортируем по убыванию (обратный порядок)
    sort(v.begin(), v.end(), greater<int>());
    return v;
}

// 2) Найти сумму элементов вектора
int sum(vector<int> arr, int n) {
    // accumulate находится в <numeric>
    return accumulate(arr.begin(), arr.begin() + n, 0);
}

// 3) Найти частоту числа x в векторе
int findFrequency(vector<int> arr, int x) {
    // count находится в <algorithm>
    return count(arr.begin(), arr.end(), x);
}

int main() {
    // Пример использования
    vector<int> v = {1, 4, 2, 4, 5, 4, 9};
    
    vector<int> sorted = sortVector(v);
    cout << "Sorted descending: ";
    for(int x : sorted) cout << x << " ";
    cout << "\n";
    
    cout << "Sum: " << sum(v, v.size()) << "\n";
    cout << "Frequency of 4: " << findFrequency(v, 4) << "\n";
    
    return 0;
}