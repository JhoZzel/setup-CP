#!/bin/bash

# Compilar los archivos C++ estáticos
g++ Gen.cpp -o Gen
g++ Checker.cpp -o Checker
g++ Correct.cpp -o Solution

# Obtener el lenguaje y el archivo fuente a hackear desde los argumentos
language=$1
source_file=$2

# Variables para el ejecutable o script a hackear
executable=""

# Compilar o preparar el archivo a hackear según el lenguaje
if [ "$language" == "cpp" ]; then
    g++ "$source_file" -o Bad
    executable="./Bad"
elif [ "$language" == "python" ]; then
    executable="python3 $source_file"
elif [ "$language" == "java" ]; then
    javac "$source_file"
    class_name=$(basename "$source_file" .java)
    executable="java $class_name"
else
    echo "Unsupported language: $language"
    exit 1
fi

# Número de casos de prueba
tt=100

# Inicialización de la verificación
ver="Accepted"

# Bucle de pruebas
for ((i = 1; i <= $tt; i++)); do
    ./Gen > input
    echo "Running on test $i"
    ./Solution < input > out1
    timeout 20 $executable < input > out2
    ./Checker input out2 out1 ver
    ver=$(cat ver)
    if [ "$ver" != "Accepted" ]; then
        break
    fi
done

echo "$ver"

