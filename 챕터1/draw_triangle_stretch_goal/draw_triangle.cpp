/*
    Stretch Goal : Get his doodle program to compile with clang++ 

    For this to work you will need to 
    1. define the preprocessor macro _DLL
    2. Set C++ version to 17
    3. Enable all warnings
    4. Enable extra warnings
    5. Optimize to highest level
    6. Set the name of the exe to draw_triangle.exe
    7. provide the source file path to draw_triangle.cpp
    8. Add an include path for doodle header files
    9. Add a library path to the bin Release x64 folder
    10. link in doodle
    11. link in Opengl32
    12. link in Gdi32
    13  link in User32
    14. link in msvcrt
    15. Add the following commands to the end
        -Xlinker /LTCG -Xlinker /NODEFAULTLIB:libcmt.lib
        These remove some linker warnings by passing in some visual studio specific flags

    If you do all of these steps then you will have made a doodle program with clang++!
*/

#include <cmath>
#include <doodle/doodle.hpp>
using namespace doodle;

int main(void)
{
    create_window(480, 320);
    set_fill_color(HexColor{0xE5C8B4FF});
    set_outline_color(HexColor{0x483524FF});
    set_outline_width(3.0);
    double offset = 0.0;
    while (!is_window_closed())
    {
        update_window();
        clear_background(HexColor{0xA47B56FF});
        const double angle1 = offset + TWO_PI / 3.0 + to_radians(60.0) * noise(ElapsedTime, 2.0);
        const double angle2 = offset + 2.0 * TWO_PI/3.0 + to_radians(30.0) * noise(ElapsedTime/2.0, 40.0);
        const double angle3 = offset + TWO_PI + to_radians(80.0) * noise(ElapsedTime, 200.0);
        offset += 0.25 * QUARTER_PI * DeltaTime;
        apply_scale(Height / 3.0);
        draw_triangle(cos(angle1), sin(angle1), cos(angle2), sin(angle2), cos(angle3), sin(angle3));
    }
    return 0;
}
