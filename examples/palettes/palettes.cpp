#include <ST7735_t3.h> // Hardware-specific library
#include "rgb565_colors.h"
#include "rgb565_alphaBlend.h"

#ifdef BUILD_FOR_OPENGL_EMULATOR
#include "st7735_opengl.h"
st7735_opengl tft = st7735_opengl(true, 10);
void my_yield() {
    if(!tft.shouldClose()) {
        tft.updateScreen();
    }
}
#else
#define TFT_CS   6  // CS & DC can use pins 2, 6, 9, 10, 15, 20, 21, 22, 23
#define TFT_DC    2  //  but certain pairs must NOT be used: 2+10, 6+9, 20+23, 21+22
#define TFT_RST   255 // RST can use any pin
ST7735_t3 tft = ST7735_t3(TFT_CS, TFT_DC, TFT_RST);
#endif


// https://en.wikipedia.org/wiki/List_of_colors_by_shade
uint16_t green_shades[113] = {
        RGB565_Acid_green,                   RGB565_Android_green,                RGB565_Apple_green,                  RGB565_Artichoke_green_pantone,
        RGB565_Blue_green_color_wheel,       RGB565_Bottle_green,                 RGB565_Bright_green,                 RGB565_British_racing_green,
        RGB565_Brunswick_green,              RGB565_Bud_green,                    RGB565_Cadmium_green,                RGB565_Caribbean_green,
        RGB565_Castleton_green,              RGB565_Celadon,                      RGB565_Celadon_green,                RGB565_Dark_green,
        RGB565_Dark_green_x11,               RGB565_Dark_jungle_green,            RGB565_Dark_moss_green,              RGB565_Dark_olive_green,
        RGB565_Dark_pastel_green,            RGB565_Dark_sea_green,               RGB565_Dark_spring_green,            RGB565_Dartmouth_green,
        RGB565_Deep_jungle_green,            RGB565_Electric_green,               RGB565_English_green,                RGB565_Erin,
        RGB565_Fern,                         RGB565_Fern_green,                   RGB565_Forest_green,                 RGB565_Forest_green_crayola,
        RGB565_Forest_green_traditional,     RGB565_Forest_green_web,             RGB565_Go_green,                     RGB565_Green,
        RGB565_Green_blue_crayola,           RGB565_Green_crayola,                RGB565_Green_cyan,                   RGB565_Green_htmlcss_color,
        RGB565_Green_lizard,                 RGB565_Green_munsell,                RGB565_Green_ncs,                    RGB565_Green_pantone,
        RGB565_Green_pigment,                RGB565_Green_ryb,                    RGB565_Green_sheen,                  RGB565_Green_web,
        RGB565_Green_x11_color_wheel,        RGB565_Green_yellow,                 RGB565_Green_yellow_crayola,         RGB565_Harlequin,
        RGB565_Honeydew,                     RGB565_Hookers_green,                RGB565_Hunter_green,                 RGB565_India_green,
        RGB565_Islamic_green,                RGB565_Jungle_green,                 RGB565_Kelly_green,                  RGB565_Kombu_green,
        RGB565_Laurel_green,                 RGB565_Lawn_green,                   RGB565_Light_green,                  RGB565_Lime_green,
        RGB565_Lime_web_x11_green,           RGB565_Lincoln_green,                RGB565_Mantis,                       RGB565_Maximum_blue_green,
        RGB565_Maximum_green,                RGB565_Maximum_green_yellow,         RGB565_May_green,                    RGB565_Medium_sea_green,
        RGB565_Medium_spring_green,          RGB565_Middle_blue_green,            RGB565_Middle_green,                 RGB565_Middle_green_yellow,
        RGB565_Midnight_green_eagle_green,   RGB565_Mint_green,                   RGB565_Moss_green,                   RGB565_Msu_green,
        RGB565_Ndhu_green,                   RGB565_Neon_green,                   RGB565_Ocean_green,                  RGB565_Olive_green,
        RGB565_Pakistan_green,               RGB565_Pale_green,                   RGB565_Paolo_veronese_green,         RGB565_Paris_green,
        RGB565_Persian_green,                RGB565_Phthalo_green,                RGB565_Rifle_green,                  RGB565_Russian_green,
        RGB565_Sacramento_state_green,       RGB565_Sap_green,                    RGB565_Screamin_green,               RGB565_Sea_green,
        RGB565_Sea_green_crayola,            RGB565_Sgbus_green,                  RGB565_Shamrock_green,               RGB565_Sheen_green,
        RGB565_Slimy_green,                  RGB565_Spanish_green,                RGB565_Spring_green,                 RGB565_Spring_green_crayola,
        RGB565_Tea_green,                    RGB565_Turquoise_green,              RGB565_Turtle_green,                 RGB565_Up_forest_green,
        RGB565_Viridian_green,               RGB565_Wintergreen_dream,            RGB565_Yellow_green,                 RGB565_Yellow_green_color_wheel,
        RGB565_Yellow_green_crayola          };

string green_shade_names[113] = {
        "Acid green",                            "Android green",                         "Apple green",                           "Artichoke green (Pantone)",
        "Blue-green (color wheel)",              "Bottle green",                          "Bright green",                          "British racing green",
        "Brunswick green",                       "Bud green",                             "Cadmium green",                         "Caribbean green",
        "Castleton green",                       "Celadon",                               "Celadon green",                         "Dark green",
        "Dark green (X11)",                      "Dark jungle green",                     "Dark moss green",                       "Dark olive green",
        "Dark pastel green",                     "Dark sea green",                        "Dark spring green",                     "Dartmouth green",
        "Deep jungle green",                     "Electric green",                        "English green",                         "Erin",
        "Fern",                                  "Fern green",                            "Forest green",                          "Forest green (Crayola)",
        "Forest green (traditional)",            "Forest green (web)",                    "GO green",                              "Green",
        "Green-blue (Crayola)",                  "Green (Crayola)",                       "Green-cyan",                            "Green (HTML/CSS color)",
        "Green Lizard",                          "Green (Munsell)",                       "Green (NCS)",                           "Green (Pantone)",
        "Green (pigment)",                       "Green (RYB)",                           "Green Sheen",                           "Green (web)",
        "Green (X11, color wheel)",              "Green-yellow",                          "Green-yellow (Crayola)",                "Harlequin",
        "Honeydew",                              "Hookers green",                         "Hunter green",                          "India green",
        "Islamic green",                         "Jungle green",                          "Kelly green",                           "Kombu green",
        "Laurel green",                          "Lawn green",                            "Light green",                           "Lime Green",
        "Lime (web) (X11 green)",                "Lincoln green",                         "Mantis",                                "Maximum blue green",
        "Maximum green",                         "Maximum green yellow",                  "May green",                             "Medium sea green",
        "Medium spring green",                   "Middle blue green",                     "Middle green",                          "Middle green yellow",
        "Midnight green (eagle green)",          "Mint green",                            "Moss green",                            "MSU green",
        "NDHU green",                            "Neon green",                            "Ocean green",                           "Olive green",
        "Pakistan green",                        "Pale green",                            "Paolo Veronese green",                  "Paris Green",
        "Persian green",                         "Phthalo green",                         "Rifle green",                           "Russian green",
        "Sacramento State green",                "Sap green",                             "Screamin Green",                        "Sea green",
        "Sea green (Crayola)",                   "SGBUS green",                           "Shamrock green",                        "Sheen green",
        "Slimy green",                           "Spanish green",                         "Spring green",                          "Spring green (Crayola)",
        "Tea green",                             "Turquoise green",                       "Turtle green",                          "UP Forest green",
        "Viridian green",                        "Wintergreen Dream",                     "Yellow-green",                          "Yellow-green (Color Wheel)",
        "Yellow-green (Crayola)"                 };

