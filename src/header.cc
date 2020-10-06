



#include "header.hh"
#include "config.h"


namespace bdt
{

	const std::string& Header::getREPO_SOURCES()const
	{
		return REPO_SOURCES;
	}
	const std::string& Header::getREPO_ORIGIN_PACKAGES_TMPSYS()const
	{
		return REPO_ORIGIN_PACKAGES_TMPSYS;
	}
	Header::Header()
	{
		db = "/var/pkmt";
	}
	const std::string& Header::getdatadir()const
	{
		return datadir;
	}



	void HeaderLFS::setVersion(octetos::core::Semver& v)
	{
		version = v;
	}
	const octetos::core::Semver& HeaderLFS::getVersion()const
	{
		return version;
	}
	const std::string HeaderLFS::getREPO_SOURCES()const
	{
		std::string str = REPO_SOURCES  + "/" + version.toString();
		return str;
	}
	const std::string HeaderLFS::getREPO_ORIGIN_PACKAGES_TMPSYS()const
	{
		std::string str = REPO_ORIGIN_PACKAGES_TMPSYS + "/" + version.toString();
		return str;
	}
	const std::string& HeaderLFS::getLFS()const
	{
		return LFS;
	}
	const std::string& HeaderLFS::getLFS_PART()const
	{
		return LFS_PART;
	}
	const std::string& HeaderLFS::getLFS_TGT()const
	{
		return LFS_TGT;
	}
	/*const std::string& HeaderLFS::getPKM()const
	{
		return PKM;
	}*/
	HeaderLFS::HeaderLFS()
	{
		version.setNumbers(8,4);
		
		db = "/var/pkmt/lfs";
		
		REPO_ORIGIN_PACKAGES_TMPSYS="/home/azael/develop/repos/pkmt/sources/lfs";		
		REPO_SOURCES = db + "/sources";
		datadir = DATADIRBDT;
		LFS="/mnt/lfs";
		LFS_PART="/dev/sda14";
		LFS_TGT="x86_64-lfs-linux-gnu";
	}
	HeaderLFS::HeaderLFS(octetos::core::Semver& v)
	{
		version = v;
		
		db = "/var/pkmt/lfs";
		
		REPO_ORIGIN_PACKAGES_TMPSYS="/home/azael/develop/repos/pkmt/packages/lfs/";		
		REPO_SOURCES = db + "/sources";
		datadir = DATADIRBDT;
		LFS="/mnt/lfs";
		LFS_PART="/dev/sda14";
		LFS_TGT="x86_64-lfs-linux-gnu";
		
	}

}
