#include "main.h"

// Buttons
//  - KEY_A
//  - KEY_B
//  - KEY_X
//  - KEY_Y
//  - KEY_L
//  - KEY_R
//  - KEY_DUP
//  - KEY_DDOWN
//  - KEY_DRIGHT
//  - KEY_DLEFT
//  - KEY_DTOUCH(Doesn't really handles touch)

int _3ds_init(void){
    // Initialization
    srvInit();        // services
    aptInit();        // applets
    hidInit();        // input
    gfxInitDefault(); // graphics
    gfxSet3D(false);  // stereoscopy (true: enabled / false: disabled)
    return 0;
}

int main(int argc, char **argv) {
    // Initialization
    _3ds_init();
    
    // Init console
    consoleInit(GFX_TOP, NULL);

    // Output
    Output::printAt("Hello world!", 20, 20);

    while(aptMainLoop()) {
        // Wait for next frame
        gspWaitForVBlank();

        // Scan for inputs
        hidScanInput();
        if((hidKeysDown())&(KEY_START)) {
            // Start is pressed
            break;
        }

        // Handle buffers
        gfxFlushBuffers();
        gfxSwapBuffers();
    }
    // Exit
    gfxExit();
    hidExit();
    aptExit();
    srvExit();

    // Return
    return 0;
}
