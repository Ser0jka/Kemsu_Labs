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

echo [1/3] Компиляция: vect.cpp...
cl /nologo /EHsc /c vect.cpp /Fo:build/vect.obj
if %errorlevel% neq 0 goto error

echo [2/3] Компиляция: calc_vect.cpp...
cl /nologo /EHsc /c calc_vect.cpp /Fo:build/calc_vect.obj
if %errorlevel% neq 0 goto error

echo [3/3] Компиляция: main.cpp...
cl /nologo /EHsc /c main.cpp /Fo:build/main.obj
if %errorlevel% neq 0 goto error

echo -----------------------------------------------
echo [4/4] Линковка: создание main.exe...
:: /Fe: указывает имя и путь готового файла
link /nologo build/main.obj build/vect.obj build/calc_vect.obj /OUT:main.exe
if %errorlevel% neq 0 goto error

echo ===============================================
echo   Сборка завершена! Запускаю программу...
echo ===============================================
echo.

main.exe

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
