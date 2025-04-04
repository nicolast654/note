#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "storage.h"

char g_storage_path[PATH_MAX] = "";

int main(int argc, char **argv) {
    if (init_path() == FAILED_TO_INIT) {
        printf("PATH: %s\n", g_storage_path);
        perror("Failed to locate and/or create storage");
        return 1;
    }
    if (!strcmp(argv[1], "add")) {
        add_note(argv[2]);
    }
    else if (!strcmp(argv[1], "delete")) {
        delete_note(argv[2]);
    }
    else if (!strcmp(argv[1], "list")) {
        list_notes();
    }
    return 0;
}
