# cc65-template-project

### What 

This is intended as boilerplate for new apple2 projects, based on cc65 compiler. The template disk image is Prodos 2.4.2, located in apple2/ directory. The only new thing I've added is in `Makefile-dsk.mk`. I've changed the creation of bootable ProDos disk to be made with the new experimental Apple Commander utility `acx`. You'll need to download the `.jar` file from [Apple Comander github repo](https://github.com/AppleCommander/AppleCommander/releases/tag/1.8.0)

I've included `start.c` in `src` directory, which was my first attempt to make a C program load an image. It worked after 2 day struggle 😀

### How

1. Compile your program and Create the bootable .dsk image with:

   ```
   make
   make dsk
   ```

2. Drop the generated `.dsk` image in your favourite Apple II emulator, or on the real hardware. It should boot in ProDos and you can run  your app.

*OR*

2.1 if you have Virtual ][ installed (on Mac OS), the last line of the `Makefile-dks.mk` will execute an AppleScript, which starts the emulator, loads the `testproj.po` disk and `Brun`s the compiled program. Alternatively, if you use other architectures, comment or amend the last line of `Makefile-dsk.mk`,
