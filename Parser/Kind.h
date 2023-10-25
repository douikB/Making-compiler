#pragma once

enum class Kind
{
	Unknown, EndOfToken,
	NullLiteral,
	TrueLiteral, FalseLiteral,
	NumberLiteral, StringLiteral,
	Identifier,

	Function, Return,
	Variable,
	For, Break, Continue,
	If, Elif, Else,
	Print, PrintLine,

	LogicalAnd, LogicalOr,
	Assignment,
	Add, Substract,
	Multiply, Divide, Modulo,
	Equal, NotEqual,
	LessThan, GreaterThan,
	LessOrEqual, GreaterOrEqual,

	Comma, Colon, Semicolon,
	LeftParen, RightParen,
	LeftBrace, RightBrace,
	LeftBraket, RightBraket,
};

