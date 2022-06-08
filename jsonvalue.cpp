#include "jsonvalue.h"

namespace NaiSys {

JsonValue::JsonValue()
{

}

bool JsonValue::isNull() const
{return m_isNull;}

bool JsonValue::isString() const
{return m_isString;}

bool JsonValue::isNumber() const
{return m_isNumber;}

bool JsonValue::isObject() const
{return m_isObject;}

bool JsonValue::isBoolean() const
{return m_isBoolean;}

std::string JsonValue::toString() const
{
    return string_cont;
}

int JsonValue::toNumber() const
{
    return number_cont;
}

void JsonValue::toObject() const
{
    //TODO: To be implemented
}

bool JsonValue::toBoolean() const
{
    nDebug(bool_cont);
    return bool_cont;
}

} // namespace NaiSys