uint16_t blue_shades[123] = {
        RGB565_Aero_blue,                    RGB565_Air_superiority_blue,         RGB565_Argentinian_blue,             RGB565_Baby_blue,
        RGB565_Baby_blue_eyes,               RGB565_Bdazzled_blue,                RGB565_Beau_blue,                    RGB565_Berkeley_blue,
        RGB565_Bleu_de_france,               RGB565_Blizzard_blue,                RGB565_Blue,                         RGB565_Blue_bell,
        RGB565_Blue_cmyk_pigment_blue,       RGB565_Blue_computer_web_color,      RGB565_Blue_crayola,                 RGB565_Blue_green_color_wheel,
        RGB565_Blue_jeans,                   RGB565_Blue_munsell,                 RGB565_Blue_ncs,                     RGB565_Blue_pantone,
        RGB565_Blue_pigment,                 RGB565_Blue_ryb,                     RGB565_Blue_sapphire,                RGB565_Blue_violet,
        RGB565_Blue_violet_color_wheel,      RGB565_Blue_violet_crayola,          RGB565_Blue_yonder,                  RGB565_Bluetiful,
        RGB565_Bright_navy_blue,             RGB565_Cadet_blue,                   RGB565_Cadet_blue_crayola,           RGB565_Cambridge_blue,
        RGB565_Carolina_blue,                RGB565_Celadon_blue,                 RGB565_Celtic_blue,                  RGB565_Cerulean_blue,
        RGB565_Cg_blue,                      RGB565_Chefchaouen_blue,             RGB565_Cobalt_blue,                  RGB565_Dark_blue,
        RGB565_Dark_blue_gray,               RGB565_Dark_cornflower_blue,         RGB565_Dark_electric_blue,           RGB565_Dark_sky_blue,
        RGB565_Dark_slate_blue,              RGB565_Delft_blue,                   RGB565_Denim_blue,                   RGB565_Duck_blue,
        RGB565_Duke_blue,                    RGB565_Egyptian_blue,                RGB565_Eton_blue,                    RGB565_Fluorescent_blue,
        RGB565_French_sky_blue,              RGB565_Green_blue_crayola,           RGB565_Han_blue,                     RGB565_Ice_blue,
        RGB565_Independence,                 RGB565_International_klein_blue,     RGB565_Italian_sky_blue,             RGB565_Lavender_blue,
        RGB565_Liberty,                      RGB565_Light_blue,                   RGB565_Light_cornflower_blue,        RGB565_Light_steel_blue,
        RGB565_Little_boy_blue,              RGB565_Majorelle_blue,               RGB565_Maximum_blue,                 RGB565_Maximum_blue_green,
        RGB565_Maximum_blue_purple,          RGB565_Medium_blue,                  RGB565_Medium_slate_blue,            RGB565_Middle_blue,
        RGB565_Middle_blue_green,            RGB565_Middle_blue_purple,           RGB565_Midnight_blue,                RGB565_Morning_blue,
        RGB565_Navy_blue,                    RGB565_Navy_blue_crayola,            RGB565_Neon_blue,                    RGB565_Non_photo_blue,
        RGB565_Ocean_blue,                   RGB565_Oxford_blue,                  RGB565_Pacific_blue,                 RGB565_Periwinkle,
        RGB565_Persian_blue,                 RGB565_Pewter_blue,                  RGB565_Phthalo_blue,                 RGB565_Picotee_blue,
        RGB565_Polynesian_blue,              RGB565_Powder_blue,                  RGB565_Prussian_blue,                RGB565_Queen_blue,
        RGB565_Resolution_blue,              RGB565_Royal_blue_dark,              RGB565_Royal_blue_light,             RGB565_Ruddy_blue,
        RGB565_Sapphire,                     RGB565_Sapphire_blue,                RGB565_Savoy_blue,                   RGB565_Shadow_blue,
        RGB565_Slate_blue,                   RGB565_Space_cadet,                  RGB565_Spanish_blue,                 RGB565_Spanish_sky_blue,
        RGB565_St_patricks_blue,             RGB565_Star_command_blue,            RGB565_Teal,                         RGB565_Teal_blue,
        RGB565_Trypan_blue,                  RGB565_Turquoise_blue,               RGB565_Ua_blue,                      RGB565_Ultramarine,
        RGB565_Ultramarine_blue,             RGB565_University_of_pennsylvania_blue,RGB565_Uranian_blue,                 RGB565_Usafa_blue,
        RGB565_Violet_blue,                  RGB565_Violet_blue_crayola,          RGB565_Vivid_sky_blue,               RGB565_Wild_blue_yonder,
        RGB565_Yale_blue,                    RGB565_Yale_blue_site_blue,          RGB565_Yinmn_blue                    };

string blue_shade_names[123] = {
        "Aero blue",                             "Air superiority blue",                  "Argentinian Blue",                      "Baby Blue",
        "Baby blue eyes",                        "Bdazzled blue",                         "Beau blue",                             "Berkeley Blue",
        "Bleu de France",                        "Blizzard blue",                         "Blue",                                  "Blue bell",
        "Blue (CMYK) (pigment blue)",            "Blue (Computer web color)",             "Blue (Crayola)",                        "Blue-green (color wheel)",
        "Blue jeans",                            "Blue (Munsell)",                        "Blue (NCS)",                            "Blue (Pantone)",
        "Blue (pigment)",                        "Blue (RYB)",                            "Blue sapphire",                         "Blue-violet",
        "Blue-violet (color wheel)",             "Blue-violet (Crayola)",                 "Blue yonder",                           "Bluetiful",
        "Bright navy blue",                      "Cadet blue",                            "Cadet blue (Crayola)",                  "Cambridge blue",
        "Carolina blue",                         "Celadon blue",                          "Celtic Blue",                           "Cerulean blue",
        "CG blue",                               "Chefchaouen Blue",                      "Cobalt blue",                           "Dark Blue",
        "Dark blue-gray",                        "Dark cornflower blue",                  "Dark electric blue",                    "Dark sky blue",
        "Dark slate blue",                       "Delft Blue",                            "Denim blue",                            "Duck Blue",
        "Duke blue",                             "Egyptian Blue",                         "Eton blue",                             "Fluorescent blue",
        "French sky blue",                       "Green-blue (Crayola)",                  "Han blue",                              "Ice Blue",
        "Independence",                          "International Klein Blue",              "Italian sky blue",                      "Lavender blue",
        "Liberty",                               "Light blue",                            "Light cornflower blue",                 "Light steel blue",
        "Little boy blue",                       "Majorelle blue",                        "Maximum blue",                          "Maximum blue green",
        "Maximum blue purple",                   "Medium Blue",                           "Medium slate blue",                     "Middle blue",
        "Middle blue green",                     "Middle blue purple",                    "Midnight Blue",                         "Morning blue",
        "Navy Blue",                             "Navy blue (Crayola)",                   "Neon Blue",                             "Non-photo blue",
        "Ocean Blue",                            "Oxford blue",                           "Pacific blue",                          "Periwinkle",
        "Persian blue",                          "Pewter Blue",                           "Phthalo blue",                          "Picotee Blue",
        "Polynesian Blue",                       "Powder Blue",                           "Prussian blue",                         "Queen blue",
        "Resolution Blue",                       "Royal blue (dark)",                     "Royal blue (light)",                    "Ruddy Blue",
        "Sapphire",                              "Sapphire blue",                         "Savoy blue",                            "Shadow blue",
        "Slate blue",                            "Space Cadet",                           "Spanish Blue",                          "Spanish sky blue",
        "St. Patricks blue",                     "Star command blue",                     "Teal",                                  "Teal blue",
        "Trypan Blue",                           "Turquoise blue",                        "UA blue",                               "Ultramarine",
        "Ultramarine blue",                      "University of Pennsylvania Blue",       "Uranian Blue",                          "USAFA blue",
        "Violet-blue",                           "Violet-blue (Crayola)",                 "Vivid sky blue",                        "Wild blue yonder",
        "Yale Blue",                             "Yale \"Blue Site\" Blue",               "YInMn Blue"                             };

uint16_t magenta_shades[27] = {
        RGB565_African_violet,               RGB565_Amaranth_purple,              RGB565_Chinese_violet,               RGB565_Dark_magenta,
        RGB565_English_violet,               RGB565_Hot_magenta,                  RGB565_Magenta,                      RGB565_Magenta_additive_secondary,
        RGB565_Magenta_crayola,              RGB565_Magenta_dye,                  RGB565_Magenta_haze,                 RGB565_Magenta_pantone,
        RGB565_Magenta_process,              RGB565_Magenta_subtractive_primary,  RGB565_Orchid,                       RGB565_Plum_crayola,
        RGB565_Purple_pizzazz,               RGB565_Quinacridone_magenta,         RGB565_Razzle_dazzle_rose,           RGB565_Rose_quartz,
        RGB565_Shocking_pink,                RGB565_Shocking_pink_crayola_formerly_known_as_ultra_pink,RGB565_Sky_magenta,                  RGB565_Steel_pink,
        RGB565_Telemagenta,                  RGB565_Violet_jtc,                   RGB565_Violet_web_color              };

string magenta_shade_names[27] = {
        "African Violet",                        "Amaranth purple",                       "Chinese Violet",                        "Dark Magenta",
        "English Violet",                        "Hot Magenta",                           "Magenta",                               "Magenta (additive secondary)",
        "Magenta (Crayola)",                     "Magenta dye",                           "Magenta Haze",                          "Magenta (Pantone)",
        "Magenta (process)",                     "Magenta (subtractive primary)",         "Orchid",                                "Plum (Crayola)",
        "Purple Pizzazz",                        "Quinacridone Magenta",                  "Razzle dazzle rose",                    "Rose quartz",
        "Shocking Pink",                         "Shocking Pink (Crayola), formerly known as Ultra Pink","Sky Magenta",                           "Steel Pink",
        "Telemagenta",                           "Violet (JTC)",                          "Violet (web color)"                     };

uint16_t violet_shades[32] = {
        RGB565_African_violet,               RGB565_Blue_violet,                  RGB565_Blue_violet_color_wheel,      RGB565_Blue_violet_crayola,
        RGB565_Chinese_violet,               RGB565_Dark_violet,                  RGB565_Electric_violet,              RGB565_English_violet,
        RGB565_French_violet,                RGB565_Grape,                        RGB565_Japanese_violet,              RGB565_Lavender,
        RGB565_Mauve_mallow,                 RGB565_Medium_violet_red,            RGB565_Red_violet_color_wheel,       RGB565_Red_violet_crayola,
        RGB565_Russian_violet,               RGB565_Spanish_violet,               RGB565_Ultra_violet,                 RGB565_Violet,
        RGB565_Violet_blue,                  RGB565_Violet_blue_crayola,          RGB565_Violet_color_wheel,           RGB565_Violet_crayola,
        RGB565_Violet_gs,                    RGB565_Violet_jtc,                   RGB565_Violet_red,                   RGB565_Violet_ryb,
        RGB565_Violet_web,                   RGB565_Violet_web_color,             RGB565_Vivid_violet,                 RGB565_Wisteria
};

string violet_shade_names[32] = {
        "African Violet",                        "Blue-violet",                           "Blue-violet (color wheel)",             "Blue-violet (Crayola)",
        "Chinese Violet",                        "Dark Violet",                           "Electric Violet",                       "English Violet",
        "French Violet",                         "Grape",                                 "Japanese violet",                       "Lavender",
        "Mauve (Mallow)",                        "Medium violet-red",                     "Red-violet (Color wheel)",              "Red-violet (Crayola)",
        "Russian Violet",                        "Spanish violet",                        "Ultra Violet",                          "Violet",
        "Violet-blue",                           "Violet-blue (Crayola)",                 "Violet (color wheel)",                  "Violet (crayola)",
        "Violet (G&S)",                          "Violet (JTC)",                          "Violet-red",                            "Violet (RYB)",
        "Violet (web)",                          "Violet (web color)",                    "Vivid Violet",                          "Wisteria"
};

