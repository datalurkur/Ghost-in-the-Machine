#include <Base/Log.h>
#include <Base/FileSystem.h>

unsigned int FileSystem::GetFileData(const std::string &filename, char **data) {
	FILE *file;
	unsigned int size;

#if SYS_PLATFORM == PLATFORM_WIN32
    // For some reason, fopen is considered "unsafe" on Win32
    // Did I mention I really hate Windows development?
	fopen_s(&file, filename.c_str(), "r");
#else
    file = fopen(filename.c_str(), "r");
#endif

	if(!file) { return 0; }
    
	(*data) = (char*)calloc(size, sizeof(char));
	fread(*data, sizeof(char), size, file);
    
	fclose(file);
    
	return size;
}

void FileSystem::CleanFilename(const std::string &filename, std::string &cleaned) {
	unsigned int i, j;

	cleaned = filename;

	// Replace backslashes with forwardslashes
	i = 0;
	while(i < cleaned.size()) {
		j = (unsigned int)cleaned.find('\\', i);
		if(j != -1) {
			cleaned[j] = '/';
			i = j+1;
		} else {
			break;
		}
	}
}