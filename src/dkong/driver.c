/***************************************************************************

Donkey Kong memory map (preliminary)

0000-3fff ROM (Donkey Kong Jr.: 0000-5fff)
6000-6fff RAM
7000-73ff ?
7400-77ff Video RAM


memory mapped ports:

read:
7c00      IN0
7c80      IN1
7d00      IN2
7d80      DSW1

*
 * IN0 (bits NOT inverted)
 * bit 7 : ?
 * bit 6 : ?
 * bit 5 : ?
 * bit 4 : JUMP player 1
 * bit 3 : DOWN player 1
 * bit 2 : UP player 1
 * bit 1 : LEFT player 1
 * bit 0 : RIGHT player 1
 *
*
 * IN1 (bits NOT inverted)
 * bit 7 : ?
 * bit 6 : ?
 * bit 5 : ?
 * bit 4 : JUMP player 2
 * bit 3 : DOWN player 2
 * bit 2 : UP player 2
 * bit 1 : LEFT player 2
 * bit 0 : RIGHT player 2
 *
*
 * IN2 (bits NOT inverted)
 * bit 7 : COIN
 * bit 6 : ?
 * bit 5 : ?
 * bit 4 : ?
 * bit 3 : START 2
 * bit 2 : START 1
 * bit 1 : ?
 * bit 0 : ? if this is 1, the code jumps to $4000, outside the rom space
 *
*
 * DSW1 (bits NOT inverted)
 * bit 7 : COCKTAIL or UPRIGHT cabinet (1 = UPRIGHT)
 * bit 6 : \ 000 = 1 coin 1 play   001 = 2 coins 1 play  010 = 1 coin 2 plays
 * bit 5 : | 011 = 3 coins 1 play  100 = 1 coin 3 plays  101 = 4 coins 1 play
 * bit 4 : / 110 = 1 coin 4 plays  111 = 5 coins 1 play
 * bit 3 : \bonus at
 * bit 2 : / 00 = 7000  01 = 10000  10 = 15000  11 = 20000
 * bit 1 : \ 00 = 3 lives  01 = 4 lives
 * bit 0 : / 10 = 5 lives  11 = 6 lives
 *

write:
6900-6a3f sprites
7800-7803 ?
7808      ?
7c00      ?
7c80      gfx bank select (Donkey Kong Jr. only)
7d00-7d07 sound related? (digital sound trigger?)
7d80      ?
7d82      ?
7d83      ?
7d84      interrupt enable
7d85      ?
7d86      ?
7d87      ?

***************************************************************************/

#include "driver.h"
#include "machine.h"
#include "common.h"


extern unsigned char *dkong_videoram;
extern unsigned char *dkong_colorram;
extern unsigned char *dkong_spriteram;
extern void dkong_videoram_w(int offset,int data);
extern void dkong_colorram_w(int offset,int data);
extern void dkongjr_gfxbank_w(int offset,int data);
extern int dkong_vh_start(void);
extern void dkong_vh_stop(void);
extern void dkong_vh_screenrefresh(struct osd_bitmap *bitmap);



static struct MemoryReadAddress dkong_readmem[] =
{
	{ 0x6000, 0x6fff, MRA_RAM },	/* including sprites ram */
	{ 0x0000, 0x3fff, MRA_ROM },
	{ 0x7c00, 0x7c00, input_port_0_r },	/* IN0 */
	{ 0x7c80, 0x7c80, input_port_1_r },	/* IN1 */
	{ 0x7d00, 0x7d00, input_port_2_r },	/* IN2 */
	{ 0x7d80, 0x7d80, input_port_3_r },	/* DSW1 */
	{ 0x7400, 0x77ff, MRA_RAM },	/* video RAM */
	{ 0x7800, 0x7bff, MRA_RAM },	/* color RAM */
	{ -1 }	/* end of table */
};
static struct MemoryReadAddress dkongjr_readmem[] =
{
	{ 0x6000, 0x6fff, MRA_RAM },	/* including sprites ram */
	{ 0x0000, 0x5fff, MRA_ROM },
	{ 0x7c00, 0x7c00, input_port_0_r },	/* IN0 */
	{ 0x7c80, 0x7c80, input_port_1_r },	/* IN1 */
	{ 0x7d00, 0x7d00, input_port_2_r },	/* IN2 */
	{ 0x7d80, 0x7d80, input_port_3_r },	/* DSW1 */
	{ 0x7400, 0x77ff, MRA_RAM },	/* video RAM */
	{ 0x7800, 0x7bff, MRA_RAM },	/* color RAM */
	{ -1 }	/* end of table */
};

