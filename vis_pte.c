#include "math.h"
#include "raylib.h"

#define button_breite 30
#define button_hoehe 30
#define CYAN (Color){172, 255, 252, 250}

typedef struct
{
    int x;
    int y;
    const char *name;
    Color farbe;
} button;


int main (void)
{
    //bildschirmgroeße
    int horizontal = 1280;
    int vertikal = 720;
    int q = 30;
    int start = 10;
    InitWindow(horizontal, vertikal, "");
    SetTargetFPS(60);

    Vector2 maus = GetMousePosition();
    Vector2 center = {horizontal/2 +20, vertikal/2};

    Rectangle LegierungButton = {940, 560, 180, 30};
    Rectangle VergleichButton = {940, 590, 180, 30};
    Rectangle MolekularButton = {940, 620, 180, 30};

    button atome[118] = 
    {
        {start, 5, "H", BLUE},
        {start, 5+q, "Li", CYAN},
        {start, 5+2*q, "Na", CYAN},
        {start, 5+3*q, "K", CYAN},
        {start, 5+4*q, "Rb", CYAN},
        {start, 5+5*q, "Cs", CYAN},
        {start, 5+6*q, "Fr", CYAN},

        {start+q, 5+q, "Be", RED},
        {start+q, 5+2*q, "Mg", RED},
        {start+q, 5+3*q, "Ca", RED},
        {start+q, 5+4*q, "Sr", RED},
        {start+q, 5+5*q, "Ba", RED},
        {start+q, 5+6*q, "Ra", RED},

        {start+2*q, 5+3*q, "Sc", PURPLE},
        {start+2*q, 5+4*q, "Y", PURPLE},
        {start+2*q, 5+5*q, "La", SKYBLUE},
        {start+2*q, 5+6*q, "Ac", ORANGE},

        {start+3*q, 5+3*q, "Ti", PURPLE},
        {start+3*q, 5+4*q, "Zr", PURPLE},
        {start+3*q, 5+5*q, "Hf", PURPLE},
        {start+3*q, 5+6*q, "Rf", PURPLE},

        {start+4*q, 5+3*q, "V", PURPLE},
        {start+4*q, 5+4*q, "Nb", PURPLE},
        {start+4*q, 5+5*q, "Ta", PURPLE},
        {start+4*q, 5+6*q, "Db", PURPLE},

        {start+5*q, 5+3*q, "Cr", PURPLE},
        {start+5*q, 5+4*q, "Mo", PURPLE},
        {start+5*q, 5+5*q, "W", PURPLE},
        {start+5*q, 5+6*q, "Sg", PURPLE},

        {start+6*q, 5+3*q, "Fe", PURPLE},
        {start+6*q, 5+4*q, "Ru", PURPLE},
        {start+6*q, 5+5*q, "Os", PURPLE},
        {start+6*q, 5+6*q, "Hs", PURPLE},

        {start+7*q, 5+3*q, "Co", PURPLE},
        {start+7*q, 5+4*q, "Rh", PURPLE},
        {start+7*q, 5+5*q, "Ir", PURPLE},
        {start+7*q, 5+6*q, "Mt", GRAY},

        {start+8*q, 5+3*q, "Ni", PURPLE},
        {start+8*q, 5+4*q, "Pd", PURPLE},
        {start+8*q, 5+5*q, "Pt", PURPLE},
        {start+8*q, 5+6*q, "Ds", GRAY},

        {start+9*q, 5+3*q, "Cu", PURPLE},
        {start+9*q, 5+4*q, "Ag", PURPLE},
        {start+9*q, 5+5*q, "Au", PURPLE},
        {start+9*q, 5+6*q, "Rg", GRAY},

        {start+10*q, 5+3*q, "Zn", PURPLE},
        {start+10*q, 5+4*q, "Cd", PURPLE},
        {start+10*q, 5+5*q, "Hg", PURPLE},
        {start+10*q, 5+6*q, "Cn", GRAY},

        {start+11*q, 5+q, "B", YELLOW},
        {start+11*q, 5+2*q, "Al", GREEN},
        {start+11*q, 5+3*q, "Ga", GREEN},
        {start+11*q, 5+4*q, "In", GREEN},
        {start+11*q, 5+5*q, "Tl", GREEN},
        {start+11*q, 5+6*q, "Nh", GRAY},

        {start+12*q, 5+q, "C", BLUE},
        {start+12*q, 5+2*q, "Si", YELLOW},
        {start+12*q, 5+3*q, "Ge", YELLOW},
        {start+12*q, 5+4*q, "Sn", GREEN},
        {start+12*q, 5+5*q, "Pb", GREEN},
        {start+12*q, 5+6*q, "Fl", GRAY},

        {start+13*q, 5+q, "N", BLUE},
        {start+13*q, 5+2*q, "P", BLUE},
        {start+13*q, 5+3*q, "As", YELLOW},
        {start+13*q, 5+4*q, "Sb", YELLOW},
        {start+13*q, 5+5*q, "Bi", GREEN},
        {start+13*q, 5+6*q, "Mc", GRAY},

        {start+14*q, 5+q, "O", BLUE},
        {start+14*q, 5+2*q, "S", BLUE},
        {start+14*q, 5+3*q, "Se", BLUE},
        {start+14*q, 5+4*q, "Te", YELLOW},
        {start+14*q, 5+5*q, "Po", GREEN},
        {start+14*q, 5+6*q, "Lv", GRAY},

        {start+15*q, 5+q, "F", BLUE},
        {start+15*q, 5+2*q, "Cl", BLUE},
        {start+15*q, 5+3*q, "Br", BLUE},
        {start+15*q, 5+4*q, "I", BLUE},
        {start+15*q, 5+5*q, "At", GREEN},
        {start+15*q, 5+6*q, "Ts", GRAY},

        {start+16*q, 5, "He", MAROON},
        {start+16*q, 5+q, "Ne", MAROON},
        {start+16*q, 5+2*q, "Ar", MAROON},
        {start+16*q, 5+3*q, "Kr", MAROON},
        {start+16*q, 5+4*q, "Xe", MAROON},
        {start+16*q, 5+5*q, "Rn", MAROON},
        {start+16*q, 5+6*q, "Og", MAROON},

        {start+3*q, 5+8*q, "Ce", SKYBLUE},
        {start+4*q, 5+8*q, "Pr", SKYBLUE},
        {start+5*q, 5+8*q, "Nd", SKYBLUE},
        {start+6*q, 5+8*q, "Pm", SKYBLUE},
        {start+7*q, 5+8*q, "Sm", SKYBLUE},
        {start+8*q, 5+8*q, "Eu", SKYBLUE},
        {start+9*q, 5+8*q, "Gd", SKYBLUE},
        {start+10*q, 5+8*q, "Tb", SKYBLUE},
        {start+11*q, 5+8*q, "Dy", SKYBLUE},
        {start+12*q, 5+8*q, "Ho", SKYBLUE},
        {start+13*q, 5+8*q, "Er", SKYBLUE},
        {start+14*q, 5+8*q, "Tm", SKYBLUE},
        {start+15*q, 5+8*q, "Yb", SKYBLUE},
        {start+16*q, 5+8*q, "Lu", SKYBLUE},

        {start+3*q, 5+9*q, "Th", ORANGE},
        {start+4*q, 5+9*q, "Pa", ORANGE},
        {start+5*q, 5+9*q, "U", ORANGE},
        {start+6*q, 5+9*q, "Np", ORANGE},
        {start+7*q, 5+9*q, "Pu", ORANGE},
        {start+8*q, 5+9*q, "Am", ORANGE},
        {start+9*q, 5+9*q, "Cm", ORANGE},
        {start+10*q, 5+9*q, "Bk", ORANGE},
        {start+11*q, 5+9*q, "Cf", ORANGE},
        {start+12*q, 5+9*q, "Es", ORANGE},
        {start+13*q, 5+9*q, "Fm", ORANGE},
        {start+14*q, 5+9*q, "Md", ORANGE},
        {start+15*q, 5+9*q, "No", ORANGE},
        {start+16*q, 5+9*q, "Lr", ORANGE},

    };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //startseite
        DrawPolyLines(center, 8, 140, 0, BLACK);
        DrawPolyLines(center, 8, 141, 0, BLACK);

        DrawRectangleRec(LegierungButton, LIGHTGRAY);
        DrawRectangleRec(VergleichButton, LIGHTGRAY);
        DrawRectangleRec(MolekularButton, LIGHTGRAY);

        DrawRectangleLines(939, 560, 181, 91, BLACK);
        DrawLine(939, 590, 1119, 590, BLACK);
        DrawLine(939, 620, 1119, 620, BLACK);

        DrawText("Legierung erstellen", 940+q, 575, 11, BLACK);
        DrawText("Vergleichen", 940+q, 605, 11, BLACK);
        DrawText("Struktur", 940+q, 635, 11, BLACK);

        for (int i = 0; i < 118; i++)
        {
            DrawRectangle(
                atome[i].x,
                atome[i].y,
                button_breite,
                button_hoehe,
                atome[i].farbe
            );
            DrawText(
                atome[i].name,
                atome[i].x +7,
                atome[i].y +7,
                11,
                BLACK
            );
        }

        EndDrawing();
    }
    
    CloseWindow();

    return 0;

}
