// cotire example project main

#include <iostream>
#include <string>
#include <cmrc/cmrc.hpp>

CMRC_DECLARE(test);

int main()
{
	auto fs = cmrc::test::get_filesystem();
	auto data = fs.open("test.txt");
	std::cout << std::string(data.begin(), data.end()) << '\n';
}
