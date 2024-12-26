#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace chrono;

// Fungsi untuk menghitung determinan menggunakan ekspansi kofaktor
double determinantRecursive(vector<vector<double>> matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    double det = 0.0;
    vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));
    for (int k = 0; k < n; k++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == k) continue;
                subMatrix[subi][subj++] = matrix[i][j];
            }
            subi++;
        }
        det += (k % 2 == 0 ? 1 : -1) * matrix[0][k] * determinantRecursive(subMatrix, n - 1);
    }
    return det;
}

// Fungsi untuk menghasilkan matriks acak
vector<vector<double>> generateRandomMatrix(int n) {
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10 + 1; // Nilai acak 1-10
        }
    }
    return matrix;
}

int main() {
    for (int n = 1; n <= 15 ; n ++) { // Batas untuk rekursif diatur hingga n=50
        vector<vector<double>> matrix = generateRandomMatrix(n);
        auto start = high_resolution_clock::now();
        double det = determinantRecursive(matrix, n);
        auto end = high_resolution_clock::now();
        duration<double> elapsed = end - start;
        cout << "Recursive | Size: " << n << " | Determinant: " << det << " | Time: " << elapsed.count() << "s\n";
    }
    return 0;
}
