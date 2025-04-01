#include "bos2_json.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int bos2_json_log(const char* msg, int level, const char* path) {
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
    
    fprintf(f, "{\"timestamp\":%ld,\"level\":\"%s\",\"pid\":%d,\"message\":\"%s\"}\n", 
            now, level_str, getpid(), msg);
    
    fclose(f);
    return 0;
}