static struct MemoryWriteAddress dkong_writemem[] =
{
	{ 0x6000, 0x68ff, MWA_RAM },
	{ 0x6a80, 0x6fff, MWA_RAM },
	{ 0x6900, 0x6a7f, MWA_RAM, &dkong_spriteram },
	{ 0x7d84, 0x7d84, interrupt_enable_w },
	{ 0x7400, 0x77ff, dkong_videoram_w, &dkong_videoram },
//	{ 0x7800, 0x7bff, dkong_colorram_w, &dkong_colorram },
	{ 0x7c80, 0x7c80, dkongjr_gfxbank_w },
	{ 0x0000, 0x3fff, MWA_ROM },
//	{ 0x7000, 0x73ff, MWA_RAM },	// ??
	{ 0x7800, 0x7803, MWA_RAM },	// ??
	{ 0x7808, 0x7808, MWA_RAM },	// ??
	{ 0x7c00, 0x7c00, MWA_RAM },	// ??
	{ 0x7d00, 0x7d07, MWA_RAM },	// ??
	{ 0x7d80, 0x7d83, MWA_RAM },	// ??
	{ 0x7d85, 0x7d87, MWA_RAM },	// ??
	{ -1 }	/* end of table */
};
static struct MemoryWriteAddress dkongjr_writemem[] =
{
	{ 0x6000, 0x68ff, MWA_RAM },
	{ 0x6a80, 0x6fff, MWA_RAM },
	{ 0x6900, 0x6a7f, MWA_RAM, &dkong_spriteram },
	{ 0x7d84, 0x7d84, interrupt_enable_w },
	{ 0x7400, 0x77ff, dkong_videoram_w, &dkong_videoram },
//	{ 0x7800, 0x7bff, dkong_colorram_w, &dkong_colorram },
	{ 0x7c80, 0x7c80, dkongjr_gfxbank_w },
	{ 0x0000, 0x5fff, MWA_ROM },
//	{ 0x7000, 0x73ff, MWA_RAM },	// ??
	{ 0x7800, 0x7803, MWA_RAM },	// ??
	{ 0x7808, 0x7808, MWA_RAM },	// ??
	{ 0x7c00, 0x7c00, MWA_RAM },	// ??
	{ 0x7d00, 0x7d07, MWA_RAM },	// ??
	{ 0x7d80, 0x7d83, MWA_RAM },	// ??
	{ 0x7d85, 0x7d87, MWA_RAM },	// ??
	{ -1 }	/* end of table */
};



