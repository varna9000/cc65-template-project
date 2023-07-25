# cc65-template-project

* Basic cc65 template project for apple2 applications

This is intended as boilerplate for new apple2 projects, based on cc65 compiler. The template disk image is Prodos 2.4.2, located in apple2/ directory. The only new thing I've added is in `Makefile-dsk.mk`. I've changed the creation of bootable ProDos disk to be made with the new experimental Apple Commander utility `acx`. You'll need to download the `.jar` file from [Apple Comander github repo](https://github.com/AppleCommander/AppleCommander/releases/tag/1.8.0)

I've included `start.c` in `src` directory, which was my first attempt to make a C program load an image. It worked after 2 day struggle 😀
