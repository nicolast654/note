#ifndef STORAGE_H
#define STORAGE_H

#include <sys/syslimits.h>
#define STORAGE_NAME "/notes.txt"
#define STORAGE_DIR "/.local/share/note"

#define SUCCESS 0
#define FAILED_TO_INIT -1
#define MAX_BUFFER_SIZE 4096

/* Functions */
int init_path();
void add_note(char *note);
void delete_note(int index);
void list_notes();
void print_usage();

extern char g_storage_path[PATH_MAX];
#endif // STORAGE_H
