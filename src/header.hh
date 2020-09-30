
#ifndef BDT_HEADER
#define BDT_HEADER

#include <string>
#include <octetos/core/Version.hh>


namespace bdt
{

class Header
{
private:
	std::string REPO_ORIGIN_PACKAGES_TMPSYS;
	std::string REPO_ORIGIN_SOURCES;
	std::string datadir;

public:	
	Header();
	const std::string& getREPO_ORIGIN_SOURCES()const;
	const std::string& getREPO_ORIGIN_PACKAGES_TMPSYS()const;
	const std::string& getdatadir()const;
};
class HeaderLFS : public Header
{
private:
	std::string LFS;
	std::string LFS_PART;
	std::string LFS_TGT;
	std::string PKM;
	octetos::core::Semver ver;
public:
	HeaderLFS();
	const std::string& getLFS()const;
	const std::string& getLFS_PART()const;
	const std::string& getLFS_TGT()const;
	const std::string& getPKM()const;
};

}

#endif