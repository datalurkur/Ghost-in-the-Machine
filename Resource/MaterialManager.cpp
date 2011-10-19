#include <Base/Base.h>
#include <Resource/MaterialManager.h>

const std::string MaterialManager::LoadDirectory = "Material";

void MaterialManager::DoLoad(const std::string &name, Material *material) {
	char *fileData,
		 *line, *type, *param,
		 *ptr1, *ptr2;
	unsigned int fileSize;

	fileSize = FileSystem::GetFileData(name, &fileData);

	//while((line = strtok_r(fileData, "\n", ptr1)) != 0) {
	// }
}
