#include "Token.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

enum class CharType {
	Unknown,				// ����� �� ���� ����
	WhiteSpace,				// ����, ��, ����
	NumberLiteral,			// ���� ���ͷ�
	StringLiteral,			// ���� ���ͷ�
	IdentifierAndKeyword,	// �ĺ���, Ű����
	OperatorAndPunctuator,	// ������, ������
};

static string::iterator current;

auto scan(string sourceCode) -> vector<Token> {
	vector<Token> result;
	sourceCode += '\0';
	current = sourceCode.begin();
	while (*current != '\0')
	{
		switch (getCharType(*current))
		{
		case CharType::WhiteSpace:
			current += 1;
			break;
		case CharType::NumberLiteral:
			result.push_back(scanNumberLiteral());
			break;
		case CharType::StringLiteral:
			result.push_back(scanStringLiteral());
			break;
		case CharType::IdentifierAndKeyword:
			result.push_back(scanIdentifierAndKeyword());
			break;
		case CharType::OperatorAndPunctuator:
			result.push_back(scanOperatorAndPunctuator());
			break;
		default:
			cout << *current << " ����� �� ���� �����Դϴ�.";
			break;
		}
	}
	result.push_back({ Kind::EndOfToken });
	return result;
}

auto getCharType(char c) -> CharType {
	if (' ' == c || '\t' == c || '\r' == c || '\n' == c)
		return CharType::WhiteSpace;

	if ('0' <= c && c <= '9')
		return CharType::NumberLiteral;

	if (c == '\'')
		return CharType::StringLiteral;

	if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')
		return CharType::IdentifierAndKeyword;

	if (33 <= c && c <= 47 && c != '\'' ||
		58 <= c && c <= 64 ||
		91 <= c && c <= 96 ||
		123 <= c && c <= 126)
		return CharType::OperatorAndPunctuator;

	
	return CharType::Unknown;
}

auto isCharType(char c, CharType type) -> bool {
	switch (type) {
	default:
		return false;
	}
}
