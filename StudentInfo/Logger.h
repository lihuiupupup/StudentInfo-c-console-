#ifndef LOGGER_H_
#define LOGGER_H_

#include <cstdio>

#define LogF(format , ...) printf(format,__VA_ARGS__)
#define Log(format) printf(format)
#endif