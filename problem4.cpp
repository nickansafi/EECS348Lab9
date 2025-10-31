#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void diagonal(int a1, std::string name) {
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
    int h = 0;
    int i = 0;
    if (a1 == 1) {
        for (int j = 0; j < a; j++) {
            h += matrix1[j][j];
            i += matrix1[j][a-j-1];
        }
    } else {
        for (int j = 0; j < a; j++) {
            h += matrix2[j][j];
            i += matrix2[j][a-j-1];
        }
    }
    std::cout << "Sum of main diagonal: " << h << std::endl << "Sum of secondary diagonal: " << i << std::endl;
}

int main() {
    std::cout << "What is the name of the input file?" << std::endl;
    std::string name;
    std::cin >> name;
    int a1 = 0;
    std::cout << "Do you want the sums of diagonals of matrix 1 or matrix 2? Enter 1 or 2:" << std::endl;
    std::cin >> a1;
    while (a1 > 2 || a1 < 1) {
        std::cout << "Enter 1 or 2." << std::endl;
        std::cin >> a1;
    }
    diagonal(a1,name);
}