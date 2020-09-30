
#ifndef BDT_HEADER
#define BDT_HEADER

#include <string>

namespace bdt
{

struct Header
{
	std::string REPO_ORIGIN_PACKAGES_TMPSYS;
	std::string REPO_ORIGIN_SOURCES;

	Header();
};
struct HeaderLFS : public Header
{
	std::string LFS;
	std::string LFS_PART;
	std::string LFS_TGT;
	std::string PKM;
	HeaderLFS();
};

}

#endif