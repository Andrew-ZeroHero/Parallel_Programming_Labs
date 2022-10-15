#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <math.h>                   // not necessary, used to enter the size of matrix
using namespace std;

// Matrix output to a .txt file
void write_matrix(string str, size_t rows, size_t cols)
{
    vector<vector<int>> m(rows);
    for (auto& i : m)
        i.resize(cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            m[i][j] = rand() % 1000;
    }
    ofstream data(str);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            data << setw(5) << m[i][j];
        data << endl;
    }
    data.close();
}

// Matrix input from a .txt file
void read_matrix(vector<vector<int>>& m, int rows, int cols, string str)
{
    m.resize(rows);
    for (auto& i : m)
        i.resize(cols);
    ifstream data;
    data.open(str);
    if (data.is_open()) {
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[i].size(); j++)
                data >> m[i][j];
        }
    }
    data.close();
}

// Matrix multiplication
void mult(const vector<vector<int>>& m1, const vector<vector<int>>& m2, vector<vector<int>>& m3)                                                         
{
    size_t rows = m1.size();
    size_t cols = m2[0].size();
    m3.resize(rows);
    for (auto& i : m3)
        i.resize(cols);
    for (int i = 0; i < m3.size(); i++) {
        for (int j = 0; j < m3[i].size(); j++) {
            for (int k = 0; k < m2.size(); k++)
                m3[i][j] += m1[i][k] * m2[k][j];
        }
    }
}

// Result matrix output to a .txt file
void write_result(string str, vector<vector<int>>& res)
{
    ofstream data(str);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            data << setw(10) << res[i][j];
        data << endl;
    }
    data.close();
}

int main()
{
    srand(time(NULL));
    size_t row, col, n;
    vector<vector<int>> matr1, matr2, matr3;

    cout << "Enter size of matrix: ";
    cin >> n;
    row = abs((int)n);
    col = abs((int)n);

    write_matrix("mat1.txt", row, col);
    write_matrix("mat2.txt", row, col);

    read_matrix(matr1, row, col, "mat1.txt");
    read_matrix(matr2, row, col, "mat2.txt");

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();       // Multiplication time counter start
    mult(matr1, matr2, matr3);                                                  //
    chrono::steady_clock::time_point end = chrono::steady_clock::now();         // Multiplication time counter end
    
    write_result("mult.txt", matr3);
    cout << "Elapsed time: " << chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms " << endl;
    return 0;
}
