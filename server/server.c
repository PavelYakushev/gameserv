#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

const int min_port_n = 1024;

const int max_port_n = 65535;

const int min_player_n = 2;

const int max_player_n = INT_MAX;

bool is_valid_port_n(const int port_n) {
    return port_n >= min_port_n && port_n <= max_port_n;
}

bool is_valid_player_n(const int player_n) {
    return player_n >= min_player_n && player_n <= max_player_n;
}

int strtoi(char* str) {
    char *leftover = NULL;
    char **endptr = &leftover;

    errno = 0;
    long result = strtol(str, endptr, 10);

    if (result > (long)INT_MAX || result < (long)INT_MIN) {
        errno = ERANGE;
    }
    if (leftover && leftover[0]) {
        errno = EINVAL;
    }

    return (int)result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr,
                "A port number and the number of players must be specified as parameters 1 and 2 respectively");
        return 1;
    }

    errno = 0;
    const int port_n = strtoi(argv[1]);
    if (errno || !is_valid_port_n(port_n)) {
        fprintf(stderr, "Please enter a valid port number (%d - %d)", min_port_n, max_port_n);
        return 1;
    }

    errno = 0;
    const int player_n = strtoi(argv[2]);
    if (errno || !is_valid_player_n(player_n)) {
        fprintf(stderr, "Please enter a valid number of players (%d - %d)", min_player_n, max_player_n);
        return 1;
    }

    return 0;
}
