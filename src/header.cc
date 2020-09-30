



#include "header.hh"

namespace bdt
{

Header::Header()
{
	REPO_ORIGIN_PACKAGES_TMPSYS="/home/azael/develop/lfs/8.4/pkm/tmpsys";
	REPO_ORIGIN_SOURCES="/home/azael/develop/lfs/8.4/pkm/sources";
}
HeaderLFS::HeaderLFS()
{
	LFS="/mnt/lfs";
	LFS_PART="/dev/sda14";
	PKM="/home/azael/develop/lfs/8.4/pkm";
	LFS_TGT="x86_64-lfs-linux-gnu";
}

}