@echo off
rem Файл для сборки Ангелок Edition возможно будет временной данная редакция поэтому делаю отдельный файл

call "%VS90COMNTOOLS%vsvars32.bat"
call version0.cmd

xcopy /y "vs2005\ui\Pocket PC 2003 (ARMV4)\Release\Bombus.exe" dist\asis_ae\

"%VS90COMNTOOLS%..\..\SmartDevices\SDK\SDKTools\cabwiz.exe" "%CD%\vs2005\ui\bombusngmd_vga_ae.inf" /err "%CD%\dist\cab\error.txt" /dest "%CD%\dist\cab"

echo F | xcopy "%cd%\dist\cab\bombusngmd_vga_ae.CAB" "%cd%\dist\cab\bombus_vga_ae-%REVN%.cab" /y /q
pkzipc -add -rec -path=relative "dist\cab\bombus_vga_ae-%REVN%.zip" dist\cab\bombus_vga_ae-%REVN%.cab
pkzipc -add -rec -path=relative "dist\arh\bombus_vga_ae-%REVN%.zip" dist\asis_ae\*.*


del /s /q "%cd%\dist\cab\bombusngmd_vga_ae.CAB"