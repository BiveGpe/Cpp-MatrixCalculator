#include <iostream>
#include <random>

using namespace std;

// Funkcja wypelniajaca macierz pseudolosowymi liczbami korzystajac z biblioteki random
void fillMatrixWithRandomNumbers(int matrix[3][3]) {
    random_device rd; // Tworzy obiekt random device ktory generuje seed
    mt19937 gen(rd());  // Tworzy generator liczb losowych korzystajac z seed'a
    uniform_int_distribution<> dis(0, 9); // Tworzy obiekt do generowania int'a z zakresu 0-9

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = dis(gen);
        }
    }
}

// Wypisuje menu i pobiera wybor od użytkownika
int printMenu() {
    int choice;
    cout << "MENU:" << endl;
    cout << "1. Dodawnie macierzy" << endl;
    cout << "2. Odejmowanie macierzy" << endl;
    cout << "3. Mnozenie macierzy" << endl;
    cout << "4. Transpozycja macierzy" << endl;
    cout << "Podaj liczbe od 1 do 4: ";
    cin >> choice;
    cout << endl;

    return choice;
}

// Wypisuje macierzy
void printMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Dodaje macierzy
void addMatrix(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Odejmowanie macierzy
void subtractMatrix(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Mnozenie macierzy
void multiplyMatrix(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Transponuje Macierz
void transposeMatrix(int A[3][3], int B[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            B[i][j] = A[j][i];
        }
    }
}

int main() {
    // Deklaruje zmienne
    int matrixA[3][3], matrixB[3][3], matrixC[3][3];
    int userChoice;

    // Wypelnia macierze losowymi liczbami
    fillMatrixWithRandomNumbers(matrixA);
    fillMatrixWithRandomNumbers(matrixB);

    // Menu
    do {
        userChoice = printMenu();
    } while (userChoice < 1 || userChoice > 4);

    // Zalezenie od wyboru wykonuje dzialanie i wypisuje macierze
    switch (userChoice) {
        case 1:
            addMatrix(matrixA, matrixB, matrixC);
            cout << "Macierz A:" << endl;
            printMatrix(matrixA);
            cout << "Macierz B:" << endl;
            printMatrix(matrixB);
            cout << "Macierz C ktora powstala w wyniku dzialania:" << endl;
            printMatrix(matrixC);
            break;
        case 2:
            subtractMatrix(matrixA, matrixB, matrixC);
            cout << "Macierz A:" << endl;
            printMatrix(matrixA);
            cout << "Macierz B:" << endl;
            printMatrix(matrixB);
            cout << "Macierz C ktora powstala w wyniku dzialania:" << endl;
            printMatrix(matrixC);
            break;
        case 3:
            multiplyMatrix(matrixA, matrixB, matrixC);
            cout << "Macierz A:" << endl;
            printMatrix(matrixA);
            cout << "Macierz B:" << endl;
            printMatrix(matrixB);
            cout << "Macierz C ktora powstala w wyniku dzialania:" << endl;
            printMatrix(matrixC);
            break;
        case 4:
            transposeMatrix(matrixA, matrixB);
            cout << "Macierz A:" << endl;
            printMatrix(matrixA);
            cout << "Macierz A transponowana:" << endl;
            printMatrix(matrixB);
            break;
    }

    return 0;
}
