#include "jsondocument.h"

namespace NaiSys {

JsonDocument::JsonDocument()
{

}

JsonDocument::JsonDocument(const JsonObject &object)
    : m_object{ object }
{

}

const std::string JsonDocument::toJson()
{
    std::string dat = "{\n";
    auto const arr = m_object.toMap();
    for(auto & v : arr){
        dat.append("\""+v.first+"\": ");

        switch (v.second._typeH) {
        case JsonValue::Null:{
            dat.append("\"\"");
            break;
        }
        case JsonValue::Number:{
            dat.append(std::to_string(v.second.toNumber()));
            break;
        }
        case JsonValue::String:{
            dat.append(std::string("\"")+v.second.toString()+"\"");
            break;
        }
        case JsonValue::Boolean:{
            v.second.toBoolean() ? dat.append("true")
                                 : dat.append("false");
            break;
        }
        case JsonValue::Object:{
            auto const _b = JsonObject(v.second.toObject());
            dat.append(JsonDocument(_b).toJson());
            break;
        }
        default: break;
        }
        dat.append(",\n");
    }
    for(auto &i : ",") dat.pop_back();
    dat.append("\n}\n");

    return dat;
}

const JsonObject JsonDocument::fromJson(const char *data)
{

}

} // namespace NaiSys
