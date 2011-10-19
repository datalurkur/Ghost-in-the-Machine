#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <Base/Base.h>

#if SYS_PLATFORM == PLATFORM_WIN32
# include <io.h>
# include <direct.h>
#else
# include <dirent.h>
#endif


class FileSystem {
public:
	static void GetDirectoryContents(const std::string &dir, std::list<std::string> &files);
	static unsigned int GetFileData(const std::string &filename, char **data);

	static void CleanFilename(const std::string &filename, std::string &cleaned);
};

#endif