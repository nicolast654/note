#include "storage_json.h"

#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

char g_storage_path[PATH_MAX] = "";


int init_path_json() {
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

    FILE *fp = fopen(g_storage_path, "a");
    if (!fp) {
        perror("Couldn't open file\n");
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    return SUCCESS;
}

cJSON *read_json_file() {
    FILE *storage = fopen(g_storage_path, "r");
    if (!storage) {
        perror("Storage couldn't be opened\n");
        exit(EXIT_FAILURE);
    }

    cJSON *root = NULL;
    fseek(storage, 0, SEEK_END);
    long len = ftell(storage);
    rewind(storage);

    char *buffer = malloc((len + 1)* sizeof(char));
    if (!buffer) {
        perror("Couldn't allocate memory");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, len, storage);
    buffer[len] = '\0';
    fclose(storage);

    root = cJSON_Parse(buffer);
    free(buffer);

    return root;
}

void save_json_to_file(cJSON *root) {
    char *json_string = cJSON_Print(root);

    FILE *storage = fopen(g_storage_path, "w");
    if (!storage) {
        cJSON_Delete(root);
        free(json_string);
        perror("Couldn't save to file\n");
        exit(EXIT_FAILURE);
    }

    fprintf(storage, "%s", json_string);
    free(json_string);
}

void add_note_json(char *note) {
    cJSON *root = read_json_file();

    if (!root || !cJSON_IsArray(root)) {
        if (root) {
            cJSON_Delete(root);
        }
        root = cJSON_CreateArray();
    }

    cJSON *note_obj = cJSON_CreateObject();
    cJSON_AddStringToObject(note_obj, "content", note);
    cJSON_AddItemToArray(root, note_obj);
    save_json_to_file(root);
    cJSON_Delete(root);
}

void delete_note_json(int index) {

}

void list_notes_json() {

}

void clear_notes_json() {

}
