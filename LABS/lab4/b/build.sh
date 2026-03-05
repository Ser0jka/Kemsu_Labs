#!/bin/bash

# Создаем папку build, если её нет
mkdir -p build

# Сборка объектных файлов
# Добавил флаг -Wall для вывода предупреждений — это полезно
g++ -c headers.cpp -o build/headers.o
g++ -c calculation.cpp -o build/calculation.o
g++ -c main.cpp -o build/main.o

# Проверяем, прошли ли этапы компиляции (код возврата последней команды)
if [ $? -ne 0 ]; then
    echo "--- Ошибка при компиляции объектов! ---"
    exit 1
fi

# Линковка (сборка исполняемого файла)
# Исправил build/file.o на build/headers.o
g++ build/headers.o build/calculation.o build/main.o -o main

# Проверка линковки и запуск
if [ $? -eq 0 ]; then
    echo "--- Сборка завершена успешно. Запуск... ---"
    ./main
else
    echo "--- Ошибка при линковке! ---"
fi