uint16_t azure_shades[49] = {
        RGB565_Air_force_blue,               RGB565_Alice_blue,                   RGB565_Argentinian_blue,             RGB565_Azure,
        RGB565_Azure_x11web_color,           RGB565_Baby_blue,                    RGB565_Berkeley_blue,                RGB565_Bleu_de_france,
        RGB565_Blue_crayola,                 RGB565_Blue_munsell,                 RGB565_Blue_ncs,                     RGB565_Brandeis_blue,
        RGB565_Celestial_blue,               RGB565_Celtic_blue,                  RGB565_Cerulean,                     RGB565_Chefchaouen_blue,
        RGB565_Columbia_blue,                RGB565_Cornflower_blue,              RGB565_Deep_sky_blue,                RGB565_Delft_blue,
        RGB565_Dodger_blue,                  RGB565_French_blue,                  RGB565_Green_blue,                   RGB565_Honolulu_blue,
        RGB565_Jordy_blue,                   RGB565_Lapis_lazuli,                 RGB565_Light_blue,                   RGB565_Light_sky_blue,
        RGB565_Maya_blue,                    RGB565_Pale_azure,                   RGB565_Picton_blue,                  RGB565_Polynesian_blue,
        RGB565_Resolution_blue,              RGB565_Royal_blue_traditional,       RGB565_Royal_blue_web_color,         RGB565_Ruddy_blue,
        RGB565_Sapphire,                     RGB565_Silver_lake_blue,             RGB565_Sky_blue,                     RGB565_Spanish_blue,
        RGB565_Steel_blue,                   RGB565_Tang_blue,                    RGB565_True_blue,                    RGB565_Tufts_blue,
        RGB565_United_nations_blue,          RGB565_University_of_pennsylvania_blue,RGB565_Uranian_blue,                 RGB565_Vista_blue,
        RGB565_Yale_blue_site_blue           };

string azure_shade_names[49] = {
        "Air Force Blue",                        "Alice Blue",                            "Argentinian Blue",                      "Azure",
        "Azure (X11/web color)",                 "Baby Blue",                             "Berkeley Blue",                         "Bleu de France",
        "Blue (Crayola)",                        "Blue (Munsell)",                        "Blue (NCS)",                            "Brandeis Blue",
        "Celestial Blue",                        "Celtic Blue",                           "Cerulean",                              "Chefchaouen Blue",
        "Columbia Blue",                         "Cornflower Blue",                       "Deep Sky Blue",                         "Delft Blue",
        "Dodger Blue",                           "French Blue",                           "Green-blue",                            "Honolulu Blue",
        "Jordy Blue",                            "Lapis Lazuli",                          "Light blue",                            "Light Sky Blue",
        "Maya Blue",                             "Pale azure",                            "Picton Blue",                           "Polynesian Blue",
        "Resolution Blue",                       "Royal blue (traditional)",              "Royal Blue (web color)",                "Ruddy Blue",
        "Sapphire",                              "Silver Lake Blue",                      "Sky Blue",                              "Spanish Blue",
        "Steel Blue",                            "Tang Blue",                             "True Blue",                             "Tufts Blue",
        "United Nations Blue",                   "University of Pennsylvania Blue",       "Uranian Blue",                          "Vista Blue",
        "Yale \"Blue Site\" Blue"                };

uint16_t white_shades[22] = {
        RGB565_Alabaster,                    RGB565_Antique_white,                RGB565_Baby_powder,                  RGB565_Beige,
        RGB565_Bone,                         RGB565_Champagne,                    RGB565_Cornsilk,                     RGB565_Cream,
        RGB565_Dutch_white,                  RGB565_Eggshell,                     RGB565_Flax,                         RGB565_Floral_white,
        RGB565_Ghost_white,                  RGB565_Ivory,                        RGB565_Navajo_white,                 RGB565_Old_lace,
        RGB565_Parchment,                    RGB565_Seashell,                     RGB565_Snow,                         RGB565_Vanilla,
        RGB565_White,                        RGB565_White_smoke                   };

string white_shade_names[22] = {
        "Alabaster",                             "Antique white",                         "Baby powder",                           "Beige",
        "Bone",                                  "Champagne",                             "Cornsilk",                              "Cream",
        "Dutch white",                           "Eggshell",                              "Flax",                                  "Floral white",
        "Ghost white",                           "Ivory",                                 "Navajo white",                          "Old lace",
        "Parchment",                             "Seashell",                              "Snow",                                  "Vanilla",
        "White",                                 "White smoke"                            };

uint16_t orange_shades[54] = {
        RGB565_Alloy_orange,                 RGB565_Apricot,                      RGB565_Atomic_tangerine,             RGB565_Brown,
        RGB565_Burnt_orange,                 RGB565_Butterscotch,                 RGB565_Cadmium_orange,               RGB565_Carrot_orange,
        RGB565_Coral,                        RGB565_Dark_orange,                  RGB565_Giants_orange,                RGB565_Goldenrod,
        RGB565_Hunyadi_yellow,               RGB565_International_orange,         RGB565_International_orange_aerospace,RGB565_International_orange_engineering,
        RGB565_International_orange_golden_gate_bridge,RGB565_Khaki,                        RGB565_Light_orange,                 RGB565_Orange,
        RGB565_Orange_color_wheel,           RGB565_Orange_crayola,               RGB565_Orange_gs,                    RGB565_Orange_pantone,
        RGB565_Orange_peel,                  RGB565_Orange_red,                   RGB565_Orange_red_crayola,           RGB565_Orange_soda,
        RGB565_Orange_web,                   RGB565_Orange_web_color,             RGB565_Orange_yellow,                RGB565_Orange_yellow_crayola,
        RGB565_Outrageous_orange,            RGB565_Papaya_whip,                  RGB565_Peach,                        RGB565_Persian_orange,
        RGB565_Persimmon,                    RGB565_Portland_orange,              RGB565_Princeton_orange,             RGB565_Pumpkin,
        RGB565_Red_orange,                   RGB565_Red_orange_color_wheel,       RGB565_Red_orange_crayola,           RGB565_Safety_orange,
        RGB565_Safety_orange_blaze_orange,   RGB565_Saffron,                      RGB565_Spanish_orange,               RGB565_Tangerine,
        RGB565_Tart_orange,                  RGB565_Tigers_eye,                   RGB565_Ut_orange,                    RGB565_Xanthous,
        RGB565_Yellow_orange,                RGB565_Yellow_orange_color_wheel     };

string orange_shade_names[54] = {
        "Alloy orange",                          "Apricot",                               "Atomic tangerine",                      "Brown",
        "Burnt orange",                          "Butterscotch",                          "Cadmium orange",                        "Carrot orange",
        "Coral",                                 "Dark orange",                           "Giants orange",                         "Goldenrod",
        "Hunyadi yellow",                        "International Orange",                  "International orange (aerospace)",      "International orange (engineering)",
        "International orange (Golden Gate Bridge)","Khaki",                                 "Light orange",                          "Orange",
        "Orange (color wheel)",                  "Orange (Crayola)",                      "Orange (G&S)",                          "Orange (Pantone)",
        "Orange peel",                           "Orange-red",                            "Orange-red (Crayola)",                  "Orange soda",
        "Orange (web)",                          "Orange (web color)",                    "Orange-yellow",                         "Orange-yellow (Crayola)",
        "Outrageous Orange",                     "Papaya Whip",                           "Peach",                                 "Persian orange",
        "Persimmon",                             "Portland Orange",                       "Princeton orange",                      "Pumpkin",
        "Red-orange",                            "Red-orange (Color wheel)",              "Red-orange (Crayola)",                  "Safety Orange",
        "Safety orange (blaze orange)",          "Saffron",                               "Spanish orange",                        "Tangerine",
        "Tart Orange",                           "Tiger’s Eye",                           "UT orange",                             "Xanthous",
        "Yellow Orange",                         "Yellow Orange (Color Wheel)"            };

uint16_t pink_shades[60] = {
        RGB565_Amaranth_pink,                RGB565_Baby_pink,                    RGB565_Baker_miller_pink,            RGB565_Barbie_pink,
        RGB565_Brink_pink,                   RGB565_Bubblegum_pink,               RGB565_Cameo_pink,                   RGB565_Candy_pink,
        RGB565_Carnation_pink,               RGB565_Champagne_pink,               RGB565_Charm_pink,                   RGB565_Cherry_blossom_pink,
        RGB565_Chilean_pink,                 RGB565_China_pink,                   RGB565_Congo_pink,                   RGB565_Coral_pink,
        RGB565_Cotton_candy,                 RGB565_Deep_pink,                    RGB565_Fairy_tale,                   RGB565_Fandango_pink,
        RGB565_French_pink,                  RGB565_Hot_pink,                     RGB565_Lavender_pink,                RGB565_Light_deep_pink,
        RGB565_Light_hot_pink,               RGB565_Light_pink,                   RGB565_Mexican_pink,                 RGB565_Mimi_pink,
        RGB565_Mountbatten_pink,             RGB565_Nadeshiko_pink,               RGB565_New_york_pink,                RGB565_Orchid_pink,
        RGB565_Pale_dogwood,                 RGB565_Pale_pink,                    RGB565_Paradise_pink,                RGB565_Pastel_pink,
        RGB565_Persian_pink,                 RGB565_Piggy_pink,                   RGB565_Pink,                         RGB565_Pink_flamingo,
        RGB565_Pink_gs,                      RGB565_Pink_lace,                    RGB565_Pink_lavender,                RGB565_Pink_pantone,
        RGB565_Pink_sherbet,                 RGB565_Queen_pink,                   RGB565_Rose_pink,                    RGB565_Rose_pompadour,
        RGB565_Schauss_pink,                 RGB565_Shocking_pink,                RGB565_Shocking_pink_crayola,        RGB565_Silver_pink,
        RGB565_Solid_pink,                   RGB565_Spanish_pink,                 RGB565_Steel_pink,                   RGB565_Super_pink,
        RGB565_Tango_pink,                   RGB565_Thulian_pink,                 RGB565_Tickle_me_pink,               RGB565_Ultra_pink
};

