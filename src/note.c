#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "storage.h"

char g_storage_path[PATH_MAX] = "";

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    // parse global flags
    if (!strcmp(argv[1], "--help")) {
        print_usage();
        return 0;
    }

    // create note directory in ~/.local/share
    if (init_path() == FAILED_TO_INIT) {
        perror("Failed to locate and/or create storage");
        return 1;
    }

    // parse subcommands
    if (!strcmp(argv[1], "add")) {
        add_note(argv[2]);
    }
    else if (!strcmp(argv[1], "delete")) {
        if (!isdigit(*(argv[2]))) {
            fprintf(stderr,"Usage: note delete <line number>\n");
            return 1;
        }
        delete_note(atoi(argv[2]));
    }
    else if (!strcmp(argv[1], "list")) {
        list_notes();
    }
    else if (!strcmp(argv[1], "clear")) {
        clear_notes();
    }
    else {
        fprintf(stderr,"Invalid command\n");
        return 1;
    }
    return 0;
}
