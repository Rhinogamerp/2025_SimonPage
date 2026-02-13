/** @file
 * Declarations for exported functions in the maths library.
 */

// Prevent multiple inclusion of this header (include guard)
#ifndef MATHSLIBADDERH
#define MATHSLIBADDERH

// Define MATHSLIBAPI to handle DLL import/export on Windows.
// - mathsEXPORTS: building the DLL (export symbols)
// - otherwise: using the DLL (import symbols)
// - mathsSTATIC: building/using a static library
#if defined(WIN32) || defined(_WIN32)
    #ifdef mathsSTATIC
        #define MATHSLIBAPI
    #else
        #ifdef mathsEXPORTS
            #define MATHSLIBAPI __declspec(dllexport)
        #else
            #define MATHSLIBAPI __declspec(dllimport)
        #endif
    #endif
#else
    // Non-Windows platforms don't need special import/export keywords
    #define MATHSLIBAPI
#endif

// Exported function prototype
MATHSLIBAPI int add(int a, int b);

#endif // MATHSLIBADDERH
