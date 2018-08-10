#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int menu (){
   int opcion = 0;
   while (true){
  	cout<<"	MENU" << endl
	<< "1. Ejercicio 1" << endl
	<< "2. Ejercicio 2" << endl
	<< "3. Salir" << endl;
	cin >> opcion;

	if (opcion < 1 || opcion > 3)
	   cout<<"Opcion incorrecta, intente de nuevo."<<endl;
	else 
	   return opcion;
}
}


//crear matriz
int** createMatrix(int n){
	int** retVal = new int*[n];

	for (int i = 0; i < n; i++){
		retVal[i] = new int [n];
	}
	return retVal;
}

//llenar matriz
int** llenarMatrix(int size, int** matrix){
	int random;
	srand(time(NULL));
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			random = 1 + rand() % (7 - 1);
			matrix[i][j] = random;
		}
	}
	return matrix;
}

//llenar matrizzzz cofactores
int** llenarMatrix2(int size, int size2, int** matrix, int** matrix2){
	size = (size - 1)*(size - 1);
	int vector[50];
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (matrix[i][j]!=0 ){
			matrix2[i][j] = matrix[i][j];	
			}
		}
	}	


	return matrix2;
}



//liberar memoria
void freeMatrix(int n, int** matrix){
	for (int i = 0; i < n; i++){
		delete [] matrix[i];
	}
	delete[] matrix;
}

//imprimir matriz
void printMatrix(int size, int** matrix){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout<<" "<<matrix[i][j];
		}
		cout<<endl;
	}
}

/*int validarNum(char str, int num){
	if (isdigit(str))
		num = atoi(str);
	else {
		while( num!= -1){
			cout<<"Error. Ingrese dato de nuevo: "<<endl;
			cin >> str;
			if (isdigit(str))
			//	num = atoi(str);
		}
	}
	return num;
}*/

int** cofactores(int** matriz,int size, int x, int y){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (i == x)
				matriz[i][j] = 0;
			if (j == y)
				matriz[i][j] = 0;
		}
	}
	return matriz;
}

void ejercicio1(){
	int n = -1,fila=-1, col=-1, random;
	string  stringN, stringFila, stringCol;
	char n1,fila1,col1;
	int** matriz;
	srand(time(NULL));

	cout<<"Ingrese tamano de la matriz: "<<endl;
	cin >> n;

//	n = validarNum(n1,n);

	while (n < 0){
		cout<<"Ingrese numero de nuevo. "<<endl;		
		cin >> n;
	//		n = validarNum(n1,n);
	}	

	cout<<"Ingrese coordenada de la fila de la matriz: "<<endl;
	cin >> fila;
	cout<<"Ingrese coordenada de la columna de la matriz:"<<endl;
	cin >> col;


//	fila = validarNum(fila1,fila);
//	col = validarNum(col1,col);
	
	while ( (fila < 0 || fila > n) || (col < 0 || col > n) ){
		cout<<"Opcion invalida. Ingrese coordenada fila de nuevo:"<<endl;
		cin >> fila;
		cout<<"Ingrese coordenada columna de nuevo: "<<endl;
		cin >> col;
	//	fila = validarNum(fila1,fila);
	//	col = validarNum(col1, fila);
	}

	matriz = createMatrix(n);
	matriz = llenarMatrix(n,matriz);
	printMatrix(n,matriz);
//	freeMatrix(n,matriz);
	matriz = cofactores(matriz,n,fila,col);

	cout<<endl;
	printMatrix(n,matriz);
	cout<<endl;
	int size2 = n - 1;
	int** matriz2;
	matriz2 = createMatrix(size2);
//	matriz2 = llenarMatrix2(n,size2, matriz, matriz2);
//	cout<<"Cofactores: "<<endl;
//	printMatrix(size2,matriz2);
//	freeMatrix(n,matriz);
//	freeMatrix(size2,matriz2)
}



void ejercicio2(){
	cout<<"Hola";
}


int main (){
	int opcion = 0;
	while (opcion != 3){
		switch (opcion = menu()){
			case 1:
				ejercicio1();
			break;

			case 2:
				ejercicio2();
			break;

		}
	 }
	return 0;
};
