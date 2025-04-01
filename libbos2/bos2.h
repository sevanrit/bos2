#ifndef BOS2_H
#define BOS2_H

#define BOS2_DEBUG 0
#define BOS2_INFO 1
#define BOS2_WARN 2
#define BOS2_ERROR 3
#define BOS2_CRITICAL 4

#define BOS2_DRIVER_TEXT 0
#define BOS2_DRIVER_JSON 1

#define BOS2_FORMAT_PLAIN 0
#define BOS2_FORMAT_JSON 1

int bos2_log(const char* msg, int level, int driver, int format, const char* path);

#endif
