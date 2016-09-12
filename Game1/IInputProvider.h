#pragma once

#include "stdafx.h"
#include "EnumKeyboard.h"

class IInputProvider
{
public:
	virtual ~IInputProvider() {}
	
	virtual bool keyDown(Keys key) = 0;
};