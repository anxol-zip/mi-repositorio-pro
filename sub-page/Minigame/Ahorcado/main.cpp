#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para transformar letras
#include <locale> // Para uso de caracteres con acentos

using namespace std;

string easy[4] = {"taco", "sol", "gato", "flor"};
string medium[4] = {"mercado", "cactus", "tijeras", "pelota"};
string hard[4] = {"quetzal", "mezcal", "esfinge", "crisalida"};
string palabra, palabra_mostrada;
char letra;
int intentos = 6;
int Lpalabra, aciertos;
bool acierto;

// Función para mostrar la palabra con guiones bajos y letras correctas
void mostrarPalabra() {
    for (int i = 0; i < Lpalabra; i++) {
        cout << palabra_mostrada[i] << " ";
    }
    cout << endl;
}

// Función para dibujar el muñeco y su "agarradera"
void mostrarMuñeco(int intentos) {
    cout << "  _____" << endl;
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
    cout << "______|___" << endl; // Base
    cout << endl;
}

// Función para normalizar letras (convertir a minúsculas y eliminar acentos)
string normalizarLetra(string texto) {
    string acentos = "ÁÉÍÓÚáéíóú";
    string sinAcentos = "AEIOUaeiou";

    for (size_t i = 0; i < texto.size(); i++) {
        for (size_t j = 0; j < acentos.size(); j++) {
            if (texto[i] == acentos[j]) {
                texto[i] = sinAcentos[j]; // Reemplaza letras con acento por sin acento
                break;
            }
        }
        texto[i] = tolower(texto[i]); // Convierte a minúscula
    }
    return texto;
}

void facil() {
    srand(time(0));
    palabra = normalizarLetra(easy[rand() % 4]); // Elige palabra aleatoria y la normaliza
    Lpalabra = palabra.length();
    palabra_mostrada = string(Lpalabra, '_'); // Inicia con guiones bajos
    aciertos = 0;
    acierto = false;

    cout << "¡Dificultad Fácil!" << endl;
    cout << "Adivina la palabra: " << endl;
    mostrarPalabra();

    while(intentos > 0 && aciertos < Lpalabra) {
        acierto = false;
        cout << "Intentos Restantes: " << intentos << "." << endl;
        cout << "Ingresa una letra: ";
        cin >> letra;
        letra = normalizarLetra(string(1, letra))[0]; // Normaliza la letra ingresada

        for (int i = 0; i < Lpalabra; i++) {
            if (palabra[i] == letra && palabra_mostrada[i] == '_') {
                palabra_mostrada[i] = letra;
                aciertos++;
                acierto = true;
            }
        }

        if (acierto) {
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
            // Falta implementar medio();
            break;
        case 3:
            // Falta implementar dificil();
            break;
        case 4:
            cout << "¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opción no válida." << endl;
    }

    return 0;
}