string pink_shade_names[60] = {
        "Amaranth Pink",                         "Baby Pink",                             "Baker-Miller Pink",                     "Barbie pink",
        "Brink Pink",                            "Bubblegum Pink",                        "Cameo Pink",                            "Candy pink",
        "Carnation Pink",                        "Champagne Pink",                        "Charm Pink",                            "Cherry Blossom Pink",
        "Chilean Pink",                          "China Pink",                            "Congo Pink",                            "Coral Pink",
        "Cotton Candy",                          "Deep Pink",                             "Fairy Tale",                            "Fandango Pink",
        "French Pink",                           "Hot Pink",                              "Lavender pink",                         "Light Deep Pink",
        "Light Hot Pink",                        "Light Pink",                            "Mexican pink",                          "Mimi Pink",
        "Mountbatten pink",                      "Nadeshiko pink",                        "New York Pink",                         "Orchid Pink",
        "Pale Dogwood",                          "Pale Pink",                             "Paradise Pink",                         "Pastel Pink",
        "Persian Pink",                          "Piggy Pink",                            "Pink",                                  "Pink flamingo",
        "Pink (G&S)",                            "Pink Lace",                             "Pink Lavender",                         "Pink (Pantone)",
        "Pink Sherbet",                          "Queen Pink",                            "Rose pink",                             "Rose Pompadour",
        "Schauss pink",                          "Shocking Pink",                         "Shocking pink (Crayola)",               "Silver Pink",
        "Solid Pink",                            "Spanish pink",                          "Steel Pink",                            "Super Pink",
        "Tango Pink",                            "Thulian pink",                          "Tickle Me Pink",                        "Ultra Pink"
};

uint16_t red_shades[98] = {
        RGB565_Amaranth_red,                 RGB565_Barn_red,                     RGB565_Bittersweet,                  RGB565_Bittersweet_shimmer,
        RGB565_Blood_red,                    RGB565_Brick_red,                    RGB565_Brink_pink,                   RGB565_Cadmium_red,
        RGB565_Candy_apple_red,              RGB565_Cantaloupe_melon,             RGB565_Cardinal,                     RGB565_Carmine,
        RGB565_Cg_red,                       RGB565_Chili_red,                    RGB565_Chinese_red,                  RGB565_Chocolate_cosmos,
        RGB565_Cinnabar,                     RGB565_Copper_red,                   RGB565_Coral_pink,                   RGB565_Cordovan,
        RGB565_Cornell_red,                  RGB565_Crimson,                      RGB565_Cultured,                     RGB565_Dark_red,
        RGB565_English_red,                  RGB565_Falu_red,                     RGB565_Fire_brick,                   RGB565_Fire_engine_red,
        RGB565_Garnet,                       RGB565_Imperial_red,                 RGB565_Indian_red,                   RGB565_Jasper,
        RGB565_Light_coral,                  RGB565_Light_red,                    RGB565_Lust,                         RGB565_Madder,
        RGB565_Maroon,                       RGB565_Maximum_red,                  RGB565_Maximum_red_purple,           RGB565_Maximum_yellow_red,
        RGB565_Medium_candy_apple_red,       RGB565_Medium_violet_red,            RGB565_Middle_red,                   RGB565_Middle_red_purple,
        RGB565_Middle_yellow_red,            RGB565_Misty_rose,                   RGB565_Old_rose,                     RGB565_Orange_red,
        RGB565_Orange_red_crayola,           RGB565_Ou_crimson_red,               RGB565_Persian_red,                  RGB565_Pink,
        RGB565_Radical_red,                  RGB565_Red,                          RGB565_Red_cmyk_pigment_red,         RGB565_Red_crayola,
        RGB565_Red_munsell,                  RGB565_Red_ncs,                      RGB565_Red_orange,                   RGB565_Red_orange_color_wheel,
        RGB565_Red_orange_crayola,           RGB565_Red_pantone,                  RGB565_Red_pigment,                  RGB565_Red_purple,
        RGB565_Red_rgb,                      RGB565_Red_ryb,                      RGB565_Red_salsa,                    RGB565_Red_violet_color_wheel,
        RGB565_Red_violet_crayola,           RGB565_Redwood,                      RGB565_Rojo,                         RGB565_Rojo_spanish_red,
        RGB565_Rose_ebony,                   RGB565_Rose_red,                     RGB565_Rose_taupe,                   RGB565_Rose_vale,
        RGB565_Rosewood,                     RGB565_Rosy_brown,                   RGB565_Rubine_red,                   RGB565_Ruby_red,
        RGB565_Rusty_red,                    RGB565_Salmon,                       RGB565_Salmon_pink,                  RGB565_Scarlet,
        RGB565_Sizzling_red,                 RGB565_Spanish_red,                  RGB565_Syracuse_orange,              RGB565_Tea_rose_red,
        RGB565_Tomato,                       RGB565_Turkey_red,                   RGB565_Tuscan_red,                   RGB565_Ua_red,
        RGB565_Ultra_red,                    RGB565_University_of_pennsylvania_red,RGB565_Upsdell_red,                  RGB565_Venetian_red,
        RGB565_Vermilion,                    RGB565_Violet_red                    };

string red_shade_names[98] = {
        "Amaranth red",                          "Barn Red",                              "Bittersweet",                           "Bittersweet shimmer",
        "Blood red",                             "Brick red",                             "Brink Pink",                            "Cadmium red",
        "Candy apple red",                       "Cantaloupe Melon",                      "Cardinal",                              "Carmine",
        " CG red",                               "Chili red",                             "Chinese red",                           "Chocolate Cosmos",
        "Cinnabar",                              "Copper red",                            "Coral Pink",                            "Cordovan",
        "Cornell red",                           "Crimson",                               "Cultured",                              "Dark red",
        "English red",                           "Falu red",                              "Fire brick",                            "Fire engine red",
        "Garnet",                                "Imperial Red",                          "Indian Red",                            "Jasper",
        "Light Coral",                           "Light red",                             "Lust",                                  "Madder",
        "Maroon",                                "Maximum red",                           "Maximum red purple",                    "Maximum yellow red",
        "Medium candy apple red",                "Medium violet-red",                     "Middle red",                            "Middle red purple",
        "Middle yellow red",                     "Misty rose",                            "Old rose",                              "Orange-red",
        "Orange-red (Crayola)",                  "OU Crimson red",                        "Persian red",                           "Pink",
        "Radical Red",                           "Red",                                   "Red (CMYK) (pigment red)",              "Red (Crayola)",
        "Red (Munsell)",                         "Red (NCS)",                             "Red-orange",                            "Red-orange (Color wheel)",
        "Red-orange (Crayola)",                  "Red (Pantone)",                         "Red (pigment)",                         "Red-purple",
        "Red (RGB)",                             "Red (RYB)",                             "Red Salsa",                             "Red-violet (Color wheel)",
        "Red-violet (Crayola)",                  "Redwood",                               "Rojo",                                  "Rojo Spanish red",
        "Rose ebony",                            "Rose red",                              "Rose taupe",                            "Rose vale",
        "Rosewood",                              "Rosy Brown",                            "Rubine red",                            "Ruby red",
        "Rusty red",                             "Salmon",                                "Salmon Pink",                           "Scarlet",
        "Sizzling Red",                          "Spanish red",                           "Syracuse Orange",                       "Tea rose (red)",
        "Tomato",                                "Turkey red",                            "Tuscan red",                            "UA red",
        "Ultra red",                             "University of Pennsylvania Red",        "Upsdell red",                           "Venetian red",
        "Vermilion",                             "Violet-red"                             };

uint16_t yellow_shades[64] = {
        RGB565_Army_green,                   RGB565_Arylide_yellow,               RGB565_Bright_yellow_crayola,        RGB565_Cadmium_yellow,
        RGB565_Canary_yellow,                RGB565_Chartreuse_traditional,       RGB565_Chinese_yellow,               RGB565_Chrome_yellow,
        RGB565_Cream,                        RGB565_Cyber_yellow,                 RGB565_Earth_yellow,                 RGB565_Feldgrau,
        RGB565_Gold_golden,                  RGB565_Golden_yellow,                RGB565_Green_earth,                  RGB565_Green_yellow,
        RGB565_Green_yellow_crayola,         RGB565_Greenish_yellow,              RGB565_Hansa_yellow,                 RGB565_Indian_yellow,
        RGB565_Lemon_chiffon,                RGB565_Lemon_crayola,                RGB565_Lemon_yellow,                 RGB565_Lemon_yellow_crayola,
        RGB565_Light_goldenrod_yellow,       RGB565_Light_yellow,                 RGB565_Maximum_green_yellow,         RGB565_Maximum_yellow,
        RGB565_Maximum_yellow_red,           RGB565_Mellow_yellow,                RGB565_Middle_green_yellow,          RGB565_Middle_yellow,
        RGB565_Middle_yellow_red,            RGB565_Mikado_yellow,                RGB565_Mindaro,                      RGB565_Minion_yellow,
        RGB565_Naples_yellow,                RGB565_Olive,                        RGB565_Orange_yellow,                RGB565_Orange_yellow_crayola,
        RGB565_Pear,                         RGB565_Process_yellow,               RGB565_Royal_yellow,                 RGB565_Safety_yellow,
        RGB565_School_bus_yellow,            RGB565_Selective_yellow,             RGB565_Stil_de_grain_yellow,         RGB565_Titanium_yellow,
        RGB565_Unmellow_yellow,              RGB565_Xanthic,                      RGB565_Yellow,                       RGB565_Yellow_crayola,
        RGB565_Yellow_green,                 RGB565_Yellow_green_color_wheel,     RGB565_Yellow_green_crayola,         RGB565_Yellow_munsell,
        RGB565_Yellow_ncs,                   RGB565_Yellow_orange,                RGB565_Yellow_orange_color_wheel,    RGB565_Yellow_pantone,
        RGB565_Yellow_process,               RGB565_Yellow_rgb_x11_yellow,        RGB565_Yellow_ryb,                   RGB565_Yellow_sunshine
};

