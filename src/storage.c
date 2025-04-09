#include "storage.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>

int init_path() {
    char *home = getenv("HOME");
    if (!home) {
        perror("No home directory\n");
        return FAILED_TO_INIT;
    }
    strcpy(g_storage_path, home);
    snprintf(g_storage_path + strlen(g_storage_path), PATH_MAX,"%s", STORAGE_DIR);

    struct stat st = {0};
    if (stat(g_storage_path, &st) == -1) {
        if (mkdir(g_storage_path, 0700) != SUCCESS) {
            perror("Failed to create directory\n");
            return FAILED_TO_INIT;
        }
    }
    snprintf(g_storage_path + strlen(g_storage_path), PATH_MAX, "%s", STORAGE_NAME);
    return SUCCESS;
}

void add_note(char *note) {
    FILE *storage = fopen(g_storage_path, "a");
    if (!storage) {
        perror("Notes storage couldn't be opened\n");
        exit(EXIT_FAILURE);
    }
    fprintf(storage, "%s\n", note);
    fclose(storage);
}

void delete_note(int index) {
    FILE *storage_read = fopen(g_storage_path, "r");
    if (!storage_read) {
        perror("Notes storage couldn't be opened\n");
        exit(EXIT_FAILURE);
    }
    char buffer[MAX_BUFFER_SIZE] = "";

    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    int i = 1;
    while ((nread = getline(&line, &len, storage_read)) != -1) {
        if (i++ == index) {
            continue;
        }
        snprintf(buffer + strlen(buffer), MAX_BUFFER_SIZE, "%s", line);
    }
    fclose(storage_read);
    free(line);

    FILE *storage_write = fopen(g_storage_path, "w");
    if (!storage_write) {
        perror("Couldn't write notes!\n");
        exit(EXIT_FAILURE);
    }
    fwrite(buffer, sizeof(char), strlen(buffer), storage_write);
    fclose(storage_write);
}

void list_notes() {
    FILE *storage = fopen(g_storage_path, "r");
    if (!storage) {
        perror("Couldn't read storage file\n");
        exit(EXIT_FAILURE);
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int i = 1;
    while ((nread = getline(&line, &len, storage)) != -1) {
        printf("%d. %s", i++, line);
    }
    fclose(storage);
    free(line);
}

void clear_notes() {
    FILE *storage = fopen(g_storage_path, "w");
    if (!storage) {
        perror("Couldn't clear storage file\n");
        return;
    }
    fclose(storage);
}

void print_usage() {
    printf(
        "Usage:\n"
        "  note add \"your note here\"      Add a new note\n"
        "  note list                        List all notes\n"
        "  note delete <number>             Delete note by line number\n"
        "  note --help                      Show this help message\n"
        "\n"
        "Notes are stored in ~/.local/share/note/notes.txt\n"
    );
}

