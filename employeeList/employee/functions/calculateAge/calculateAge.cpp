#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int calculateAge(const string &dob)
{
	istringstream iss(dob);
	tm dob_tm{};
	iss >> get_time(&dob_tm, "%d%m%Y");

	time_t now_time_t = time(nullptr);
	tm *now_tm = localtime(&now_time_t);

	int age = now_tm->tm_year + 1900 - (dob_tm.tm_year + 1900);
	if (now_tm->tm_mon < dob_tm.tm_mon ||
		(now_tm->tm_mon == dob_tm.tm_mon && now_tm->tm_mday < dob_tm.tm_mday))
	{
		age--;
	}
	return age;
}
