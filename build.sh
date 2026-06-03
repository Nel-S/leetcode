for folder in "$@"; do
    if [ ! -d "$folder" ]; then
        echo "Error: input $folder did not correspond to a valid folder."
        exit 1
    fi
    for subfolder in ./"$folder"/*/; do
        # echo "$subfolder"
        # subfolderBasename=$(basename "$subfolder" | tr '[:upper:]' '[:lower:]')
        # echo "$subfolderBasename"
        case "$(basename "$subfolder" | tr '[:upper:]' '[:lower:]')" in
            "c")
                # gcc "$subfolder\Solution.c" "$subfolder\Test Cases.c" -o "solution_c.exe" -O2 -fsanitize=address
                gcc "$subfolder\Solution.c" "$subfolder\Test Cases.c" -o "solution_c.exe" -O2
                exitcode=$?
                if [ $exitcode -ne 0 ]; then
                    echo "C build failed (error code $exitcode)."
                else
                    echo "C build succeeded."
                fi ;;
            "c++")
                # g++ "$subfolder\Test Cases.cpp" -o "solution_cpp.exe" -O2 -fsanitize=address
                g++ "$subfolder\Test Cases.cpp" -o "solution_cpp.exe" -O2
                exitcode=$?
                if [ $exitcode -ne 0 ]; then
                    echo "C++ build failed (error code $exitcode)."
                else
                    echo "C++ build succeeded."
                fi ;;
        esac
    done
done
exit 0