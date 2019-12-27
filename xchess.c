#include <stdio.h>
#include "chess.h"

#include <X11/Xlib.h>
#include <assert.h>

Window window;
Display* display;
GC gc;
int blackColor;
int whiteColor;
void on_expose();

int main() {
	display = XOpenDisplay(0);
	assert(display);

	blackColor = BlackPixel(display, DefaultScreen(display));
	whiteColor = WhitePixel(display, DefaultScreen(display));
	printf("black color is %d, white is %d\n", blackColor, whiteColor);

	window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, 200, 100, 0, blackColor, whiteColor);

	XSelectInput(display, window, ExposureMask | StructureNotifyMask);
	XMapWindow(display, window);

	gc = XCreateGC(display, window, 0, 0);
	assert(gc);

	XSetForeground(display, gc, blackColor);
	
	while(1) {
		XEvent e;
		XNextEvent(display, &e);

		switch (e.type) {
			case Expose:
				printf("So naked\n");
				on_expose();
				break;
			case ConfigureNotify:
				printf("ConfigureNotify\n");
				XConfigureEvent conf = e.xconfigure;
				printf("%d by %d\n", conf.width, conf.height);
				break;
			default:
				printf("Something else %d\n", e.type);
				break;
		}
	}
	printf("g'bye\n");
	return 0;
}

void on_expose() {
	printf("about to draw\n");
	XSetForeground(display, gc, blackColor);
	//XSetWindowBackground(display, window, whiteColor);
	XDrawLine(display, window, gc, 10, 60, 180, 20);
	XColor red;
	red.red = 65535;
	red.green = 0;
	red.blue = 0;
	red.flags = DoRed | DoGreen | DoBlue;
	XAllocColor(display, DefaultColormap(display, 0), &red);
	XSetForeground(display, gc, red.pixel);
	XDrawString(display, window, gc, 50, 50, "Hello world", 11);
}
