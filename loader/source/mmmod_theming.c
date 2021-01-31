/*

Nintendont (Loader) - Playing Gamecubes in Wii mode on a Wii U

Copyright (C) 2021  drescherflo (send0r)

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
#include <string.h>
#include <sys/param.h>

#include "global.h"
#include "ff_utf8.h"

#include "mmmod_theming.h"

extern char launch_dir[MAXPATHLEN];
void load_text_color()
{
    char *color_ini_path = (char *) calloc(MAXPATHLEN, sizeof(char));
    if (color_ini_path == NULL)
    {
        // calloc failed
        return;
    }

    bool launch_dir_exists = strnlen(launch_dir, MAXPATHLEN);
    snprintf(color_ini_path, MAXPATHLEN, "%stextcolor.ini", launch_dir_exists ? launch_dir : "/apps/Nintendont/");

    FIL color_ini_file;
    FRESULT f_op_result = f_open_char(&color_ini_file, color_ini_path, FA_READ);
    if (f_op_result != FR_OK)
    {
        // textcolor.ini could not be opened
        free(color_ini_path);
        return;
    }

    char *read_color = (char *) calloc(7, sizeof(char)); // 6 characters for RGB and 1 for null terminator
    if (read_color == NULL)
    {
        // calloc failed
        free(color_ini_path);
        return;
    }

    UINT read;
    f_op_result = f_read(&color_ini_file, read_color, 6, &read);
    if (f_op_result != FR_OK && read != 6)
    {
        // read not successful
        free(read_color);
        free(color_ini_path);
        return;
    }

    // convert RGB string to number and append 0xFF as A-value of RGBA
    text_color = (((unsigned int) strtoul(read_color, NULL, 16)) << 8) + 0xFF;

    free(read_color);
    free(color_ini_path);
}
