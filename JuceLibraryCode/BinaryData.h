/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_42753365_INCLUDED
#define BINARYDATA_H_42753365_INCLUDED

namespace BinaryData
{
    extern const char*   drumHiHat_png;
    const int            drumHiHat_pngSize = 1812;

    extern const char*   drumKick_png;
    const int            drumKick_pngSize = 2591;

    extern const char*   drumSnare_png;
    const int            drumSnare_pngSize = 10894;

    extern const char*   drumTom_png;
    const int            drumTom_pngSize = 1844;

    extern const char*   headerDrum_png;
    const int            headerDrum_pngSize = 39364;

    extern const char*   headerLogo_png;
    const int            headerLogo_pngSize = 2109;

    extern const char*   headerMixer_png;
    const int            headerMixer_pngSize = 4623;

    extern const char*   headerSettings_png;
    const int            headerSettings_pngSize = 18736;

    extern const char*   headerMetronome_png;
    const int            headerMetronome_pngSize = 5119;

    extern const char*   playMixer_png;
    const int            playMixer_pngSize = 37691;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 10;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
