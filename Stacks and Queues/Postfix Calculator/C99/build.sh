mkdir -p ./build

gcc -std=c99 -O2 -pipe -W -Wall -Wextra -Wformat=2 \
    -I./include source/*.c \
    -o ./build/main.exe
