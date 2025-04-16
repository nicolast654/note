#ifndef STORAGE_JSON_H
#define STORAGE_JSON_H

#include <cjson/cJSON.h>
#include <limits.h>

typedef struct {
    char *content;
} Note;

#define STORAGE_NAME "/notes.json"
#define STORAGE_DIR "/.local/share/note"

#define SUCCESS 0
#define FAILED_TO_INIT -1

int init_path_json();
void add_note_json(char *note);
void delete_note_json(int index);
cJSON *read_json_file();
void save_json_to_file(cJSON *root);
void list_notes_json();
void clear_notes_json();
void print_usage();

extern char g_storage_path[PATH_MAX];
#endif // STORAGE_JSON_H
