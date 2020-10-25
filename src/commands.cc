
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









int Interpret::config3(int argc, char* argv[])
{	
	std::vector<coreutils::Enviroment*> venv;
	coreutils::Enviroment* env = new coreutils::Enviroment();
	env->name = "LFS";
	env->value = header->getRootDir();
	venv.push_back(env);env = new coreutils::Enviroment();
	env->name = "REPO";
	env->value = header->getRoot_Repository();
	venv.push_back(env);
	shell.set(venv);
	
	std::string cmd;
	
	
	cmd = "/tools/bin/bash bdt-basichost-directories";
	shell.execute(cmd);
	cmd = "/tools/bin/bash bdt-basichost-populate2";
	
	
	for(auto env : venv)
	{
		delete env;
	}
	return 0;
}

int Interpret::config2(int argc, char* argv[])
{	
	std::vector<coreutils::Enviroment*> venv;
	coreutils::Enviroment* env = new coreutils::Enviroment();
	env->name = "LFS";
	env->value = header->getRootDir();
	venv.push_back(env);
	shell.set(venv);
	
	std::string cmd;
	
	
	cmd = "/tools/bin/bash bdt-basichost-chroot";
	shell.execute(cmd);
	
	
	
	delete env;
	return 0;
}

int Interpret::config1(int argc, char* argv[])
{	
	std::vector<coreutils::Enviroment*> venv;
	coreutils::Enviroment* env = new coreutils::Enviroment();
	env->name = "LFS";
	env->value = header->getRootDir();
	venv.push_back(env);
	shell.set(venv);
	
	std::string cmd;
	
	
	cmd = "/tools/bin/bash bdt-basichost-populate";
	shell.execute(cmd);
	
	
	
	delete env;
	return 0;
}
int Interpret::build(int argc, char* argv[])
{
	if(argc < 1) return 1;//minimo se deve especificar la version
		
	std::string cmd;
	
	
			
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"--version") == 0 and argv[i+1] != NULL and i+1 <= argc)
		{
			version.set(argv[i+1]);
			i++;
		}		
	}
	
	if(strcmp(argv[0],"tmpsys") == 0)
	{		
		cmd = "pkmt lfs tmpsys --version ";
		cmd += version.toString();
		return shell.execute(cmd);
	}
	else if(strcmp(argv[0],"basic") == 0)
	{		
		cmd = "pkmt lfs basic --version ";
		cmd += version.toString();
		return shell.execute(cmd);
	}
	
	return 0;
}
int Interpret::remove(int argc, char* argv[])
{
	std::string cmd = "bdt-prephost-remove ";
	cmd = cmd + (((pkmt::HeaderLFS*)header)->getLFS_PART()) + " " + (((pkmt::HeaderLFS*)header)->getLFS());
	//std::cout << "Ejecutando : "<< cmd << "\n";
	return system (cmd.c_str());
}
int Interpret::install(int argc, char* argv[])
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
			std::string cmdver = "echo ";
			cmdver += ver.toString() + " >> " +  header->getRootDir() + "/etc/version";
			shell.execute(cmdver);
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
int Interpret::prephost(int argc, char* argv[])
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
		//return sync(argc-1,argv+1);
	}
	else if(strcmp(argv[0],"build") == 0)
	{
		return build(argc-1,argv+1);
	}
	else
	{
		std::string msg = "En prephost, ";
		msg = msg + "'" + argv[0] + "' commando desconocida.";
		throw msg;
	}
	
	return 0;
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
	else if(strcmp(argv[0],"--help") == 0)
	{
		std::cout << "bdt prephost remove				Elimnano el host\n";
		std::cout << "bdt prephost install --version X	Crea un host para la version X\n";
		std::cout << "bdt prephost build tmpsys	--version X		Construlle el sistem temporal X\n";
		std::cout << "bdt prephost config1 --version X			Construlle el sistem temporal X\n";
		std::cout << "bdt prephost config2 --version X			Construlle el sistem temporal X\n";
		std::cout << "bdt prephost config3 --version X			Construlle el sistem temporal X\n";
		std::cout << "bdt prephost build basic --version X		Construlle el sistem temporal X\n";
		
		return 0;
	}
	else
	{
		std::string msg = "En pkmt, ";
		msg = msg + "'" + argv[0] + "' commando desconocida.";
		throw msg;
	}
}

	
}
