
#ifndef BDT_HEADER
#define BDT_HEADER

#include <string>
#include <octetos/core/Version.hh>


namespace bdt
{

class Header
{
protected:
	std::string REPO_ORIGIN_PACKAGES_TMPSYS;
	std::string REPO_SOURCES;
	std::string datadir;
	std::string ORIGIN_PACKAGES_CROSSTOOLCHAIN;
	std::string db;
	std::string rootrepo;
	
public:	
	Header();
	const std::string& getREPO_SOURCES()const;
	const std::string& getREPO_ORIGIN_PACKAGES_TMPSYS()const;
	const std::string& getREPO_ORIGIN_PACKAGES_CROSSTOOLCHAIN()const;
	const std::string& getdatadir()const;
	const std::string getRoot_Repository() const;
};

class HeaderLFS : public Header
{
protected:
	std::string LFS;
	std::string LFS_PART;
	std::string LFS_TGT;
	octetos::core::Semver version;
	
public:
	HeaderLFS();
	HeaderLFS(octetos::core::Semver& v);
	const std::string getREPO_SOURCES() const;
	const std::string getREPO_ORIGIN_PACKAGES_TMPSYS() const;
	const std::string& getLFS() const;
	const std::string& getLFS_PART() const;
	const std::string& getLFS_TGT() const;
	const octetos::core::Semver& getVersion()const;
	void setVersion(octetos::core::Semver&);
};

}

#endif
