@echo off
set CurrentPath=%cd%
cd %CurrentPath%
path %ProgramFiles%\CMake\bin;%PATH%

if not exist build md build
cd build
cmake .. -G "Visual Studio 15 2017 Win64"
cd ..

pause