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
        if(v.second.isNull())
            dat.append("\"\"");

        else if(v.second.isNumber())
            dat.append(std::to_string(v.second.toNumber()));

        else if (v.second.isString())
            dat.append(std::string("\"")+v.second.toString()+"\"");

        else if (v.second.isBoolean())
            v.second.toBoolean() ? dat.append("true")
                                 : dat.append("false");
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
