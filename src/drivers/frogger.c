/***************************************************************************

 Frogger hardware

***************************************************************************/

#include "driver.h"
#include "galaxian.h"



static MEMORY_READ_START( readmem )
	{ 0x0000, 0x3fff, MRA_ROM },
	{ 0x8000, 0x87ff, MRA_RAM },
	{ 0x8800, 0x8800, watchdog_reset_r },
	{ 0xa800, 0xabff, MRA_RAM },
	{ 0xb000, 0xb0ff, MRA_RAM },
	{ 0xd000, 0xd007, frogger_ppi8255_1_r },
	{ 0xe000, 0xe007, frogger_ppi8255_0_r },
MEMORY_END

static MEMORY_WRITE_START( writemem )
	{ 0x0000, 0x3fff, MWA_ROM },
	{ 0x8000, 0x87ff, MWA_RAM },
	{ 0xa800, 0xabff, galaxian_videoram_w, &galaxian_videoram },
	{ 0xb000, 0xb03f, galaxian_attributesram_w, &galaxian_attributesram },
	{ 0xb040, 0xb05f, MWA_RAM, &galaxian_spriteram, &galaxian_spriteram_size },
	{ 0xb060, 0xb0ff, MWA_RAM },
	{ 0xb808, 0xb808, galaxian_nmi_enable_w },
	{ 0xb80c, 0xb80c, galaxian_flip_screen_y_w },
	{ 0xb810, 0xb810, galaxian_flip_screen_x_w },
	{ 0xb818, 0xb818, galaxian_coin_counter_0_w },
	{ 0xb81c, 0xb81c, galaxian_coin_counter_1_w },
	{ 0xd000, 0xd007, frogger_ppi8255_1_w },
	{ 0xe000, 0xe007, frogger_ppi8255_0_w },
MEMORY_END


MEMORY_READ_START( frogger_sound_readmem )
	{ 0x0000, 0x1fff, MRA_ROM },
	{ 0x4000, 0x43ff, MRA_RAM },
MEMORY_END

MEMORY_WRITE_START( frogger_sound_writemem )
	{ 0x0000, 0x1fff, MWA_ROM },
	{ 0x4000, 0x43ff, MWA_RAM },
    { 0x6000, 0x6fff, frogger_filter_w },
MEMORY_END


PORT_READ_START( frogger_sound_readport )
	{ 0x40, 0x40, AY8910_read_port_0_r },
PORT_END

PORT_WRITE_START( frogger_sound_writeport )
	{ 0x40, 0x40, AY8910_write_port_0_w },
	{ 0x80, 0x80, AY8910_control_port_0_w },
PORT_END



INPUT_PORTS_START( frogger )
	PORT_START	/* IN0 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_4WAY | IPF_COCKTAIL )
	PORT_BIT( 0x02, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* 1P shoot2 - unused */
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_SERVICE1 )
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* 1P shoot1 - unused */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_4WAY )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_4WAY )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_COIN2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_COIN1 )

	PORT_START	/* IN1 */
	PORT_DIPNAME( 0x03, 0x00, DEF_STR( Lives ) )
	PORT_DIPSETTING(	0x00, "3" )
	PORT_DIPSETTING(	0x01, "5" )
	PORT_DIPSETTING(	0x02, "7" )
	PORT_BITX( 0,		0x03, IPT_DIPSWITCH_SETTING | IPF_CHEAT, "256", IP_KEY_NONE, IP_JOY_NONE )
	PORT_BIT( 0x04, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* 2P shoot2 - unused */
	PORT_BIT( 0x08, IP_ACTIVE_LOW, IPT_UNKNOWN ) /* 2P shoot1 - unused */
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_RIGHT | IPF_4WAY | IPF_COCKTAIL )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_JOYSTICK_LEFT | IPF_4WAY | IPF_COCKTAIL )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_START2 )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_START1 )

	PORT_START	/* IN2 */
	PORT_BIT( 0x01, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_4WAY | IPF_COCKTAIL )
	PORT_DIPNAME( 0x06, 0x00, DEF_STR( Coinage ) )
	PORT_DIPSETTING(	0x02, "A 2/1 B 2/1 C 2/1" )
	PORT_DIPSETTING(	0x04, "A 2/1 B 1/3 C 2/1" )
	PORT_DIPSETTING(	0x00, "A 1/1 B 1/1 C 1/1" )
	PORT_DIPSETTING(	0x06, "A 1/1 B 1/6 C 1/1" )
	PORT_DIPNAME( 0x08, 0x00, DEF_STR( Cabinet ) )
	PORT_DIPSETTING(	0x00, DEF_STR( Upright ) )
	PORT_DIPSETTING(	0x08, DEF_STR( Cocktail ) )
	PORT_BIT( 0x10, IP_ACTIVE_LOW, IPT_JOYSTICK_UP | IPF_4WAY )
	PORT_BIT( 0x20, IP_ACTIVE_LOW, IPT_UNUSED )
	PORT_BIT( 0x40, IP_ACTIVE_LOW, IPT_JOYSTICK_DOWN | IPF_4WAY )
	PORT_BIT( 0x80, IP_ACTIVE_LOW, IPT_UNUSED )
INPUT_PORTS_END


struct AY8910interface frogger_ay8910_interface =
{
	1,	/* 1 chip */
	14318000/8,	/* 1.78975 MHz */
	{ MIXERG(80,MIXER_GAIN_2x,MIXER_PAN_CENTER) },
	{ soundlatch_r },
	{ frogger_portB_r },
	{ 0 },
	{ 0 }
};


