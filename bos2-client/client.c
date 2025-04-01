#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include "../libbos2/bos2.h"

int main(int argc, char *argv[]) {
    int opt;
    char *msg = NULL;
    int level = BOS2_INFO;
    int driver = BOS2_DRIVER_TEXT;
    char *path = "/var/log/bos2.log";

    while ((opt = getopt(argc, argv, "m:l:d:p:")) != -1) {
        switch (opt) {
            case 'm': msg = optarg; break;
            case 'l': level = atoi(optarg); break;
            case 'd': driver = atoi(optarg); break;
            case 'p': path = optarg; break;
            default: 
                fprintf(stderr, "Usage: %s -m message -l level -d driver -p path\n", argv[0]);
                return 1;
        }
    }

    if (!msg) {
        fprintf(stderr, "Message is required\n");
        return 1;
    }

    return bos2_log(msg, level, driver, BOS2_FORMAT_PLAIN, path);
}
