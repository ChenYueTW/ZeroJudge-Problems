@echo off
setlocal

echo Number:
echo 0 = ZeroJudge
echo 1 = NTOJ
echo 2 = TIOJ
echo 3 = UVa
set /p platform=Enter 0~3:

if "%platform%"=="0" (
    set "platformName=ZeroJudge"
    goto input_problem
)

if "%platform%"=="1" (
    set "platformName=NTOJ"
    goto input_problem
)

if "%platform%"=="2" (
    set "platformName=TIOJ"
    goto input_problem
)

if "%platform%"=="3" (
	set "platformName=UVa"
	goto input_problem
)

echo.
echo Error, enter 0, 1 or 2.
pause
exit /b

:input_problem
set /p problem=Enter problem num:

if "%problem%"=="" (
    echo problem num cannot be null.
    pause
    exit /b
)

set "base=%~dp0"
set "target=%base%%platformName%\%problem%"

mkdir "%target%" 2>nul

if not exist "%target%\main.cpp" (
    type nul > "%target%\main.cpp"
)

echo.
echo Built:
echo %target%
pause