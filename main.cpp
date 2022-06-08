#include <iostream>

#include "jsonobject.h"
#include "jsondocument.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    NaiSys::JsonObject obj;

    obj.append({"str", NaiSys::JsonValue(std::string("1234"))});
    obj.append({"num", NaiSys::JsonValue(22234)});
    obj.append({"bl", NaiSys::JsonValue(true)});

    cout << NaiSys::JsonDocument(obj).toJson();

    return 0;
}
