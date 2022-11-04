/*
 *images.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */
#include "images.h"
//
//  Image data for ship
//

const uint8_t shipBitmaps[] = { 0x06, 0x00, //      ##
                                0x06, 0x00, //      ##
                                0x06, 0x00, //      ##
                                0x09, 0x00, //     #  #
                                0x39, 0xC0, //   ###  ###
                                0x29, 0x40, //   # #  # #
                                0xE0, 0x70, // ###      ###
                                0xA6, 0x50, // # #  ##  # #
                                0x80, 0x10, // #          #
                                0x99, 0x90, // #  ##  ##  #
                                0xBF, 0xD0, // # ######## #
                                0x46, 0x20, //  #   ##   #
        };

// Bitmap sizes for ship
const uint8_t shipWidthPixels = 12;
const uint8_t shipHeightPixels = 12;

//
//  Image data for bug1
//

const uint8_t bug1Bitmaps[] = { 0x02, 0x00, //       #
                                0x2F, 0xA0, //   # ##### #
                                0x1F, 0xC0, //    #######
                                0x0F, 0x80, //     #####
                                0x1F, 0xC0, //    #######
                                0x3F, 0xE0, //   #########
                                0x77, 0x70, //  ### ### ###
                                0xF7, 0x78, // #### ### ####
                                0xE7, 0x38, // ###  ###  ###
                                0xE2, 0x38, // ###   #   ###
        };

// Bitmap sizes for bug1
const uint8_t bug1WidthPixels = 13;
const uint8_t bug1HeightPixels = 10;

//
//  Image data for bug2
//

const uint8_t bug2Bitmaps[] = { 0x25, 0x20, //   #  # #  #
                                0xE5, 0x38, // ###  # #  ###
                                0xEF, 0xB8, // ### ##### ###
                                0xEF, 0xB8, // ### ##### ###
                                0x7F, 0xF0, //  ###########
                                0x3F, 0xE0, //   #########
                                0x7F, 0xF0, //  ###########
                                0xFF, 0xF8, // #############
                                0x77, 0x70, //  ### ### ###
                                0x10, 0x40, //    #     #
        };

// Bitmap sizes for bug2
const uint8_t bug2WidthPages = 12;
const uint8_t bug2HeightPixels = 10;

//
//  Image data for bug3
//

const uint8_t bug3Bitmaps[] = { 0x0A, 0x00, //     # #
                                0x0A, 0x00, //     # #
                                0x7F, 0xC0, //  #########
                                0x3F, 0x80, //   #######
                                0x1F, 0x00, //    #####
                                0x3F, 0x80, //   #######
                                0xFF, 0xE0, // ###########
                                0x7F, 0xC0, //  #########
                                0x6A, 0xC0, //  ## # # ##
                                0xE0, 0xE0, // ###     ###
                                0xE0, 0xE0, // ###     ###
                                0xE0, 0xE0, // ###     ###
                                0xC0, 0x60, // ##       ##
        };

// Bitmap sizes for bug3
const uint8_t bug3WidthPages = 11;
const uint8_t bug3HeightPixels = 13;

//
//  Image data for dart
//

const uint8_t dartBitmaps[] = { 0x20, //   #
        0x70, //  ###
        0xA8, // # # #
        0x20, //   #
        0x20, //   #
        };

// Bitmap sizes for dart
const uint8_t dartWidthPages = 3;
const uint8_t dartHeightPixels = 5;

//
//  Image data for zero
//

const uint8_t zeroBitmaps[] = { 0x00, 0xF0, 0x00, //         ####
                                0x07, 0xFE, 0x00, //      ##########
                                0x0F, 0xFF, 0x00, //     ############
                                0x1F, 0xFF, 0x80, //    ##############
                                0x3E, 0x07, 0xC0, //   #####      #####
                                0x38, 0x03, 0xC0, //   ###         ####
                                0x70, 0x01, 0xE0, //  ###           ####
                                0x70, 0x00, 0xE0, //  ###            ###
                                0x60, 0x00, 0xE0, //  ##             ###
                                0x60, 0x00, 0x70, //  ##              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0x60, 0x00, 0x60, //  ##              ##
                                0x70, 0x00, 0xE0, //  ###            ###
                                0x70, 0x00, 0xE0, //  ###            ###
                                0x78, 0x01, 0xC0, //  ####          ###
                                0x3C, 0x03, 0xC0, //   ####        ####
                                0x1F, 0x0F, 0x80, //    #####    #####
                                0x1F, 0xFF, 0x80, //    ##############
                                0x0F, 0xFE, 0x00, //     ###########
                                0x01, 0xF8, 0x00, //        ######
        };

