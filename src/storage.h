#ifndef STORAGE_H
#define STORAGE_H

#include <sys/syslimits.h>
#define STORAGE_NAME "/notes.txt"
#define STORAGE_DIR "/.local/share/note"

#define SUCCESS 0
#define FAILED_TO_INIT -1

/* Functions */
int init_path();
void add_note(char *note);
void delete_note(char *note);
void list_notes();

extern char g_storage_path[PATH_MAX];
#endif // STORAGE_H
