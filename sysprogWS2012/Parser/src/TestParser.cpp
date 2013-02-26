#include <iostream>
#include "Parser.h"
#include "OutBuffer_OutputFileHandler.h"
#include "OutBuffer_OutConsoleHandler.h"
using namespace std;

int main(int argc, char **argv) {


	Buffer* b = new Buffer("TestFilesParser/p1Test.txt");

	//File Ausgabe
	OutputHandlerBase* outfile = new OutputFileHandler("out.txt");
	b->RegisterMessageHandler(outfile);

	//Consolen Ausgabe
	OutputHandlerBase* outConsole = new OutConsoleHandler();
	b->RegisterMessageHandler(outConsole);

	Scanner* s = new Scanner(b);
	Parser *p = new Parser(s, b);
	p->parse();

	cout<<"Test Parser..."<<endl;

}