// Bitmap sizes for zero
const uint8_t zeroWidthPixels = 20;
const uint8_t zeroHeightPixels = 30;

//
//  Image data for one
//

const uint8_t oneBitmaps[] = { 0x7E, //  ######
        0xFE, // #######
        0xFE, // #######
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x0E, //     ###
        0x04, //      #
        };

// Bitmap sizes for one
const uint8_t oneWidthPixels = 7;
const uint8_t oneHeightPixels = 30;

//
//  Image data for two
//

const uint8_t twoBitmaps[] = { 0x07, 0xFC, 0x00, //      #########
                               0x0F, 0xFF, 0x00, //     ############
                               0x1C, 0x0F, 0x00, //    ###      ####
                               0x38, 0x03, 0x80, //   ###         ###
                               0x30, 0x01, 0x80, //   ##           ##
                               0x30, 0x01, 0xC0, //   ##           ###
                               0x60, 0x00, 0xC0, //  ##             ##
                               0x00, 0x00, 0xC0, //                 ##
                               0x00, 0x00, 0xC0, //                 ##
                               0x00, 0x01, 0xC0, //                ###
                               0x00, 0x01, 0x80, //                ##
                               0x00, 0x03, 0x80, //               ###
                               0x00, 0x03, 0x00, //               ##
                               0x00, 0x07, 0x00, //              ###
                               0x00, 0x1E, 0x00, //            ####
                               0x00, 0x18, 0x00, //            ##
                               0x00, 0x30, 0x00, //           ##
                               0x00, 0x70, 0x00, //          ###
                               0x00, 0x60, 0x00, //          ##
                               0x00, 0xE0, 0x00, //         ###
                               0x01, 0xC0, 0x00, //        ###
                               0x07, 0x80, 0x00, //      ####
                               0x06, 0x00, 0x00, //      ##
                               0x0C, 0x00, 0x00, //     ##
                               0x1C, 0x00, 0x00, //    ###
                               0x3C, 0x00, 0x00, //   ####
                               0x3F, 0xFF, 0xC0, //   ################
                               0x7F, 0xFF, 0xC0, //  #################
                               0xFF, 0xFF, 0xC0, // ##################
        };

// Bitmap sizes for two
const uint8_t twoWidthPixels = 18;
const uint8_t twoHeightPixels = 29;

//
//  Image data for three
//

const uint8_t threeBitmaps[] = { 0x01, 0x80, //        ##
                                 0x0F, 0xF8, //     #########
                                 0x3F, 0xFC, //   ############
                                 0x3E, 0x7C, //   #####  #####
                                 0x78, 0x3E, //  ####     #####
                                 0x70, 0x0F, //  ###        ####
                                 0x60, 0x07, //  ##          ###
                                 0x60, 0x07, //  ##          ###
                                 0x00, 0x03, //               ##
                                 0x00, 0x07, //              ###
                                 0x00, 0x07, //              ###
                                 0x00, 0x0E, //             ###
                                 0x00, 0x1E, //            ####
                                 0x01, 0xFC, //        #######
                                 0x01, 0xF8, //        ######
                                 0x01, 0xFC, //        #######
                                 0x00, 0x3E, //           #####
                                 0x00, 0x0E, //             ###
                                 0x00, 0x0F, //             ####
                                 0x00, 0x07, //              ###
                                 0x00, 0x03, //               ##
                                 0x00, 0x03, //               ##
                                 0x40, 0x03, //  #            ##
                                 0xC0, 0x03, // ##            ##
                                 0xE0, 0x07, // ###          ###
                                 0x60, 0x07, //  ##          ###
                                 0x70, 0x0E, //  ###        ###
                                 0x7C, 0x3E, //  #####    #####
                                 0x3F, 0xFC, //   ############
                                 0x01, 0x80, //        ##
        };

// Bitmap sizes for three
const uint8_t threeWidthPixels = 16;
const uint8_t threeHeightPixels = 30;

//
//  Image data for four
//