static struct InputPort input_ports[] =
{
	{	/* IN0 */
		0x00,
		{ OSD_KEY_RIGHT, OSD_KEY_LEFT, OSD_KEY_UP, OSD_KEY_DOWN,
				OSD_KEY_CONTROL, 0, 0, 0 },
		{ OSD_JOY_RIGHT, OSD_JOY_LEFT, OSD_JOY_UP, OSD_JOY_DOWN,
				OSD_JOY_FIRE, 0, 0, 0 },
	},
	{	/* IN1 */
		0x00,
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	{	/* IN2 */
		0x00,
		{ 0, 0, OSD_KEY_1, OSD_KEY_2, 0, 0, 0, OSD_KEY_3 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	{	/* DSW1 */
		0x84,
		{ 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0 }
	},
	{ -1 }	/* end of table */
};



static struct DSW dsw[] =
{
	{ 3, 0x03, "LIVES", { "3", "4", "5", "6" } },
	{ 3, 0x0c, "BONUS", { "7000", "10000", "15000", "20000" } },
	{ -1 }
};


static struct GfxLayout dkong_charlayout =
{
	8,8,	/* 8*8 characters */
	256,	/* 256 characters */
	2,	/* 2 bits per pixel */
	{ 0, 256*8*8 },	/* the two bitplanes are separated */
	{ 7*8, 6*8, 5*8, 4*8, 3*8, 2*8, 1*8, 0*8 },
	{ 0, 1, 2, 3, 4, 5, 6, 7 },	/* pretty straightforward layout */
	8*8	/* every char takes 8 consecutive bytes */
};
static struct GfxLayout dkongjr_charlayout =
{
	8,8,	/* 8*8 characters */
	512,	/* 512 characters */
	2,	/* 2 bits per pixel */
	{ 0, 512*8*8 },	/* the two bitplanes are separated */
	{ 7*8, 6*8, 5*8, 4*8, 3*8, 2*8, 1*8, 0*8 },
	{ 0, 1, 2, 3, 4, 5, 6, 7 },	/* pretty straightforward layout */
	8*8	/* every char takes 8 consecutive bytes */
};
static struct GfxLayout spritelayout =
{
	16,16,	/* 16*16 sprites */
	128,	/* 128 sprites */
	2,	/* 2 bits per pixel */
	{ 0, 128*16*16 },	/* the two bitplanes are separated */
	{ 15*8, 14*8, 13*8, 12*8, 11*8, 10*8, 9*8, 8*8,
			7*8, 6*8, 5*8, 4*8, 3*8, 2*8, 1*8, 0*8 },
	{ 0, 1, 2, 3, 4, 5, 6, 7,	/* the two halves of the sprite are separated */
			64*16*16+0, 64*16*16+1, 64*16*16+2, 64*16*16+3, 64*16*16+4, 64*16*16+5, 64*16*16+6, 64*16*16+7 },
	16*8	/* every sprite takes 16 consecutive bytes */
};



static struct GfxDecodeInfo dkong_gfxdecodeinfo[] =
{
	{ 0x10000, &dkong_charlayout,      0, 16 },
	{ 0x11000, &spritelayout,    0, 16 },
	{ -1 } /* end of array */
};
static struct GfxDecodeInfo dkongjr_gfxdecodeinfo[] =
{
	{ 0x10000, &dkongjr_charlayout,      0, 16 },
	{ 0x12000, &spritelayout,    0, 16 },
	{ -1 } /* end of array */
};



static unsigned char palette[] =
{
	0x00,0x00,0x00,	/* BLACK */
	3,167,255,	/* BLUE */
	0xff,0x00,0x00,	/* RED */
	0xff,0xff,0xff,	/* WHITE */
	239,3,239,	/* PINK */
	231,231,3,	/* YELLOW */
	3,3,239,	/* DKBLUE */
	255,131,3,	/* ORANGE */
	0x00,0xff,0x00,	/* GREEN */
	247,3,155,	/* LTRED */
	167,3,3,	/* DKBROWN */
	255,183,115	/* LTBROWN */
};

enum { BLACK,BLUE,RED,WHITE,PINK,YELLOW,DKBLUE,ORANGE,GREEN,LTRED,DKBROWN,LTBROWN };

static unsigned char dkong_colortable[] =
{
	BLACK,BLUE,LTBROWN,RED,	/* Fireball (When Mario has hammer) */
							/* Rotating ends on conveyors */
							/* Springy things (lift screen) */
	BLACK,RED,YELLOW,WHITE,	/* Fireball (normal) */
							/* Flames (on top of oil tank) */
	BLACK,RED,WHITE,DKBLUE,	/* Mario */
	BLACK,1,2,3,			/* -Moving Ladder (conveyor screen) */
							/* Moving Lift */
	BLACK,4,5,6,
	BLACK,7,8,9,
	BLACK,10,11,12,
	BLACK,LTBROWN,DKBROWN,WHITE,	/* Kong (Head), Hammer, Scores (100,200,500,800 etc) */
	BLACK,LTBROWN,DKBROWN,ORANGE,	/* Kong (body) */
	BLACK,ORANGE,WHITE,PINK,	/* girl (Head), Heart (when screen completed) */
	BLACK,WHITE,DKBLUE,PINK,	/* Girl (lower half), Umbrella, Purse, hat */
	BLACK,ORANGE,DKBLUE,YELLOW,	/* Rolling Barrel (type 1), Standing Barrel (near Kong)	*/
	BLACK,WHITE,BLUE,DKBLUE,	/* Oil tank, Rolling Barrel (type 2), Explosion (barrel hit withhammer) */
	BLACK,3,4,5,
	BLACK,GREEN,1,2,	/* -Pies (Conveyor screen) */
	BLACK,YELLOW,RED,BLACK,	/* -Thing at top/bottom of lifts, Clipping sprite (all black) */
};
static unsigned char dkongjr_colortable[] =
{
	BLACK,BLUE,LTBROWN,RED,
	BLACK,RED,YELLOW,WHITE,
	BLACK,RED,WHITE,DKBLUE,
	BLACK,1,2,3,
	BLACK,4,5,6,
	BLACK,7,8,9,
	BLACK,10,11,12,
	BLACK,LTBROWN,DKBROWN,WHITE,
	BLACK,LTBROWN,DKBROWN,ORANGE,
	BLACK,ORANGE,WHITE,PINK,
	BLACK,WHITE,DKBLUE,PINK,
	BLACK,ORANGE,DKBLUE,YELLOW,
	BLACK,WHITE,BLUE,DKBLUE,
	BLACK,3,4,5,
	BLACK,GREEN,1,2,
	BLACK,YELLOW,RED,BLUE
};



const struct MachineDriver dkong_driver =
{
	/* basic machine hardware */
	3072000,	/* 3.072 Mhz */
	60,
	dkong_readmem,dkong_writemem,0,0,
	input_ports,dsw,
	0,
	nmi_interrupt,

	/* video hardware */
	256,256,
	dkong_gfxdecodeinfo,
	sizeof(palette)/3,sizeof(dkong_colortable),
	0,0,palette,dkong_colortable,
	0,17,
	1,11,
	8*13,8*16,0,
	0,
	dkong_vh_start,
	dkong_vh_stop,
	dkong_vh_screenrefresh,

	/* sound hardware */
	0,
	0,
	0,
	0,
	0
};



const struct MachineDriver dkongjr_driver =
{
	/* basic machine hardware */
	3072000,	/* 3.072 Mhz */
	60,
	dkongjr_readmem,dkongjr_writemem,0,0,
	input_ports,dsw,
	0,
	nmi_interrupt,

	/* video hardware */
	256,256,
	dkongjr_gfxdecodeinfo,
	sizeof(palette)/3,sizeof(dkongjr_colortable),
	0,0,palette,dkongjr_colortable,
	0,17,
	1,11,
	8*13,8*16,0,
	0,
	dkong_vh_start,
	dkong_vh_stop,
	dkong_vh_screenrefresh,

	/* sound hardware */
	0,
	0,
	0,
	0,
	0
};
