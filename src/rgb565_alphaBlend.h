//
// Created by Moolet on 03/02/2021.
//
#ifndef RGB565_colors_ALPHABLENDRGB565_H
#define RGB565_colors_ALPHABLENDRGB565_H
//copied from https://stackoverflow.com/a/50012418
int16_t RGB565_alphaBlend( uint32_t fg, uint32_t bg, uint8_t alpha )
{
    alpha = ( alpha + 4 ) >> 3; // from 0-255 to 0-31
    bg = (bg | (bg << 16)) & 0b00000111111000001111100000011111;
    fg = (fg | (fg << 16)) & 0b00000111111000001111100000011111;
    uint32_t result = ((((fg - bg) * alpha) >> 5) + bg) & 0b00000111111000001111100000011111;
    return (uint16_t)((result >> 16) | result); // contract result
}

#endif //MULTIPLE_ALPHABLENDRGB565_H
