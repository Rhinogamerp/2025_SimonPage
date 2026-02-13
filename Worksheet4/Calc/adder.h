#pragma once

#ifdef WIN32
  #ifdef maths_STATIC
    #define MATHSLIB_API          // nothing for static
  #else
    #ifdef maths_EXPORTS
      #define MATHSLIB_API __declspec(dllexport)
    #else
      #define MATHSLIB_API __declspec(dllimport)
    #endif
  #endif
#else
  #define MATHSLIB_API            // non-Windows can ignore
#endif

int MATHSLIB_API add(int a, int b);