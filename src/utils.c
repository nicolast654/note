#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *get_date_as_string() {
    time_t current_time = time(NULL);
    if (current_time == ((time_t)-1)) {
        fprintf(stderr, "Failed to get time.\n");
        exit(EXIT_FAILURE);
    }

    struct tm *tm_info = localtime(&current_time);
    if (!tm_info) {
        fprintf(stderr, "localtime failed.\n");
        exit(EXIT_FAILURE);
    }

    char *buffer = malloc(17);  // "YYYY-MM-DD HH:MM"
    if (!buffer) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    strftime(buffer, 17, "%d/%m/%Y %H:%M", tm_info);
    return buffer;
}