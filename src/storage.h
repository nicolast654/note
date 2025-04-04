#ifndef STORAGE_H
#define STORAGE_H

#define STORAGE_NAME "/notes.txt"
#define STORAGE_DIR "/.local/share/note"

/* Functions */
void add_note(char *note);
void delete_note(char *note);
void list_notes();

#endif // STORAGE_H
