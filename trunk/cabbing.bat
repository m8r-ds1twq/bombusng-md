@echo off
"%VS90COMNTOOLS%..\..\SmartDevices\SDK\SDKTools\cabwiz.exe" "%CD%\vs2005\ui\bombusngmd_qvga.inf" /err "%CD%\dist\cab\error.txt" /dest "%CD%\dist\cab"
"%VS90COMNTOOLS%..\..\SmartDevices\SDK\SDKTools\cabwiz.exe" "%CD%\vs2005\ui\bombusngmd_vga.inf" /err "%CD%\dist\cab\error.txt" /dest "%CD%\dist\cab"
call version0.cmd
echo %REVN% [%REVDATE%]
echo F | xcopy "%cd%\dist\cab\bombusngmd_qvga.CAB" "%cd%\dist\cab\bombus_qvga-%REVN%[%REVDATE%].cab" /y /q
echo F | xcopy "%cd%\dist\cab\bombusngmd_qvga.CAB" "%cd%\dist\cab\bombus_qvga-%REVN%.cab" /y /q
echo F | xcopy "%cd%\dist\cab\bombusngmd_vga.CAB" "%cd%\dist\cab\bombus_vga-%REVN%[%REVDATE%].cab" /y /q
echo F | xcopy "%cd%\dist\cab\bombusngmd_vga.CAB" "%cd%\dist\cab\bombus_vga-%REVN%.cab" /y /q

del /s /q "%cd%\dist\cab\bombusngmd_qvga.CAB"
del /s /q "%cd%\dist\cab\bombusngmd_vga.CAB"
