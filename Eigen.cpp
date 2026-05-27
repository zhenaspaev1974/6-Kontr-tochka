#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <Eigen/Dense> // Требуется установленная библиотека Eigen

using namespace std;
using namespace Eigen;

void solveAxB() {
    cout << "--- Задача 2: Решение Ax = B ---\n";
    // Пример невырожденной матрицы 3x3 и вектора B
    Matrix3d A;
    A << 2, -1, 1,
         1,  3, 2,
         3, -2, 4;
    Vector3d B;
    B << 4, 12, 11;

    // Решение уравнения с помощью QR-разложения
    Vector3d x = A.colPivHouseholderQr().solve(B);
    cout << "Вектор x:\n" << x << "\n\n";
}

void compareVectors() {
    cout << "--- Задача 3: Векторы x и y (n = 1000) ---\n";
    int n = 1000;
    
    // Генерация случайных векторов в Eigen
    VectorXd x_eigen = VectorXd::Random(n);
    VectorXd y_eigen = VectorXd::Random(n);

    // 1. Вычисление через Eigen
    auto start = chrono::high_resolution_clock::now();
    double dot_eigen = x_eigen.dot(y_eigen);
    double norm_eigen = x_eigen.norm();
    auto end = chrono::high_resolution_clock::now();
    auto ms_eigen = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Eigen - Скалярное произведение: " << dot_eigen << ", Норма x: " << norm_eigen << "\n";
    cout << "Время (Eigen): " << ms_eigen.count() << " ns\n";

    // 2. Ручное вычисление в цикле (копируем данные в std::vector для честности)
    vector<double> x_man(x_eigen.data(), x_eigen.data() + x_eigen.size());
    vector<double> y_man(y_eigen.data(), y_eigen.data() + y_eigen.size());

    start = chrono::high_resolution_clock::now();
    double dot_manual = 0.0;
    double sum_sq = 0.0;
    for (int i = 0; i < n; ++i) {
        dot_manual += x_man[i] * y_man[i];
        sum_sq += x_man[i] * x_man[i];
    }
    double norm_manual = sqrt(sum_sq);
    end = chrono::high_resolution_clock::now();
    auto ms_manual = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Ручное - Скалярное произведение: " << dot_manual << ", Норма x: " << norm_manual << "\n";
    cout << "Время (Ручное): " << ms_manual.count() << " ns\n";
}

int main() {
    solveAxB();
    compareVectors();
    return 0;
}