string yellow_shade_names[64] = {
        "Army green",                            "Arylide yellow",                        "Bright yellow (Crayola)",               "Cadmium yellow",
        "Canary Yellow",                         "Chartreuse (traditional)",              "Chinese yellow",                        "Chrome yellow",
        "Cream",                                 "Cyber Yellow",                          "Earth yellow",                          "Feldgrau",
        "Gold (Golden)",                         "Golden yellow",                         "Green earth",                           "Green-yellow",
        "Green-yellow (Crayola)",                "Greenish Yellow",                       "Hansa yellow",                          "Indian yellow",
        "Lemon Chiffon",                         "Lemon (Crayola)",                       "Lemon yellow",                          "Lemon yellow (Crayola)",
        "Light goldenrod yellow",                "Light Yellow",                          "Maximum green yellow",                  "Maximum Yellow",
        "Maximum yellow red",                    "Mellow Yellow",                         "Middle green yellow",                   "Middle yellow",
        "Middle yellow red",                     "Mikado yellow",                         "Mindaro",                               "Minion yellow",
        "Naples yellow",                         "Olive",                                 "Orange-yellow",                         "Orange-yellow (Crayola)",
        "Pear",                                  "Process Yellow",                        "Royal Yellow",                          "Safety Yellow",
        "School bus yellow",                     "Selective yellow",                      "Stil de grain yellow",                  "Titanium yellow",
        "Unmellow Yellow",                       "Xanthic",                               "Yellow",                                "Yellow (Crayola)",
        "Yellow-green",                          "Yellow-green (Color Wheel)",            "Yellow-green (Crayola)",                "Yellow (Munsell)",
        "Yellow (NCS)",                          "Yellow Orange",                         "Yellow Orange (Color Wheel)",           "Yellow (Pantone)",
        "Yellow (process)",                      "Yellow (RGB) (X11 yellow)",             "Yellow (RYB)",                          "Yellow Sunshine"
};

uint16_t gray_shades[40] = {
        RGB565_Ash_gray,                     RGB565_Battleship_gray,              RGB565_Black,                        RGB565_Blue_gray,
        RGB565_Cadet_gray,                   RGB565_Charcoal,                     RGB565_Cinereous,                    RGB565_Cool_gray,
        RGB565_Dark_blue_gray,               RGB565_Dark_slate_gray,              RGB565_Davys_gray,                   RGB565_Dim_gray,
        RGB565_Gainsboro,                    RGB565_Glaucous,                     RGB565_Granite_gray,                 RGB565_Gray_green,
        RGB565_Gray_web,                     RGB565_Gray_x11_gray,                RGB565_Graygrey,                     RGB565_Gunmetal,
        RGB565_Heliotrope_gray,              RGB565_Jet,                          RGB565_Lavender_gray,                RGB565_Light_gray,
        RGB565_Light_slate_gray,             RGB565_Marengo,                      RGB565_Medium_gray,                  RGB565_Nickel,
        RGB565_Platinum,                     RGB565_Puce,                         RGB565_Rocket_metallic,              RGB565_Rose_quartz,
        RGB565_Silver,                       RGB565_Slate_gray,                   RGB565_Spanish_gray,                 RGB565_Stone_gray,
        RGB565_Taupe,                        RGB565_Taupe_gray,                   RGB565_White,                        RGB565_Xanadu
};

string gray_shade_names[40] = {
        "Ash gray",                              "Battleship gray",                       "Black",                                 "Blue-gray",
        "Cadet gray",                            "Charcoal",                              "Cinereous",                             "Cool gray",
        "Dark blue-gray",                        "Dark slate gray",                       "Davy's gray",                           "Dim gray",
        "Gainsboro",                             "Glaucous",                              "Granite gray",                          "Gray-green",
        "Gray (web)",                            "Gray (X11 gray)",                       "Gray/Grey",                             "Gunmetal",
        "Heliotrope gray",                       "Jet",                                   "Lavender gray",                         "Light gray",
        "Light slate gray",                      "Marengo",                               "Medium Gray",                           "Nickel",
        "Platinum",                              "Puce",                                  "Rocket metallic",                       "Rose quartz",
        "Silver",                                "Slate gray",                            "Spanish Gray",                          "Stone gray",
        "Taupe",                                 "Taupe gray",                            "White",                                 "Xanadu"
};

uint16_t cyan_shades[27] = {
        RGB565_Azure_web,                    RGB565_Blue_green,                   RGB565_Caribbean_current,            RGB565_Celeste,
        RGB565_Charleston_green,             RGB565_Cyan,                         RGB565_Cyan_additive_secondary,      RGB565_Cyan_process,
        RGB565_Cyan_subtractive_primary,     RGB565_Dark_cyan,                    RGB565_Electric_blue,                RGB565_Green_cyan,
        RGB565_Keppel,                       RGB565_Light_cyan,                   RGB565_Light_sea_green,              RGB565_Midnight_green,
        RGB565_Moonstone,                    RGB565_Myrtle_green,                 RGB565_Pine_green,                   RGB565_Robin_egg_blue,
        RGB565_Skobeloff,                    RGB565_Sky_blue_crayola,             RGB565_Teal,                         RGB565_Tiffany_blue,
        RGB565_Turquoise,                    RGB565_Verdigris,                    RGB565_Zomp                          };

string cyan_shade_names[27] = {
        "Azure (web)",                           "Blue-green",                            "Caribbean Current",                     "Celeste",
        "Charleston green",                      "Cyan",                                  "Cyan (additive secondary)",             "Cyan (process)",
        "Cyan (subtractive primary)",            "Dark cyan",                             "Electric blue",                         "Green-cyan",
        "Keppel",                                "Light cyan",                            "Light sea green",                       "Midnight green",
        "Moonstone",                             "Myrtle green",                          "Pine green",                            "Robin egg blue",
        "Skobeloff",                             "Sky blue (Crayola)",                    "Teal",                                  "Tiffany Blue",
        "Turquoise",                             "Verdigris",                             "Zomp"                                   };

uint16_t black_shades[26] = {
        RGB565_Bean,                         RGB565_Black,                        RGB565_Black_bean,                   RGB565_Black_chocolate,
        RGB565_Black_coffee,                 RGB565_Black_coral,                  RGB565_Black_olive,                  RGB565_Black_shadows,
        RGB565_Charcoal,                     RGB565_Charleston_green,             RGB565_Davys_gray,                   RGB565_Dim_gray,
        RGB565_Ebony,                        RGB565_Eerie_black,                  RGB565_Jet,                          RGB565_Licorice,
        RGB565_Olive_ral,                    RGB565_Onyx,                         RGB565_Outer_space,                  RGB565_Raisin_black,
        RGB565_Rich_black,                   RGB565_Rich_black_fogra29,           RGB565_Rich_black_fogra39,           RGB565_Smoky_black,
        RGB565_Taupe,                        RGB565_Warm_black                    };

string black_shade_names[26] = {
        "Bean",                                  "Black",                                 "Black bean",                            "Black chocolate",
        "Black coffee",                          "Black coral",                           "Black olive",                           "Black Shadows",
        "Charcoal",                              "Charleston green",                      "Davy's gray",                           "Dim gray",
        "Ebony",                                 "Eerie black",                           "Jet",                                   "Licorice",
        "Olive (RAL)",                           "Onyx",                                  "Outer Space",                           "Raisin Black",
        "Rich black",                            "Rich black (FOGRA29)",                  "Rich black (FOGRA39)",                  "Smoky black",
        "Taupe",                                 "Warm black"                             };

uint16_t brown_shades[35] = {
        RGB565_Beaver,                       RGB565_Beige,                        RGB565_Bistre_brown,                 RGB565_Brown,
        RGB565_Brown_sugar,                  RGB565_Buff,                         RGB565_Burnished_brown,              RGB565_Burnt_umber,
        RGB565_Chestnut,                     RGB565_Chocolate,                    RGB565_Cocoa_brown,                  RGB565_Coyote_brown,
        RGB565_Dark_brown,                   RGB565_Desert_sand,                  RGB565_Golden_brown,                 RGB565_Khaki,
        RGB565_Kobicha,                      RGB565_Peru,                         RGB565_Pullman_brown_ups_brown,      RGB565_Raw_umber,
        RGB565_Red_brown,                    RGB565_Rosy_brown,                   RGB565_Russet,                       RGB565_Saddle_brown,
        RGB565_Sandy_brown,                  RGB565_Seal_brown,                   RGB565_Smokey_topaz,                 RGB565_Sweet_brown,
        RGB565_Tan,                          RGB565_Taupe,                        RGB565_Tuscan_brown,                 RGB565_Van_dyke_brown,
        RGB565_Walnut_brown,                 RGB565_Wenge,                        RGB565_Wood_brown                    };

