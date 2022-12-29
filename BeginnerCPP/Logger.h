#pragma once
#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include <fstream>

class Logger
{
public:
	// 日志等级
	enum log_level { debug, info, warning, error };
	// 日志输出目标
	enum log_target { file, terminal, file_and_terminal };

private:
	std::ofstream outfile;     // 将日志输出到文件的流对象
	log_target target;         // 日志输出目标
	log_level level;           // 日志级别
	void output(std::string, log_level);  // 输出行为
	std::string GetLevelColor(const log_level);  // 获取等级颜色

public:
	Logger();   // 默认构造函数
	Logger(log_target, log_level);
	void DEBUG(std::string);
	void INFO(std::string);
	void WARNING(std::string);
	void ERROR(std::string);
	void Exit();
};

#endif // _LOGGER_H
