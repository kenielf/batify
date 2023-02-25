// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
// Other files
// Macros
#define PROG_NAME "Batify"
#define PROG_VERSION "v0.1.0"
#define PROG_LICENSE "MIT"


void version(bool exitAfter){
    printf(
        "%s (%s)\n",
        PROG_NAME, PROG_VERSION
    );
    if (exitAfter) {
        exit(EXIT_SUCCESS);
    }
}


void usage(bool exitAfter){
    version(false);
    printf(
        " -%s\t\t%s\n -%s\t\t%s\n",
        "v", "Prints the version and exits",
        "{?,h}", "Prints this helpful usage menu and exits"
    );
    if (exitAfter) {
        exit(EXIT_SUCCESS);
    }
}


void parseArgs(int argc, char* argv[]){
    int opt; /* getopt uses int for choosing args */

    while ((opt = getopt(argc, argv, "v?h")) != 1) {
        switch (opt) {
            // Arg: version
            case 'v':
                version(true);
                break;
            // Arg: help
            case '?':
            case 'h':
                usage(true);
                break;
            // Default
            default:
                printf("ERROR: must use an argument!\n");
                usage(false);
                exit(EXIT_FAILURE);
                break;
        }
    }
}


int main(int argc, char* argv[]){
    parseArgs(argc, argv);
    // Exit
    return(0);
}
