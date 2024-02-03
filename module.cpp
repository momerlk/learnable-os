

namespace {
    #include <iostream>
    #ifdef _WIN32 // Windows
    #include <Windows.h>

    int getVirtualKeyCode(const char* keyString) {
        if (strcmp(keyString, "a") == 0) return 0x41; // 'a'
        else if (strcmp(keyString, "b") == 0) return 0x42; // 'b'
        else if (strcmp(keyString, "c") == 0) return 0x43; // 'c'
        else if (strcmp(keyString, "d") == 0) return 0x44; // 'd'
        else if (strcmp(keyString, "e") == 0) return 0x45; // 'e'
        else if (strcmp(keyString, "f") == 0) return 0x46; // 'f'
        else if (strcmp(keyString, "g") == 0) return 0x47; // 'g'
        else if (strcmp(keyString, "h") == 0) return 0x48; // 'h'
        else if (strcmp(keyString, "i") == 0) return 0x49; // 'i'
        else if (strcmp(keyString, "j") == 0) return 0x4A; // 'j'
        else if (strcmp(keyString, "k") == 0) return 0x4B; // 'k'
        else if (strcmp(keyString, "l") == 0) return 0x4C; // 'l'
        else if (strcmp(keyString, "m") == 0) return 0x4D; // 'm'
        else if (strcmp(keyString, "n") == 0) return 0x4E; // 'n'
        else if (strcmp(keyString, "o") == 0) return 0x4F; // 'o'
        else if (strcmp(keyString, "p") == 0) return 0x50; // 'p'
        else if (strcmp(keyString, "q") == 0) return 0x51; // 'q'
        else if (strcmp(keyString, "r") == 0) return 0x52; // 'r'
        else if (strcmp(keyString, "s") == 0) return 0x53; // 's'
        else if (strcmp(keyString, "t") == 0) return 0x54; // 't'
        else if (strcmp(keyString, "u") == 0) return 0x55; // 'u'
        else if (strcmp(keyString, "v") == 0) return 0x56; // 'v'
        else if (strcmp(keyString, "w") == 0) return 0x57; // 'w'
        else if (strcmp(keyString, "x") == 0) return 0x58; // 'x'
        else if (strcmp(keyString, "y") == 0) return 0x59; // 'y'
        else if (strcmp(keyString, "z") == 0) return 0x5A; // 'z'

        // Number keys
        else if (strcmp(keyString, "0") == 0) return 0x30; // '0'
        else if (strcmp(keyString, "1") == 0) return 0x31; // '1'
        else if (strcmp(keyString, "2") == 0) return 0x32; // '2'
        else if (strcmp(keyString, "3") == 0) return 0x33; // '3'
        else if (strcmp(keyString, "4") == 0) return 0x34; // '4'
        else if (strcmp(keyString, "5") == 0) return 0x35; // '5'
        else if (strcmp(keyString, "6") == 0) return 0x36; // '6'
        else if (strcmp(keyString, "7") == 0) return 0x37; // '7'
        else if (strcmp(keyString, "8") == 0) return 0x38; // '8'
        else if (strcmp(keyString, "9") == 0) return 0x39; // '9'

        // Special keys
        else if (strcmp(keyString, "space") == 0) return 0x20; // Space
        else if (strcmp(keyString, "enter") == 0) return 0x0D; // Enter
        else if (strcmp(keyString, "esc") == 0) return 0x1B; // Escape
        else if (strcmp(keyString, "backspace") == 0) return 0x08; // Backspace
        else if (strcmp(keyString, "tab") == 0) return 0x09; // Tab
        else if (strcmp(keyString, "shift") == 0) return 0x10; // Shift
        else if (strcmp(keyString, "ctrl") == 0) return 0x11; // Ctrl
        else if (strcmp(keyString, "alt") == 0) return 0x12; // Alt
        else if (strcmp(keyString, "capslock") == 0) return 0x14; // Caps Lock
        else if (strcmp(keyString, "pageup") == 0) return 0x21; // Page Up
        else if (strcmp(keyString, "pagedown") == 0) return 0x22; // Page Down
        else if (strcmp(keyString, "end") == 0) return 0x23; // End
        else if (strcmp(keyString, "home") == 0) return 0x24; // Home
        else if (strcmp(keyString, "left") == 0) return 0x25; // Left Arrow
        else if (strcmp(keyString, "up") == 0) return 0x26; // Up Arrow
        else if (strcmp(keyString, "right") == 0) return 0x27; // Right Arrow
        else if (strcmp(keyString, "down") == 0) return 0x28; // Down Arrow
        else if (strcmp(keyString, "insert") == 0) return 0x2D; // Insert
        else if (strcmp(keyString, "delete") == 0) return 0x2E; // Delete
        else if (strcmp(keyString, "win") == 0) return 0x5B; // Left Windows
        else if (strcmp(keyString, "f1") == 0) return 0x70; // F1
        else if (strcmp(keyString, "f2") == 0) return 0x71; // F2
        else if (strcmp(keyString, "f3") == 0) return 0x72; // F3
        else if (strcmp(keyString, "f4") == 0) return 0x73; // F4
        else if (strcmp(keyString, "f5") == 0) return 0x74; // F5
        else if (strcmp(keyString, "f6") == 0) return 0x75; // F6
        else if (strcmp(keyString, "f7") == 0) return 0x76; // F7
        else if (strcmp(keyString, "f8") == 0) return 0x77; // F8
        else if (strcmp(keyString, "f9") == 0) return 0x78; // F9
        else if (strcmp(keyString, "f10") == 0) return 0x79; // F10
        else if (strcmp(keyString, "f11") == 0) return 0x7A; // F11
        else if (strcmp(keyString, "f12") == 0) return 0x7B; // F12
        else {
            printf("Unsupported key: %s\n", keyString);
            return -1;
        }
    }


