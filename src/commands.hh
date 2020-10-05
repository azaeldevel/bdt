
#ifndef BDT_COMMANDS
#define BDT_COMMANDS

#include <octetos/coreutils/shell.hh>

#include "header.hh"


namespace bdt
{



class Interpret
{
protected:
	const Header* header;
	//
private:
	int bdt(int argc, char* argv[]);
	
public:
	Interpret(const Header& configure);
	int execute(int argc, char* argv[]);
};

class LFS : public Interpret
{
	
public:
	LFS(const Header& h);
	int prephost(int argc, char* argv[]);
	int install(int argc, char* argv[]);
	int remove(int argc, char* argv[]);
	int sync(int argc, char* argv[]);
	int download(int argc, char* argv[]);
};


}

#endif
