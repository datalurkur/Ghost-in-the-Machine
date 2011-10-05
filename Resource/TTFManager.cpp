#include <Resource/TTFManager.h>

int TTFManager::ThreadedLoad(void *data) {
    ResourceThreadParams *params = (ResourceThreadParams*)data;

    Font *font = (Font*)params->ptr;
	std::string name = params->name;

    // FIXME - Write this code
	
	Finish(font);

    return 1;
}