string brown_shade_names[35] = {
        "Beaver",                                "Beige",                                 "Bistre brown",                          "Brown",
        "Brown sugar",                           "Buff",                                  "Burnished brown",                       "Burnt umber",
        "Chestnut",                              "Chocolate",                             "Cocoa Brown",                           "Coyote brown",
        "Dark Brown",                            "Desert Sand",                           "Golden brown",                          "Khaki",
        "Kobicha",                               "Peru",                                  "Pullman Brown (UPS Brown)",             "Raw Umber",
        "Red-Brown",                             "Rosy Brown",                            "Russet",                                "Saddle brown",
        "Sandy Brown",                           "Seal brown",                            "Smokey Topaz",                          "Sweet Brown",
        "Tan",                                   "Taupe",                                 "Tuscan brown",                          "Van Dyke brown",
        "Walnut Brown",                          "Wenge",                                 "Wood Brown"                             };

uint16_t purple_shades[48] = {
        RGB565_Byzantium,                    RGB565_Dark_purple,                  RGB565_Electric_purple,              RGB565_Eminence,
        RGB565_Fuchsia_purple,               RGB565_Han_purple,                   RGB565_Heliotrope,                   RGB565_Ksu_purple,
        RGB565_Liseran_purple,               RGB565_Mardi_gras,                   RGB565_Mauve_mallow,                 RGB565_Maximum_blue_purple,
        RGB565_Maximum_purple,               RGB565_Maximum_red_purple,           RGB565_Medium_purple,                RGB565_Middle_blue_purple,
        RGB565_Middle_purple,                RGB565_Middle_red_purple,            RGB565_Mulberry,                     RGB565_Northwestern_purple,
        RGB565_Orchid,                       RGB565_Palatinate,                   RGB565_Palatinate_purple,            RGB565_Pale_purple,
        RGB565_Pale_purple_pantone,          RGB565_Pansy_purple,                 RGB565_Pearly_purple,                RGB565_Phlox,
        RGB565_Plump_purple,                 RGB565_Pomp_and_power,               RGB565_Psychedelic_purple,           RGB565_Purple,
        RGB565_Purple_htmlcss_color,         RGB565_Purple_mountain_majesty,      RGB565_Purple_munsell,               RGB565_Purple_navy,
        RGB565_Purple_pizzazz,               RGB565_Purple_plum,                  RGB565_Purple_web,                   RGB565_Purple_x11,
        RGB565_Purple_x11_color,             RGB565_Purpureus,                    RGB565_Rebecca_purple,               RGB565_Red_purple,
        RGB565_Red_violet,                   RGB565_Royal_purple,                 RGB565_Thistle,                      RGB565_Tyrian_purple
};

string purple_shade_names[48] = {
        "Byzantium",                             "Dark Purple",                           "Electric Purple",                       "Eminence",
        "Fuchsia purple",                        "Han purple",                            "Heliotrope",                            "KSU Purple",
        "Liseran Purple",                        "Mardi Gras",                            "Mauve (Mallow)",                        "Maximum blue purple",
        "Maximum purple",                        "Maximum red purple",                    "Medium Purple",                         "Middle blue purple",
        "Middle purple",                         "Middle red purple",                     "Mulberry",                              "Northwestern Purple",
        "Orchid",                                "Palatinate",                            "Palatinate purple",                     "Pale Purple",
        "Pale purple (Pantone)",                 "Pansy Purple",                          "Pearly Purple",                         "Phlox",
        "Plump Purple",                          "Pomp and Power",                        "Psychedelic purple",                    "Purple",
        "Purple (HTML/CSS color)",               "Purple mountain majesty",               "Purple (Munsell)",                      "Purple navy",
        "Purple Pizzazz",                        "Purple Plum",                           "Purple (web)",                          "Purple (X11)",
        "Purple (X11 color)",                    "Purpureus",                             "Rebecca purple",                        "Red-purple",
        "Red-Violet",                            "Royal Purple",                          "Thistle",                               "Tyrian Purple"
};

