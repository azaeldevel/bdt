



#include "header.hh"
#include "config.h"


namespace bdt
{

	const std::string& Header::getREPO_ORIGIN_SOURCES()const
	{
		return REPO_ORIGIN_SOURCES;
	}
	const std::string& Header::getREPO_ORIGIN_PACKAGES_TMPSYS()const
	{
		return REPO_ORIGIN_PACKAGES_TMPSYS;
	}
	Header::Header()
	{
		REPO_ORIGIN_PACKAGES_TMPSYS="/home/azael/develop/bdt/src/tmpsys/8.4";
		REPO_ORIGIN_SOURCES="/home/azael/develop/bdt/src/sources/8.4";
		datadir = DATADIRBDT;
	}
	const std::string& Header::getdatadir()const
	{
		return datadir;
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
	const std::string& HeaderLFS::getPKM()const
	{
		return PKM;
	}
	HeaderLFS::HeaderLFS()
	{
		LFS="/mnt/lfs";
		LFS_PART="/dev/sda14";
		PKM="/home/azael/develop/lfs/8.4/pkm";
		LFS_TGT="x86_64-lfs-linux-gnu";
	}

}