#include <iostream>
#include "../../OneDrive/מסמכים/Semester's Current Courses/236360 - Theory Of Compilation/HW/Winter20/HW2/Our files/output.hpp"
#include <sstream>

using namespace std;

const string output::rules[] = {
	"Program -> Enums Funcs",// rule 1
	"Funcs -> epsilon", // rule 2
	"Funcs -> FuncDecl Funcs", // rule 3
	"FuncDecl -> RetType ID LPAREN Formals RPAREN LBRACE Statements RBRACE", // rule 4
	"Enums -> epsilon", // rule 5
	"Enums -> EnumDecl Enums", // rule 6
	"EnumDecl -> ENUM ID LBRACE EnumeratorList RBRACE SC", // rule 7
	"RetType -> Type", // rule 8
	"RetType ->  VOID", // rule 9
	"Formals -> epsilon", // rule 10
	"Formals -> FormalsList", // rule 11
	"FormalsList -> FormalDecl", // rule 12
	"FormalsList -> FormalDecl COMMA FormalsList", // rule 13
	"FormalDecl -> Type ID", // rule 14
	"FormalDecl -> EnumType ID", // rule 15
	"EnumeratorList -> Enumerator", // rule 16
	"EnumeratorList -> EnumeratorList COMMA Enumerator", // rule 17
	"Enumerator -> ID", // rule 18
	"Statements -> Statement", // rule 19
	"Statements -> Statements Statement", // rule 20
	"Statement -> LBRACE Statements RBRACE", // rule 21
	"Statement -> Type ID SC", // rule 22
	"Statement -> EnumType ID SC", // rule 23
	"Statement -> EnumDecl", // rule 24
	"Statement -> Type ID ASSIGN Exp SC", // rule 25
	"Statement -> EnumType ID ASSIGN Exp SC", // rule 26
	"Statement -> ID ASSIGN Exp SC", // rule 27
	"Statement -> Call SC", // rule 28
	"Statement -> RETURN SC", // rule 29
	"Statement -> RETURN Exp SC", // rule 30
	"Statement -> IF LPAREN Exp RPAREN Statement", // rule 31
	"Statement -> IF LPAREN Exp RPAREN Statement ELSE Statement", // rule 32
	"Statement -> WHILE LPAREN Exp RPAREN Statement", // rule 33
	"Statement -> BREAK SC", // rule 34
	"Statement -> CONTINUE SC", // rule 35
	"Call -> ID LPAREN ExpList RPAREN", // rule 36
	"Call -> ID LPAREN RPAREN", // rule 37
	"ExpList -> Exp", // rule 38
	"ExpList -> Exp COMMA ExpList", // rule 39
	"Type -> INT", // rule 40
	"Type -> BYTE", // rule 41
	"Type -> BOOL", // rule 42
	"EnumType -> ENUM ID", // rule 43
	"Exp -> LPAREN Exp RPAREN", // rule 44
	//"Exp -> Exp MULDIV Exp", // rule 45
	"Exp -> Exp BINOP Exp", // rule 45
	"Exp -> ID", // rule 46
	"Exp -> Call", // rule 47
	"Exp -> NUM", // rule 48
	"Exp -> NUM B", // rule 49
	"Exp -> STRING", // rule 50
	"Exp -> TRUE", // rule 51
	"Exp -> FALSE", // rule 52
	"Exp -> NOT Exp", // rule 53
	"Exp -> Exp AND Exp", // rule 54
	"Exp -> Exp OR Exp", // rule 55
	"Exp -> Exp RELOP Exp", // rule 56
	"Exp -> LPAREN Type RPAREN Exp", // rule 57
	"Exp -> Exp ADDSUB Exp", // rule 58
	"Exp -> Exp RELOP Exp" // rule 59
	//"BINOP -> MULDIV",
	//"BINOP -> ADDSUB",
	//"RELOP -> RELOPNONASSOC",
	//"RELOP -> RELOPASSOC"
};

void output::printProductionRule(int ruleno) {
	cout << ruleno << ": " << output::rules[ruleno-1] << endl;
}

void output::errorLex(int lineno){
    cout << "line " << lineno << ": " << "lexical error" << endl;
}

void output::errorSyn(int lineno){
    cout << "line " << lineno << ": " << "syntax error" << endl;
}

