#pragma once
#ifndef _TIME_H
#define _TIME_H
#include <iostream>
#include <time.h>

// 获取当前时间
std::string GetCurrentTime(const char* format = "%Y-%m-%d %H:%M:%S");

#endif // !_TIME_H
