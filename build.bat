@echo off
echo Building chessMTUCI with CMake...

REM Очистка предыдущей сборки
if exist build rmdir /s /q build

REM Создание папки сборки
mkdir build
cd build

REM Генерация проекта для Visual Studio 2022
cmake .. -G "Visual Studio 17 2022" -A x64

if %errorlevel% neq 0 (
    echo CMake generation failed!
    pause
    exit /b 1
)

REM Сборка Release версии
cmake --build . --config Release

if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b 1
)

echo.
echo Build successful!
echo Executable: build\Release\chessMTUCI.exe
echo Images folder: build\Release\images\

cd ..
pause