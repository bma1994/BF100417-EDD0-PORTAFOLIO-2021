#include <stdio.h>

#include <iostream> // Entrada/salida

#include <array> // Arreglos

#include <cstdlib> // Random
#include <stdio.h>

#include <iostream> // Entrada/salida

#include <array> // Arreglos

#include <cstdlib> // Random

#include <ctime> // Inicializar random

#include <cctype> // Funciones para caracteres
#include <string>
#include <string.h> // Funciones para cadenas
// CARLOS ELEAZAR BAIRES FUENTES - BF100417
using namespace std;
const int ELEMENTOS = 25;
const int SIZE = 25;
// Algunos de las franquicias de videojuegos mas vendidas
array < string, ELEMENTOS > franquicias = {
  "Assassin's Creed",
  "Battlefield",
  "Call of Duty",
  "Diablo",
  "Dragon Quest",
  "Fallout",
  "Final Fantasy",
  "Gran Turismo",
  "Grand Theft Auto",
  "Halo",
  "Just Dance",
  "Metal Gear",
  "Minecraft",
  "Need for Speed",
  "Resident Evil",
  "Star Wars",
  "Street Fighter",
  "Super Mario",
  "Super Smash Bros",
  "Tetris",
  "The Elder Scrolls",
  "The Legend of Zelda",
  "The Sims",
  "Tomb Raider",
  "Uncharted"
};
// Elige al azar uno de los elementos del arreglo
string elegirElemento(array < string, SIZE > & arr);
// Inicializa la palabra del jugador con guiones bajos
// Devuelve la cantidad de letras a adivinar en la palabra
int inicializarRespuesta(char respuesta[], string palabra);
// Solicita al usuario que ingrese una letra
// y la devuelve a la funci�n desde donde se invoca
char pedirLetra(char respuesta[]);
// Valida si la letra ingresada es parte de la palabra
int validarLetra(char respuesta[], string palabra, char letra);
// Dibuja la figura de un ahorcado
void dibujarAhorcado(int errores, int letrasRestantes, string palabra);
// Jugar al ahorcado
void jugar();
// Elegir una opcion de menu
int elegirOpcion();
// Realizar busqueda binaria en un arreglo
int busquedaBinaria(array < string, SIZE > & arr, string valor);
// Busca una franquicia ingresada por el usuario en el arreglo de franquicias
void buscarFranquicia();

int main() {
  int opcion;
  opcion = elegirOpcion();
  while (opcion != 3) {
    switch (opcion) {
    case 1:
      jugar();
      break;
    case 2:
      buscarFranquicia();
      break;
    }
    cout << endl;
    opcion = elegirOpcion();
  }
  cout << "Que tengas un buen dia." << endl;
  return 0;
}

int elegirOpcion() {
  int opcion;
  cout << "Que desea hacer?" << endl;
  cout << "1- Jugar al ahorcado" << endl;
  cout << "2- Buscar mi franquicia favorita" << endl;
  cout << "3- Salir" << endl;
  cout << "Su eleccion: ";
  cin >> opcion;
  while (cin.fail() || !(opcion >= 1 && opcion <= 3)) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Opcion no valida. Su eleccion: ";
    cin >> opcion;
  }
  cout << endl;
  return opcion;
}
void jugar() {
  string palabra = elegirElemento(franquicias);
  char respuesta[25];
  char letra;
  int letrasRestantes = inicializarRespuesta(respuesta, palabra);
  int intentosFallidos = 0;
  int letrasCorrectas = 0;
  cout << "Jugar al ahorcado" << endl;
  while (letrasRestantes > 0 && intentosFallidos < 7) {
    letra = pedirLetra(respuesta);
    cout << "Escogio" << letra << endl;
    letrasCorrectas = validarLetra(respuesta, palabra, letra);
    if (letrasCorrectas > 0) {
      letrasRestantes -= letrasCorrectas;
    } else {
      intentosFallidos++;
    }
    dibujarAhorcado(intentosFallidos, letrasRestantes, palabra);
  }
}

