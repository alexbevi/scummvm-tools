#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#include "parser.h"
#include "instruction.h"
#include "cfg.h"

bool g_disasm = false;
bool g_blocks = false;
bool g_graph = false;

int main(int argc, char **argv) {
	int argno = 1;
	if (argno >= argc) {
		printf("decompiler [-disasm] [-blocks] [-graph] file.dmp\n");
		return 0;
	}
	while (true) {
		if (0 == strcmp("-disasm", argv[argno])) {
			g_disasm = true;
			argno++;
		} else if (0 == strcmp("-blocks", argv[argno])) {
			g_blocks = true;
			argno++;
		} else if (0 == strcmp("-graph", argv[argno])) {
			g_graph = true;
			argno++;
		} else
			break;
	}
	Script script(new Scumm6Parser(), argv[argno]);
	if (g_disasm)
		for (index_t i = 0; i < script.size(); i++)
			script.print(i);
	CFG *cfg = new CFG(script);
	if (g_blocks)
		cfg->printBasicBlocks();
	cfg->removeJumpsToJumps();
	cfg->removeDeadBlocks();
	if (g_graph)
		cfg->printDot();
	return 0;
}
