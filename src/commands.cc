
#include <stdio.h>
#include <string.h>
#include <string>
#include<stdlib.h>
#include <iostream>
#include <fstream>
#include <string>


#include "commands.hh"




namespace bdt
{






LFS::LFS(const pkmt::Header& h) : Interpret(h)
{
	
}
int LFS::download(int argc, char* argv[])
{
	std::string cmd;
	#ifdef DEBUG
	cmd = "bdt-prephost-download ";
	#else
	cmd = "./src/bdt-prephost-download ";
	#endif
	cmd = cmd + (((pkmt::HeaderLFS*)header)->getREPO_SOURCES());
	//std::cout << "Ejecutando : "<< cmd << "\n";
	return system (cmd.c_str());
}
int LFS::sync(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-sync ";
	cmd = cmd + (((pkmt::HeaderLFS*)header)->getREPO_ORIGIN_PACKAGES_TMPSYS()) + " " + (((pkmt::HeaderLFS*)header)->getLFS());
	//std::cout << "Ejecutando : "<< cmd << "\n";
	return system (cmd.c_str());
}
int LFS::remove(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-remove ";
	cmd = cmd + (((pkmt::HeaderLFS*)header)->getLFS_PART()) + " " + (((pkmt::HeaderLFS*)header)->getLFS());
	//std::cout << "Ejecutando : "<< cmd << "\n";
	return system (cmd.c_str());
}
int LFS::install(int argc, char* argv[])
{
	std::string cmd;
	#ifdef DEBUG
	cmd = "./src/bdt-prephost-install ";
	#else
	cmd = "bdt-prephost-install ";
	#endif
	octetos::core::Semver ver;
	if(argc > 1)
	{
		if(strcmp(argv[0],"--version") == 0)
		{
			ver.set(argv[1]);
			((pkmt::HeaderLFS*)header)->setVersion(ver);
		}
	}
	cmd = cmd + (((pkmt::HeaderLFS*)header)->getLFS_PART()) \
				+ " " + (((pkmt::HeaderLFS*)header)->getLFS()) \
				+ " " + (((pkmt::HeaderLFS*)header)->getREPO_SOURCES()) \
				+ " " + ((pkmt::HeaderLFS*)header)->getdatadir() \
				+ " " + (((pkmt::HeaderLFS*)header)->getREPO_ORIGIN_PACKAGES_TMPSYS()) \
				+ " " + (((pkmt::HeaderLFS*)header)->getRootDir()) \
				+ " " + ver.toString();
	if(argc > 1)
	{
		if(strcmp(argv[0],"--version") == 0 )
		{
			cmd = cmd + " " + argv[1];
			//std::cout << "Ejecutando : "<< cmd << "\n";
		}
	}
	//std::cout << "Ejecutando : "<< cmd << "\n";
	return system (cmd.c_str());
}
int LFS::prephost(int argc, char* argv[])
{
	if(strcmp(argv[0],"install") == 0)
	{
		return install(argc-1,argv+1);
	}
	else if(strcmp(argv[0],"remove") == 0)
	{
		return remove(argc-1,argv+1);
	}
	else if(strcmp(argv[0],"sync") == 0)
	{
		return sync(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En prephost, ";
		msg = msg + "'" + argv[0] + "' commando desconocida.";
		throw msg;
	}
}













Interpret::Interpret(const pkmt::Header& h)
{
	this->header = &h;
}
int Interpret::execute(int argc, char* argv[])
{
	char* bn = basename(argv[0]);
	if(strcmp(bn,"bdt") == 0)
	{
		return bdt(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En execute, ";
		msg = msg + "'" + bn + "' commando desconocida.";
		throw msg;
	}
}
int Interpret::bdt(int argc, char* argv[])
{
	if(strcmp(argv[0],"prephost") == 0)
	{
		LFS lfs(*header);
		return lfs.prephost(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En pkmt, ";
		msg = msg + "'" + argv[0] + "' commando desconocida.";
		throw msg;
	}
}

	
}
