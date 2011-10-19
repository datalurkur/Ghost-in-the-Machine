#include <Base/Base.h>
#include <Resource/MaterialManager.h>

const std::string MaterialManager::LoadDirectory = "Material";

void MaterialManager::DoLoad(const std::string &name, Material *material) {
	char *fileData;
	unsigned int fileSize;
	fileSize = FileSystem::GetFileData(LoadPath() + name, &fileData);
    
    if(fileSize == 0) {
        Error("Failed to load " << name);
        return;
    }
    
    free(fileData);
}
