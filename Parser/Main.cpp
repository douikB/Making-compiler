auto scan(string) -> vector<Token>;

auto main() -> void {
	string sourceCode = R""""(
			function main() {
				printLine 'Hello, World';
				printLine 1 + 2 * 3;
		}
	)"""";

	auto tokenList = scan(sourceCode);
	printTokenList(tokenList);
}