#include "Directory.h"

// 创建目录
int32_t CreateDirectory(const std::string directoryPath)
{
	size_t dirPathLen = directoryPath.length();
	if (dirPathLen > MAX_PATH_LEN)
	{
		return -1;
	}
	char tmpDirPath[MAX_PATH_LEN] = { 0 };
	for (size_t i = 0; i < dirPathLen; ++i)
	{
		tmpDirPath[i] = directoryPath[i];
		if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
		{
			if (!IsExistDir(tmpDirPath))
			{
				int32_t ret = MKDIR(tmpDirPath);
				if (ret != 0)
				{
					return ret;
				}
			}
		}
	}
	return 0;
}

// 验证目录是否存在
bool IsExistDir(const char* path)
{
	return ACCESS(path, 0) != -1;
}