#include <Base/PropertyMap.h>

PropertyMap::PropertyMap() {
}

PropertyMap::PropertyMap(const char *data) {

}

void PropertyMap::getKeys(std::list<std::string> &keys) {
    std::map<std::string,std::string>::iterator itr;
    for(itr = _mapData.begin(); itr != _mapData.end(); itr++) {
        keys.push_back(itr->first);
    }
}

template <>
void PropertyMap::getValue(const std::string &key, std::string **value) {
    (*value) = new std::string(_mapData[key]);
}