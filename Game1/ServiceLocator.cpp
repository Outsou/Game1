#include "stdafx.h"
#include "ServiceLocator.h"


IInputProvider* ServiceLocator::_inputProvider = NULL;
IAudioProvider* ServiceLocator::_audioProvider = NULL;