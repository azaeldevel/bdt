
#ifndef BDT_COMMANDS
#define BDT_COMMANDS

#include <octetos/coreutils/shell.hh>
#include <octetos/core/Version.hh>
#include <pkmt/header.hh>


namespace bdt
{



class Interpret
{
protected:
	const pkmt::Header* header;
	
private:
	int bdt(int argc, char* argv[]);
	coreutils::Shell shell;
	octetos::core::Semver version;
	
public:
	Interpret(const pkmt::Header& configure);
	int execute(int argc, char* argv[]);
	int prephost(int argc, char* argv[]);
	int remove(int argc, char* argv[]);
	int install(int argc, char* argv[]);
	int build(int argc, char* argv[]);
	int config1(int argc, char* argv[]);
	int config2(int argc, char* argv[]);
	int config3(int argc, char* argv[]);
};

class LFS : public Interpret
{
	
public:
	LFS(const pkmt::Header& h);
	int sync(int argc, char* argv[]);
	int download(int argc, char* argv[]);
};


}

#endif
