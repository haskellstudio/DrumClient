/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_42753365_INCLUDED
#define BINARYDATA_H_42753365_INCLUDED

namespace BinaryData
{
    extern const char*   padImage1_png;
    const int            padImage1_pngSize = 4362;

    extern const char*   padImage2_png;
    const int            padImage2_pngSize = 5716;

    extern const char*   padImage3_png;
    const int            padImage3_pngSize = 5136;

    extern const char*   padImage4_png;
    const int            padImage4_pngSize = 5423;

    extern const char*   padImage5_png;
    const int            padImage5_pngSize = 5785;

    extern const char*   padImage6_png;
    const int            padImage6_pngSize = 6005;

    extern const char*   padImage7_png;
    const int            padImage7_pngSize = 5475;

    extern const char*   padImage8_png;
    const int            padImage8_pngSize = 6169;

    extern const char*   padImage9_png;
    const int            padImage9_pngSize = 6047;

    extern const char*   padImage10_png;
    const int            padImage10_pngSize = 6076;

    extern const char*   _29_png;
    const int            _29_pngSize = 1509;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 11;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
