#include "jsonobject.h"

namespace NaiSys {

JsonObject::JsonObject()
{

}

JsonObject::JsonObject(const std::map<std::string, JsonValue> &init)
    : m_objectMap{init}
{

}

void JsonObject::operator=(const std::map<std::string, JsonValue> &init)
{
    m_objectMap = init;
}

JsonValue JsonObject::operator[](const std::string &key)
{
    return m_objectMap[key];
}

void JsonObject::append(const char *key, const JsonValue &val)
{
    m_objectMap.insert({key, val});
}

const std::map<std::string, JsonValue> &JsonObject::toMap()
{
    return m_objectMap;
}

} // namespace NaiSys
