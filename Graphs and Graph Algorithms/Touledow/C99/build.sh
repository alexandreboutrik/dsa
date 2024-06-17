gcc -I./include -I./src src/main.c \
    src/include/data_structure/graph.c src/include/data_structure/queue.c \
    src/include/data_structure/search.c \
    src/include/debug.c \
    -o exe $*
