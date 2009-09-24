@echo off
call "%VS80COMNTOOLS%vsvars32.bat"
call version.cmd
del /s /q dist\asis\
mkdir dist\asis
xcopy /y "vs2005\ui\Pocket PC 2003 (ARMV4)\Release\Bombus.exe" dist\asis\
xcopy /s /y resources\*.* dist\asis\
xcopy /s /y gsgetfile\dll\*.* dist\asis\
xcopy /y copying.txt dist\asis\
xcopy /y copying_rus.txt dist\asis\
xcopy /y news.txt dist\asis\