const uint8_t fourBitmaps[] = { 0x00, 0x00, 0x40, //                  #
                                0x00, 0x00, 0x40, //                  #
                                0x00, 0x00, 0xC0, //                 ##
                                0x00, 0x01, 0xC0, //                ###
                                0x00, 0x03, 0xC0, //               ####
                                0x00, 0x03, 0xC0, //               ####
                                0x00, 0x07, 0xC0, //              #####
                                0x00, 0x0F, 0xC0, //             ######
                                0x00, 0x0E, 0xC0, //             ### ##
                                0x00, 0x1C, 0xC0, //            ###  ##
                                0x00, 0x38, 0xC0, //           ###   ##
                                0x00, 0x70, 0xC0, //          ###    ##
                                0x00, 0x60, 0xC0, //          ##     ##
                                0x00, 0xE0, 0xC0, //         ###     ##
                                0x01, 0xC0, 0xC0, //        ###      ##
                                0x03, 0x80, 0xC0, //       ###       ##
                                0x07, 0x00, 0xC0, //      ###        ##
                                0x06, 0x00, 0xC0, //      ##         ##
                                0x0E, 0x00, 0xC0, //     ###         ##
                                0x1C, 0x00, 0xC0, //    ###          ##
                                0x38, 0x00, 0xC0, //   ###           ##
                                0x38, 0x00, 0xC0, //   ###           ##
                                0x7F, 0xFF, 0xFC, //  #####################
                                0xFF, 0xFF, 0xFC, // ######################
                                0x00, 0x03, 0xF8, //               #######
                                0x00, 0x00, 0xC0, //                 ##
                                0x00, 0x00, 0xC0, //                 ##
                                0x00, 0x00, 0xC0, //                 ##
                                0x00, 0x00, 0xC0, //                 ##
                                0x00, 0x00, 0xC0, //                 ##
        };

// Bitmap sizes for four
const uint8_t fourWidthPixels = 22;
const uint8_t fourHeightPixels = 30;

//
//  Image data for five
//

const uint8_t fiveBitmaps[] = { 0x07, 0xF8, //      ########
                                0x0F, 0xF8, //     #########
                                0x0C, 0x00, //     ##
                                0x08, 0x00, //     #
                                0x08, 0x00, //     #
                                0x18, 0x00, //    ##
                                0x18, 0x00, //    ##
                                0x1F, 0xE0, //    ########
                                0x1D, 0xF0, //    ### #####
                                0x00, 0x18, //            ##
                                0x00, 0x0C, //             ##
                                0x00, 0x04, //              #
                                0x00, 0x06, //              ##
                                0x00, 0x06, //              ##
                                0x00, 0x02, //               #
                                0x00, 0x02, //               #
                                0x00, 0x06, //              ##
                                0x00, 0x04, //              #
                                0x80, 0x0C, // #           ##
                                0xC0, 0x08, // ##          #
                                0x60, 0x38, //  ##       ###
                                0x3F, 0xF0, //   ##########
                                0x0F, 0xC0, //     ######
        };

// Bitmap sizes for five
const uint8_t fiveWidthPixels = 15;
const uint8_t fiveHeightPixels = 23;

//
//  Image data for six
//

const uint8_t sixBitmaps[] = { 0x00, 0x60, 0x00, //          ##
                               0x00, 0xE0, 0x00, //         ###
                               0x00, 0xC0, 0x00, //         ##
                               0x01, 0x80, 0x00, //        ##
                               0x03, 0x00, 0x00, //       ##
                               0x07, 0x00, 0x00, //      ###
                               0x06, 0x00, 0x00, //      ##
                               0x0C, 0x00, 0x00, //     ##
                               0x1F, 0xF0, 0x00, //    #########
                               0x3F, 0xFC, 0x00, //   ############
                               0x3C, 0x1E, 0x00, //   ####     ####
                               0x70, 0x07, 0x00, //  ###         ###
                               0x60, 0x03, 0x00, //  ##           ##
                               0xC0, 0x01, 0x80, // ##             ##
                               0xC0, 0x01, 0x80, // ##             ##
                               0x80, 0x00, 0x80, // #               #
                               0x80, 0x00, 0x80, // #               #
                               0x80, 0x00, 0x80, // #               #
                               0x80, 0x00, 0x80, // #               #
                               0xC0, 0x01, 0x80, // ##             ##
                               0xC0, 0x01, 0x00, // ##             #
                               0x60, 0x03, 0x00, //  ##           ##
                               0x70, 0x06, 0x00, //  ###         ##
                               0x3E, 0x3C, 0x00, //   #####   ####
                               0x0F, 0xF8, 0x00, //     #########
                               0x01, 0xC0, 0x00, //        ###
        };

