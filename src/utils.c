#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *my_strdup(const char *str) {
    char *new = malloc(strlen(str) + 1);
    assert(new);
    strcpy(new, str);
    return new;
}

char *get_date_as_string() {
    time_t current_time = time(NULL);
    if (current_time == ((time_t)-1)) {
        fprintf(stderr, "Failed to get time.\n");
        exit(EXIT_FAILURE);
    }
    char *raw = ctime(&current_time);
    if (!raw) {
        fprintf(stderr, "ctime failed.\n");
        exit(EXIT_FAILURE);
    }
    return my_strdup(raw);
}