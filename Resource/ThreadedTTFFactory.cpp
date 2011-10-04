#include <Resource/ThreadedTTFFactory.h>

int ThreadedTTFFactory::ThreadedLoad(void *data) {
    Font *font = ((FactoryThreadParams<Font>*)data)->ptr;
	std::string name = ((FactoryThreadParams<Font>*)data)->name;
	
	Finish(font);

    return 1;
}