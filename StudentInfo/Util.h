#ifndef UTIL_H_
#define UTIL_H_
#include <string>
namespace Util
{
auto isVaildSexInput = [](std::string str) -> bool {
    if (str == "Ů" || str == "��")
    {
        return true;
    }
    return false;
};
std::string sexTrans(char ch)
{
	if (ch == '0')
	{
		return std::string("Ů");
	}
	else
	{
		return std::string("��");
	}

}
}

#endif