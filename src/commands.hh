
#ifndef BDT_COMMANDS
#define BDT_COMMANDS

#include "header.hh"

namespace bdt
{

class Interpret
{
private:
	const Header* header;
	//
	void bdt(int argc, char* argv[]);
	void prephost(int argc, char* argv[]);
	void prephost_install(int argc, char* argv[]);
	void prephost_remove(int argc, char* argv[]);
	void prephost_sync(int argc, char* argv[]);
	void prephost_download(int argc, char* argv[]);
	void writeParamschar (std::string& argout, int argc, char *argv[]);
	
public:
	Interpret(const Header& configure);
	void execute(int argc, char* argv[]);
};

class pkmt
{

};


}

#endif