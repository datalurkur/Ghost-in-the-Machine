#include <Base/Log.h>
#include <Base/FileSystem.h>

void FileSystem::GetDirectoryContents(const std::string &dir, std::list<std::string> &files) {
#if SYS_PLATFORM == PLATFORM_WIN32
	_finddata_t fileInfo;
	intptr_t handle;
	std::string cleanDirName;

	// Clean up the directory name, and make sure there's a wildcard on the end
	CleanFilename(dir, cleanDirName);
	if(cleanDirName[cleanDirName.size()-1] != '/') {
		cleanDirName += '/';
	}
	cleanDirName += "*";

	// Iterate through the directory
	if((handle = _findfirst(cleanDirName.c_str(), &fileInfo)) == -1) {
		return;
	}
	while(_findnext(handle, &fileInfo) == 0) {
		files.push_back(fileInfo.name);
	}

	// Remove the parent directory from this list
	files.remove("..");

	_findclose(handle);
#else
	// FIXME - Write OSX / Linux directory listing code
	ASSERT(0);
#endif
}

unsigned int FileSystem::GetFileData(const std::string &filename, char **data) {
#if SYS_PLATFORM == PLATFORM_WIN32
	_finddata_t fileInfo;
	intptr_t handle;

	FILE *file;
	unsigned int size;

	if((handle = _findfirst(filename.c_str(), &fileInfo)) == 0) {
		size = fileInfo.size;
		_findclose(handle);
	} else {
		return 0;
	}

	fopen_s(&file, filename.c_str(), "r");
	if(!file) { return 0; }

	(*data) = (char*)calloc(size, sizeof(char));
	fread(*data, sizeof(char), size, file);

	fclose(file);

	return size;
#else
	// FIXME - Write OSX / Linux file loading code
	ASSERT(0);
#endif
}

void FileSystem::CleanFilename(const std::string &filename, std::string &cleaned) {
	unsigned int i, j;

	cleaned = filename;

	// Replace backslashes with forwardslashes
	i = 0;
	while(i < cleaned.size()) {
		j = cleaned.find('\\', i);
		if(j != -1) {
			cleaned[j] = '/';
			i = j+1;
		} else {
			break;
		}
	}
}