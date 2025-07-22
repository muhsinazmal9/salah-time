#include <X11/Xlib.h>
#include <unistd.h>

int main() {
    Display* d = XOpenDisplay(NULL);
    if (d == NULL) return 1;

    int s = DefaultScreen(d);
    Window w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 300, 200, 1,
                                   BlackPixel(d, s), WhitePixel(d, s));
    XStoreName(d, w, "Salah Time 🕌");
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);

    GC gc = DefaultGC(d, s);

    while (true) {
        XEvent e;
        XNextEvent(d, &e);
        if (e.type == Expose) {
            XDrawString(d, w, gc, 50, 50, "Salah Time 🕌", 12);
        } else if (e.type == KeyPress) {
            break;
        }
    }

    XCloseDisplay(d);
    return 0;
}
