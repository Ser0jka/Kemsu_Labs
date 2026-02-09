#!/bin/bash

# Сборка объектных файлов
g++ -c file.cpp -o build/file.o
g++ -c main.cpp -o build/main.o

# Линковка (сборка исполняемого файла)
g++ build/file.o build/main.o -o main

# Проверка: если сборка прошла успешно, запустить программу
if [ $? -eq 0 ]; then
    echo "--- Сборка завершена успешно. Запуск... ---"
    ./main
else
    echo "--- Ошибка при сборке! ---"
fi