uint16_t misc_shades[349] = {
        RGB565_Absolute_zero,                RGB565_Aero,                         RGB565_Almond,                       RGB565_Amaranth,
        RGB565_Amaranth_mp,                  RGB565_Amazon,                       RGB565_Amber,                        RGB565_Amber_saeece,
        RGB565_Amethyst,                     RGB565_Antique_brass,                RGB565_Antique_bronze,               RGB565_Antique_fuchsia,
        RGB565_Antique_ruby,                 RGB565_Ao_english,                   RGB565_Aqua,                         RGB565_Aquamarine,
        RGB565_Arctic_lime,                  RGB565_Artichoke,                    RGB565_Asparagus,                    RGB565_Auburn,
        RGB565_Aureolin,                     RGB565_Avocado,                      RGB565_Banana_mania,                 RGB565_Battleship_grey,
        RGB565_Big_dip_oruby,                RGB565_Bisque,                       RGB565_Bistre,                       RGB565_Bitter_lemon,
        RGB565_Bitter_lime,                  RGB565_Blanched_almond,              RGB565_Blast_off_bronze,             RGB565_Blond,
        RGB565_Blush,                        RGB565_Bole,                         RGB565_Brandy,                       RGB565_Bright_lilac,
        RGB565_Bright_maroon,                RGB565_Brilliant_rose,               RGB565_Bronze,                       RGB565_Burgundy,
        RGB565_Burlywood,                    RGB565_Burnt_sienna,                 RGB565_Byzantine,                    RGB565_Cadet,
        RGB565_Cadet_grey,                   RGB565_Cafe_au_lait,                 RGB565_Cafe_noir,                    RGB565_Camel,
        RGB565_Canary,                       RGB565_Capri,                        RGB565_Caput_mortuum,                RGB565_Carmine_mp,
        RGB565_Carnelian,                    RGB565_Catawba,                      RGB565_Cedar_chest,                  RGB565_Cerise,
        RGB565_Cerulean_crayola,             RGB565_Cerulean_frost,               RGB565_Chartreuse_web,               RGB565_China_rose,
        RGB565_Chocolate_traditional,        RGB565_Chocolate_web,                RGB565_Cinnamon_satin,               RGB565_Citrine,
        RGB565_Citron,                       RGB565_Claret,                       RGB565_Coffee,                       RGB565_Cool_grey,
        RGB565_Copper,                       RGB565_Copper_crayola,               RGB565_Copper_penny,                 RGB565_Copper_rose,
        RGB565_Coquelicot,                   RGB565_Corn,                         RGB565_Cosmic_cobalt,                RGB565_Cosmic_latte,
        RGB565_Crimson_ua,                   RGB565_Crystal,                      RGB565_Cyber_grape,                  RGB565_Cyclamen,
        RGB565_Dark_byzantium,               RGB565_Dark_goldenrod,               RGB565_Dark_khaki,                   RGB565_Dark_lava,
        RGB565_Dark_liver,                   RGB565_Dark_liver_horses,            RGB565_Dark_orchid,                  RGB565_Dark_salmon,
        RGB565_Dark_sienna,                  RGB565_Dark_turquoise,               RGB565_Davys_grey,                   RGB565_Deep_cerise,
        RGB565_Deep_champagne,               RGB565_Deep_chestnut,                RGB565_Deep_saffron,                 RGB565_Deep_space_sparkle,
        RGB565_Deep_taupe,                   RGB565_Denim,                        RGB565_Desert,                       RGB565_Dogwood_rose,
        RGB565_Drab,                         RGB565_Ecru,                         RGB565_Eggplant,                     RGB565_Eigengrau,
        RGB565_Electric_indigo,              RGB565_Electric_lime,                RGB565_Emerald,                      RGB565_English_lavender,
        RGB565_English_vermillion,           RGB565_Fallow,                       RGB565_Fandango,                     RGB565_Fashion_fuchsia,
        RGB565_Fawn,                         RGB565_Field_drab,                   RGB565_Fiery_rose,                   RGB565_Fire_opal,
        RGB565_Firebrick,                    RGB565_Flame,                        RGB565_Flirt,                        RGB565_French_beige,
        RGB565_French_bistre,                RGB565_French_fuchsia,               RGB565_French_lilac,                 RGB565_French_lime,
        RGB565_French_mauve,                 RGB565_French_raspberry,             RGB565_French_rose,                  RGB565_Frostbite,
        RGB565_Fuchsia,                      RGB565_Fuchsia_crayola,              RGB565_Fuchsia_rose,                 RGB565_Fulvous,
        RGB565_Fuzzy_wuzzy,                  RGB565_Gamboge,                      RGB565_Generic_viridian,             RGB565_Glossy_grape,
        RGB565_Gold,                         RGB565_Gold_crayola,                 RGB565_Gold_fusion,                  RGB565_Gold_metallic,
        RGB565_Gold_web_golden,              RGB565_Golden_poppy,                 RGB565_Granny_smith_apple,           RGB565_Grullo,
        RGB565_Harvest_gold,                 RGB565_Heat_wave,                    RGB565_Hollywood_cerise,             RGB565_Iceberg,
        RGB565_Icterine,                     RGB565_Illuminating_emerald,         RGB565_Inchworm,                     RGB565_Indigo,
        RGB565_Indigo_dye,                   RGB565_Iris,                         RGB565_Irresistible,                 RGB565_Isabelline,
        RGB565_Jade,                         RGB565_Japanese_carmine,             RGB565_Jasmine,                      RGB565_Jazzberry_jam,
        RGB565_Jonquil,                      RGB565_June_bud,                     RGB565_Key_lime,                     RGB565_Khaki_web,
        RGB565_Khaki_x11_light_khaki,        RGB565_Kobe,                         RGB565_Kobi,                         RGB565_Languid_lavender,
        RGB565_Laser_lemon,                  RGB565_Lava,                         RGB565_Lavender_blush,               RGB565_Lavender_floral,
        RGB565_Lavender_web,                 RGB565_Lemon,                        RGB565_Lemon_curry,                  RGB565_Lemon_glacier,
        RGB565_Lemon_meringue,               RGB565_Light_french_beige,           RGB565_Light_periwinkle,             RGB565_Light_salmon,
        RGB565_Lilac,                        RGB565_Lilac_luster,                 RGB565_Lime_color_wheel,             RGB565_Linen,
        RGB565_Lion,                         RGB565_Liver,                        RGB565_Liver_chestnut,               RGB565_Liver_dogs,
        RGB565_Liver_organ,                  RGB565_Livid,                        RGB565_Macaroni_and_cheese,          RGB565_Madder_lake,
        RGB565_Magic_mint,                   RGB565_Magnolia,                     RGB565_Mahogany,                     RGB565_Maize,
        RGB565_Maize_crayola,                RGB565_Malachite,                    RGB565_Manatee,                      RGB565_Mandarin,
        RGB565_Mango,                        RGB565_Mango_tango,                  RGB565_Marigold,                     RGB565_Maroon_crayola,
        RGB565_Maroon_web,                   RGB565_Maroon_x11,                   RGB565_Mauve,                        RGB565_Mauve_taupe,
        RGB565_Mauvelous,                    RGB565_Medium_aquamarine,            RGB565_Medium_carmine,               RGB565_Medium_champagne,
        RGB565_Medium_orchid,                RGB565_Medium_turquoise,             RGB565_Mellow_apricot,               RGB565_Melon,
        RGB565_Metallic_gold,                RGB565_Metallic_seaweed,             RGB565_Metallic_sunburst,            RGB565_Middle_grey,
        RGB565_Midnight,                     RGB565_Ming,                         RGB565_Mint,                         RGB565_Mint_cream,
        RGB565_Misty_moss,                   RGB565_Mode_beige,                   RGB565_Mountain_meadow,              RGB565_Mulberry_crayola,
        RGB565_Mustard,                      RGB565_Mystic,                       RGB565_Mystic_maroon,                RGB565_Neon_carrot,
        RGB565_Neon_fuchsia,                 RGB565_Nyanza,                       RGB565_Ochre,                        RGB565_Old_burgundy,
        RGB565_Old_gold,                     RGB565_Old_lavender,                 RGB565_Old_mauve,                    RGB565_Old_silver,
        RGB565_Olive_drab_3,                 RGB565_Olive_drab_7,                 RGB565_Olivine,                      RGB565_Opal,
        RGB565_Opera_mauve,                  RGB565_Orchid_crayola,               RGB565_Outer_space_crayola,          RGB565_Oxblood,
        RGB565_Pale_aqua,                    RGB565_Pale_cerulean,                RGB565_Pale_silver,                  RGB565_Pale_spring_bud,
        RGB565_Patriarch,                    RGB565_Paynes_grey,                  RGB565_Peach_crayola,                RGB565_Peach_puff,
        RGB565_Periwinkle_crayola,           RGB565_Permanent_geranium_lake,      RGB565_Persian_indigo,               RGB565_Persian_plum,
        RGB565_Persian_rose,                 RGB565_Pictorial_carmine,            RGB565_Pine_tree,                    RGB565_Pistachio,
        RGB565_Plum,                         RGB565_Plum_web,                     RGB565_Polished_pine,                RGB565_Popstar,
        RGB565_Prune,                        RGB565_Quick_silver,                 RGB565_Rajah,                        RGB565_Raspberry,
        RGB565_Raspberry_glace,              RGB565_Raspberry_rose,               RGB565_Raw_sienna,                   RGB565_Razzmatazz,
        RGB565_Razzmic_berry,                RGB565_Rhythm,                       RGB565_Roman_silver,                 RGB565_Rose,
        RGB565_Rose_bonbon,                  RGB565_Rose_dust,                    RGB565_Rose_madder,                  RGB565_Rosso_corsa,
        RGB565_Ruber,                        RGB565_Ruby,                         RGB565_Rufous,                       RGB565_Rust,
        RGB565_Sage,                         RGB565_Sand,                         RGB565_Sand_dune,                    RGB565_Sapphire_crayola,
        RGB565_Satin_sheen_gold,             RGB565_Sepia,                        RGB565_Shadow,                       RGB565_Shimmering_blush,
        RGB565_Shiny_shamrock,               RGB565_Sienna,                       RGB565_Silver_chalice,               RGB565_Silver_crayola,
        RGB565_Silver_metallic,              RGB565_Silver_sand,                  RGB565_Sinopia,                      RGB565_Sizzling_sunrise,
        RGB565_Smitten,                      RGB565_Sonic_silver,                 RGB565_Spanish_bistre,               RGB565_Spanish_carmine,
        RGB565_Spanish_viridian,             RGB565_Spring_bud,                   RGB565_Spring_frost,                 RGB565_Steel_teal,
        RGB565_Straw,                        RGB565_Strawberry,                   RGB565_Strawberry_blonde,            RGB565_Sugar_plum,
        RGB565_Sunglow,                      RGB565_Sunray,                       RGB565_Sunset,                       RGB565_Tan_crayola,
        RGB565_Tea_rose,                     RGB565_Tenne,                        RGB565_Terra_cotta,                  RGB565_Timberwolf,
        RGB565_Tropical_rainforest,          RGB565_Tumbleweed,                   RGB565_Tuscan,                       RGB565_Tuscan_tan,
        RGB565_Tuscany,                      RGB565_Twilight_lavender,            RGB565_Umber,                        RGB565_Unbleached_silk,
        RGB565_Up_maroon,                    RGB565_Vanilla_ice,                  RGB565_Vegas_gold,                   RGB565_Veronica,
        RGB565_Viridian,                     RGB565_Vivid_burgundy,               RGB565_Vivid_tangerine,              RGB565_Volt,
        RGB565_Wheat,                        RGB565_Wild_orchid,                  RGB565_Wild_strawberry,              RGB565_Wild_watermelon,
        RGB565_Windsor_tan,                  RGB565_Wine,                         RGB565_Wine_dregs,                   RGB565_Winter_sky,
        RGB565_Zaffre                        };
