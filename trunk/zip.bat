@echo off
rem del /s /q sidt\arh\
call version0.cmd
pkzipc -add -rec -path=relative "dist\arh\bombus-%REVN% [%REVDATE%].zip" dist\asis\*.*
echo F | xcopy "dist\arh\bombus-%REVN% [%REVDATE%].zip" "dist\arh\bombus-r%REVN%.zip"