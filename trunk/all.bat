@echo off
del /s /q dist
mkdir dist
mkdir dist/asis
mkdir disk/cab
mkdir disk/arh
echo *****************************
echo ******** Сборка файла *******
echo *****************************
call make.bat
echo *****************************
echo **** Копирование всех *******
echo **** файлов в dist\asis *****
echo *****************************
call build_all.bat
echo *****************************
echo ******** Сборка cab`а *******
echo *****************************
call cabbing.bat
echo *****************************
echo ******* Архивирование *******
echo *****************************
call zip.bat