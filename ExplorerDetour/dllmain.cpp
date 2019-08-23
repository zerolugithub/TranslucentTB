#include "arch.h"
#include <libloaderapi.h>
#include <windef.h>
#include <process.h>

#include "detour.hpp"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID) noexcept
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		DisableThreadLibraryCalls(hinstDLL);
		Detour::Install();
		break;
	}

	case DLL_PROCESS_DETACH:
	{
		Detour::Uninstall();
		break;
	}
	}

	return TRUE;
}
