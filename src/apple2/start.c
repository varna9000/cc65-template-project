/* Adapted example from here: https://github.com/cc65/wiki/wiki/Apple-II-11d.-Hires-Monochrome-Mode */
#include <apple2.h>
#include <conio.h>
#include <fcntl.h>
#include <string.h>
#include <peekpoke.h>
#include <unistd.h>

int hgr;
const char Image[]="image";

/* Needed for second hgr page? */
/* unsigned char hgr_memory[0x6000]; */

int main (void)
{

hgr = open (Image, O_RDONLY);

if (hgr == -1) {
   clrscr();
   cprintf ("Error! File not found.");
   return 0;
 }
 else {
   clrscr();
   cprintf("Image found! Press any key..");
   cgetc ();
 }

POKE(0xC050, 0);                            /* Display Graphics                                   */
POKE(0xC054, 0);                            /* LOWSCR - Page 1                                    */
POKE(0xC053, 0);                            /* MIXSET - Enable 4 lines of text                    */
POKE(0xC057, 0);                            /* HIRES - 280x192 Mono or 140x192 col                */

/* Clear hgr memory */
/* memset((unsigned char *)0x2000, 0, 0x6000); */

read (hgr, (void*)0x2000, 0x6000);
close(hgr);

 /* Copy image buffer to hgr page. needed for doublebuf? */
/* memcpy((void *)0x2000, hgr_memory, 0x6000); */

cgetc ();
clrscr();
cprintf ("Well done. Image loded :) \n");
POKE(0xC051, 0);
return 0;
}
