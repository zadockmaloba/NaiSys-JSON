#ifndef NAISYS_JSONOBJECT_H
#define NAISYS_JSONOBJECT_H

#include <map>
#include <vector>
#include <iostream>

#include "naisysdefs.h"
#include "jsonvalue.h"

namespace NaiSys {

class JsonObject
{
    struct _json_entry{
        std::string key;
        JsonValue val;
    };

public:
    JsonObject();
    explicit JsonObject(const std::map<std::string, JsonValue> &init);

    void operator=(const std::map<std::string, JsonValue> &init);
    JsonValue operator[](const std::string &key);

    void append(const char *key, const JsonValue &val);
    const std::map <std::string, JsonValue> &toMap();

private:
    std::map <std::string, JsonValue> m_objectMap;
};

} // namespace NaiSys

#endif // NAISYS_JSONOBJECT_H
