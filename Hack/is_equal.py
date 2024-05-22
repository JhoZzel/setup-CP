import filecmp
import sys

def comparar_archivos(archivo1, archivo2):
    # Comparar los archivos
    resultado = filecmp.cmp(archivo1, archivo2)
    return "YES" if resultado else "NO"

if __name__ == "__main__":
    # Verificar si se proporcionaron los nombres de los archivos como argumentos
    if len(sys.argv) != 3:
        print("Usage: python script.py archivo1 archivo2")
        sys.exit(1)

    # Obtener los nombres de los archivos de los argumentos de línea de comandos
    archivo1 = sys.argv[1]
    archivo2 = sys.argv[2]

    # Comparar los archivos y mostrar el resultado
    print(comparar_archivos(archivo1, archivo2))

