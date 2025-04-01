#include "bos2_text.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int bos2_text_log(const char* msg, int level, const char* path) {
    return bos2_log(msg, level, BOS2_DRIVER_TEXT, BOS2_FORMAT_PLAIN, path);
}
