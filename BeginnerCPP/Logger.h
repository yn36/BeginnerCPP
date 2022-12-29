#pragma once
#ifndef _LOGGER_H
#define _LOGGER_H

#include <iostream>
#include <fstream>

class Logger
{
public:
	// ��־�ȼ�
	enum log_level { debug, info, warning, error };
	// ��־���Ŀ��
	enum log_target { file, terminal, file_and_terminal };

private:
	std::ofstream outfile;     // ����־������ļ���������
	log_target target;         // ��־���Ŀ��
	log_level level;           // ��־����
	void output(std::string, log_level);  // �����Ϊ
	std::string GetLevelColor(const log_level);  // ��ȡ�ȼ���ɫ

public:
	Logger();   // Ĭ�Ϲ��캯��
	Logger(log_target, log_level);
	void DEBUG(std::string);
	void INFO(std::string);
	void WARNING(std::string);
	void ERROR(std::string);
	void Exit();
};

#endif // _LOGGER_H
