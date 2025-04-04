#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "storage.h"

int main(int argc, char **argv) {
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
