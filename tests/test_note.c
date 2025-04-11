#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>

#include "../src/storage.h"

Test(note_tests, add_and_list_note) {
    init_path();
    clear_notes();

    add_note("test note");

    FILE *file = fopen(g_storage_path, "r");
    cr_assert_not_null(file, "Storage file should exist");

    char line[256];
    fgets(line, sizeof(line), file);
    fclose(file);

    cr_assert(strcmp(line, "test note\n") == 0, "Note content mismatch");
}

