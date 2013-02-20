#pragma once
#include "../Scanner/Scanner.h"
#include "ParseTree\Tree.h"
#include "../Exceptions/InvalidTokenException.h"
#include "../Exceptions/EndOfFileException.h"
#include "../Exceptions/SyntaxErrorException.h"
#include "../Exceptions/LookAheadException.h"


using namespace std;

/**
	�berpr�ft die Syntax des Programmcodes und erstellt den Strukturbaum.
*/
class Parser
{
	/** 
		Scanner Objekt, ben�tigt um die Tokens auszulesen und auszuwerten
	*/
	Scanner *scanner;

	/** 
		Strukturbaum
	*/
	Tree *tree;

	/**
		Kopie des vom Scanner erhaltenen Tokens.
	*/
	Token myToken;
	
	/**
		Weist den Scanner an, dass n�chste Token zu lesen
		@return: Pointer (Type: Token)
	*/
	Token *readNextToken();

	/**
		Es folgen die Funktionen f�r jedes Nicht-Terminalsymbol mit deren Hilfe
		der rekursive Abstieg vollzogen werden kann.
		@return: Pointer (Type: Node)
		@throws: SyntaxErrorException
	*/
	NodeProg* prog();
	NodeDecls* decls();
	NodeDecl* decl();
	NodeArray* array_();
	NodeStatements* statements();
	NodeStatement* statement();
	NodeExp* exp();
	NodeExp2* exp2();
	NodeIndex* index();
	NodeOpExp* op_exp();
	NodeOp* op();
	
	/* Neue Eigenschaften f�r Verschr�nkung */
	/** Wird f�r die semantische Code-Pr�fung eingesetzt. */
	Visitor* typeChecker;

	/** Ist f�r die letztliche Code-Erzeugung zust�ndig. */
	Visitor* codeGenerator;

public:
	/**
		Standardkonstrukor, der den Scanner initialisiert
	*/
	Parser(char *inFile, char *scannerLog, OutputBuffer *semanticLog, OutputBuffer *outFile);

	Parser(void);
	
	/**
		Erstellt einen Strukturbaum und pr�ft auf die Syntax
		@return: Pointer (Type: Tree)
	*/
	Tree* parse();

	/**
		Destruktor
	*/
	~Parser(void);

	/**
		Getter & Setter
	*/
	Tree* getTree();
};
