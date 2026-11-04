@echo off
setlocal

if "%~1"=="" (
    echo Usage: generate.bat lab\task01
    exit /b 1
)

set "TASK=%~1"
set "BUILD_DIR=%TASK%\build"
set "OUT=%BUILD_DIR%\vs"

if not exist "CMakeLists.txt" (
    echo No CMakeLists.txt, cd into oop/
    exit /b 1
)

where cmake >nul 2>nul
if errorlevel 1 (
    echo CMake not found, installing with winget...
    winget install --id Kitware.CMake -e --silent --accept-package-agreements --accept-source-agreements
    if errorlevel 1 (
        echo Install failed. Get CMake from https://cmake.org/download/
        exit /b 1
    )
    rem winget updates PATH only for new shells, so use the default install location now
    set "PATH=%PATH%;C:\Program Files\CMake\bin"
)

cmake -S . -B "%OUT%"
if errorlevel 1 exit /b 1

echo.
echo Solution: %OUT%\*.sln

for %%f in ("%OUT%\*.sln") do start "" "%%f"
