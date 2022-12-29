// 处理目录
#pragma once
#ifdef _WIN32
#include <iostream>
#include <direct.h>      //for mkdir rmdir
#include <io.h>          //for access
#elif __linux__
#include <unistd.h>      //for mkdir rmdir
#include <sys/stat.h>    //for access
#include <stdint.h>
#endif

#define MAX_PATH_LEN 256

#ifdef _WIN32
#define ACCESS(fileName,accessMode) _access(fileName,accessMode)
#define MKDIR(path) _mkdir(path)
#elif __linux__
#define ACCESS(fileName,accessMode) access(fileName,accessMode)
#define MKDIR(path) mkdir(path,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#endif

// 创建目录
int32_t CreateDirectory(const std::string);

// 验证目录是否存在
bool IsExistDir(const char*);