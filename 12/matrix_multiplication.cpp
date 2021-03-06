#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void init_matrix(int n1, int n2, ifstream &in, vector<vector<double>> &A);

void out_matrix(int n1, int n2, const vector<vector<double>> &A);

vector<vector<double>> &
multiplication(int n1, int n2, int n3, const vector<vector<double>> &A, const vector<vector<double>> &B,
               vector<vector<double>> &C);

int main() {
    int n1 = 3, n2 = 4, n3 = 3;
    int c_x_size, c_y_size;
    std::ifstream in("in.txt");
    std::ofstream out("out.txt");

    vector<vector<double>> A(n1, vector<double>(n2));
    vector<vector<double>> B(n2, vector<double>(n3));

    c_x_size = n1 < n2 ? n1 : n2;
    c_y_size = n2 < n3 ? n2 : n3;

    vector<vector<double>> C(c_x_size, vector<double>(c_y_size));

    init_matrix(n1, n2, in, A);
    init_matrix(n2, n3, in, B);

    in.close();

    printf("n1 = %d\nn2 = %d\nn3 = %d\n", n1, n2, n3);
    printf("\n");

    printf("Matrix A:\n");
    out_matrix(n1, n2, A);
    printf("\n");
    printf("Matrix B:\n");
    out_matrix(n2, n3, B);

    printf("\n");
    printf("A * B = C\n");

    C = multiplication(n1, n2, n3, A, B, C);

    printf("\n");
    printf("Matrix C:\n");
    out_matrix(c_x_size, c_x_size, C);

    for (int i = 0; i < c_x_size; ++i) {
        for (int j = 0; j < c_y_size; ++j) {
            out << C[i][j];
            if (j + 1 < c_y_size) out << " ";
        }
        out << "\n";
    }

    return 0;
}

vector<vector<double>> &
multiplication(int n1, int n2, int n3, const vector<vector<double>> &A, const vector<vector<double>> &B,
               vector<vector<double>> &C) {
    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < n3; ++j)
            for (int k = 0; k < n2; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
    return C;
}

void out_matrix(int n1, int n2, const vector<vector<double>> &A) {
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            printf("%6.2f", A[i][j]);
        }
        printf("\n");
    }
}

void init_matrix(int n1, int n2, ifstream &in, vector<vector<double>> &A) {
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            in >> A[i][j];
        }
    }
}
