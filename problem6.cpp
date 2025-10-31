#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int count(std::string name) {
    std::ifstream input (name);
    int a = 0;
    std::string b;
    int c = 0;
    while (input >> b) {
        a = std::stoi(b);
        break;
    }
    input.close();
    return a;
}

void column(int a1, int a2, int a3, std::string name) {
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
    if (a1 = 1) {
        int h = 0;
        for (int i = 0; i < a; i++) {
            h = matrix1[i][a2];
            matrix1[i][a2] = matrix1[i][a3];
            matrix1[i][a3] = h;
        }
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a; k++) {
                std::cout << std::setw(5) << matrix1[j][k] << " ";
                if ((k + 1) % a == 0) {
                    std::cout << std::endl;
                }
            }
        }
    } else {
        int h = 0;
        for (int i = 0; i < a; i++) {
            h = matrix2[i][a2];
            matrix2[i][a2] = matrix2[i][a3];
            matrix2[i][a3] = h;
        }
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a; k++) {
                std::cout << std::setw(5) << matrix2[j][k] << " ";
                if ((k + 1) % a == 0) {
                    std::cout << std::endl;
                }
            }
        }
    }
}

int main() {
    std::cout << "What is the name of the input file?" << std::endl;
    std::string name;
    std::cin >> name;
    int a1 = 0;
    std::cout << "Do you want to change the columns of matrix 1 or matrix 2? Enter 1 or 2:" << std::endl;
    std::cin >> a1;
    while (a1 > 2 || a1 < 1) {
        std::cout << "Enter 1 or 2." << std::endl;
        std::cin >> a1;
    }
    int a2 = -1;
    std::cout << "Enter a column index to swap:" << std::endl;
    std::cin >> a2;
    while (a2 >= count(name) || a2 < 0) {
        std::cout << "Enter a valid column index." << std::endl;
        std::cin >> a2;
    }
    int a3 = -1;
    std::cout << "Enter another column index to swap:" << std::endl;
    std::cin >> a3;
    while (a3 >= count(name) || a3 < 0) {
        std::cout << "Enter a valid column index." << std::endl;
        std::cin >> a3;
    }
    column(a1,a2,a3,name);
}