static MACHINE_DRIVER_START( frogger )

	/* basic machine hardware */
	MDRV_IMPORT_FROM(galaxian_base)
	MDRV_CPU_MODIFY("main")
	MDRV_CPU_MEMORY(readmem,writemem)

	MDRV_CPU_ADD(Z80,14318000/8)
	MDRV_CPU_FLAGS(CPU_AUDIO_CPU) /* 1.78975 MHz */
	MDRV_CPU_MEMORY(frogger_sound_readmem,frogger_sound_writemem)
	MDRV_CPU_PORTS(frogger_sound_readport,frogger_sound_writeport)

	MDRV_MACHINE_INIT(scramble)

	/* video hardware */
	MDRV_PALETTE_LENGTH(32+64+2+1)	/* 32 for characters, 64 for stars, 2 for bullets, 1 for background */	\

	MDRV_PALETTE_INIT(frogger)
	MDRV_VIDEO_START(frogger)

	/* sound hardware */
	MDRV_SOUND_ADD(AY8910, frogger_ay8910_interface)
MACHINE_DRIVER_END


/***************************************************************************

  Game driver(s)

***************************************************************************/

ROM_START( frogger )
	ROM_REGION( 0x10000, REGION_CPU1, 0 )	/* 64k for code */
	ROM_LOAD( "frogger.26",   0x0000, 0x1000, 0x597696d6 )
	ROM_LOAD( "frogger.27",   0x1000, 0x1000, 0xb6e6fcc3 )
	ROM_LOAD( "frsm3.7",      0x2000, 0x1000, 0xaca22ae0 )

	ROM_REGION( 0x10000, REGION_CPU2, 0 )	/* 64k for the audio CPU */
	ROM_LOAD( "frogger.608",  0x0000, 0x0800, 0xe8ab0256 )
	ROM_LOAD( "frogger.609",  0x0800, 0x0800, 0x7380a48f )
	ROM_LOAD( "frogger.610",  0x1000, 0x0800, 0x31d7eb27 )

	ROM_REGION( 0x1000, REGION_GFX1, ROMREGION_DISPOSE )
	ROM_LOAD( "frogger.607",  0x0000, 0x0800, 0x05f7d883 )
	ROM_LOAD( "frogger.606",  0x0800, 0x0800, 0xf524ee30 )

	ROM_REGION( 0x0020, REGION_PROMS, 0 )
	ROM_LOAD( "pr-91.6l",     0x0000, 0x0020, 0x413703bf )
ROM_END

ROM_START( frogseg1 )
	ROM_REGION( 0x10000, REGION_CPU1, 0 )	/* 64k for code */
	ROM_LOAD( "frogger.26",   0x0000, 0x1000, 0x597696d6 )
	ROM_LOAD( "frogger.27",   0x1000, 0x1000, 0xb6e6fcc3 )
	ROM_LOAD( "frogger.34",   0x2000, 0x1000, 0xed866bab )

	ROM_REGION( 0x10000, REGION_CPU2, 0 )	/* 64k for the audio CPU */
	ROM_LOAD( "frogger.608",  0x0000, 0x0800, 0xe8ab0256 )
	ROM_LOAD( "frogger.609",  0x0800, 0x0800, 0x7380a48f )
	ROM_LOAD( "frogger.610",  0x1000, 0x0800, 0x31d7eb27 )

	ROM_REGION( 0x1000, REGION_GFX1, ROMREGION_DISPOSE )
	ROM_LOAD( "frogger.607",  0x0000, 0x0800, 0x05f7d883 )
	ROM_LOAD( "frogger.606",  0x0800, 0x0800, 0xf524ee30 )

	ROM_REGION( 0x0020, REGION_PROMS, 0 )
	ROM_LOAD( "pr-91.6l",     0x0000, 0x0020, 0x413703bf )
ROM_END

ROM_START( frogseg2 )
	ROM_REGION( 0x10000, REGION_CPU1, 0 )	/* 64k for code */
	ROM_LOAD( "frogger.ic5",  0x0000, 0x1000, 0xefab0c79 )
	ROM_LOAD( "frogger.ic6",  0x1000, 0x1000, 0xaeca9c13 )
	ROM_LOAD( "frogger.ic7",  0x2000, 0x1000, 0xdd251066 )
	ROM_LOAD( "frogger.ic8",  0x3000, 0x1000, 0xbf293a02 )

	ROM_REGION( 0x10000, REGION_CPU2, 0 )	/* 64k for the audio CPU */
	ROM_LOAD( "frogger.608",  0x0000, 0x0800, 0xe8ab0256 )
	ROM_LOAD( "frogger.609",  0x0800, 0x0800, 0x7380a48f )
	ROM_LOAD( "frogger.610",  0x1000, 0x0800, 0x31d7eb27 )

	ROM_REGION( 0x1000, REGION_GFX1, ROMREGION_DISPOSE )
	ROM_LOAD( "frogger.607",  0x0000, 0x0800, 0x05f7d883 )
	ROM_LOAD( "frogger.606",  0x0800, 0x0800, 0xf524ee30 )

	ROM_REGION( 0x0020, REGION_PROMS, 0 )
	ROM_LOAD( "pr-91.6l",     0x0000, 0x0020, 0x413703bf )
ROM_END



GAME( 1981, frogger,  0,	   frogger,  frogger,  frogger,  ROT90, "Konami", "Frogger" )
GAME( 1981, frogseg1, frogger, frogger,  frogger,  frogger,  ROT90, "[Konami] (Sega license)", "Frogger (Sega set 1)" )
GAME( 1981, frogseg2, frogger, frogger,  frogger,  frogger,  ROT90, "[Konami] (Sega license)", "Frogger (Sega set 2)" )
