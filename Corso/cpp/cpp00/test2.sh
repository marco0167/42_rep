#!/bin/bash

# ANSI color codes
WHITE="\033[1;37m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
RED="\033[1;31m"
RESET="\033[0m"

# Ask user for a custom make command or use 'std' by default
read -p "Enter the make command you want to run (default is "make"): " user_make_command
user_make_command="${user_make_command}"

subdirs=()

for dir in */ ; do
    if [ -d "${dir}" ]; then
        dir=${dir%/}
        subdirs+=("${dir}")
    fi
done

echo -e "VERIFY ${YELLOW}${subdirs[@]}${RESET}"
for subdir in "${subdirs[@]}"
do
    # echo -e "Processing directory ${YELLOW}$subdir${RESET}"
    cd "$subdir"
    # Check for files not ending in .cpp, .hpp, .h, or .c
     # echo -e "Checking for non-standard files..."
    # Running various make commands and checking for errors
    make fclean > /dev/null && make all > /dev/null && make fclean > /dev/null
    if [ $? -ne 0 ]; then
        echo -e "make ALL failed in ${RED}$subdir${RESET}"
        exit 1
    fi

    make "${user_make_command}" >/dev/null && make fclean >/dev/null
    if [ $? -ne 0 ]; then
        echo -e "make ${user_make_command} failed in ${RED}$subdir${RESET}"
        exit 1
    fi

    make re >/dev/null && make clean >/dev/null && make fclean >/dev/null
    if [ $? -ne 0 ]; then
        echo -e "make RE failed in ${RED}$subdir${RESET}"
        exit 1
    fi

    non_standard_files=$(find . -type f ! -name '*.cpp' ! -name '*.hpp' ! -name '*.h' ! -name '*.c' ! -name 'Makefile')
    if [ ! -z "$non_standard_files" ]; then
        echo -e "Non-standard files found in ${RED}$subdir:${RESET}"
        echo -e "${WHITE}$non_standard_files${RESET}"
    else
        echo -e "Finished processing directory ${GREEN}$subdir${RESET}"
    fi
    cd ..

done
echo -e "${GREEN}ALL directories processed.${RESET}"