    void simulateKeyPress(const char* keyString) {
        WORD keyCode = getVirtualKeyCode(keyString);
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = keyCode;
        input.ki.wScan = 0;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;
        input.ki.dwFlags = 0; // key press

        SendInput(1, &input, sizeof(INPUT));

        // Optional: simulate key release
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));
    }

    #elif __APPLE__ // macOS
    #include <ApplicationServices/ApplicationServices.h>
    #elif __linux__ // Linux
    #include <X11/Xlib.h>
    #include <X11/keysym.h>
    #include <X11/extensions/XTest.h>
    #endif

    void KeyPress(int keyCode) {
    #ifdef _WIN32
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = keyCode;
        input.ki.wScan = 0;
        input.ki.time = 0;
        input.ki.dwExtraInfo = 0;
        input.ki.dwFlags = 0; // key press

        SendInput(1, &input, sizeof(INPUT));

        // Optional: simulate key release
        input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));
    #elif __APPLE__
        CGEventRef event = CGEventCreateKeyboardEvent(NULL, keyCode, true);
        CGEventPost(kCGHIDEventTap, event);
        CFRelease(event);
    #elif __linux__
        Display *display = XOpenDisplay(NULL);
        if (display == NULL) {
            std::cerr << "Cannot open display" << std::endl;
            return;
        }

        KeySym keySym = keyCode;
        KeyCode keyCodeX11 = XKeysymToKeycode(display, keySym);
        XTestFakeKeyEvent(display, keyCodeX11, True, 0);
        XFlush(display);
        usleep(1000); // Optional delay
        XTestFakeKeyEvent(display, keyCodeX11, False, 0);
        XFlush(display);

        XCloseDisplay(display);
    #endif
    }
}

int main() {
#ifdef _WIN32
    // Simulate pressing the 'A' key on Windows
    simulateKeyPress("A");
#elif __APPLE__
    // Simulate pressing the 'A' key on macOS
    simulateKeyPress(kVK_ANSI_A);
#elif __linux__
    // Simulate pressing the 'A' key on Linux
    simulateKeyPress(XK_A);
#endif
    return 0;
}
