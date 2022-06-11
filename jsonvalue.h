#ifndef NAISYS_JSONVALUE_H
#define NAISYS_JSONVALUE_H

#include <type_traits>
#include <string>
#include <map>

#include "naisysdefs.h"

namespace NaiSys {

class JsonValue;

typedef  std::map <std::string, JsonValue> _n_obj;

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
    std::map <std::string, JsonValue> object_cont;

public:

    enum type_handle{
        Null,
        String,
        Number,
        Object,
        Boolean
    };

    int _typeH;

    JsonValue();
    template<typename T>
    JsonValue(const T &_value){

        if constexpr(std::is_same_v< T , bool>)
        {
            nDebug("Boolean");
            m_isBoolean = true;
            _typeH = type_handle::Boolean;
            bool_cont = _value;
        }

        else if constexpr(std::is_same_v< T , int>)
        {
            nDebug("Number");
            m_isNumber = true;
            _typeH = type_handle::Number;
            number_cont = _value;
        }

        else if constexpr(std::is_same_v< T  , std::string>)
        {
            nDebug("String");
            m_isString = true;
            _typeH = type_handle::String;
            string_cont = _value;
        }

        else if constexpr(std::is_same_v< T  , char const *>)
        {
            nDebug("String");
            m_isString = true;
            _typeH = type_handle::String;
            string_cont = _value;
        }

        else if constexpr(std::is_same_v< T  , char **>)
        {
            nDebug("String");
            m_isString = true;
            _typeH = type_handle::String;
            string_cont = _value;
        }

        else if constexpr(std::is_same_v< T , std::map<std::string, JsonValue> >){
            nDebug("Object");
            m_isObject = true;
            _typeH = type_handle::Object;
            object_cont = _value;
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
    _n_obj toObject() const;
    bool toBoolean()const;
};

} // namespace NaiSys

#endif // NAISYS_JSONVALUE_H
