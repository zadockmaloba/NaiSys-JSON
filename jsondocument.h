#ifndef NAISYS_JSONDOCUMENT_H
#define NAISYS_JSONDOCUMENT_H

#include "jsonobject.h"

namespace NaiSys {

class JsonDocument
{
public:
    JsonDocument();
    explicit JsonDocument(const JsonObject &object);
    const std::string toJson();
    static const JsonObject fromJson(const char *data);

private:
    JsonObject m_object;
    std::string m_data_string;
};

} // namespace NaiSys

#endif // NAISYS_JSONDOCUMENT_H
