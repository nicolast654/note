#include "storage.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syslimits.h>

void add_note(char *note) {

    // Check that the directory to store notes.txt exists, otherwise create it.
    char *home = getenv("HOME");
    if (!home) {
        perror("No home directory\n");
    }
    char path[PATH_MAX];
    strcpy(path, home);
    strcat(path, STORAGE_DIR);

    struct stat st = {0};
    if (stat(path, &st) == -1) {
        mkdir(path, 0700);
    }
    strcat(path, STORAGE_NAME);

    // path is created, open the file and add
    FILE *storage = fopen(path, "a");
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
