



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
		REPO_ORIGIN_PACKAGES_TMPSYS="/home/azael/develop/lfs/8.4/pkm/tmpsys";
		REPO_ORIGIN_SOURCES="/home/azael/develop/lfs/8.4/pkm/sources";
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