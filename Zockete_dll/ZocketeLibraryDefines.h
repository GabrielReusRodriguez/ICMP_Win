#pragma once

#define ZOCKETELIBRARY_EXPORTS 1

#ifdef ZOCKETELIBRARY_EXPORTS
#define ZOCKETELIBRARY_API __declspec(dllexport)
#else
#define ZOCKETELIBRARY_API __declspec(dllimport)
#endif
