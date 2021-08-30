#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Autor: Carlos Eleazar Baires Fuentes, BF100417*/
using namespace std;

int main() {
	int movJug;
	cout << "Nombre del alumno: Carlos Eleazar Baires Fuentes. Carnet: BF100417.\nJuguemos a piedra, papel, tijera, lagarto o spock. Selecciona tu movimiento." <<endl;
	cout << "1. Piedra\n2. Papel\n3. Tijera\n4. Lagarto\n5. Spock" <<endl;
	cin >> movJug;
	srand(time(0));
	int movComp = rand() % 5 + 1;
	string nombreMovComp;
	string nombreMovJug;
	switch(movJug){
		case 1:
			nombreMovJug = "Piedra";
			break;
		case 2:
			nombreMovJug = "Papel";
			break;
		case 3:
			nombreMovJug = "Tijera";
			break;
		case 4:
			nombreMovJug = "Lagarto";
			break;
		case 5:
			nombreMovJug = "Spock";
			break;
	}
		switch(movComp){
		case 1:
			nombreMovComp = "Piedra";
			break;
		case 2:
			nombreMovComp = "Papel";
			break;
		case 3:
			nombreMovComp = "Tijera";
			break;
		case 4:
			nombreMovComp = "Lagarto";
			break;
		case 5:
			nombreMovComp = "Spock";
			break;
	}
	cout << "Tu escogiste " << nombreMovJug << endl << "La computadora escogio: " << nombreMovComp << endl;
	if(movJug == movComp){
		cout << "Empate" << endl;
	}
	else if(movJug == 1 && (movComp == 4 || movComp == 3)){
		cout << "Ganaste" << endl;
	}
		else if(movJug == 2 && (movComp == 1 || movComp == 5)){
		cout << "Ganaste" << endl;
	}
		else if(movJug == 3 && (movComp == 2 || movComp == 4)){
		cout << "Ganaste" << endl;
	}
		else if(movJug == 4 && (movComp == 5 || movComp == 2)){
		cout << "Ganaste" << endl;
	}
		else if(movJug == 5 && (movComp == 3 || movComp == 1)){
		cout << "Ganaste" << endl;
	}
	else {
		cout << "Perdiste" << endl;
	}
	return 0;
}
