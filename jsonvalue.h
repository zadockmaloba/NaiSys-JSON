#ifndef NAISYS_JSONVALUE_H
#define NAISYS_JSONVALUE_H

#include <type_traits>
#include <string>
#include <map>

#include "naisysdefs.h"

namespace NaiSys {


class JsonValue
{
private:
    bool m_isNull;
    bool m_isString;
    bool m_isNumber;
    bool m_isObject;
    bool m_isBoolean;

private:
    std::string string_cont;
    int number_cont;
    bool bool_cont;

public:
    JsonValue();
    template<typename T>
    explicit JsonValue(const T &_value){

        if constexpr(std::is_same_v< T , bool>)
        {
            nDebug("Boolean");
            m_isBoolean = true;
            bool_cont = _value;
        }

        else if constexpr(std::is_same_v< T , int>)
        {
            nDebug("Number");
            m_isNumber = true;
            number_cont = _value;
        }

        else if constexpr(std::is_same_v<T , std::string>)
        {
            nDebug("String");
            m_isString = true;
            string_cont = _value;
        }

        else{
            nDebug("Undefined");
        }
    }

public:
    bool isNull() const;
    bool isString() const;
    bool isNumber() const;
    bool isObject() const;
    bool isBoolean() const;

public:
    std::string toString() const;
    int toNumber() const;
    void toObject() const;
    bool toBoolean()const;
};

} // namespace NaiSys

#endif // NAISYS_JSONVALUE_H
