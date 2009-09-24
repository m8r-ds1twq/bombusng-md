call "%VS90COMNTOOLS%vsvars32.bat"
@echo on
call version0.cmd
vcbuild.exe /build vs2005\sockets\regex\regex.vcproj Release
if ERRORLEVEL 1 goto :EOF
vcbuild.exe /build vs2005\sockets\zlib\zlib.vcproj Release
if ERRORLEVEL 1 goto :EOF
vcbuild.exe /build vs2005\ui\ui.vcproj Release
if ERRORLEVEL 1 goto :EOF