// Bitmap sizes for six
const uint8_t sixWidthPixels = 17;
const uint8_t sixHeightPixels = 26;

//
//  Image data for seven
//

const uint8_t sevenBitmaps[] = { 0xFF, 0xFF, 0xC0, // ##################
                                 0xFF, 0xFF, 0x80, // #################
                                 0x00, 0x03, 0x80, //               ###
                                 0x00, 0x03, 0x00, //               ##
                                 0x00, 0x06, 0x00, //              ##
                                 0x00, 0x06, 0x00, //              ##
                                 0x00, 0x0C, 0x00, //             ##
                                 0x00, 0x18, 0x00, //            ##
                                 0x00, 0x18, 0x00, //            ##
                                 0x00, 0x30, 0x00, //           ##
                                 0x00, 0x60, 0x00, //          ##
                                 0x00, 0x60, 0x00, //          ##
                                 0x00, 0xC0, 0x00, //         ##
                                 0x01, 0x80, 0x00, //        ##
                                 0x01, 0x80, 0x00, //        ##
                                 0x03, 0x00, 0x00, //       ##
                                 0x06, 0x00, 0x00, //      ##
                                 0x06, 0x00, 0x00, //      ##
                                 0x0C, 0x00, 0x00, //     ##
                                 0x18, 0x00, 0x00, //    ##
                                 0x38, 0x00, 0x00, //   ###
                                 0x30, 0x00, 0x00, //   ##
                                 0x60, 0x00, 0x00, //  ##
                                 0xC0, 0x00, 0x00, // ##
                                 0xC0, 0x00, 0x00, // ##
        };

// Bitmap sizes for seven
const uint8_t sevenWidthPixels = 18;
const uint8_t sevenHeightPixels = 25;

//
//  Image data for eight
//

const uint8_t eightBitmaps[] = { 0x03, 0xE0, 0x00, //       #####
                                 0x0F, 0xF8, 0x00, //     #########
                                 0x1F, 0xFC, 0x00, //    ###########
                                 0x3C, 0x1E, 0x00, //   ####     ####
                                 0x30, 0x0E, 0x00, //   ##        ###
                                 0x70, 0x07, 0x00, //  ###         ###
                                 0x60, 0x03, 0x00, //  ##           ##
                                 0x60, 0x03, 0x00, //  ##           ##
                                 0x60, 0x03, 0x00, //  ##           ##
                                 0x60, 0x03, 0x00, //  ##           ##
                                 0x60, 0x03, 0x00, //  ##           ##
                                 0x70, 0x07, 0x00, //  ###         ###
                                 0x30, 0x0E, 0x00, //   ##        ###
                                 0x3C, 0x1C, 0x00, //   ####     ###
                                 0x1F, 0xFC, 0x00, //    ###########
                                 0x0F, 0xF8, 0x00, //     #########
                                 0x1F, 0xFC, 0x00, //    ###########
                                 0x38, 0x1E, 0x00, //   ###      ####
                                 0x70, 0x07, 0x00, //  ###         ###
                                 0xE0, 0x03, 0x80, // ###           ###
                                 0xC0, 0x01, 0x80, // ##             ##
                                 0xC0, 0x01, 0x80, // ##             ##
                                 0xC0, 0x01, 0x80, // ##             ##
                                 0x80, 0x01, 0x80, // #              ##
                                 0xC0, 0x01, 0x80, // ##             ##
                                 0xC0, 0x01, 0x80, // ##             ##
                                 0xC0, 0x01, 0x80, // ##             ##
                                 0xE0, 0x03, 0x00, // ###           ##
                                 0x70, 0x07, 0x00, //  ###         ###
                                 0x38, 0x0E, 0x00, //   ###       ###
                                 0x1F, 0xFC, 0x00, //    ###########
                                 0x0F, 0xF8, 0x00, //     #########
                                 0x01, 0x80, 0x00, //        ##
        };

