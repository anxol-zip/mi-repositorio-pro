import random
import unicodedata

# Palabras por dificultad
easy = ["taco", "sol", "gato", "flor"]
medium = ["mercado", "cactus", "tijeras", "pelota"]
hard = ["quetzal", "mezcal", "esfinge", "crisalida"]

# Función para mostrar la palabra con guiones bajos y letras correctas
def mostrar_palabra(palabra_mostrada):
    print(" ".join(palabra_mostrada))

# Función para dibujar el muñeco y su "agarradera"
def mostrar_muneco(intentos):
    print("  x---x")
    print("  |   |")
    if intentos <= 5:
        print("  O   |")
    else:
        print("      |")
    if intentos <= 4:
        print("  |   |")
    elif intentos <= 3:
        print(" /|   |")
    elif intentos <= 2:
        print(" /|\\  |")
    else:
        print("      |")
    if intentos <= 1:
        print(" /    |")
    elif intentos == 0:
        print(" / \\  |")
    else:
        print("      |")
    print("x_____|__x\n")

# Función para normalizar letras (convertir a minúsculas y eliminar acentos)
def normalizar_letra(texto):
    return ''.join(
        c.lower() for c in unicodedata.normalize('NFD', texto)
        if unicodedata.category(c) != 'Mn'
    )

# Función base para jugar en cualquier dificultad
def jugar(palabras):
    palabra = normalizar_letra(random.choice(palabras))
    Lpalabra = len(palabra)
    palabra_mostrada = ["_"] * Lpalabra
    intentos = 6
    aciertos = 0

    print("Adivina la palabra:")
    mostrar_palabra(palabra_mostrada)

    while intentos > 0 and aciertos < Lpalabra:
        letra = input(f"Intentos restantes: {intentos}. Ingresa una letra: ").strip()
        letra = normalizar_letra(letra)

        if len(letra) != 1:
            print("Por favor, ingresa solo una letra.")
            continue

        acierto = False
        for i in range(Lpalabra):
            if palabra[i] == letra and palabra_mostrada[i] == "_":
                palabra_mostrada[i] = letra
                aciertos += 1
                acierto = True

        if acierto:
            print("¡Correcto!")
        else:
            print("¡Incorrecto!")
            intentos -= 1
            mostrar_muneco(intentos)

        mostrar_palabra(palabra_mostrada)

    if aciertos == Lpalabra:
        print("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^")
        print("¡Felicidades! :D Has adivinado la palabra.")
        print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~")
    else:
        print("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")
        print(f"Game Over D:. La palabra era: {palabra}")
        print("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX")

# Función principal
def main():
    print("¡BIENVENID@ AL JUEGO DEL AHORCADO!")
    print("----------------------------------------")
    print("Selecciona la dificultad del juego:")
    print("1. Fácil")
    print("2. Medio")
    print("3. Difícil")
    print("4. Salir")

    try:
        n = int(input("Opción: "))
    except ValueError:
        print("Opción no válida.")
        return

    print("----------------------------------------")
    if n == 1:
        print("¡Dificultad Fácil!")
        jugar(easy)
    elif n == 2:
        print("¡Dificultad Media!")
        jugar(medium)
    elif n == 3:
        print("¡Dificultad Difícil!")
        jugar(hard)
    elif n == 4:
        print("¡Hasta luego!")
    else:
        print("Opción no válida.")

if __name__ == "__main__":
    main()
