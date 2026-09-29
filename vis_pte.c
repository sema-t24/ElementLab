#include "math.h"
#include "raylib.h"


int main (void)
{
    InitWindow(1280, 720, "");
    SetTargetFPS(60);

    Vector2 center = {640, 360};
    Vector2 maus = GetMousePosition();

    Rectangle LegierungButton = {940, 560, 180, 30};
    Rectangle VergleichButton = {940, 590, 180, 30};
    Rectangle MolekularButton = {940, 620, 180, 30};

    int q = 30;

    Rectangle H = {400, 5, q, q};
    Rectangle Li = {400, 5+q, q, q};
    Rectangle Na = {400, 5+2*q, q, q};
    Rectangle K = {400, 5+3*q, q, q};
    Rectangle Rb = {400, 5+4*q, q, q};
    Rectangle Cs = {400, 5+5*q, q, q};
    Rectangle Fr = {400, 5+6*q, q, q};

    Rectangle Be = {400+q, 5+q, q, q};
    Rectangle Mg = {400+q, 5+2*q, q, q};
    Rectangle Ca = {400+q, 5+3*q, q, q};
    Rectangle Sr = {400+q, 5+4*q, q, q};
    Rectangle Ba = {400+q, 5+5*q, q, q};
    Rectangle Ra = {400+q, 5+6*q, q, q};

    Rectangle Sc = {400+2*q, 5+3*q, q, q};
    Rectangle Y = {400+2*q, 5+4*q, q, q};
    Rectangle La = {400+2*q, 5+5*q, q, q};
    Rectangle Ac = {400+2*q, 5+6*q, q, q};

    Rectangle Ti = {400+3*q, 5+3*q, q, q};
    Rectangle Zr = {400+3*q, 5+4*q, q, q};
    Rectangle Hf = {400+3*q, 5+5*q, q, q};
    Rectangle Rf = {400+3*q, 5+6*q, q, q};

    Rectangle V = {400+4*q, 5+3*q, q, q};
    Rectangle Nb = {400+4*q, 5+4*q, q, q};
    Rectangle Ta = {400+4*q, 5+5*q, q, q};
    Rectangle Db = {400+4*q, 5+6*q, q, q};

    Rectangle Cr = {400+5*q, 5+3*q, q, q};
    Rectangle Mo = {400+5*q, 5+4*q, q, q};
    Rectangle W = {400+5*q, 5+5*q, q, q};
    Rectangle Sg = {400+5*q, 5+6*q, q, q};

    Rectangle Mn = {400+6*q, 5+3*q, q, q};
    Rectangle Tc = {400+6*q, 5+4*q, q, q};
    Rectangle Re = {400+6*q, 5+5*q, q, q};
    Rectangle Bh = {400+6*q, 5+6*q, q, q};

    Rectangle Fe = {400+7*q, 5+3*q, q, q};
    Rectangle Ru = {400+7*q, 5+4*q, q, q};
    Rectangle Os = {400+7*q, 5+5*q, q, q};
    Rectangle Hs = {400+7*q, 5+6*q, q, q};

    Rectangle Co = {400+8*q, 5+3*q, q, q};
    Rectangle Rh = {400+8*q, 5+4*q, q, q};
    Rectangle Ir = {400+8*q, 5+5*q, q, q};
    Rectangle Mt = {400+8*q, 5+6*q, q, q};

    Rectangle Ni = {400+9*q, 5+3*q, q, q};
    Rectangle Pd = {400+9*q, 5+4*q, q, q};
    Rectangle Pt = {400+9*q, 5+5*q, q, q};
    Rectangle Ds = {400+9*q, 5+6*q, q, q};

    Rectangle Cu = {400+10*q, 5+3*q, q, q};
    Rectangle Ag = {400+10*q, 5+4*q, q, q};
    Rectangle Au = {400+10*q, 5+5*q, q, q};
    Rectangle Rg = {400+10*q, 5+6*q, q, q};

    Rectangle Zn = {400+11*q, 5+3*q, q, q};
    Rectangle Cd = {400+11*q, 5+4*q, q, q};
    Rectangle Hg = {400+11*q, 5+5*q, q, q};
    Rectangle Cn = {400+11*q, 5+6*q, q, q};

    Rectangle B = {400+12*q, 5+q, q, q};
    Rectangle Al = {400+12*q, 5+2*q, q, q};
    Rectangle Ga = {400+12*q, 5+3*q, q, q};
    Rectangle In = {400+12*q, 5+4*q, q, q};
    Rectangle Tl = {400+12*q, 5+5*q, q, q};
    Rectangle Nh = {400+12*q, 5+6*q, q, q};

    Rectangle C = {400+13*q, 5+q, q, q};
    Rectangle Si = {400+13*q, 5+2*q, q, q};
    Rectangle Ge = {400+13*q, 5+3*q, q, q};
    Rectangle Sn = {400+13*q, 5+4*q, q, q};
    Rectangle Pb = {400+13*q, 5+5*q, q, q};
    Rectangle Fl = {400+13*q, 5+6*q, q, q};

    Rectangle N = {400+14*q, 5+q, q, q};
    Rectangle P = {400+14*q, 5+2*q, q, q};
    Rectangle As = {400+14*q, 5+3*q, q, q};
    Rectangle Sb = {400+14*q, 5+4*q, q, q};
    Rectangle Bi = {400+14*q, 5+5*q, q, q};
    Rectangle Mc = {400+14*q, 5+6*q, q, q};

    Rectangle O = {400+15*q, 5+q, q, q};
    Rectangle S = {400+15*q, 5+2*q, q, q};
    Rectangle Se = {400+15*q, 5+3*q, q, q};
    Rectangle Te = {400+15*q, 5+4*q, q, q};
    Rectangle Po = {400+15*q, 5+5*q, q, q};
    Rectangle Lv = {400+15*q, 5+6*q, q, q};

    Rectangle F = {400+16*q, 5+q, q, q};
    Rectangle Cl = {400+16*q, 5+2*q, q, q};
    Rectangle Br = {400+16*q, 5+3*q, q, q};
    Rectangle I = {400+16*q, 5+4*q, q, q};
    Rectangle At = {400+16*q, 5+5*q, q, q};
    Rectangle Ts = {400+16*q, 5+6*q, q, q};

    Rectangle He = {400+17*q, 5, q, q};
    Rectangle Ne = {400+17*q, 5+q, q, q};
    Rectangle Ar = {400+17*q, 5+2*q, q, q};
    Rectangle Kr = {400+17*q, 5+3*q, q, q};
    Rectangle Xe = {400+17*q, 5+4*q, q, q};
    Rectangle Rn = {400+17*q, 5+5*q, q, q};
    Rectangle Og = {400+17*q, 5+6*q, q, q};

    while(!WindowShouldClose())
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


        //pde-mini

        DrawRectangleRec(H, BLUE);
        DrawRectangleRec(Li, SKYBLUE);
        DrawRectangleRec(Na, SKYBLUE);
        DrawRectangleRec(K, SKYBLUE);
        DrawRectangleRec(Rb, SKYBLUE);
        DrawRectangleRec(Cs, SKYBLUE);
        DrawRectangleRec(Fr, SKYBLUE);

        DrawText("H", 400+q/2, 5+q/2, 11, BLACK);
        DrawText("Li", 400+q/2, 5+q/2+q, 11, BLACK);
        DrawText("Na", 400+q/2, 5+q/2+2*q, 11, BLACK);
        DrawText("K", 400+q/2, 5+q/2+3*q, 11, BLACK);
        DrawText("Rb", 400+q/2, 5+q/2+4*q, 11, BLACK);
        DrawText("Cs", 400+q/2, 5+q/2+5*q, 11, BLACK);
        DrawText("Fr", 400+q/2, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Be, RED);
        DrawRectangleRec(Mg, RED);
        DrawRectangleRec(Ca, RED);
        DrawRectangleRec(Sr, RED);
        DrawRectangleRec(Ba, RED);
        DrawRectangleRec(Ra, RED);

        DrawText("Be", 400+q/2+q, 5+q/2+q, 11, BLACK);
        DrawText("Mg", 400+q/2+q, 5+q/2+2*q, 11, BLACK);
        DrawText("Ca", 400+q/2+q, 5+q/2+3*q, 11, BLACK);
        DrawText("Sr", 400+q/2+q, 5+q/2+4*q, 11, BLACK);
        DrawText("Ba", 400+q/2+q, 5+q/2+5*q, 11, BLACK);
        DrawText("Ra", 400+q/2+q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Sc, PURPLE);
        DrawRectangleRec(Y, PURPLE);
        DrawRectangleRec(La, DARKBLUE);
        DrawRectangleRec(Ac, ORANGE);

        DrawText("Sc", 400+q/2+2*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Y", 400+q/2+2*q, 5+q/2+4*q, 11, BLACK);
        DrawText("La", 400+q/2+2*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Ac", 400+q/2+2*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Ti, PURPLE);
        DrawRectangleRec(Zr, PURPLE);
        DrawRectangleRec(Hf, PURPLE);
        DrawRectangleRec(Rf, PURPLE);

        DrawText("Ti", 400+q/2+3*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Zr", 400+q/2+3*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Hf", 400+q/2+3*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Rf", 400+q/2+3*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(V, PURPLE);
        DrawRectangleRec(Nb, PURPLE);
        DrawRectangleRec(Ta, PURPLE);
        DrawRectangleRec(Db, PURPLE);

        DrawText("V", 400+q/2+4*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Nb", 400+q/2+4*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Ta", 400+q/2+4*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Db", 400+q/2+4*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Cr, PURPLE);
        DrawRectangleRec(Mo, PURPLE);
        DrawRectangleRec(W, PURPLE);
        DrawRectangleRec(Sg, PURPLE);

        DrawText("Cr", 400+q/2+5*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Mo", 400+q/2+5*q, 5+q/2+4*q, 11, BLACK);
        DrawText("W", 400+q/2+5*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Sg", 400+q/2+5*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Mn, PURPLE);
        DrawRectangleRec(Tc, PURPLE);
        DrawRectangleRec(Re, PURPLE);
        DrawRectangleRec(Bh, PURPLE);

        DrawText("Mn", 400+q/2+6*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Tc", 400+q/2+6*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Re", 400+q/2+6*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Bh", 400+q/2+6*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Fe, PURPLE);
        DrawRectangleRec(Ru, PURPLE);
        DrawRectangleRec(Os, PURPLE);
        DrawRectangleRec(Hs, PURPLE);

        DrawText("Fe", 400+q/2+7*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Ru", 400+q/2+7*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Os", 400+q/2+7*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Hs", 400+q/2+7*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Co, PURPLE);
        DrawRectangleRec(Rh, PURPLE);
        DrawRectangleRec(Ir, PURPLE);
        DrawRectangleRec(Mt, GRAY);

        DrawText("Co", 400+q/2+8*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Rh", 400+q/2+8*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Ir", 400+q/2+8*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Mt", 400+q/2+8*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Ni, PURPLE);
        DrawRectangleRec(Pd, PURPLE);
        DrawRectangleRec(Pt, PURPLE);
        DrawRectangleRec(Ds, GRAY);

        DrawText("Ni", 400+q/2+9*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Pd", 400+q/2+9*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Pt", 400+q/2+9*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Ds", 400+q/2+9*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Cu, PURPLE);
        DrawRectangleRec(Ag, PURPLE);
        DrawRectangleRec(Au, PURPLE);
        DrawRectangleRec(Rg, GRAY);

        DrawText("Cu", 400+q/2+10*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Ag", 400+q/2+10*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Au", 400+q/2+10*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Rg", 400+q/2+10*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(Zn, PURPLE);
        DrawRectangleRec(Cd, PURPLE);
        DrawRectangleRec(Hg, PURPLE);
        DrawRectangleRec(Cn, GRAY);

        DrawText("Zn", 400+q/2+11*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Cd", 400+q/2+11*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Hg", 400+q/2+11*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Cn", 400+q/2+11*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(B, YELLOW);
        DrawRectangleRec(Al, GREEN);
        DrawRectangleRec(Ga, GREEN);
        DrawRectangleRec(In, GREEN);
        DrawRectangleRec(Tl, GREEN);
        DrawRectangleRec(Nh, GRAY);

        DrawText("B", 400+q/2+12*q, 5+q/2+q, 11, BLACK);
        DrawText("Al", 400+q/2+12*q, 5+q/2+2*q, 11, BLACK);
        DrawText("Ga", 400+q/2+12*q, 5+q/2+3*q, 11, BLACK);
        DrawText("In", 400+q/2+12*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Tl", 400+q/2+12*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Nh", 400+q/2+12*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(C, BLUE);
        DrawRectangleRec(Si, YELLOW);
        DrawRectangleRec(Ge, YELLOW);
        DrawRectangleRec(Sn, GREEN);
        DrawRectangleRec(Pb, GREEN);
        DrawRectangleRec(Fl, GRAY);

        DrawText("C", 400+q/2+13*q, 5+q/2+q, 11, BLACK);
        DrawText("Si", 400+q/2+13*q, 5+q/2+2*q, 11, BLACK);
        DrawText("Ge", 400+q/2+13*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Sn", 400+q/2+13*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Pb", 400+q/2+13*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Fl", 400+q/2+13*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(N, BLUE);
        DrawRectangleRec(P, BLUE);
        DrawRectangleRec(As, YELLOW);
        DrawRectangleRec(Sb, YELLOW);
        DrawRectangleRec(Bi, GREEN);
        DrawRectangleRec(Mc, GRAY);

        DrawText("N", 400+q/2+14*q, 5+q/2+q, 11, BLACK);
        DrawText("P", 400+q/2+14*q, 5+q/2+2*q, 11, BLACK);
        DrawText("As", 400+q/2+14*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Sb", 400+q/2+14*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Bi", 400+q/2+14*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Mc", 400+q/2+14*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(O, BLUE);
        DrawRectangleRec(S, BLUE);
        DrawRectangleRec(Se, BLUE);
        DrawRectangleRec(Te, YELLOW);
        DrawRectangleRec(Po, GREEN);
        DrawRectangleRec(Lv, GRAY);

        DrawText("O", 400+q/2+15*q, 5+q/2+q, 11, BLACK);
        DrawText("S", 400+q/2+15*q, 5+q/2+2*q, 11, BLACK);
        DrawText("Se", 400+q/2+15*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Te", 400+q/2+15*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Po", 400+q/2+15*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Lv", 400+q/2+15*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(F, BLUE);
        DrawRectangleRec(Cl, BLUE);
        DrawRectangleRec(Br, BLUE);
        DrawRectangleRec(I, BLUE);
        DrawRectangleRec(At, GREEN);
        DrawRectangleRec(Ts, GRAY);

        DrawText("F", 400+q/2+16*q, 5+q/2+q, 11, BLACK);
        DrawText("Cl", 400+q/2+16*q, 5+q/2+2*q, 11, BLACK);
        DrawText("Br", 400+q/2+16*q, 5+q/2+3*q, 11, BLACK);
        DrawText("I", 400+q/2+16*q, 5+q/2+4*q, 11, BLACK);
        DrawText("At", 400+q/2+16*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Ts", 400+q/2+16*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleRec(He, RED);
        DrawRectangleRec(Ne, RED);
        DrawRectangleRec(Ar, RED);
        DrawRectangleRec(Kr, RED);
        DrawRectangleRec(Xe, RED);
        DrawRectangleRec(Rn, RED);
        DrawRectangleRec(Og, GRAY);

        DrawText("He", 400+q/2+17*q, 5+q/2, 11, BLACK);
        DrawText("Ne", 400+q/2+17*q, 5+q/2+q, 11, BLACK);
        DrawText("Ar", 400+q/2+17*q, 5+q/2+2*q, 11, BLACK);
        DrawText("Kr", 400+q/2+17*q, 5+q/2+3*q, 11, BLACK);
        DrawText("Xe", 400+q/2+17*q, 5+q/2+4*q, 11, BLACK);
        DrawText("Rn", 400+q/2+17*q, 5+q/2+5*q, 11, BLACK);
        DrawText("Og", 400+q/2+17*q, 5+q/2+6*q, 11, BLACK);

        DrawRectangleLines(399, 4, 542, 212, BLACK);

        // maus
        if (CheckCollisionPointRec(maus, LegierungButton))

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
