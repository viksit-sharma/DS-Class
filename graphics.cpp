#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Background
    setbkcolor(BLACK);
    cleardevice();

    int x = 50, y = 200;
    int step = 5;

    while (!kbhit()) {
        cleardevice();

        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(x, y, 30, 30);  // Draw filled circle

        x += step;

        if (x > getmaxx() - 30 || x < 30) {
            step = -step;  // Bounce back
        }

        delay(20);
    }

    closegraph();
    return 0;
}
