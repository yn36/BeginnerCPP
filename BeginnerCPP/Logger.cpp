#include "Logger.h"
#include "Time.h"
#include "Directory.h"
#include <filesystem>

// 默认构造函数
Logger::Logger()
{
	this->target = terminal;
	this->level = debug;
	std::cout << "[Welcome]" << __FILE__ << " " << GetCurrentTime() << " : " << "================== 开始记录 ==================" << std::endl;
}

std::string Logger::GetLevelColor(const log_level level)
{
	std::string s;
	switch (level)
	{
	case debug:
		s = "\033[37m";
		break;
	case info:
		s = "\033[34m";
		break;
	case warning:
		s = "\033[33m";
		break;
	case error:
		s = "\033[31m";
		break;
	}
	return s;
}


Logger::Logger(log_target target, log_level level)
{
	this->target = target;
	this->level = level;
	std::string tmp = "";
	std::string welcome_dialog = tmp + "[Welcome] " + __FILE__ + "" + GetCurrentTime() + " : " + "================== 开始记录 ==================\n";
	std::string path = std::filesystem::current_path().string();
	path += "\\logs\\";
	path += GetCurrentTime("%Y%m%d");
	path += ".log";
	CreateDirectory(path);
	if (target != terminal)
	{
		this->outfile.open(path, std::ios::out | std::ios::app);  // 打开输出文件
		this->outfile << welcome_dialog;
	}
	if (target != file)
	{
		std::cout << GetLevelColor(level) << welcome_dialog;
	}
}

void Logger::output(std::string text, log_level act_level)
{
	std::string prefix = "";
	if (act_level == debug) prefix = "[DEBUG]   ";
	else if (act_level == info) prefix = "[INFO]   ";
	else if (act_level == warning) prefix = "[WARNING]   ";
	else if (act_level == error) prefix = "[ERROR]   ";

	prefix += __FILE__;
	prefix += " ";
	std::string output_content = prefix + GetCurrentTime() + " : " + text + "\n";
	if (this->level <= act_level && this->target != file)
	{
		std::cout << GetLevelColor(act_level) << output_content << GetLevelColor(debug);
	}
	if (this->target != terminal)
	{
		outfile << output_content;
	}
}

void Logger::DEBUG(std::string text)
{
	this->output(text, debug);
}
void Logger::INFO(std::string text)
{
	this->output(text, info);
}
void Logger::WARNING(std::string text)
{
	this->output(text, warning);
}
void Logger::ERROR(std::string text)
{
	this->output(text, error);
}

void Logger::Exit()
{
	std::string output_content = "[" + GetCurrentTime() + "] : " + "程序退出。。。。。。\n\n\n";

	if (target != file)
	{
		std::cout << output_content;
	}
	if (target != terminal)
	{
		//outfile << output_content;
	}
}