#include <Resource/MaterialManager.h>

int MaterialManager::ThreadedLoad(void *data) {
    ResourceThreadParams *params = (ResourceThreadParams*)data;

    Material *material = (Material*)params->ptr;
	std::string name = params->name;

    // FIXME - Write this code
	
	Finish(material);

    return 1;
}
