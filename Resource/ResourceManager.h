#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <Base/Base.h>
#include <Base/Log.h>

template <typename T, typename F>
class ResourceManager {
public:
    static void Setup();
    static void Teardown();

    static T* Get(const std::string &name);
    static T* Load(const std::string &name);
    static T* GetOrLoad(const std::string &name);
    static void Unload(T* t);
	static void Unload(const std::string &name);
	static void Reload(T* t);
	static void Reload(const std::string &name);

	static void ReloadAll();

    static bool Register(const std::string &name, T* t);
    static T* Unregister(const std::string &name);

protected:
	static void DoLoad(const std::string &name, T* t);
	static std::string LoadPath();

protected:
	static const std::string LoadDirectory;

    typedef std::map<std::string, T*> ContentMap;
    static ContentMap Resources;
};

template <typename T, typename F>
const std::string ResourceManager<T,F>::LoadDirectory = "Data";

template <typename T, typename F>
typename ResourceManager<T,F>::ContentMap ResourceManager<T,F>::Resources;

template <typename T, typename F>
void ResourceManager<T,F>::Setup() {}

template <typename T, typename F>
void ResourceManager<T,F>::Teardown() {
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        delete (itr->second);
    }
    F::Resources.clear();
}

template <typename T, typename F>
T* ResourceManager<T,F>::Get(const std::string &name) {
	typename ContentMap::iterator itr = F::Resources.begin();
	for(; itr != F::Resources.end(); itr++) {
		if(name == itr->first) {
			return itr->second;
		}
	}
	ASSERT(0);
	return 0;
}

template <typename T, typename F>
T* ResourceManager<T,F>::Load(const std::string &name) {
    T* t;
    t = new T();

	F::DoLoad(name, t);
	F::Register(name, t);

    return t;
}

template <typename T, typename F>
T* ResourceManager<T,F>::GetOrLoad(const std::string &name) {
    T* t;
    t = F::Get(name);
    if(!t) {
        t = F::Load(name);
    }
    return t;
}

template <typename T, typename F>
void ResourceManager<T,F>::Unload(T* t) {
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->second == t) { break; }
    }
    ASSERT(itr != F::Resources.end());
    F::Resources.erase(itr);
    delete t;
}

template <typename T, typename F>
void ResourceManager<T,F>::Unload(const std::string &name) {
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->first == name) {
            delete (itr->second);
            break;
        }
    }
    ASSERT(itr != F::Resources.end());
    F::Resources.erase(itr);
}

template <typename T, typename F>
void ResourceManager<T,F>::Reload(T* t) {
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->second == t) {
			itr->second->teardown();
			F::DoLoad(itr->first, itr->second);
			return;
        }
    }
	ASSERT(0);
}

template <typename T, typename F>
void ResourceManager<T,F>::Reload(const std::string &name) {
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->first == name) {
			itr->second->teardown();
			F::DoLoad(itr->first, itr->second);
			return;
        }
    }
	ASSERT(0);
}

template <typename T, typename F>
void ResourceManager<T,F>::ReloadAll() {
	typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
		itr->second->teardown();
		F::DoLoad(itr->first, itr->second);
    }
}

template <typename T, typename F>
bool ResourceManager<T,F>::Register(const std::string &name, T* t) {
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->first == name) {
            break;
        }
    }

    if(itr == F::Resources.end()) {
        F::Resources[name] = t;
        return true;
    } else {
		Warn("Resource " << name << " is already registered.");
        return false;
    }
}

template <typename T, typename F>
T* ResourceManager<T,F>::Unregister(const std::string &name) {
    T* t = 0;
    typename ContentMap::iterator itr = F::Resources.begin();
    for(; itr != F::Resources.end(); itr++) {
        if(itr->first == name) {
            t = itr->second;
            break;
        }
    }
	ASSERT(itr != F::Resources.end());
    F::Resources.erase(itr);
    return t;
}

template <typename T, typename F>
std::string ResourceManager<T,F>::LoadPath() {
	return (LoadDirectory + "/" + F::LoadDirectory + "/");
}

#endif