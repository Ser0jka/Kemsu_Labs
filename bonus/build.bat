@echo off
:: Устанавливаем кодировку UTF-8, чтобы русский текст отображался корректно
chcp 65001 > nul

:: Создаем папку build для объектных файлов
if not exist build mkdir build

echo ===============================================
echo        СБОРКА ПРОЕКТА (MSVC cl.exe)
echo ===============================================

:: /nologo - убирает приветствие компилятора
:: /EHsc   - включает стандартную обработку исключений C++
:: /c      - только компиляция (создание .obj), без линковки
:: /Fo:    - указывает, куда положить объектные файлы
:: /I.     - путь к заголовочным файлам (текущая папка)

echo [1/3] Компиляция: main.cpp...
cl /nologo /EHsc /c main.cpp /Fo:build/main.obj /I.
if %errorlevel% neq 0 goto error

echo [2/3] Компиляция: array.cpp...
cl /nologo /EHsc /c f.cpp /Fo:build/array.obj /I.
if %errorlevel% neq 0 goto error


echo -----------------------------------------------
echo [3/3] Линковка: создание program.exe...
:: /Fe: указывает имя и путь готового файла
link /nologo build/main.obj build/array.obj /OUT:program.exe
if %errorlevel% neq 0 goto error

echo ===============================================
echo   Сборка завершена! Запускаю программу...
echo ===============================================
echo.

program.exe

echo.
echo -----------------------------------------------
pause
exit /b 0

:error
echo.
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
echo   ПРОИЗОШЛА ОШИБКА ПРИ СБОРКЕ
echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
pause
exit /b 1