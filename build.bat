@echo off
setlocal enabledelayedexpansion
for /d %%i in (%*) do (
    if not exist "%%~fi" (
        @echo "Error: input %%i did not correspond to a valid folder."
        exit \b 1
    ) else (
        for %%s in ("%%~fi\Solution.*") do (
            @REM echo "%%s"
            @REM echo "%%~fi\Test Cases%%~xs"
            if /i "%%~xs"==".c" (
                gcc "%%s" "%%~fi\Test Cases%%~xs" -o "main.exe" -O2 -fsanitize=address
                if !ERRORLEVEL! NEQ 0 (
                    @echo "C build failed (error code !ERRORLEVEL!)"
                    exit \b !ERRORLEVEL!
                ) else (
                    @echo "C build succeeded."
                    exit \b 0
                )
            ) else if /i "%%~xs"==".cpp" (
                g++ "%%s" "%%~fi\Test Cases%%~xs" -o "main.exe" -O2
                if !ERRORLEVEL! NEQ 0 (
                    @echo "C++ build failed (error code !ERRORLEVEL!)"
                    exit \b !ERRORLEVEL!
                ) else (
                    @echo "C++ build succeeded."
                    exit \b 0
                )
            ) else (
                @echo "Uncompilable extension '%%~xs'."
                exit \b 2
            )
        )
    )
)
endlocal