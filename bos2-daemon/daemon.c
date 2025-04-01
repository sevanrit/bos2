#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../libbos2/bos2.h"

volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    while (running) {
        bos2_log("Daemon is running", BOS2_INFO, BOS2_DRIVER_TEXT, BOS2_FORMAT_PLAIN, "/var/log/bos2.log");
        sleep(5);
    }

    bos2_log("Daemon stopped", BOS2_INFO, BOS2_DRIVER_TEXT, BOS2_FORMAT_PLAIN, "/var/log/bos2.log");
    return 0;
}
