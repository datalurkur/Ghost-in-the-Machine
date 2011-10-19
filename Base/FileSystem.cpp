#include <Base/Log.h>
#include <Base/FileSystem.h>

void FileSystem::GetDirectoryContents(const std::string &dir, std::list<std::string> &files) {
	std::string cleanDirName;
    
    // Clean up the directory name
    CleanFilename(dir, cleanDirName);

#if SYS_PLATFORM == PLATFORM_WIN32
	_finddata_t fileInfo;
	intptr_t handle;

	// Ensure the directory name ends in a wildcard for Win32
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

    // Cleanup
	_findclose(handle);
#else
    DIR *dirObj;
    dirent *entry;

    // Check that the directory exists
    dirObj = opendir(dir.c_str());
    if(dirObj == 0) { return; }
    
    // Iterate through the directory
    while((entry = readdir(dirObj)) != 0) {
        files.push_back(entry->d_name);
    }

    // Cleanup
    closedir(dirObj);
#endif
    
	// Remove the local and parent directory from this list
    files.remove(".");
	files.remove("..");
}

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