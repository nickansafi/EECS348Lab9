#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void multiply(std::string name) {
    std::ifstream input (name);
    int a = 0;
    std::string b;
    int c = 0;
    while (input >> b) {
        a = std::stoi(b);
        break;
    }
    input.close();
    std::ifstream input2 (name);
    int d = 0;
    int matrix1[a][a];
    int matrix2[a][a];
    int e = 0;
    int f = 0;
    int g = 0;
    while (input2 >> b) {
        if (g >= 1 && g < (a*a)+1) {
            matrix1[e/4][e%4] = std::stoi(b);
            e += 1;
        }
        if (g >= (a*a)+1 && g < (2*a*a)+1) {
            matrix2[f/4][f%4] = std::stoi(b);
            f += 1;
        }
        g += 1;
    }
    input2.close();
    int matrix3[a][a];
    for (int h = 0; h < a; h++) {
        for (int i = 0; i < a; i++) {
            matrix3[h][i] = 0;
        }
    }
    for (int h = 0; h < a; h++) {
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                matrix3[h][i] += matrix1[h][j] * matrix2[j][i];
            }
        }
    }
    for (int h = 0; h < a; h++) {
        for (int i = 0; i < a; i++) {
            std::cout << std::setw(5) << matrix3[h][i] << " ";
            if ((i + 1) % a == 0) {
                std::cout << std::endl;
            }
        }
    }
}

int main() {
    std::cout << "What is the name of the input file?" << std::endl;
    std::string name;
    std::cin >> name;
    multiply(name);
}