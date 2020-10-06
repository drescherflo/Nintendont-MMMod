/*

Nintendont (Loader) - Playing Gamecubes in Wii mode on a Wii U

Copyright (C) 2020  send0r

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation version 2.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include <stdio.h>
#include <stdlib.h>
#include <asndlib.h>
#include <mp3player.h>

#include "global.h"

#include "bootanim_audio_mp3.h"
#include "gc0_jpg.h"
#include "gc1_jpg.h"
#include "gc2_jpg.h"
#include "gc3_jpg.h"
#include "gc4_jpg.h"
#include "gc5_jpg.h"
#include "gc6_jpg.h"
#include "gc7_jpg.h"
#include "gc8_jpg.h"
#include "gc9_jpg.h"
#include "gc10_jpg.h"
#include "gc11_jpg.h"
#include "gc12_jpg.h"
#include "gc13_jpg.h"
#include "gc14_jpg.h"
#include "gc15_jpg.h"
#include "gc16_jpg.h"
#include "gc17_jpg.h"
#include "gc18_jpg.h"
#include "gc19_jpg.h"
#include "gc20_jpg.h"
#include "gc21_jpg.h"
#include "gc22_jpg.h"
#include "gc23_jpg.h"
#include "gc24_jpg.h"
#include "gc25_jpg.h"
#include "gc26_jpg.h"
#include "gc27_jpg.h"
#include "gc28_jpg.h"
#include "gc29_jpg.h"
#include "gc30_jpg.h"
#include "gc31_jpg.h"
#include "gc32_jpg.h"
#include "gc33_jpg.h"
#include "gc34_jpg.h"
#include "gc35_jpg.h"
#include "gc36_jpg.h"
#include "gc37_jpg.h"
#include "gc38_jpg.h"
#include "gc39_jpg.h"
#include "gc40_jpg.h"
#include "gc41_jpg.h"
#include "gc42_jpg.h"
#include "gc43_jpg.h"
#include "gc44_jpg.h"
#include "gc45_jpg.h"
#include "gc46_jpg.h"
#include "gc47_jpg.h"
#include "gc48_jpg.h"
#include "gc49_jpg.h"
#include "gc50_jpg.h"
#include "gc51_jpg.h"
#include "gc52_jpg.h"
#include "gc53_jpg.h"
#include "gc54_jpg.h"
#include "gc55_jpg.h"
#include "gc56_jpg.h"
#include "gc57_jpg.h"
#include "gc58_jpg.h"
#include "gc59_jpg.h"
#include "gc60_jpg.h"
#include "gc61_jpg.h"
#include "gc62_jpg.h"
#include "gc63_jpg.h"
#include "gc64_jpg.h"
#include "gc65_jpg.h"
#include "gc66_jpg.h"
#include "gc67_jpg.h"
#include "gc68_jpg.h"
#include "gc69_jpg.h"
#include "gc70_jpg.h"
#include "gc71_jpg.h"
#include "gc72_jpg.h"
#include "gc73_jpg.h"
#include "gc74_jpg.h"
#include "gc75_jpg.h"
#include "gc76_jpg.h"
#include "gc77_jpg.h"
#include "gc78_jpg.h"
#include "gc79_jpg.h"
#include "gc80_jpg.h"
#include "gc81_jpg.h"
#include "gc82_jpg.h"
#include "gc83_jpg.h"
#include "gc84_jpg.h"
#include "gc85_jpg.h"
#include "gc86_jpg.h"
#include "gc87_jpg.h"
#include "gc88_jpg.h"
#include "gc89_jpg.h"
#include "gc90_jpg.h"
#include "gc91_jpg.h"
#include "gc92_jpg.h"
#include "gc93_jpg.h"
#include "gc94_jpg.h"
#include "gc95_jpg.h"
#include "gc96_jpg.h"
#include "gc97_jpg.h"
#include "gc98_jpg.h"
#include "gc99_jpg.h"
#include "gc100_jpg.h"
#include "gc101_jpg.h"
#include "gc102_jpg.h"
#include "gc103_jpg.h"
#include "gc104_jpg.h"
#include "gc105_jpg.h"
#include "gc106_jpg.h"
#include "gc107_jpg.h"
#include "gc108_jpg.h"
#include "gc109_jpg.h"
#include "gc110_jpg.h"
#include "gc111_jpg.h"
#include "gc112_jpg.h"
#include "gc113_jpg.h"
#include "gc114_jpg.h"
#include "gc115_jpg.h"
#include "gc116_jpg.h"
#include "gc117_jpg.h"
#include "gc118_jpg.h"
#include "gc119_png.h"
#include "gc120_png.h"
#include "gc121_png.h"
#include "gc122_png.h"
#include "gc123_png.h"
#include "gc124_png.h"
#include "gc125_png.h"
#include "gc126_png.h"
#include "gc127_png.h"
#include "gc128_png.h"
#include "gc129_png.h"
#include "gc130_png.h"
#include "gc131_png.h"
#include "gc132_png.h"
#include "gc133_png.h"
#include "gc134_png.h"
#include "gc135_png.h"
#include "gc136_png.h"
#include "gc137_png.h"
#include "gc138_png.h"
#include "gc139_png.h"
#include "gc140_png.h"
#include "gc141_png.h"
#include "gc142_png.h"
#include "gc143_png.h"
#include "gc144_png.h"
#include "gc145_png.h"
#include "gc146_png.h"
#include "gc147_png.h"
#include "gc148_png.h"
#include "gc149_png.h"
#include "gc150_png.h"
#include "gc151_png.h"
#include "gc152_jpg.h"

#include "mmmod_animation.h"

#define IMAGE_NAME_BUFFER_LENGTH 10

void play_bios_animation() 
{
    ASND_Init();
    MP3Player_Init();
    MP3Player_PlayBuffer(bootanim_audio_mp3, bootanim_audio_mp3_size, NULL);

    GRRLIB_texImg *animation_frame = NULL;
    char *image_name = calloc(IMAGE_NAME_BUFFER_LENGTH, sizeof(char));
    if (image_name == NULL) {
        ExitToLoader(-1);
    }

    GRRLIB_FillScreen(BLACK);

    int i = 0;
    for (; i <= 152; i++)
    {
        char *image_file_type = strndup(i <= 118 || i == 152 ? "jpg" : "png", 3);
        int ret = snprintf(image_name, IMAGE_NAME_BUFFER_LENGTH, "gc%d.%s", i, image_file_type);
        if (ret <= 0 || ret >= IMAGE_NAME_BUFFER_LENGTH)
        {
            ExitToLoader(-1);
        }

        if (animation_frame) {
            GRRLIB_FreeTexture(animation_frame);
        }

        animation_frame = GRRLIB_LoadTexture(gc0_jpg);
        if (animation_frame == NULL)
        {
            ExitToLoader(-1);
        }

        const int screen_width = (rmode->fbWidth - animation_frame->w) / 2;
        const int screen_height = (rmode->efbHeight - animation_frame->h) / 2 + 20;

        GRRLIB_DrawImg(screen_width, screen_height, animation_frame, 0, 1, 1, 0xFFFFFFFF);
        GRRLIB_Render();

        free(image_file_type);
    }

    const int screen_width = (rmode->fbWidth - animation_frame->w) / 2;
    const int screen_height = (rmode->efbHeight - animation_frame->h) / 2 + 20;

    for (i = 255; i > 0; i -= 10)
    {
        GRRLIB_DrawImg(screen_width, screen_height, animation_frame, 0, 1, 1, RGBA(255, 255, 255, i));
        GRRLIB_Render();
    }

    GRRLIB_FreeTexture(animation_frame);
    free(image_name);
}