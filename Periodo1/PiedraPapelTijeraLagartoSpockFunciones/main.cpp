#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

string obtenerInformacionAlumno();
string obtenerMovimientoJugador();
int obtenerMovimientoComputadora();
string obtenerNombreMovimiento(int mov);
void determinarGanador(string movimientoJugador, int movimientoComputadora);
void procesarEntradaJugadorPiedra(int movimientoComputadora);
void procesarEntradaJugadorPapel(int movimientoComputadora);
void procesarEntradaJugadorTijera(int movimientoComputadora);
void procesarEntradaJugadorLagarto(int movimientoComputadora);
void procesarEntradaJugadorSpock(int movimientoComputadora);

int main(int argc, char** argv) {
	string informacionAlumno = obtenerInformacionAlumno();
	cout << informacionAlumno << endl;
	do {
	string movimientoJugador = obtenerMovimientoJugador();
		if(movimientoJugador == "salir"){
		return 0;
		}
	int movimientoComputadora = obtenerMovimientoComputadora();
	determinarGanador(movimientoJugador, movimientoComputadora);
	}
	while(1);
	return 0;
}

string obtenerInformacionAlumno(){
	string informacionAlumno = "Nombre del alumno: Carlos Eleazar Baires Fuentes. Carnet: BF100417.";
	return informacionAlumno;
}

string obtenerMovimientoJugador(){
	string movJug;
	cout << "Juguemos a piedra, papel, tijera, lagarto o spock. Selecciona tu movimiento." << endl;
	cout << "piedra, papel, tijera, lagarto o spock (para terminar el juego, escribe salir)" << endl;
	cin >> movJug;
	return movJug;
}

int obtenerMovimientoComputadora(){
	srand(time(0));
	int movComp = rand() % 5 + 1;
	return movComp;
}
string obtenerNombreMovimiento(int mov){
	string nombreMovimientoComputadora;
	switch(mov){
			case 1:
			nombreMovimientoComputadora = "piedra";
			break;
		case 2:
			nombreMovimientoComputadora = "papel";
			break;
		case 3:
			nombreMovimientoComputadora = "tijera";
			break;
		case 4:
			nombreMovimientoComputadora = "lagarto";
			break;
		case 5:
			nombreMovimientoComputadora = "spock";
			break;	
	}
	return nombreMovimientoComputadora;
	
}

void determinarGanador(string movimientoJugador, int movimientoComputadora){
	cout << "******" << endl;
	cout << "Tu escogiste " << movimientoJugador << ". La computadora escogio " << obtenerNombreMovimiento(movimientoComputadora) << endl;
	if(movimientoJugador == obtenerNombreMovimiento(movimientoComputadora)){
		cout << "Empate" << endl;
	}
	else if (movimientoJugador == "piedra"){
		procesarEntradaJugadorPiedra(movimientoComputadora);
	}
	else if (movimientoJugador == "papel"){
		procesarEntradaJugadorPapel(movimientoComputadora);
	}
	else if (movimientoJugador == "tijera"){
		procesarEntradaJugadorTijera(movimientoComputadora);
	}
	else if (movimientoJugador == "lagarto"){
		procesarEntradaJugadorLagarto(movimientoComputadora);
	}
	else if (movimientoJugador == "spock"){
		procesarEntradaJugadorSpock(movimientoComputadora);
	}
	else {
		cout << "Entrada no valida. Ingrese piedra, papel, tijera, lagarto o spock." << endl;
	}
	cout << "******" << endl;
}

void procesarEntradaJugadorPiedra(int movimientoComputadora){
	switch(movimientoComputadora){
		case 2:
			cout << "La computadora gana. El papel envuelve la piedra." << endl;
			break;
		case 3:
			cout << "Tu ganaste. La piedra aplasta las tijeras." << endl;
			break;
		case 4:
			cout << "Tu ganaste. La piedra aplasta al lagarto." << endl;
			break;
		case 5:
			cout << "La computadora gana. Spock desintegra la piedra." << endl;
			break;
		default:
			cout << "El movimiento de la computadora es incorrecto." << endl;
			break;
	}
}

void procesarEntradaJugadorPapel(int movimientoComputadora){
	switch(movimientoComputadora){
		case 1:
			cout << "Tu ganaste. El papel envuelve la piedra." << endl;
			break;
		case 3:
			cout << "La computadora gana. Las tijeras cortan el papel." << endl;
			break;
		case 4:
			cout << "La computadora gana. El lagarto devora el papel." << endl;
			break;
		case 5:
			cout << "Tu ganaste. El papel desaprueba a Spock." << endl;
			break;
		default:
			cout << "El movimiento de la computadora es incorrecto." << endl;
			break;
	}
}

void procesarEntradaJugadorTijera(int movimientoComputadora){
	switch(movimientoComputadora){
		case 1:
			cout << "La computadora gana. La piedra aplasta las tijeras." << endl;
			break;
		case 2:
			cout << "Tu ganaste. Las tijeras cortan el papel." << endl;
			break;
		case 4:
			cout << "Tu ganaste. Las tijeras decapitan al lagarto." << endl;
			break;
		case 5:
			cout << "La computadora gana. Spock aplasta las tijeras." << endl;
			break;
		default:
			cout << "El movimiento de la computadora es incorrecto." << endl;
			break;
	}
}

void procesarEntradaJugadorLagarto(int movimientoComputadora){
	switch(movimientoComputadora){
		case 1:
			cout << "La computadora gana. La piedra aplasta al lagarto." << endl;
			break;
		case 2:
			cout << "Tu ganaste. El lagarto devora el papel." << endl;
			break;
		case 3:
			cout << "La computadora gana. Las tijeras decapitan al lagarto." << endl;
			break;
		case 5:
			cout << "Tu ganaste. El lagarto envenena a Spock." << endl;
			break;
		default:
			cout << "El movimiento de la computadora es incorrecto." << endl;
			break;
	}
}

void procesarEntradaJugadorSpock(int movimientoComputadora){
		switch(movimientoComputadora){
		case 1:
			cout << "Tu ganaste. Spock desintegra la piedra." << endl;
			break;
		case 2:
			cout << "La computadora gana. El papel desaprueba a Spock." << endl;
			break;
		case 3:
			cout << "Tu ganaste. Spock aplasta las tijeras." << endl;
			break;
		case 4:
			cout << "La computadora gana. El lagarto envenena a Spock." << endl;
			break;
		default:
			cout << "El movimiento de la computadora es incorrecto." << endl;
			break;
	}
}

