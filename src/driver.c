#include "driver.h"

extern struct MachineDriver pacman_driver;
extern struct MachineDriver mspacman_driver;
extern struct MachineDriver crush_driver;
extern struct MachineDriver pengo_driver;
extern struct MachineDriver ladybug_driver;
extern struct MachineDriver mrdo_driver;
extern struct MachineDriver cclimber_driver;
extern struct MachineDriver ckong_driver;
extern struct MachineDriver dkong_driver;
extern struct MachineDriver dkongjr_driver;
extern struct MachineDriver bagman_driver;
extern struct MachineDriver wow_driver;
extern struct MachineDriver galaxian_driver;
extern struct MachineDriver pisces_driver;
extern struct MachineDriver japirem_driver;
extern struct MachineDriver warofbug_driver;
extern struct MachineDriver mooncrst_driver;
extern struct MachineDriver theend_driver;


static struct RomModule pacman_rom[] =
{
	/* code */
	{ "%s.6e", 0x00000, 0x1000 },
	{ "%s.6f", 0x01000, 0x1000 },
	{ "%s.6h", 0x02000, 0x1000 },
	{ "%s.6j", 0x03000, 0x1000 },
	/* gfx */
	{ "%s.5e", 0x10000, 0x1000 },
	{ "%s.5f", 0x11000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule pacmod_rom[] =
{
	/* code */
	{ "6e.mod",    0x00000, 0x1000 },
	{ "pacman.6f", 0x01000, 0x1000 },
	{ "6h.mod",    0x02000, 0x1000 },
	{ "pacman.6j", 0x03000, 0x1000 },
	/* gfx */
	{ "5e",        0x10000, 0x1000 },
	{ "5f",        0x11000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule piranha_rom[] =
{
	/* code */
	{ "pr1.cpu", 0x00000, 0x1000 },
	{ "pr2.cpu", 0x01000, 0x1000 },
	{ "pr3.cpu", 0x02000, 0x1000 },
	{ "pr4.cpu", 0x03000, 0x1000 },
	/* gfx */
	{ "pr5.cpu", 0x10000, 0x0800 },
	{ "pr7.cpu", 0x10800, 0x0800 },
	{ "pr6.cpu", 0x11000, 0x0800 },
	{ "pr8.cpu", 0x11800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule mspacman_rom[] =
{
	/* code */
	{ "boot1", 0x00000, 0x1000 },
	{ "boot2", 0x01000, 0x1000 },
	{ "boot3", 0x02000, 0x1000 },
	{ "boot4", 0x03000, 0x1000 },
	{ "boot5", 0x08000, 0x1000 },
	{ "boot6", 0x09000, 0x1000 },
	/* gfx */
	{ "5e",    0x10000, 0x1000 },
	{ "5f",    0x11000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule crush_rom[] =
{
	/* code */
	{ "CR1", 0x00000, 0x0800 },
	{ "CR5", 0x00800, 0x0800 },
	{ "CR2", 0x01000, 0x0800 },
	{ "CR6", 0x01800, 0x0800 },
	{ "CR3", 0x02000, 0x0800 },
	{ "CR7", 0x02800, 0x0800 },
	{ "CR4", 0x03000, 0x0800 },
	{ "CR8", 0x03800, 0x0800 },
	/* gfx */
	{ "CRA", 0x10000, 0x0800 },
	{ "CRC", 0x10800, 0x0800 },
	{ "CRB", 0x11000, 0x0800 },
	{ "CRD", 0x11800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule pengo_rom[] =
{
	/* code */
	{ "pengopop.u8",  0x00000, 0x1000 },
	{ "pengopop.u7",  0x01000, 0x1000 },
	{ "pengopop.u15", 0x02000, 0x1000 },
	{ "pengopop.u14", 0x03000, 0x1000 },
	{ "pengopop.u21", 0x04000, 0x1000 },
	{ "pengopop.u20", 0x05000, 0x1000 },
	{ "pengopop.u32", 0x06000, 0x1000 },
	{ "pengopop.u31", 0x07000, 0x1000 },
	/* gfx */
	{ "pengopop.u92", 0x10000, 0x2000 },
	{ "pengopop.105", 0x12000, 0x2000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule penta_rom[] =
{
	/* code */
	{ "penta.u8",  0x00000, 0x1000 },
	{ "penta.u7",  0x01000, 0x1000 },
	{ "penta.u15", 0x02000, 0x1000 },
	{ "penta.u14", 0x03000, 0x1000 },
	{ "penta.u21", 0x04000, 0x1000 },
	{ "penta.u20", 0x05000, 0x1000 },
	{ "penta.u32", 0x06000, 0x1000 },
	{ "penta.u31", 0x07000, 0x1000 },
	/* gfx */
	{ "penta.u92", 0x10000, 0x2000 },
	{ "penta.105", 0x12000, 0x2000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule ladybug_rom[] =
{
	/* code */
	{ "lb1.cpu", 0x00000, 0x1000 },
	{ "lb2.cpu", 0x01000, 0x1000 },
	{ "lb3.cpu", 0x02000, 0x1000 },
	{ "lb4.cpu", 0x03000, 0x1000 },
	{ "lb5.cpu", 0x04000, 0x1000 },
	{ "lb6.cpu", 0x05000, 0x1000 },
	/* gfx */
	{ "lb9.vid",  0x10000, 0x1000 },
	{ "lb10.vid", 0x11000, 0x1000 },
	{ "lb8.cpu",  0x12000, 0x1000 },
	{ "lb7.cpu",  0x13000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule mrdo_rom[] =
{
	/* code */
	{ "D1", 0x00000, 0x2000 },
	{ "D2", 0x02000, 0x2000 },
	{ "D3", 0x04000, 0x2000 },
	{ "D4", 0x06000, 0x2000 },
	/* gfx */
	{ "D9", 0x10000, 0x1000 },
	{ "D10",0x11000, 0x1000 },
	{ "D8", 0x12000, 0x1000 },
	{ "D7", 0x13000, 0x1000 },
	{ "D5", 0x14000, 0x1000 },
	{ "D6", 0x15000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule mrlo_rom[] =
{
	/* code */
	{ "a4-01.bin", 0x00000, 0x2000 },
	{ "c4-02.bin", 0x02000, 0x2000 },
	{ "e4-03.bin", 0x04000, 0x2000 },
	{ "g4-04.bin", 0x06000, 0x2000 },
	/* gfx */
	{ "s8-09.bin", 0x10000, 0x1000 },
	{ "u8-10.bin", 0x11000, 0x1000 },
	{ "r8-08.bin", 0x12000, 0x1000 },
	{ "n8-07.bin", 0x13000, 0x1000 },
	{ "h5-05.bin", 0x14000, 0x1000 },
	{ "k5-06.bin", 0x15000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule cclimber_rom[] =
{
	/* code */
	{ "cc11", 0x00000, 0x1000 },
	{ "cc10", 0x01000, 0x1000 },
	{ "cc09", 0x02000, 0x1000 },
	{ "cc08", 0x03000, 0x1000 },
	{ "cc07", 0x04000, 0x1000 },
	/* gfx */
	{ "cc06", 0x10000, 0x0800 },
	{ "cc04", 0x10800, 0x0800 },
	{ "cc05", 0x11000, 0x0800 },
	{ "cc03", 0x11800, 0x0800 },
	{ "cc02", 0x12000, 0x0800 },
	{ "cc01", 0x12800, 0x0800 },
	/* samples */
	{ "cc13", 0x18000, 0x1000 },
	{ "cc12", 0x19000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



unsigned cclimber_decode(dword A)
{
	static const unsigned char evetab[] =
	{
		0x44,0x14,0x47,0x12,0x54,0x10,0x13,0x46,0x4c,0x1c,0x4f,0x1a,0x5c,0x18,0x1b,0x4e,
		0x11,0x41,0x07,0x52,0x05,0x50,0x53,0x06,0x19,  -1,0x0f,0x5a,0x0d,0x58,0x5b,0x0e,
		0x64,0x34,0x67,0x32,0x74,0x30,0x33,0x66,0x6c,0x3c,0x6f,0x3a,0x7c,0x38,0x3b,0x6e,
		0x31,  -1,0x27,0x72,0x25,0x70,0x73,0x26,0x39,  -1,0x2f,0x7a,0x2d,0x78,0x7b,0x2e,
		0x51,0x00,0x43,0x16,0x40,0x55,0x17,0x42,0x59,0x08,0x4b,0x1e,0x48,0x5d,0x1f,0x4a,
		  -1,0x04,0x03,0x56,0x01,0x15,0x57,0x02,  -1,  -1,0x0b,0x5e,0x09,0x1d,0x5f,0x0a,
		0x71,0x20,0x63,0x36,0x60,0x75,0x37,0x62,0x79,0x28,0x6b,0x3e,0x68,0x7d,0x3f,0x6a,
		  -1,  -1,0x23,0x76,0x21,0x35,0x77,0x22,  -1,  -1,0x2b,0x7e,0x29,0x3d,0x7f,0x2a,
		0xd4,0xd1,0xd3,0x86,0x95,0xc5,0x92,  -1,0xdc,0xd9,0xdb,  -1,0x9d,0xcd,0x9a,  -1,
		0xc4,0x81,0xd2,0xc2,0x91,0xc1,0x82,  -1,0xcc,  -1,0xda,0xca,0x99,0xc9,0x8a,  -1,
		0xf4,0xf1,0xf3,  -1,0xb5,0xe5,0xb2,  -1,0xfc,0xf9,0xfb,  -1,0xbd,0xed,0xba,  -1,
		0xe4,  -1,0xf2,0xe2,0xb1,0xe1,0xa2,  -1,0xec,  -1,0xfa,0xea,0xb9,0xe9,0xaa,  -1,
		0x84,0xd5,0xc3,0x83,0xd0,  -1,0x87,0x97,0x8c,0xdd,0xcb,  -1,0xd8,  -1,0x8f,0x9f,
		0x80,0x90,0x93,0x96,0xc0,  -1,0xc6,0xd6,0x88,0x98,0x9b,0x9e,0xc8,  -1,0xce,0xde,
		0xa4,0xf5,0xe3,  -1,0xf0,  -1,0xa7,0xb7,0xac,0xfd,0xeb,  -1,0xf8,  -1,0xaf,0xbf,
		0xa0,0xb0,0xb3,0xb6,0xe0,  -1,0xe6,0xf6,0xa8,0xb8,0xbb,0xbe,0xe8,  -1,0xee,0xfe
	};
	static const unsigned char oddtab[] =
	{
		0x44,0x10,0x06,0x53,0x15,0x55,0x47,0x02,0x4c,0x18,0x0e,0x5b,0x1d,0x5d,0x4f,0x0a,
		0x00,0x41,0x46,0x12,  -1,0x51,  -1,0x57,0x08,  -1,0x4e,0x1a,  -1,0x59,  -1,0x5f,
		0x64,0x30,0x26,0x73,0x35,0x75,0x67,0x22,0x6c,0x38,0x2e,0x7b,0x3d,0x7d,0x6f,0x2a,
		0x20,  -1,0x66,0x32,  -1,0x71,  -1,0x77,0x28,  -1,0x6e,0x3a,  -1,0x79,  -1,0x7f,
		0x14,0x45,0x13,0x56,0x11,0x50,0x52,0x42,0x1c,0x4d,0x1b,0x5e,0x19,0x58,0x5a,  -1,
		0x01,0x54,0x07,  -1,0x04,0x05,0x16,0x03,0x09,0x5c,0x0f,  -1,0x0c,0x0d,0x1e,0x0b,
		0x34,0x65,0x33,0x76,0x31,0x70,0x72,  -1,0x3c,0x6d,0x3b,0x7e,0x39,0x78,0x7a,  -1,
		0x21,0x74,0x27,  -1,0x24,0x25,0x36,0x23,0x29,0x7c,0x2f,  -1,0x2c,0x2d,0x3e,0x2b,
		  -1,  -1,  -1,  -1,  -1,  -1,0xd6,0x83,  -1,0xdc,  -1,  -1,  -1,0xd8,0xde,  -1,
		0xd1,0x81,0x97,0xc2,  -1,0xc0,0xc7,0xc3,0xd9,  -1,0x9f,0xca,  -1,0xc8,  -1,0xcb,
		  -1,  -1,  -1,  -1,0xb4,  -1,0xf6,  -1,  -1,  -1,  -1,  -1,  -1,  -1,0xfe,  -1,
		0xf1,  -1,0xb7,0xe2,  -1,0xe0,  -1,0xe3,0xf9,  -1,0xbf,0xea,  -1,0xe8,  -1,0xeb,
		0xc1,0x90,0xd3,0x86,0x80,0xd5,0xd2,0x87,0xc9,0x98,0xdb,0x8e,  -1,0xdd,0xda,0x8f,
		0x85,0xc4,0x93,0xc6,0x91,0xc5,0x92,0x96,  -1,0xcc,0x9b,0xce,0x99,0xcd,  -1,0x9e,
		0xe1,0xb0,0xf3,0xa6,  -1,0xf5,0xf2,0xa7,0xe9,0xb8,0xfb,0xae,  -1,0xfd,0xfa,0xaf,
		  -1,0xe4,0xb3,0xe6,0xb1,0xe5,  -1,0xb6,  -1,0xec,0xbb,0xee,0xb9,0xed,  -1,0xbe
	};


	if (A & 1) return oddtab[RAM[A]];
	else return evetab[RAM[A]];
}



static struct RomModule ccboot_rom[] =
{
	/* code */
	{ "m11.bin", 0x00000, 0x1000 },
	{ "m10.bin", 0x01000, 0x1000 },
	{ "m09.bin", 0x02000, 0x1000 },
	{ "m08.bin", 0x03000, 0x1000 },
	{ "m07.bin", 0x04000, 0x1000 },
	/* gfx */
	{ "m06.bin", 0x10000, 0x0800 },
	{ "m04.bin", 0x10800, 0x0800 },
	{ "m05.bin", 0x11000, 0x0800 },
	{ "m03.bin", 0x11800, 0x0800 },
	{ "m02.bin", 0x12000, 0x0800 },
	{ "m01.bin", 0x12800, 0x0800 },
	/* samples */
	{ "m13.bin", 0x18000, 0x1000 },
	{ "m12.bin", 0x19000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



unsigned ccboot_decode(dword A)
{
	static const unsigned char evetab[] =
	{
		0x41,0x54,0x46,0x13,0x51,0x14,0x02,0x52,0x49,0x5c,0x4e,0x1b,0x59,0x1c,0x0a,0x5a,
		0x05,0x10,0x43,0x56,0x01,0x55,0x06,0x16,0x0d,0x18,0x4b,0x5e,0x09,0x5d,0x0e,0x1e,
		0x61,0x74,0x66,0x33,0x71,0x34,0x22,0x72,0x69,0x7c,0x6e,0x3b,0x79,0x3c,0x2a,0x7a,
		0x25,0x30,0x63,0x76,0x21,0x75,0x26,0x36,0x2d,0x38,0x6b,0x7e,0x29,0x7d,0x2e,0x3e,
		0x44,0x11,0x17,0x42,0x00,0x50,0x53,0x57,0x4c,0x19,0x1f,0x4a,0x08,0x58,0x5b,0x5f,
		0x15,0x40,0x07,0x12,0x04,0x45,0x03,0x47,0x1d,0x48,0x0f,0x1a,0x0c,0x4d,0x0b,0x4f,
		0x64,0x31,0x37,0x62,0x20,0x70,0x73,0x77,0x6c,0x39,0x3f,0x6a,0x28,0x78,0x7b,0x7f,
		0x35,0x60,0x27,0x32,0x24,0x65,0x23,0x67,0x3d,0x68,0x2f,0x3a,0x2c,0x6d,0x2b,0x6f,
		0x94,0xc1,0x87,0xd7,0x81,0xc4,0x82,0xd2,0x9c,0xc9,0x8f,0xdf,0x89,0xcc,0x8a,0xda,
		0x84,0xd0,0x93,0xc2,0xd1,0xc5,0xd6,0x96,0x8c,0xd8,0x9b,0xca,0xd9,0xcd,0xde,0x9e,
		0xb4,0xe1,0xa7,0xf7,0xa1,0xe4,0xa2,0xf2,0xbc,0xe9,0xaf,0xff,0xa9,0xec,0xaa,0xfa,
		0xa4,0xf0,0xb3,0xe2,0xf1,0xe5,0xf6,0xb6,0xac,0xf8,0xbb,0xea,0xf9,0xed,0xfe,0xbe,
		0x91,0xc0,0xc7,0xd3,0xd4,0x95,0x92,0x86,0x99,0xc8,0xcf,0xdb,0xdc,0x9d,0x9a,0x8e,
		0x90,0x80,0xc6,0x83,0xd5,0x85,0xc3,0x97,0x98,0x88,0xce,0x8b,0xdd,0x8d,0xcb,0x9f,
		0xb1,0xe0,0xe7,0xf3,0xf4,0xb5,0xb2,0xa6,0xb9,0xe8,0xef,0xfb,0xfc,0xbd,0xba,0xae,
		0xb0,0xa0,0xe6,0xa3,0xf5,0xa5,0xe3,0xb7,0xb8,0xa8,0xee,0xab,0xfd,0xad,0xeb,0xbf,
	};
	static const unsigned char oddtab[] =
	{
		0x50,0x11,0x12,0x52,0x40,0x55,0x56,0x57,0x58,0x19,0x1a,0x5a,0x48,0x5d,0x5e,0x5f,
		0x51,0x14,0x03,0x46,0x45,0x04,0x42,0x06,0x59,0x1c,0x0b,0x4e,0x4d,0x0c,0x4a,0x0e,
		0x70,0x31,0x32,0x72,0x60,0x75,0x76,0x77,0x78,0x39,0x3a,0x7a,0x68,0x7d,0x7e,0x7f,
		0x71,0x34,0x23,0x66,0x65,0x24,0x62,0x26,0x79,0x3c,0x2b,0x6e,0x6d,0x2c,0x6a,0x2e,
		0x54,0x15,0x16,0x13,0x10,0x05,0x02,0x43,0x5c,0x1d,0x1e,0x1b,0x18,0x0d,0x0a,0x4b,
		0x44,0x01,0x47,0x17,0x00,0x41,0x53,0x07,0x4c,0x09,0x4f,0x1f,0x08,0x49,0x5b,0x0f,
		0x74,0x35,0x36,0x33,0x30,0x25,0x22,0x63,0x7c,0x3d,0x3e,0x3b,0x38,0x2d,0x2a,0x6b,
		0x64,0x21,0x67,0x37,0x20,0x61,0x73,0x27,0x6c,0x29,0x6f,0x3f,0x28,0x69,0x7b,0x2f,
		0x81,0x85,0xd7,0xd2,0xc1,0xc5,0x97,0x92,0x89,0x8d,0xdf,0xda,0xc9,0xcd,0x9f,0x9a,
		0xd4,0xd0,0x83,0x86,0xd5,0x90,0xc3,0xc6,0xdc,0xd8,0x8b,0x8e,0xdd,0x98,0xcb,0xce,
		0xa1,0xa5,0xf7,0xf2,0xe1,0xe5,0xb7,0xb2,0xa9,0xad,0xff,0xfa,0xe9,0xed,0xbf,0xba,
		0xf4,0xf0,0xa3,0xa6,0xf5,0xb0,0xe3,0xe6,0xfc,0xf8,0xab,0xae,0xfd,0xb8,0xeb,0xee,
		0x91,0x95,0xc7,0xc2,0xd1,0x94,0x87,0x82,0x99,0x9d,0xcf,0xca,0xd9,0x9c,0x8f,0x8a,
		0xc4,0xc0,0x93,0x96,0x84,0x80,0xd3,0xd6,0xcc,0xc8,0x9b,0x9e,0x8c,0x88,0xdb,0xde,
		0xb1,0xb5,0xe7,0xe2,0xf1,0xb4,0xa7,0xa2,0xb9,0xbd,0xef,0xea,0xf9,0xbc,0xaf,0xaa,
		0xe4,0xe0,0xb3,0xb6,0xa4,0xa0,0xf3,0xf6,0xec,0xe8,0xbb,0xbe,0xac,0xa8,0xfb,0xfe
	};


	if (A & 1) return oddtab[RAM[A]];
	else return evetab[RAM[A]];
}



static struct RomModule ckong_rom[] =
{
	/* code */
	{ "7.dat",  0x00000, 0x1000 },
	{ "8.dat",  0x01000, 0x1000 },
	{ "9.dat",  0x02000, 0x1000 },
	{ "10.dat", 0x03000, 0x1000 },
	{ "11.dat", 0x04000, 0x1000 },
	{ "12.dat", 0x05000, 0x1000 },
	/* gfx */
	{ "6.dat",  0x10000, 0x1000 },
	{ "4.dat",  0x11000, 0x1000 },
	{ "5.dat",  0x12000, 0x1000 },
	{ "3.dat",  0x13000, 0x1000 },
	{ "2.dat",  0x14000, 0x0800 },
	{ "1.dat",  0x14800, 0x0800 },
	/* samples */
	{ "14.dat", 0x18000, 0x1000 },
	{ "13.dat", 0x19000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule dkong_rom[] =
{
	/* code */
	{ "dk.5e",  0x00000, 0x1000 },
	{ "dk.5c",  0x01000, 0x1000 },
	{ "dk.5b",  0x02000, 0x1000 },
	{ "dk.5a",  0x03000, 0x1000 },
	/* gfx */
	{ "dk.3n",  0x10000, 0x0800 },
	{ "dk.3p",  0x10800, 0x0800 },
	{ "dk.7c",  0x11000, 0x0800 },
	{ "dk.7d",  0x11800, 0x0800 },
	{ "dk.7e",  0x12000, 0x0800 },
	{ "dk.7f",  0x12800, 0x0800 },
	/* samples? */
	{ "dk.3h",  0x18000, 0x0800 },
	{ "dk.3f",  0x18800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule dkongjr_rom[] =
{
	/* code */
	{ "dkj.5b",  0x00000, 0x1000 },
	{ 0,         0x03000, 0x1000 },
	{ "dkj.5c",  0x02000, 0x0800 },
	{ 0,         0x04800, 0x0800 },
	{ 0,         0x01000, 0x0800 },
	{ 0,         0x05800, 0x0800 },
	{ "dkj.5e",  0x04000, 0x0800 },
	{ 0,         0x02800, 0x0800 },
	{ 0,         0x05000, 0x0800 },
	{ 0,         0x01800, 0x0800 },
	/* gfx */
	{ "dkj.3n",  0x10000, 0x1000 },
	{ "dkj.3p",  0x11000, 0x1000 },
	{ "dkj.7c",  0x12000, 0x0800 },
	{ "dkj.7d",  0x12800, 0x0800 },
	{ "dkj.7e",  0x13000, 0x0800 },
	{ "dkj.7f",  0x13800, 0x0800 },
	/* samples? */
	{ "dkj.3h",  0x18000, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule bagman_rom[] =
{
	/* code */
	{ "a4_9e.bin", 0x00000, 0x1000 },
	{ "a4_9f.bin", 0x01000, 0x1000 },
	{ "a4_9j.bin", 0x02000, 0x1000 },
	{ "a4_9k.bin", 0x03000, 0x1000 },
	{ "a4_9m.bin", 0x04000, 0x1000 },
	{ "a4_9n.bin", 0x05000, 0x1000 },
	/* gfx */
	{ "a2_1e.bin", 0x10000, 0x1000 },
	{ "a2_1j.bin", 0x11000, 0x1000 },
	{ "a2_1c.bin", 0x12000, 0x1000 },
	{ "a2_1f.bin", 0x13000, 0x1000 },
	/* ??? */
	{ "a1_9r.bin", 0x18000, 0x1000 },
	{ "a1_9t.bin", 0x19000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule wow_rom[] =
{
	/* code */
	{ "wow.x1", 0x00000, 0x1000 },
	{ "wow.x2", 0x01000, 0x1000 },
	{ "wow.x3", 0x02000, 0x1000 },
	{ "wow.x4", 0x03000, 0x1000 },
	{ "wow.x5", 0x08000, 0x1000 },
	{ "wow.x6", 0x09000, 0x1000 },
	{ "wow.x7", 0x0a000, 0x1000 },
/*	{ "wow.x8", 0x0c000, 0x1000 },	here would go the foreign language ROM */
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule robby_rom[] =
{
	/* code */
	{ "robbya", 0x00000, 0x1000 },
	{ "robbyb", 0x01000, 0x1000 },
	{ "robbyc", 0x02000, 0x1000 },
	{ "robbyd", 0x03000, 0x1000 },
	{ "robbye", 0x08000, 0x1000 },
	{ "robbyf", 0x09000, 0x1000 },
	{ "robbyg", 0x0a000, 0x1000 },
	{ "robbyh", 0x0b000, 0x1000 },
	{ "robbyi", 0x0c000, 0x1000 },
	{ "robbyj", 0x0d000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule gorf_rom[] =
{
	/* code */
	{ "gorf.x01", 0x00000, 0x1000 },
	{ "gorf.x03", 0x01000, 0x1000 },
	{ "gorf.x05", 0x02000, 0x1000 },
	{ "gorf.x07", 0x03000, 0x1000 },
	{ "gorf.x11", 0x08000, 0x1000 },
	{ "gorf.x13", 0x09000, 0x1000 },
	{ "gorf.x15", 0x0a000, 0x1000 },
	{ "gorf.x17", 0x0c000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule galaxian_rom[] =
{
	/* code */
	{ "%s.u",  0x00000, 0x0800 },
	{ "%s.v",  0x00800, 0x0800 },
	{ "%s.w",  0x01000, 0x0800 },
	{ "%s.y",  0x01800, 0x0800 },
	{ "%s.z",  0x02000, 0x0800 },
	/* gfx */
	{ "%s.1j", 0x10000, 0x0800 },
	{ "%s.1k", 0x10800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule galnamco_rom[] =
{
	/* code */
	{ "galaxian.u",  0x00000, 0x0800 },
	{ "galaxian.v",  0x00800, 0x0800 },
	{ "galaxian.w",  0x01000, 0x0800 },
	{ "galaxian.y",  0x01800, 0x0800 },
	{ "galaxian.z",  0x02000, 0x0800 },
	/* gfx */
	{ "galaxian.1h", 0x10000, 0x0800 },
	{ "galaxian.1k", 0x10800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule galapx_rom[] =
{
	/* code */
	{ "galx.u",  0x00000, 0x0800 },
	{ "galx.v",  0x00800, 0x0800 },
	{ "galx.w",  0x01000, 0x0800 },
	{ "galx.y",  0x01800, 0x0800 },
	{ "galx.z",  0x02000, 0x0800 },
	/* gfx */
	{ "galx.1h", 0x10000, 0x0800 },
	{ "galx.1k", 0x10800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule galap1_rom[] =
{
	/* code */
	{ "galx_1.rom",   0x00000, 0x2800 },
	/* gfx */
	{ "galx_1c1.rom", 0x10000, 0x0800 },
	{ "galx_1c2.rom", 0x10800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule galap4_rom[] =
{
	/* code */
	{ "galx_4.rom",   0x00000, 0x2800 },
	/* gfx */
	{ "galx_4c1.rom", 0x10000, 0x0800 },
	{ "galx_4c2.rom", 0x10800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule pisces_rom[] =
{
	/* code */
	{ "pisces.a1", 0x00000, 0x0800 },
	{ "pisces.a2", 0x00800, 0x0800 },
	{ "pisces.b2", 0x01000, 0x0800 },
	{ "pisces.c1", 0x01800, 0x0800 },
	{ "pisces.d1", 0x02000, 0x0800 },
	{ "pisces.e2", 0x02800, 0x0800 },
	/* gfx */
	{ "pisces.1j", 0x10000, 0x1000 },
	{ "pisces.1k", 0x11000, 0x1000 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule japirem_rom[] =
{
	/* code */
	{ "f07_1a.bin",  0x00000, 0x0800 },
	{ "h07_2a.bin",  0x00800, 0x0800 },
	{ "k07_3a.bin",  0x01000, 0x0800 },
	{ "m07_4a.bin",  0x01800, 0x0800 },
	{ "d08p_5a.bin", 0x02000, 0x0800 },
	{ "e08p_6a.bin", 0x02800, 0x0800 },
	{ "m08p_7a.bin", 0x03000, 0x0800 },
	{ "n08p_8a.bin", 0x03800, 0x0800 },
	/* gfx */
	{ "k01_1.bin",   0x10000, 0x0800 },
	{ "k01_2.bin",   0x10800, 0x0800 },
	{ "h01_1.bin",   0x11000, 0x0800 },
	{ "h01_2.bin",   0x11800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule mooncrst_rom[] =
{
	/* code */
	{ "EPR194", 0x00000, 0x0800 },
	{ "EPR195", 0x00800, 0x0800 },
	{ "EPR196", 0x01000, 0x0800 },
	{ "EPR197", 0x01800, 0x0800 },
	{ "EPR198", 0x02000, 0x0800 },
	{ "EPR199", 0x02800, 0x0800 },
	{ "EPR200", 0x03000, 0x0800 },
	{ "EPR201", 0x03800, 0x0800 },
	/* gfx */
	{ "EPR202", 0x10000, 0x0800 },
	{ "EPR171", 0x10800, 0x0800 },
	{ "EPR203", 0x11000, 0x0800 },
	{ "EPR172", 0x11800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



static struct RomModule theend_rom[] =
{
	/* code */
	{ "IC13", 0x00000, 0x0800 },
	{ "IC14", 0x00800, 0x0800 },
	{ "IC15", 0x01000, 0x0800 },
	{ "IC16", 0x01800, 0x0800 },
	{ "IC17", 0x02000, 0x0800 },
	{ "IC18", 0x02800, 0x0800 },
	{ "IC56", 0x03000, 0x0800 },
	{ "IC55", 0x03800, 0x0800 },
	/* gfx */
	{ "IC30", 0x10000, 0x0800 },
	{ "IC31", 0x10800, 0x0800 },
	{ 0, 0, 0 }	/* end of table */
};



struct GameDriver drivers[] =
{
	{ "pacman",   pacman_rom,   0,               &pacman_driver },
	{ "pacmod",   pacmod_rom,   0,               &pacman_driver },
	{ "namcopac", pacman_rom,   0,               &pacman_driver },
	{ "hangly",   pacman_rom,   0,               &pacman_driver },
	{ "puckman",  pacman_rom,   0,               &pacman_driver },
	{ "piranha",  piranha_rom,  0,               &pacman_driver },
	{ "mspacman", mspacman_rom, 0,               &mspacman_driver },
	{ "crush",    crush_rom,    0,               &crush_driver },
	{ "pengo",    pengo_rom,    0,               &pengo_driver },
	{ "penta",    penta_rom,    0,               &pengo_driver },
	{ "ladybug",  ladybug_rom,  0,               &ladybug_driver },
	{ "mrdo",     mrdo_rom,     0,               &mrdo_driver },
	{ "mrlo",     mrlo_rom,     0,               &mrdo_driver },
	{ "cclimber", cclimber_rom, cclimber_decode, &cclimber_driver },
	{ "ccboot",   ccboot_rom,   ccboot_decode,   &cclimber_driver },
	{ "ckong",    ckong_rom,    0,               &ckong_driver },
	{ "dkong",    dkong_rom,    0,               &dkong_driver },
	{ "dkongjr",  dkongjr_rom,  0,               &dkongjr_driver },
	{ "bagman",   bagman_rom,   0,               &bagman_driver },
	{ "wow",      wow_rom,      0,               &wow_driver },
	{ "robby",    robby_rom,    0,               &wow_driver },
	{ "gorf",     gorf_rom,     0,               &wow_driver },
	{ "galaxian", galaxian_rom, 0,               &galaxian_driver },
	{ "galnamco", galnamco_rom, 0,               &galaxian_driver },
	{ "superg",   galnamco_rom, 0,               &galaxian_driver },
	{ "galapx",   galapx_rom,   0,               &galaxian_driver },
	{ "galap1",   galap1_rom,   0,               &galaxian_driver },
	{ "galap4",   galap4_rom,   0,               &galaxian_driver },
	{ "galturbo", galnamco_rom, 0,               &galaxian_driver },
	{ "pisces",   pisces_rom,   0,               &pisces_driver },
	{ "japirem",  japirem_rom,  0,               &japirem_driver },
	{ "warofbug", galaxian_rom, 0,               &warofbug_driver },
	{ "mooncrst", mooncrst_rom, 0,               &mooncrst_driver },
	{ "theend",   theend_rom,   0,               &theend_driver },
	{ 0	}	/* end of array */
};
