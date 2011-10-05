#include <Resource/TTFManager.h>

int TTFManager::ThreadedLoad(void *data) {
    Font *font = ((ResourceThreadParams<Font>*)data)->ptr;
	std::string name = ((ResourceThreadParams<Font>*)data)->name;

    // FIXME - Write this code
	
	Finish(font);

    return 1;
}
