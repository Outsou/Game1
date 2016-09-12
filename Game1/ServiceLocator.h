#pragma once

#include "stdafx.h"
#include "IInputProvider.h"
#include "IAudioProvider.h"

class ServiceLocator
{
public:

	static IInputProvider* GetInput() { return _inputProvider; }
	static IAudioProvider* GetAudio() { return _audioProvider; }
	
	static void RegisterServiceLocator(IInputProvider *provider)
	{
		_inputProvider = provider;
	}

	static void RegisterServiceLocator(IAudioProvider *provider)
	{
		_audioProvider = provider;
	}

private:
	static IInputProvider * _inputProvider;
	static IAudioProvider * _audioProvider;
};