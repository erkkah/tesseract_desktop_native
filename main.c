#if defined(_WIN32)
HMODULE module = nullptr;

extern "C" EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	module = hinstDLL;

	return TRUE;
}
#endif
