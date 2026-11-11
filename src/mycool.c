#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, void *reserved) {
    return TRUE;
}

DWORD BSQCORE_Version(void) {
    return 0x00000200;
}

int EvaluationStatus(void *a, void *b, void *c, void *d) {
    return 127;
}

void GetCEInformation(DWORD *info) {
    OSVERSIONINFOW os;
    os.dwOSVersionInfoSize = sizeof(os);
    GetVersionExW(&os);
    info[0] = 0;
    info[1] = os.dwMajorVersion;
    info[2] = os.dwMinorVersion;
    info[3] = os.dwBuildNumber;
}

void ShowAboutBox(HWND parent, HINSTANCE instance, LPCWSTR product, LPCWSTR version) {
    MessageBoxW(parent, L"mycool: My awesome DLL app!", L"About", MB_OK | MB_ICONINFORMATION);
}

void ShowAboutBoxEx(HWND parent, HINSTANCE instance, LPCWSTR product, LPCWSTR version, LPCWSTR extra) {
    ShowAboutBox(parent, instance, product, version);
}
