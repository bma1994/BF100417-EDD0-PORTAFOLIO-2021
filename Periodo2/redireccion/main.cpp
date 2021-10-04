#include <iostream>
#include <string>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string nombre;
	cout << "Escriba su nombre: ";
	getline(cin, nombre);
	cout << "Hola, " << nombre;
	return 0;
}
