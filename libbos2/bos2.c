#include "bos2.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int bos2_log(const char* msg, int level, int driver, int format, const char* path) {
    time_t now;
    time(&now);
    
    FILE* f = fopen(path, "a");
    if (!f) return -1;
    
    char* level_str;
    switch(level) {
        case BOS2_DEBUG: level_str = "DEBUG"; break;
        case BOS2_INFO: level_str = "INFO"; break;
        case BOS2_WARN: level_str = "WARN"; break;
        case BOS2_ERROR: level_str = "ERROR"; break;
        case BOS2_CRITICAL: level_str = "CRITICAL"; break;
        default: level_str = "UNKNOWN";
    }
    
    if (driver == BOS2_DRIVER_TEXT) {
        fprintf(f, "%ld %s %d %s\n", now, level_str, getpid(), msg);
    }
    
    fclose(f);
    return 0;
}
