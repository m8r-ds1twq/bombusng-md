;
; начал писать файл который бы формировал список пакуемых файлов для inf файла с помощью котороого каб строится :)
; но знаний по коммандной строке не хватает и чета он числовые значения не выводит
;
;
@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
set /A %%i==1
echo [SourceDisksFiles] > SDF.txt
FOR /F %%t IN ('dir /b /a-d') DO (
	echo "%%t"=%%i >> SDF.txt
	set /A i+=1
	)
FOR /F %%d IN ('dir /b /ad') DO (
	 FOR /F %%b IN ('dir %%d /b ') DO (
		rem echo %%d/%%b = %%d/%%b/%%b
		FOR /F %%c IN ('dir %%d\%%b /b') DO (
			IF NOT '%%d/%%b/%%c'=='%%d/%%b/%%b' echo %%d/%%b/%%c
		)
	)
)
