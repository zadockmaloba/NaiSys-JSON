#include <iostream>

#include "jsonobject.h"
#include "jsondocument.h"
#include "jsonvalue.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    NaiSys::JsonObject obj;
    obj = {
        {
            "emp1" , NaiSys::_n_obj({
                {"EmpName" , (string)"Chris Jackman"},
                {"EmpAge" , 34},
                {"EmpGender" , (string)"Male"},
                {"EmpDept" , (string)"IT"},
                {"EmpDesg" , (string)"Project Manager"} })
        },
        {
            "emp2" , NaiSys::_n_obj({
                 {"EmpName" , "Mary Jane"},
                 {"EmpAge" , 27},
                 {"EmpGender" , (string)"Female"},
                 {"EmpDept" , (string)"IT"},
                 {"EmpDesg" , (string)"Team Leader"}
              })
        }
    };


    //cout << NaiSys::JsonDocument(obj).toJson();
    cout << NaiSys::JsonDocument(NaiSys::JsonObject(obj["emp2"].toObject())).toJson();

    return 0;
}
