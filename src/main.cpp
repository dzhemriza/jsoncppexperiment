#include <iostream>
#include <sstream>
// json cpp
#include <jsoncpp/json/json.h>
// rapid json is a header only library so it doesn't need to link
// the only requirement is to be installed on the machine
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace std;

namespace Test01
{
  void test()
  {
    cout << "\n\nTest01...\n";

    Json::Value root;

    root["key1"] = "value1";
    root["key2"] = 42;
    root["key3"] = "sdjkdskjsdkjsd";
    root["key4"] = "dsjkfsdkfs3029-sdlk";
    root["key5"] = "32489sdkj2389";
    root["key6"] = "dskj3248";

    std::cout << root << std::endl;
  }
}

namespace Test02
{
  void test()
  {
    cout << "\n\nTest02...\n";

    const string jsonSting = R"json(
    {
    "encoding" : "UTF-8",
    "plug-ins" : [
        "python",
        "c++",
        "ruby"
        ],
    "indent" : { "length" : 3, "use_space": true }
    })json";

    cout << "JSON = " << jsonSting << endl;

    istringstream iss(jsonSting);

    Json::Reader reader;
    Json::Value root;
    reader.parse(iss, root);

    cout << "ROOT = " << root << endl;
    cout << "root[\"plug-ins\"][1] = " << root["plug-ins"][1] << endl;
    cout << "Modify c++ -> C++" << endl;
    root["plug-ins"][1] = "*** C++ is the best mate! ***";
    cout << "ROOT = " << root << endl;
  }
}

namespace Test03
{
  void test()
  {
    cout << "\n\nTest03...\n";

    const string jsonSting = R"json(
    {
    "encoding" : "UTF-8",
    "plug-ins" : [
        "python",
        "c++",
        "ruby"
        ],
    "indent" : { "length" : 3, "use_space": true }
    })json";

    cout << "JSON = " << jsonSting << endl;

    using namespace rapidjson;

    Document d;
    d.Parse(jsonSting.c_str());

    {
    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    d.Accept(writer);

    cout << "ROOT = " << sb.GetString() << endl;
    }

    Value& v = d["plug-ins"][1];
    cout << "d[\"plug-ins\"][1] = " << d["plug-ins"][1].GetString() << endl;
    d["plug-ins"][1].SetString("*** C++ is the best mate! ***");

    {
    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    d.Accept(writer);

    cout << "ROOT = " << sb.GetString() << endl;
    }
  }
}

int main(int argc, char** argv)
{
  Test01::test();
  Test02::test();
  Test03::test();

  return 0;
}
