#pragma once

#include "stdafx.h"
#include "IInputProvider.h"

class ServiceLocator
{
public:
	static IInputProvider* GetInput() { return _inputProvider; } const

	static void RegisterServiceLocator(IInputProvider *provider)
	{
		_inputProvider = provider;
	}

private:
	static IInputProvider * _inputProvider;
};