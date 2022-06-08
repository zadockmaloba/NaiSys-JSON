#include "jsonobject.h"

namespace NaiSys {

JsonObject::JsonObject()
{

}

JsonObject::JsonObject(const std::vector<_json_entry> &init)
{
    for(auto const &v : init)
        this->append(v);
}

void JsonObject::append(const _json_entry &entry)
{
    m_objectMap.insert({entry.key, entry.val});
}

const std::map<std::string, JsonValue> &JsonObject::toMap()
{
    return m_objectMap;
}

} // namespace NaiSys
