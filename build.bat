@echo off
setlocal enabledelayedexpansion
for /d %%i in (%*) do (
    if not exist "%%~fi" (
        @echo "Error: input %%i did not correspond to a valid folder."
        exit \b 1
    )
    for /d %%l in ("%%~fi\*") do (
        @rem echo "%%~nl"
        if /i "%%~nl"=="c" (
            @rem gcc "%%l\Solution.c" "%%l\Test Cases.c" -o "solution_c.exe" -O2 -fsanitize=address
            gcc "%%l\Solution.c" "%%l\Test Cases.c" -o "solution_c.exe" -O2
            if !ERRORLEVEL! NEQ 0 (
                @echo "C build failed (error code !ERRORLEVEL!)."
            ) else (
                @echo "C build succeeded."
            )
        ) else if /i "%%~nl"=="c++" (
            @rem g++ "%%l\Solution.cpp" "%%l\Test Cases.cpp" -o "solution_cpp.exe" -O2 -fsanitize=address
            g++ "%%l\Test Cases.cpp" -o "solution_cpp.exe" -O2
            if !ERRORLEVEL! NEQ 0 (
                @echo "C++ build failed (error code !ERRORLEVEL!)."
            ) else (
                @echo "C++ build succeeded."
            )
        )
    )
)
exit \b 0
endlocal