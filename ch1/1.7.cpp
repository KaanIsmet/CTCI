#include <iostream>
#include <cstdlib>

#define MAX_COLS 10
#define MAX_ROWS 10

using std::cout, std::cin, std::endl, std::swap;

int** initMatrix();
void fillMatrix(int** matrix);
void rotateMatrix(int** matrix);
void printMatrix(int** matrix);
void deleteMatrix(int** matrix);

int main(int argc, char** argv) {
	int** matrix_a = initMatrix();
	fillMatrix(matrix_a);
	
	cout << "Before rotating matrix" << endl;
	printMatrix(matrix_a);
	cout << "After rotating matrix" << endl;
	rotateMatrix(matrix_a);
	printMatrix(matrix_a);
	deleteMatrix(matrix_a);
	return 0;
}

int** initMatrix() {
	int** matrix = new int*[MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		matrix[i] = new int[MAX_COLS];
	}
	return matrix;
}

void deleteMatrix(int** matrix) {
	for (int i = 0; i < MAX_ROWS; i++) {
		delete matrix[i];
	}

	delete matrix;
}


void fillMatrix(int** matrix) {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			if (j % 2 == 0)
				matrix[i][j] = 0;
			else
				matrix[i][j] = 1;
		}
	}
}

void printMatrix(int** matrix) {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void rotateMatrix(int** matrix) {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = i + 1; j < MAX_COLS; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS / 2; j++) {
			swap(matrix[i][j], matrix[i][MAX_COLS - j - 1]);
		}
	}
}
