
#include <stdio.h>
#include <string.h>
#include <string>
#include<stdlib.h>
#include <iostream>

#include "commands.hh"




namespace bdt
{





Interpret::Interpret(const Header& header)
{
	this->header = &header;
}
void Interpret::prephost_download(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-download ";
	cmd = cmd + (((HeaderLFS*)header)->getREPO_ORIGIN_SOURCES()) ;
	std::cout << "Ejecutando : "<< cmd << "\n";
	system (cmd.c_str());
}
void Interpret::prephost_sync(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-sync ";
	cmd = cmd + (((HeaderLFS*)header)->getREPO_ORIGIN_PACKAGES_TMPSYS()) + " " + (((HeaderLFS*)header)->getLFS()) + " " + (((HeaderLFS*)header)->getPKM()) ;
	//std::cout << "Ejecutando : "<< cmd << "\n";
	system (cmd.c_str());
}
void Interpret::prephost_remove(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-remove ";
	cmd = cmd + (((HeaderLFS*)header)->getLFS_PART()) + " " + (((HeaderLFS*)header)->getLFS());
	//std::cout << "Ejecutando : "<< cmd << "\n";
	system (cmd.c_str());
}
void Interpret::prephost_install(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-install ";
	cmd = cmd + (((HeaderLFS*)header)->getLFS_PART()) + " " + (((HeaderLFS*)header)->getLFS()) + " " + (((HeaderLFS*)header)->getREPO_ORIGIN_SOURCES()) + " " + ((HeaderLFS*)header)->getdatadir();
	//std::cout << "Ejecutando : "<< cmd << "\n";
	system (cmd.c_str());
}
void Interpret::writeParamschar (std::string& argout, int argc, char *argv[])
{
	for(int i = 0; i < argc; i++)
	{
		argout = argout + " " + argv[i];
	}
}
void Interpret::prephost(int argc, char* argv[])
{
	if(strcmp(argv[0],"install") == 0)
	{
		prephost_install(argc-1,argv+1);
	}
	else if(strcmp(argv[0],"remove") == 0)
	{
		prephost_remove(argc-1,argv+1);
	}
	else if(strcmp(argv[0],"sync") == 0)
	{
		prephost_sync(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En prephost, ";
		msg = msg + "'" + argv[0] + "' commando desconocida.";
		throw msg;
	}
}
void Interpret::execute(int argc, char* argv[])
{
	char* bn = basename(argv[0]);
	if(strcmp(bn,"bdt") == 0)
	{
		bdt(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En execute, ";
		msg = msg + "'" + bn + "' commando desconocida.";
		throw msg;
	}
}
void Interpret::bdt(int argc, char* argv[])
{
	if(strcmp(argv[0],"prephost") == 0)
	{
		prephost(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En pkmt, ";
		msg = msg + "'" + argv[0] + "' commando desconocida.";
		throw msg;
	}
}

	
}