// Bitmap sizes for eight
const uint8_t eightWidthPixels = 17;
const uint8_t eightHeightPixels = 33;

//
//  Image data for nine
//

const uint8_t nineBitmaps[] = { 0x00, 0xF0, 0x00, //         ####
                                0x07, 0xFE, 0x00, //      ##########
                                0x0F, 0xFF, 0x80, //     #############
                                0x3E, 0x07, 0xC0, //   #####      #####
                                0x38, 0x01, 0xE0, //   ###          ####
                                0x70, 0x00, 0xE0, //  ###            ###
                                0xE0, 0x00, 0x70, // ###              ###
                                0xC0, 0x00, 0x30, // ##                ##
                                0xC0, 0x00, 0x30, // ##                ##
                                0xC0, 0x00, 0x38, // ##                ###
                                0x80, 0x00, 0x18, // #                  ##
                                0x80, 0x00, 0x18, // #                  ##
                                0xC0, 0x00, 0x10, // ##                 #
                                0xC0, 0x00, 0x30, // ##                ##
                                0xC0, 0x00, 0x30, // ##                ##
                                0xE0, 0x00, 0x70, // ###              ###
                                0x70, 0x00, 0x60, //  ###             ##
                                0x38, 0x01, 0xE0, //   ###          ####
                                0x3E, 0x07, 0xC0, //   #####      #####
                                0x0F, 0xFF, 0x80, //     #############
                                0x07, 0xFF, 0x80, //      ############
                                0x00, 0x7F, 0x00, //          #######
                                0x00, 0x0E, 0x00, //             ###
                                0x00, 0x0C, 0x00, //             ##
                                0x00, 0x1C, 0x00, //            ###
                                0x00, 0x38, 0x00, //           ###
                                0x00, 0x70, 0x00, //          ###
                                0x00, 0x60, 0x00, //          ##
                                0x00, 0xC0, 0x00, //         ##
                                0x01, 0xC0, 0x00, //        ###
                                0x03, 0x80, 0x00, //       ###
                                0x01, 0x00, 0x00, //        #
        };

// Bitmap sizes for nine
const uint8_t nineWidthPixels = 21;
const uint8_t nineHeightPixels = 32;

//
//  Image data for score
//

const uint8_t scoreBitmaps[] = { 0x3E, 0x03, 0xE0, 0x3E, 0x06, 0x70, 0x78, //   #####       #####       #####      ##  ###     ####
                                 0x7F, 0x07, 0xF0, 0xFF, 0x07, 0xF1, 0xFE, //  #######     #######    ########     #######   ########
                                 0x60, 0x0E, 0x11, 0xC3, 0x87, 0x83, 0x86, //  ##         ###    #   ###    ###    ####     ###    ##
                                 0xC0, 0x0C, 0x01, 0x81, 0xC7, 0x03, 0x03, // ##          ##         ##      ###   ###      ##      ##
                                 0x60, 0x1C, 0x03, 0x80, 0xC6, 0x03, 0x03, //  ##        ###        ###       ##   ##       ##      ##
                                 0x78, 0x18, 0x03, 0x00, 0xC6, 0x07, 0xFF, //  ####      ##         ##        ##   ##      ###########
                                 0x3E, 0x18, 0x03, 0x00, 0xC6, 0x07, 0xFF, //   #####    ##         ##        ##   ##      ###########
                                 0x07, 0x18, 0x03, 0x00, 0xC6, 0x06, 0x00, //      ###   ##         ##        ##   ##      ##
                                 0x03, 0x1C, 0x03, 0x80, 0xC6, 0x07, 0x00, //       ##   ###        ###       ##   ##      ###
                                 0x03, 0x0C, 0x01, 0x81, 0x86, 0x03, 0x00, //       ##    ##         ##      ##    ##       ##
                                 0x83, 0x0E, 0x11, 0xC3, 0x86, 0x03, 0x80, // #     ##    ###    #   ###    ###    ##       ###
                                 0xFF, 0x07, 0xF0, 0xFF, 0x06, 0x01, 0xFF, // ########     #######    ########     ##        #########
                                 0x7C, 0x03, 0xE0, 0x7E, 0x06, 0x00, 0x7C, //  #####        #####      ######      ##          #####
        };

// Bitmap sizes for score
const uint8_t scoreWidthPixels = 90;
const uint8_t scoreHeightPixels = 13;
