#include <iostream>

#include "jsonobject.h"
#include "jsondocument.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    NaiSys::JsonObject obj({
        {"1234", "test"},
        {"num1", 1234}
    });

    const char *test = "1234";
    obj.append("str", (const char*)"1234");
    obj.append("num", NaiSys::JsonValue(22234));
    obj.append("bl", true);

    cout << NaiSys::JsonDocument(obj).toJson();

    return 0;
}
