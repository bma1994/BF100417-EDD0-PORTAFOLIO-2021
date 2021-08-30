#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void primerLiteral();
void efectuarProcesoTriangulo(double lado1, double lado2, double lado3);
void segundoLiteral();
void efectuarProcesoMayorNumero(double num1, double num2, double num3, double num4, double num5);
void tercerLiteral();
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	do {
		int opcion;
		cout << "Seleccione una opcion:" << endl;
		cout << "1. Primer literal (triangulos)." << endl << "2. Segundo literal (mayor numero)." << endl << "3. Tercer literal (promedio)." << endl << "4. Salir." << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				primerLiteral();
			break;
			case 2:
				segundoLiteral();
			break;
			case 3:
				tercerLiteral();
			break;
			case 4:
				return 0;
			break;
			default:
				cout << "Opcion incorrecta." << endl;
			break;
		}
	}
	while(1);
	return 0;
}

void primerLiteral(){
	double lado1;
	double lado2;
	double lado3;
	cout << "Ingrese el lado 1 del triangulo:" << endl;
	cin >> lado1;
	cout << "Ingrese el lado 2 del triangulo:" << endl;
	cin >> lado2;
	cout << "Ingrese el lado 3 del triangulo:" << endl;
	cin >> lado3;
	efectuarProcesoTriangulo(lado1, lado2, lado3);
	
}

void efectuarProcesoTriangulo(double lado1, double lado2, double lado3){
	if((lado1 + lado2) < lado3 || (lado1 + lado3) < lado2 || (lado2 + lado3) < lado1){
		cout << "Los lados del triangulo no son correctos" << endl;
		return;
	}
	string tipoTriangulo;
	double area;
	if(lado1 == lado2 && lado2 == lado3){
		tipoTriangulo =  "Equilatero";
	}
	else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3){
		tipoTriangulo = "Isosceles";
	}
	else {
		tipoTriangulo = "Escaleno";
	}
	double semiperimetro = (lado1 + lado2 + lado3) / 2;
	area = sqrt(semiperimetro * ((semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3)));
	cout << "Tipo de triangulo: " << tipoTriangulo << endl << "Area del triangulo: " << area << endl;
}


void segundoLiteral(){
	double num1, num2, num3, num4, num5;
	cout << "Ingrese el primer numero: " << endl;
	cin >> num1;
	cout << "Ingrese el segundo numero: " << endl;
	cin >> num2;
	cout << "Ingrese el tercer numero: " << endl;
	cin >> num3;
	cout << "Ingrese el cuarto numero: " << endl;
	cin >> num4;
	cout << "Ingrese el quinto numero: " << endl;
	cin >> num5;
	efectuarProcesoMayorNumero(num1, num2, num3, num4, num5);
}
void efectuarProcesoMayorNumero(double num1, double num2, double num3, double num4, double num5){
	double numeroMayor = num1;
	string posicionNumeroMayor = "Primer";
	if(num2 > numeroMayor){
		numeroMayor = num2;
		posicionNumeroMayor = "Segundo";
	}
	if(num3 > numeroMayor){
		numeroMayor = num3;
		posicionNumeroMayor = "Tercer";
	}
	if(num4 > numeroMayor){
		numeroMayor = num4;
		posicionNumeroMayor = "Cuarto";
	}
	if(num5 > numeroMayor){
		numeroMayor = num5;
		posicionNumeroMayor = "Quinto";
	}
	cout << "El numero mayor es el " << posicionNumeroMayor << " numero (" << numeroMayor << ")." << endl;
}
void tercerLiteral(){
	int cantidad;
	double total;
	double elemento;
	cout << "Cuantos numeros desea ingresar?" << endl;
	cin >> cantidad;
	if(cantidad <= 0){
		cout << "Debe ingresar al menos un elemento." << endl;
	}
	else{
		for(int i = 0; i < cantidad; i++){
			cout << "Ingrese el valor del elemento " << (i + 1) << ":" << endl;
			cin >> elemento;
			total += elemento;
		}
		cout << "Promedio: " << (total / cantidad) << endl;
	}
}
