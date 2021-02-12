#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;
/// <summary>
/// Нарисовать линию
/// </summary>
/// <param name="n">длина линии (в символах)</param>
/// <returns></returns>
void DrawLine(int n) {
	for (int i = 0; i < n; i++) {
		cout << "-";
	}
}
void PlayMarioSound() {
    //Super Mario Bros
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
}
/// <summary>
/// Практика 1 cin ciout
/// </summary>
/// <returns></returns>
///     
int main()
{   
	setlocale(LC_ALL, "Russian");
    cout << "Ведомость спортивних состязаний\n";
	DrawLine(64);
    
    PlayMarioSound();
    _getch();
}

