// TestBeepSound.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;

void TinkleBels() {
    int x;
    for (x = 0; x < 2; x++)
    {
        Beep(523, 500); // Jingle 
    }
    Beep(523, 800);  // Bell   
    Sleep(200);
    for (x = 0; x < 2; x++)
    {
        Beep(523, 500); // Jingle     
    }
    Beep(523, 800);  // Bell   
    Sleep(200);
    Beep(523, 500); // Jin
    Sleep(50);
    Beep(659, 400); // gle 
    Sleep(50);
    Beep(440, 400); //  all
    Sleep(50);
    Beep(494, 400); //  the 
    Sleep(50);
    Beep(523, 750);  // way
    Sleep(400);
    Beep(600, 400); // oh
    Sleep(100);
    Beep(600, 350); // what
    Sleep(200);
    Beep(600, 300); // fun
    Sleep(150);
    Beep(600, 250); // it
    Sleep(150);
    Beep(600, 150); // is
    Sleep(150);
    Beep(550, 250); // to
    Sleep(150);
    Beep(555, 350); // ride
    Sleep(50);
    Beep(555, 200); // in
    Sleep(150);
    Beep(555, 200); // a
    Sleep(150);
    Beep(690, 200); // one
    Sleep(150);
    Beep(690, 200); // horse
    Sleep(150);
    Beep(610, 200); // o
    Sleep(150);
    Beep(535, 160); // pen
    Sleep(100);
    Beep(500, 150); // sleigh
    Beep(500, 50); // sleigh
    Sleep(200);
    Beep(700, 200); // yeah
}
void MarioSound() {
    Beep(330, 100); Sleep(100);
    Beep(330, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(330, 100); Sleep(300);
    Beep(392, 100); Sleep(700);
    Beep(196, 100); Sleep(700);
    Beep(262, 300); Sleep(300);
    Beep(196, 300); Sleep(300);
    Beep(164, 300); Sleep(300);
    Beep(220, 300); Sleep(100);
    Beep(246, 100); Sleep(300);
    Beep(233, 200);
    Beep(220, 100); Sleep(300);
    Beep(196, 100); Sleep(150);
    Beep(330, 100); Sleep(150);
    Beep(392, 100); Sleep(150);
    Beep(440, 100); Sleep(300);
    Beep(349, 100); Sleep(100);
    Beep(392, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(100);
    Beep(247, 100); Sleep(500);
    Beep(262, 300); Sleep(300);
    Beep(196, 300); Sleep(300);
    Beep(164, 300); Sleep(300);
    Beep(220, 300); Sleep(100);
    Beep(246, 100); Sleep(300);
    Beep(233, 200);
    Beep(220, 100); Sleep(300);
    Beep(196, 100); Sleep(150);
    Beep(330, 100); Sleep(150);
    Beep(392, 100); Sleep(150);
    Beep(440, 100); Sleep(300);
    Beep(349, 100); Sleep(100);
    Beep(392, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(100);
    Beep(247, 100); Sleep(900);
    Beep(392, 100); Sleep(100);
    Beep(370, 100); Sleep(100);
    Beep(349, 100); Sleep(100);
    Beep(311, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(207, 100); Sleep(100);
    Beep(220, 100); Sleep(100);
    Beep(262, 100); Sleep(300);
    Beep(220, 100); Sleep(100);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(500);
    Beep(392, 100); Sleep(100);
    Beep(370, 100); Sleep(100);
    Beep(349, 100); Sleep(100);
    Beep(311, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(523, 100); Sleep(300);
    Beep(523, 100); Sleep(100);
    Beep(523, 100); Sleep(1100);
    Beep(392, 100); Sleep(100);
    Beep(370, 100); Sleep(100);
    Beep(349, 100); Sleep(100);
    Beep(311, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(207, 100); Sleep(100);
    Beep(220, 100); Sleep(100);
    Beep(262, 100); Sleep(300);
    Beep(220, 100); Sleep(100);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(500);
    Beep(311, 300); Sleep(300);
    Beep(296, 300); Sleep(300);
    Beep(262, 300); Sleep(1300);
    Beep(262, 100); Sleep(100);
    Beep(262, 100); Sleep(300);
    Beep(262, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(300);
    Beep(330, 200); Sleep(50);
    Beep(262, 200); Sleep(50);
    Beep(220, 200); Sleep(50);
    Beep(196, 100); Sleep(700);
    Beep(262, 100); Sleep(100);
    Beep(262, 100); Sleep(300);
    Beep(262, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(100);
    Beep(330, 100); Sleep(700);
    Beep(440, 100); Sleep(300);
    Beep(392, 100); Sleep(500);
    Beep(262, 100); Sleep(100);
    Beep(262, 100); Sleep(300);
    Beep(262, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(294, 100); Sleep(300);
    Beep(330, 200); Sleep(50);
    Beep(262, 200); Sleep(50);
    Beep(220, 200); Sleep(50);
    Beep(196, 100); Sleep(700);
    /*Intro*/
    Beep(330, 100); Sleep(100);
    Beep(330, 100); Sleep(300);
    Beep(330, 100); Sleep(300);
    Beep(262, 100); Sleep(100);
    Beep(330, 100); Sleep(300);
    Beep(392, 100); Sleep(700);
    Beep(196, 100); Sleep(700);
    Beep(196, 100); Sleep(125);
    Beep(262, 100); Sleep(125);
    Beep(330, 100); Sleep(125);
    Beep(392, 100); Sleep(125);
    Beep(523, 100); Sleep(125);
    Beep(660, 100); Sleep(125);
    Beep(784, 100); Sleep(575);
    Beep(660, 100); Sleep(575);
    Beep(207, 100); Sleep(125);
    Beep(262, 100); Sleep(125);
    Beep(311, 100); Sleep(125);
    Beep(415, 100); Sleep(125);
    Beep(523, 100); Sleep(125);
    Beep(622, 100); Sleep(125);
    Beep(830, 100); Sleep(575);
    Beep(622, 100); Sleep(575);
    Beep(233, 100); Sleep(125);
    Beep(294, 100); Sleep(125);
    Beep(349, 100); Sleep(125);
    Beep(466, 100); Sleep(125);
    Beep(587, 100); Sleep(125);
    Beep(698, 100); Sleep(125);
    Beep(932, 100); Sleep(575);
    Beep(932, 100); Sleep(125);
    Beep(932, 100); Sleep(125);
    Beep(932, 100); Sleep(125);
    Beep(1046, 675);
}
static void graviti_folz() {
    Beep(698, 250);
    Beep(587, 250);
    Beep(440, 250);
    Beep(587, 250);
    Beep(698, 250);
    Beep(587, 250);
    Beep(440, 250);
    Beep(587, 250);
    Beep(698, 250);
    Beep(523, 250);
    Beep(440, 250);
    Beep(523, 250);
    Beep(698, 250);
    Beep(523, 250);
    Beep(440, 250);
    Beep(523, 250);
    Beep(659, 250);
    Beep(554, 250);
    Beep(440, 250);
    Beep(554, 250);
    Beep(659, 250);
    Beep(554, 250);
    Beep(440, 250);
    Beep(554, 250);
    Beep(659, 250);
    Beep(554, 250);
    Beep(440, 250);
    Beep(554, 250);
    Beep(659, 250);
    Sleep(1000);
    Beep(587, 1000);
    Beep(659, 500);
    Beep(698, 750);
    Beep(880, 1000);
    Beep(784, 750);
    Beep(880, 750);
    Beep(523, 1000);
    Beep(587, 1000);
    Beep(659, 750);
    Beep(698, 750);
    Beep(659, 1000);
    Beep(784, 1000);
    Beep(880, 1000);
    Beep(784, 1000);
    Beep(698, 1000);
    Sleep(1000);
    Beep(698, 250);
    Beep(698, 250);
    Beep(698, 250);
    Beep(880, 250);
    Beep(880, 250);
    Beep(784, 250);
    Beep(698, 500);
    Beep(880, 250);
    Beep(880, 250);
    Beep(880, 250);
    Beep(784, 250);
    Beep(880, 250);
    Beep(784, 250);
    Beep(698, 500);
    Beep(698, 250);
    Beep(698, 250);
    Beep(698, 250);
    Beep(880, 250);
    Beep(880, 250);
    Beep(784, 250);
    Beep(698, 250);
    Sleep(100);
    Beep(880, 250);
    Beep(880, 250);
    Beep(880, 250);
    Beep(1108, 300);
    Beep(1108, 300);
    Beep(1108, 300);
    Sleep(200);
    Beep(698, 250);
    Beep(698, 250);
    Beep(698, 250);
    Beep(880, 250);
    Beep(880, 250);
    Beep(784, 250);
    Beep(698, 250);
    Beep(932, 250);
    Beep(932, 250);
    Beep(932, 250);
    Beep(784, 1000);
    Beep(1046, 1000);
    Beep(880, 1000);
    Beep(1108, 1000);
    Beep(1174, 1000);

}

static void Seven_Naion_Army()
{
    Beep(330, 624);
    Beep(330, 250);
    Beep(392, 374);
    Beep(330, 374);
    Beep(294, 250);
    Beep(262, 1000);
    Beep(247, 1000);
    Beep(330, 624);
    Beep(330, 250);
    Beep(392, 374);
    Beep(330, 374);
    Beep(294, 250);
    Beep(262, 1000);
    Beep(247, 1000);
    Beep(330, 624);
    Beep(330, 250);
    Beep(392, 374);
    Beep(330, 374);
    Beep(294, 250);
    Beep(262, 1000);
    Beep(247, 1000);
    Beep(330, 624);
    Beep(330, 250);
    Beep(392, 374);
    Beep(330, 374);
    Beep(294, 250);
    Beep(262, 374);
    Beep(294, 374);
    Beep(262, 250);
    Beep(247, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(784, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(659, 374);
    Beep(659, 374);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(784, 250);
    Beep(659, 250);
    Beep(659, 250);
    Sleep(500);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(659, 374);
    Beep(659, 374);
    Beep(659, 250);
    Sleep(250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(988, 250);
    Beep(988, 250);
    Beep(880, 250);
    Beep(880, 250);
    Beep(784, 374);
    Beep(784, 374);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(622, 250);
    Beep(622, 250);
    Beep(622, 250);
    Beep(698, 250);
    Beep(659, 250);
    Sleep(500);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 250);
    Beep(587, 250);
    Beep(659, 374);
    Beep(784, 374);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(659, 250);
    Beep(622, 250);
    Beep(622, 250);
    Beep(622, 250);
    Beep(659, 250);
    Sleep(1250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(330, 750);
    Beep(330, 250);
    Beep(392, 374);
    Beep(330, 374);
    Beep(294, 250);
    Beep(392, 1000);
    Beep(370, 1000);
    Beep(330, 750);
    Beep(330, 250);
    Beep(392, 374);
    Beep(330, 374);
    Beep(330, 250);
    Beep(392, 374);
    Beep(440, 374);
    Beep(392, 250);
    Beep(370, 500);
    Beep(659, 750);
    Beep(659, 250);
    Beep(784, 374);
    Beep(659, 374);
    Beep(659, 250);
    Beep(784, 1000);
    Beep(740, 1000);
    Beep(659, 750);
    Beep(659, 250);
    Beep(784, 374);
    Beep(659, 374);
    Beep(659, 250);
    Beep(784, 374);
    Beep(880, 250);
    Beep(784, 250);
    Beep(370, 500);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(392, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(440, 250);
    Beep(330, 1000);
    cout << endl;
}
int main()
{
    Seven_Naion_Army();
    cout << endl;
    graviti_folz();
    MarioSound();
    TinkleBels();
    return 0;
}