// Inicializa la palabra del jugador con guiones bajos
// Devuelve la cantidad de letras a adivinar en la palabra
int inicializarRespuesta(char respuesta[], string palabra) {
  int longitudPalabra = palabra.length();
  int cantidadLetras = 0;
  for (int i = 0; i < longitudPalabra; i++) {
    char caracter = palabra.at(i);
    if (isalpha(caracter)) {
      respuesta[i] = '_';
      cantidadLetras++;
    } else {
      respuesta[i] = caracter;
    }
  }
  respuesta[longitudPalabra] = '\0'; // caracter de fin de cadena
  return cantidadLetras;
}
// Elige al azar uno de los elementos del arreglo
string elegirElemento(array < string, SIZE > & arr) {
  // variable est�tica, "recuerda" su valor
  // se usa para plantar la semilla en el generador
  // de numeros aleatorios solo una vez
  static bool semillaPlantada = false;
  if (!semillaPlantada) {
    srand(time(NULL));
    semillaPlantada = true;
  }
  // Genera un n�mero aleatorio entre 0 y 24
  // y devuelve el elemento en ese indice
  int indice = rand() % arr.size();
  return arr[indice];
}

char pedirLetra(char respuesta[]) {
	cout << "Escriba una letra: ";
	string letra;
	cin >> letra;
	while(!isalpha(letra.at(0))){
		cout << "Por favor, ingrese una letra valida: ";
		cin >> letra;
	}
	return letra.at(0);
}

int validarLetra(char respuesta[], string palabra, char letra) {
  int veces = 0;
  for (int i = 0; i < palabra.length(); i++) {
    if (tolower(palabra.at(i)) == tolower(letra) &&
      respuesta[i] != palabra.at(i)) {
      respuesta[i] = palabra.at(i);
      veces++;
    }
  }
  return veces;
}

void dibujarAhorcado(int errores, int letrasRestantes, string palabra) {
  cout << "Intentos fallidos: " << errores << endl;
  cout << " ____" << endl;
  cout << " | |" << endl;
  cout << " | " << (errores > 0 ? "o" : "") << endl;
  cout << " | " << (errores > 1 ? "/" : "") << (errores > 3 ? "|" :
    " ") << (errores > 2 ? "\\" : "") << endl;
  cout << " | " << (errores > 4 ? "|" : "") << endl;
  cout << " | " << (errores > 5 ? "/ " : " ") << (errores > 6 ? "\\" :
    "") << endl;
  cout << " _|_" << endl;
  cout << "| |______" << endl;
  cout << "| |" << endl;
  cout << "|__________|" << endl << endl;
  if (errores > 6) {
    cout << "Te has ahorcado." << endl;
    cout << "La franquicia era " << palabra << endl;
  } else if (letrasRestantes == 0) {
    cout << "Felicidades! Has adivinado." << endl;
  }
}

int busquedaBinaria(array < string, ELEMENTOS > &arr, string valor) {
	char cValor[valor.length() + 1];
	strcpy(cValor, valor.c_str());
	int min = 0;
	int max = arr.size();
	int mid;
	int b;
	int result;
	if(min >= max)
		return -1;
	while(min <= max){
		mid = (min + max) / 2;
		char cElemento[mid];
		cin >> b;
		strcpy(cElemento, arr[mid].c_str());
		result = strcmp(cElemento, cValor);
		if(result == 0)
			return mid;
		if(result > 0)
			min = mid;
		else if(result < 0)
			max = mid;
		}
	return -1;
}
void buscarFranquicia() {
  string franquicia;
  int posicion;
  cin.clear();
  cin.ignore(1000, '\n');
  cout << "Buscar una franquicia en el top 25 de ventas" << endl;
  cout << "Nombre de la franquicia: ";
  getline(cin, franquicia);
  int b = busquedaBinaria(franquicias, franquicia);
  if (b != -1)
    cout << "Genial! Su franquicia esta en el top 25, " << b << endl;
  else
    cout << "Su franquicia no es tan comercial, sus gustos son refinados." << endl;
}
