#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "storage_json.h"

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
    if (init_path_json() == FAILED_TO_INIT) {
        perror("Failed to locate and/or create storage");
        return 1;
    }

    // parse subcommands
    if (!strcmp(argv[1], "add")) {
        add_note_json(argv[2]);
    }
    else if (!strcmp(argv[1], "delete")) {
        if (!argv[2] || !isdigit(*(argv[2]))) {
            fprintf(stderr,"Usage: note delete <note index>\n");
            return 1;
        }
        delete_note_json(atoi(argv[2]));
    }
    else if (!strcmp(argv[1], "list")) {
        list_notes_json();
    }
    else if (!strcmp(argv[1], "clear")) {
        clear_notes_json();
    }
    else if (!strcmp(argv[1], "edit")) {
        if (!argv[2] || isdigit(*(argv[2]))) {
            fprintf(stderr, "Usage: note edit <note index>\n");
            return 1;
        }
        edit_note_json(atoi(argv[2]));
    }
    else {
        fprintf(stderr,"Invalid command\n");
        return 1;
    }
    return 0;
}
