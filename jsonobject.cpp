#include "jsonobject.h"

namespace NaiSys {

JsonObject::JsonObject()
{

}

JsonObject::JsonObject(const std::vector<_json_entry> &init)
{
    for(auto const &v : init)
        this->append(v.key.c_str(), v.val);
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
