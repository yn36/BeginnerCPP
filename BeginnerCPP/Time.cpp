#include "Time.h"
#include <string>
#pragma warning( disable : 4996 )

// ��ȡ��ǰʱ��
std::string GetCurrentTime()
{
	time_t t = time(NULL);
	char tmp[32] = { NULL };
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&t));
	return tmp;
}