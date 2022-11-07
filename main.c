#include "minic.h"

int
main(int NumberOfArguments, char **Arguments)
{
	if (NumberOfArguments != 2)
		Error("invalid number of arguments");

	struct token *Tokens = Tokenize((u8 *)Arguments[1]);
	struct ast Ast = Parse(Tokens);
	AddTypes(Ast);
	Codegen(Ast);

	return 0;
}
