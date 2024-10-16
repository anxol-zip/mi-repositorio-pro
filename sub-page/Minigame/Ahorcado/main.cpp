#include <iostream>
#include <string> //Para usar strings
//Estas dos librerías son para generar números aleatorios
#include <cstdlib>
#include <ctime>
#include <locale> // Para uso de caracteres con acentos

using namespace std;

string easy[4] = {"taco", "sol", "gato", "flor"}; //Vector de palabras fáciles
string medium[4] = {"mercado", "cactus", "tijeras", "pelota"}; //Vector de palabras medias
string hard[4] = {"quetzal", "mezcal", "esfinge", "crisalida"}; //Vector de palabras difíciles
string palabra, palabra_mostrada; //Palabra a adivinar y palabra mostrada con guiones bajos
char letra; //Letra ingresada por el usuario
int intentos = 6; //Número de intentos
int Lpalabra, aciertos; //Longitud de la palabra y número de aciertos
bool win; //Variable para saber si se ganó o no

// Función para mostrar la palabra con guiones bajos y letras correctas
void mostrarPalabra() {
    for (int i = 0; i < Lpalabra; i++) {
        cout << palabra_mostrada[i] << " ";
    }
    cout << endl;
}

// Función para dibujar el muñeco y su "agarradera"
void mostrarMuñeco(int intentos) {
    cout << "  x---x" << endl;
    cout << "  |   |" << endl;
    switch(intentos) {
        case 5:
            cout << "  O   |" << endl; // Cabeza
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 4:
            cout << "  O   |" << endl; // Cabeza y torso
            cout << "  |   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 3:
            cout << "  O   |" << endl; // Cabeza, torso y brazo izquierdo
            cout << " /|   |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 2:
            cout << "  O   |" << endl; // Cabeza, torso y ambos brazos
            cout << " /|\\  |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
        case 1:
            cout << "  O   |" << endl; // Cabeza, torso, brazos y pierna izquierda
            cout << " /|\\  |" << endl;
            cout << " /    |" << endl;
            cout << "      |" << endl;
            break;
        case 0:
            cout << "  O   |" << endl; // Cabeza, torso, brazos y ambas piernas
            cout << " /|\\  |" << endl;
            cout << " / \\  |" << endl;
            cout << "      |" << endl;
            break;
        default:
            cout << "      |" << endl;
            cout << "      |" << endl;
            cout << "      |" << endl;
            break;
    }
    cout << "x_____|__x" << endl; // Base
    cout << endl;
}

// Función para normalizar letras (convertir a minúsculas y eliminar acentos)
string normalizarLetra(string texto) {
    string acentos = "ÁÉÍÓÚáéíóú";
    string sinAcentos = "AEIOUaeiou";

    for (int i = 0; i < texto.size(); i++) { //texto.size() es el tamaño del string
        for (int j = 0; j < acentos.size(); j++) {
            if (texto[i] == acentos[j]) {
                texto[i] = sinAcentos[j]; // Reemplaza letras con acento por sin acento
                break;
            }
        }
        texto[i] = tolower(texto[i]); // Convierte a minúscula
    }
    return texto;
}

// Función base para jugar en cualquier dificultad
void jugar(string palabras[], int tamano) {
    srand(time(0));
    palabra = normalizarLetra(palabras[rand() % tamano]); // Elige palabra aleatoria y la normaliza
    Lpalabra = palabra.length();
    palabra_mostrada = string(Lpalabra, '_'); // Inicia con guiones bajos
    aciertos = 0;
    intentos = 6;
    win = false;

    cout << "Adivina la palabra: " << endl;
    mostrarPalabra();

    while (intentos > 0 && aciertos < Lpalabra) {
        win = false;
        cout << "Intentos Restantes: " << intentos << "." << endl;
        cout << "Ingresa una letra: ";
        cin >> letra;
        letra = normalizarLetra(string(1, letra))[0]; // Normaliza la letra ingresada

        for (int i = 0; i < Lpalabra; i++) {
            if (palabra[i] == letra && palabra_mostrada[i] == '_') {
                palabra_mostrada[i] = letra;
                aciertos++;
                win = true;
            }
        }

        if (win) {
            cout << "¡Correcto!" << endl;
        } else {
            cout << "¡Incorrecto!" << endl;
            intentos--;
            mostrarMuñeco(intentos);
        }

        mostrarPalabra();
    }

    if (aciertos == Lpalabra) {
        cout << "¡Felicidades! Has adivinado la palabra." << endl;
    } else {
        cout << "Game Over. La palabra era: " << palabra << endl;
    }
}

// Funciones de dificultades
void facil() {
    cout << "¡Dificultad Fácil!" << endl;
    jugar(easy, 4);
}

void medio() {
    cout << "¡Dificultad Media!" << endl;
    jugar(medium, 4);
}

void dificil() {
    cout << "¡Dificultad Difícil!" << endl;
    jugar(hard, 4);
}

int main() {
    int n;
    cout << "¡BIENVENID@ AL JUEGO DEL AHORCADO!" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Selecciona la dificultad del juego: " << endl;
    cout << "1. Fácil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. Difícil" << endl;
    cout << "4. Salir" << endl;
    cin >> n;

    switch (n) {
        case 1:
            facil();
            break;
        case 2:
            medio();
            break;
        case 3:
            dificil();
            break;
        case 4:
            cout << "¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
    }

    return 0;
}
