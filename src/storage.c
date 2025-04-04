#include "storage.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syslimits.h>

int init_path() {
    char *home = getenv("HOME");
    if (!home) {
        perror("No home directory\n");
        return FAILED_TO_INIT;
    }
    strcpy(g_storage_path, home);
    strcat(g_storage_path, STORAGE_DIR);

    struct stat st = {0};
    if (stat(g_storage_path, &st) == -1) {
        if (mkdir(g_storage_path, 0700) != SUCCESS) {
            perror("Failed to create directory\n");
            return FAILED_TO_INIT;
        }
    }
    strcat(g_storage_path, STORAGE_NAME);
    return SUCCESS;
}

void add_note(char *note) {
    FILE *storage = fopen(g_storage_path, "a");
    if (!storage) {
        perror("Notes storage couldn't be opened\n");
        return;
    }
    fprintf(storage, "%s\n", note);
}

void delete_note(char *note) {

}

void list_notes() {

}