string misc_shade_names[349] = {
        "Absolute Zero",                         "Aero",                                  "Almond",                                "Amaranth",
        "Amaranth (M&P)",                        "Amazon",                                "Amber",                                 "Amber (SAE/ECE)",
        "Amethyst",                              "Antique brass",                         "Antique bronze",                        "Antique fuchsia",
        "Antique ruby",                          "Ao (English)",                          "Aqua",                                  "Aquamarine",
        "Arctic lime",                           "Artichoke",                             "Asparagus",                             "Auburn",
        "Aureolin",                              "Avocado",                               "Banana Mania",                          "Battleship grey",
        "Big dip o’ruby",                        "Bisque",                                "Bistre",                                "Bitter lemon",
        "Bitter lime",                           "Blanched almond",                       "Blast-off bronze",                      "Blond",
        "Blush",                                 "Bole",                                  "Brandy",                                "Bright lilac",
        "Bright maroon",                         "Brilliant rose",                        "Bronze",                                "Burgundy",
        "Burlywood",                             "Burnt sienna",                          "Byzantine",                             "Cadet",
        "Cadet grey",                            "Café au lait",                          "Café noir",                             "Camel",
        "Canary",                                "Capri",                                 "Caput mortuum",                         "Carmine (M&P)",
        "Carnelian",                             "Catawba",                               "Cedar Chest",                           "Cerise",
        "Cerulean (Crayola)",                    "Cerulean frost",                        "Chartreuse (web)",                      "China rose",
        "Chocolate (traditional)",               "Chocolate (web)",                       "Cinnamon Satin",                        "Citrine",
        "Citron",                                "Claret",                                "Coffee",                                "Cool grey",
        "Copper",                                "Copper (Crayola)",                      "Copper penny",                          "Copper rose",
        "Coquelicot",                            "Corn",                                  "Cosmic cobalt",                         "Cosmic latte",
        "Crimson (UA)",                          "Crystal",                               "Cyber grape",                           "Cyclamen",
        "Dark byzantium",                        "Dark goldenrod",                        "Dark khaki",                            "Dark lava",
        "Dark liver",                            "Dark liver (horses)",                   "Dark orchid",                           "Dark salmon",
        "Dark sienna",                           "Dark turquoise",                        "Davys grey",                            "Deep cerise",
        "Deep champagne",                        "Deep chestnut",                         "Deep saffron",                          "Deep Space Sparkle",
        "Deep taupe",                            "Denim",                                 "Desert",                                "Dogwood rose",
        "Drab",                                  "Ecru",                                  "Eggplant",                              "Eigengrau",
        "Electric indigo",                       "Electric lime",                         "Emerald",                               "English lavender",
        "English vermillion",                    "Fallow",                                "Fandango",                              "Fashion fuchsia",
        "Fawn",                                  "Field drab",                            "Fiery rose",                            "Fire opal",
        "Firebrick",                             "Flame",                                 "Flirt",                                 "French beige",
        "French bistre",                         "French fuchsia",                        "French lilac",                          "French lime",
        "French mauve",                          "French raspberry",                      "French rose",                           "Frostbite",
        "Fuchsia",                               "Fuchsia (Crayola)",                     "Fuchsia rose",                          "Fulvous",
        "Fuzzy Wuzzy",                           "Gamboge",                               "Generic viridian",                      "Glossy grape",
        "Gold",                                  "Gold (Crayola)",                        "Gold Fusion",                           "Gold (metallic)",
        "Gold (web) (Golden)",                   "Golden poppy",                          "Granny Smith apple",                    "Grullo",
        "Harvest gold",                          "Heat Wave",                             "Hollywood cerise",                      "Iceberg",
        "Icterine",                              "Illuminating emerald",                  "Inchworm",                              "Indigo",
        "Indigo dye",                            "Iris",                                  "Irresistible",                          "Isabelline",
        "Jade",                                  "Japanese carmine",                      "Jasmine",                               "Jazzberry jam",
        "Jonquil",                               "June bud",                              "Key lime",                              "Khaki (web)",
        "Khaki (X11) (Light khaki)",             "Kobe",                                  "Kobi",                                  "Languid lavender",
        "Laser lemon",                           "Lava",                                  "Lavender blush",                        "Lavender (floral)",
        "Lavender (web)",                        "Lemon",                                 "Lemon curry",                           "Lemon glacier",
        "Lemon meringue",                        "Light French beige",                    "Light periwinkle",                      "Light salmon",
        "Lilac",                                 "Lilac Luster",                          "Lime (color wheel)",                    "Linen",
        "Lion",                                  "Liver",                                 "Liver chestnut",                        "Liver (dogs)",
        "Liver (organ)",                         "Livid",                                 "Macaroni and Cheese",                   "Madder Lake",
        "Magic mint",                            "Magnolia",                              "Mahogany",                              "Maize",
        "Maize (Crayola)",                       "Malachite",                             "Manatee",                               "Mandarin",
        "Mango",                                 "Mango Tango",                           "Marigold",                              "Maroon (Crayola)",
        "Maroon (web)",                          "Maroon (X11)",                          "Mauve",                                 "Mauve taupe",
        "Mauvelous",                             "Medium aquamarine",                     "Medium carmine",                        "Medium champagne",
        "Medium orchid",                         "Medium turquoise",                      "Mellow apricot",                        "Melon",
        "Metallic gold",                         "Metallic Seaweed",                      "Metallic Sunburst",                     "Middle grey",
        "Midnight",                              "Ming",                                  "Mint",                                  "Mint cream",
        "Misty moss",                            "Mode beige",                            "Mountain Meadow",                       "Mulberry (Crayola)",
        "Mustard",                               "Mystic",                                "Mystic maroon",                         "Neon Carrot",
        "Neon fuchsia",                          "Nyanza",                                "Ochre",                                 "Old burgundy",
        "Old gold",                              "Old lavender",                          "Old mauve",                             "Old silver",
        "Olive Drab (#3)",                       "Olive Drab #7",                         "Olivine",                               "Opal",
        "Opera mauve",                           "Orchid (Crayola)",                      "Outer space (Crayola)",                 "Oxblood",
        "Pale aqua",                             "Pale cerulean",                         "Pale silver",                           "Pale spring bud",
        "Patriarch",                             "Paynes grey",                           "Peach (Crayola)",                       "Peach puff",
        "Periwinkle (Crayola)",                  "Permanent Geranium Lake",               "Persian indigo",                        "Persian plum",
        "Persian rose",                          "Pictorial carmine",                     "Pine tree",                             "Pistachio",
        "Plum",                                  "Plum (web)",                            "Polished Pine",                         "Popstar",
        "Prune",                                 "Quick Silver",                          "Rajah",                                 "Raspberry",
        "Raspberry glace",                       "Raspberry rose",                        "Raw sienna",                            "Razzmatazz",
        "Razzmic Berry",                         "Rhythm",                                "Roman silver",                          "Rose",
        "Rose bonbon",                           "Rose Dust",                             "Rose madder",                           "Rosso corsa",
        "Ruber",                                 "Ruby",                                  "Rufous",                                "Rust",
        "Sage",                                  "Sand",                                  "Sand dune",                             "Sapphire (Crayola)",
        "Satin sheen gold",                      "Sepia",                                 "Shadow",                                "Shimmering Blush",
        "Shiny Shamrock",                        "Sienna",                                "Silver chalice",                        "Silver (Crayola)",
        "Silver (Metallic)",                     "Silver sand",                           "Sinopia",                               "Sizzling Sunrise",
        "Smitten",                               "Sonic silver",                          "Spanish bistre",                        "Spanish carmine",
        "Spanish viridian",                      "Spring bud",                            "Spring Frost",                          "Steel Teal",
        "Straw",                                 "Strawberry",                            "Strawberry Blonde",                     "Sugar Plum",
        "Sunglow",                               "Sunray",                                "Sunset",                                "Tan (Crayola)",
        "Tea rose",                              "Tenné",                                 "Terra cotta",                           "Timberwolf",
        "Tropical rainforest",                   "Tumbleweed",                            "Tuscan",                                "Tuscan tan",
        "Tuscany",                               "Twilight lavender",                     "Umber",                                 "Unbleached silk",
        "UP maroon",                             "Vanilla ice",                           "Vegas gold",                            "Veronica",
        "Viridian",                              "Vivid burgundy",                        "Vivid tangerine",                       "Volt",
        "Wheat",                                 "Wild orchid",                           "Wild Strawberry",                       "Wild watermelon",
        "Windsor tan",                           "Wine",                                  "Wine dregs",                            "Winter Sky",
        "Zaffre"                                 };

#define num_shades 16
string      shade_names[num_shades] = {"green", "blue", "magenta", "violet", "azure", "white", "orange", "pink", "red", "yellow", "gray", "cyan", "black", "brown", "purple", "misc"};
uint16_t*   shade_tone_colors[num_shades] = {green_shades, blue_shades, magenta_shades, violet_shades, azure_shades, white_shades, orange_shades, pink_shades, red_shades, yellow_shades, gray_shades, cyan_shades, black_shades, brown_shades, purple_shades, misc_shades};
string*     shade_tone_names[num_shades] = {green_shade_names, blue_shade_names, magenta_shade_names, violet_shade_names, azure_shade_names, white_shade_names, orange_shade_names, pink_shade_names, red_shade_names, yellow_shade_names, gray_shade_names, cyan_shade_names, black_shade_names, brown_shade_names, purple_shade_names, misc_shade_names};
uint16_t    num_tones[num_shades] = {113, 123, 27, 32, 49, 22, 54, 60, 98, 64, 40, 27, 26, 35, 48, 349};

uint16_t*   tone_colors = nullptr;
string*     tone_names = nullptr;

unsigned int shade_index = 0,
             num_tones_in_shades = 0,
             shade_tone_index = 0,
             prev_tone_color = ST7735_BLACK;

void render(const string &toneName, const string &shadeName, uint16_t backgroundColor, bool renderText);

void changeShade() {
    shade_index %= num_shades;
    shade_tone_index = 0;
    tone_colors = shade_tone_colors[shade_index];
    tone_names = shade_tone_names[shade_index];
    string n1 = tone_names[0];

    for (uint16_t i=0; i < 256; i++) {
        uint16_t fadeColor = RGB565_alphaBlend(tone_colors[shade_tone_index], prev_tone_color, i);
        render(n1, shade_names[shade_index], fadeColor, false);
        delay(4);
    }
    prev_tone_color = tone_colors[shade_tone_index];
    num_tones_in_shades = num_tones[shade_index];
    Serial.printf("num shades: %d\n", num_tones_in_shades);
}

void setup() {
    Serial.begin(9600);

    tft.initR(INITR_GREENTAB);
    tft.setRotation(3);
    tft.useFrameBuffer(true);
    tft.updateScreenAsync(false);

    tft.fillScreen(ST7735_BLACK);
    tft.updateScreen();

    changeShade();
}


void loop() {
    if (Serial.available()) {
        int ch = Serial.read();
        if (ch >= 0) {
            shade_index++;
            changeShade();
        }
        while (Serial.available()){
            Serial.read();
        }
    }
    string toneName = tone_names[shade_tone_index];
    string shadeName = shade_names[shade_index];
    Serial.printf("shade: %s \t\ttone name: %s\n", shadeName.c_str(), toneName.c_str());

    uint16_t backgroundColor = tone_colors[shade_tone_index];
    for (uint16_t i=0; i < 256; i++) {
        uint16_t fadeColor = RGB565_alphaBlend(backgroundColor, prev_tone_color, i);
        render(toneName, shadeName, fadeColor, false);
        delay(4);
    }
    render(toneName, shadeName, backgroundColor, true);
    delay(1000);


    prev_tone_color =  backgroundColor;

    shade_tone_index ++;
    if (shade_tone_index == num_tones_in_shades) {
        shade_index++;
        changeShade();
    }
}

void render(const string &toneName, const string &shadeName, uint16_t backgroundColor, bool renderText) {
    tft.fillScreen(backgroundColor);

    if (renderText) {
        tft.setCursor(0, 0);
        tft.setTextColor(ST7735_WHITE);
        tft.print(shadeName.c_str());
        tft.print(" ");
        tft.print(shade_tone_index + 1);
        tft.print("/");
        tft.println(num_tones_in_shades);
        tft.setTextColor(ST7735_BLACK);
        tft.print(shadeName.c_str());
        tft.print(" ");
        tft.print(shade_tone_index + 1);
        tft.print("/");
        tft.println(num_tones_in_shades);

        tft.setCursor(0, 52);
        tft.setTextColor(ST7735_WHITE);
        tft.println(toneName.c_str());
        tft.setTextColor(ST7735_BLACK);
        tft.println(toneName.c_str());
    }
    tft.updateScreen();
}


#ifdef BUILD_FOR_OPENGL_EMULATOR
int main() {
    setup();
    while (!tft.shouldClose()) {
        loop();
    }
}
#endif