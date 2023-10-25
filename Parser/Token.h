#pragma once
#include "Kind.h"

struct Token
{
	Kind kind = Kind::Unknown;
	string string;
};