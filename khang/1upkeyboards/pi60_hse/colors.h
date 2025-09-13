#include "quantum/rgblight/rgblight.h"

#pragma once

#define ONE(i, hue, lum) {i, 1, hue, 255, lum}

const rgblight_segment_t PROGMEM NO_RGB[] =
    RGBLIGHT_LAYER_SEGMENTS({0, 16, 0, 0, 0});

/*
const rgblight_segment_t PROGMEM BASE_RGB[] = RGBLIGHT_LAYER_SEGMENTS( //
ONE(0x0, 190, 180),
ONE(0x1, 196, 180),
ONE(0x2, 202, 181),
ONE(0x3, 208, 181),
ONE(0x4, 214, 182),
ONE(0x5, 220, 182),
ONE(0x6, 226, 183),
ONE(0x7, 232, 183),
ONE(0x8, 6, 184),
ONE(0x9, 8, 184),
ONE(0xA, 11, 185),
ONE(0xB, 13, 185),
ONE(0xC, 16, 186),
ONE(0xD, 18, 186),
ONE(0xE, 21, 187),
ONE(0xF, 23, 187));
*/

#define Z(n) {n, 1, HUE(n), SAT(n), LUM(n)}

#define HUE(n) 100 + 2 * n
#define SAT(n) 255
#define LUM(n) 120
const rgblight_segment_t PROGMEM FUNC_RGB[] = RGBLIGHT_LAYER_SEGMENTS(Z(0x0),
                                                                      Z(0x1),
                                                                      Z(0x2),
                                                                      Z(0x3),
                                                                      Z(0x4),
                                                                      Z(0x5),
                                                                      Z(0x6),
                                                                      Z(0x7),
                                                                      Z(0x8),
                                                                      Z(0x9),
                                                                      Z(0xA),
                                                                      Z(0xB),
                                                                      Z(0xC),
                                                                      Z(0xD),
                                                                      Z(0xE),
                                                                      Z(0xF));
#undef HUE
#undef SAT
#undef LUM

#define HUE(n) (240 + 2 * n) % 256
#define SAT(n) 255
#define LUM(n) 180
const rgblight_segment_t PROGMEM DANGER_RGB[] = RGBLIGHT_LAYER_SEGMENTS(Z(0x0),
                                                                        Z(0x1),
                                                                        Z(0x2),
                                                                        Z(0x3),
                                                                        Z(0x4),
                                                                        Z(0x5),
                                                                        Z(0x6),
                                                                        Z(0x7),
                                                                        Z(0x8),
                                                                        Z(0x9),
                                                                        Z(0xA),
                                                                        Z(0xB),
                                                                        Z(0xC),
                                                                        Z(0xD),
                                                                        Z(0xE),
                                                                        Z(0xF));

#undef HUE
#undef SAT
#undef LUM

#undef Z
