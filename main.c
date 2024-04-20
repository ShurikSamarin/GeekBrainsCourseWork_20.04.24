#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "temp_functions.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printHelp();
        return 0;
    }

    char *filename = NULL;
    int month = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printHelp();
            return 0;
        } else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                filename = argv[i + 1];
            } else {
                printf("Error: -f requires a filename argument\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-m") == 0) {
            if (i + 1 < argc) {
                month = atoi(argv[i + 1]);
            } else {
                printf("Error: -m requires a month argument\n");
                return 1;
            }
        }
    }

    if (filename == NULL) {
        printf("Error: Missing input filename\n");
        return 1;
    }

    processFile(filename, month);

    return 0;
}
