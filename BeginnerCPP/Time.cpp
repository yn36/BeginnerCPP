#include "Time.h"
#include <string>
#pragma warning( disable : 4996 )

// ��ȡ��ǰʱ��
std::string GetCurrentTime(const char* format)
{
	time_t t = time(NULL);
	char tmp[32] = { NULL };
	strftime(tmp, sizeof(tmp), format, localtime(&t));
	return tmp;
}