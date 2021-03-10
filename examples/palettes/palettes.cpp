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
// Azure
uint16_t azure_shades[39] = {
    RGB565_Alice_blue,          RGB565_Columbia_Blue,       RGB565_Light_sky_blue,      RGB565_Baby_blue,
    RGB565_Sky_blue,            RGB565_Deep_sky_blue,       RGB565_Light_blue,          RGB565_Baby_blue_eyes,
    RGB565_Maya_blue,           RGB565_Jordy_blue,          RGB565_Picton_blue,         RGB565_Celestial_blue,
    RGB565_Vista_blue,          RGB565_Tufts_Blue,          RGB565_Blue_Crayola,        RGB565_Azure,
    RGB565_Cerulean,            RGB565_Green_blue,          RGB565_United_Nations_blue, RGB565_Cornflower_blue,
    RGB565_Bleu_de_France,      RGB565_Dodger_blue,         RGB565_Brandeis_blue,       RGB565_True_Blue,
    RGB565_Royal_blue,          RGB565_Royal_blue2,         RGB565_Celestial_blue,      RGB565_Silver_Lake_blue,
    RGB565_Honolulu_blue,       RGB565_Air_Force_blue_RAF,  RGB565_Air_Force_blue_USAF, RGB565_Steel_blue,
    RGB565_French_blue,         RGB565_Lapis_lazuli,        RGB565_Blue_NCS,            RGB565_Blue_Munsell,
    RGB565_Yale_Blue,           RGB565_Sapphire,            RGB565_Resolution_blue
};

string azure_shade_names[39] = {
    "Alice blue",               "Columbia Blue",            "Light sky blue",           "Baby blue",
    "Sky blue",                 "Deep sky blue",            "Light blue",               "Baby blue eyes",
    "Maya blue",                "Jordy blue",               "Picton blue",              "Celestial blue",
    "Vista blue",               "Tufts Blue",               "Blue Crayola",             "Azure",
    "Cerulean",                 "Green blue",               "United Nations blue",      "Cornflower blue",
    "Bleu de France",           "Dodger blue",              "Brandeis blue",            "True Blue",
    "Royal blue",               "Royal blue2",              "Celestial blue",           "Silver Lake blue",
    "Honolulu blue",            "Air Force blue RAF",       "Air Force blue USAF",      "Steel blue",
    "French blue",              "Lapis lazuli",             "Blue NCS",                 "Blue Munsell",
    "Yale Blue",                "Sapphire",                 "Resolution blue"
};

uint16_t black_shades[18] = {
        RGB565_Bistre,          RGB565_Black,               RGB565_Black_bean,          RGB565_Black_olive,
        RGB565_Cafe_noir,       RGB565_Charcoal,            RGB565_Dark_purple,         RGB565_Ebony,
        RGB565_Eerie_black,     RGB565_Jet,                 RGB565_Licorice,            RGB565_Midnight_blue,
        RGB565_Onyx,            RGB565_Outer_Space,         RGB565_Oxford_Blue,         RGB565_Raisin_black,
        RGB565_Russian_violet,  RGB565_Smoky_black
};
string black_shade_names[18] = {
        "Bistre",           "Black",        "Black bean",       "Black olive",
        "Cafe noir",        "Charcoal",     "Dark purple",      "Ebony",
        "Eerie black",      "Jet",          "Licorice",         "Midnight blue",
        "Onyx",             "Outer Space",  "Oxford Blue",      "Raisin black",
        "Russian violet",   "Smoky black"};

uint16_t blue_shades[62] = {
        RGB565_Air_Force_blue_RAF,        RGB565_Air_Force_blue_USAF,        RGB565_Air_superiority_blue,      RGB565_Alice_blue,
        RGB565_Azure,                     RGB565_Azureish_white,             RGB565_Baby_blue,                 RGB565_Bleu_de_France,
        RGB565_Blue,                      RGB565_Blue_gray,                  RGB565_Bondi_blue,                RGB565_Brandeis_blue,
        RGB565_Capri,                     RGB565_Carolina_blue,              RGB565_Celeste,                   RGB565_Cerulean,
        RGB565_Cobalt_Blue,               RGB565_Columbia_Blue,              RGB565_Cornflower_blue,           RGB565_Cyan,
        RGB565_Dark_blue,                 RGB565_Denim,                      RGB565_Dodger_blue,               RGB565_Duke_blue,
        RGB565_Egyptian_blue,             RGB565_Electric_blue,              RGB565_Glaucous,                  RGB565_Electric_indigo,
        RGB565_Indigo,                    RGB565_Indigo_dye,                 RGB565_International_Klein_Blue,  RGB565_Iris,
        RGB565_Light_blue,                RGB565_Majorelle_Blue,             RGB565_Maya_blue,                 RGB565_Medium_blue,
        RGB565_Medium_slate_blue,         RGB565_Midnight_blue,              RGB565_Non_photo_blue,            RGB565_Oxford_Blue,
        RGB565_Pacific_Blue,              RGB565_Palatinate_blue,            RGB565_Periwinkle,                RGB565_Persian_blue,
        RGB565_Phthalo_blue,              RGB565_Powder_blue,                RGB565_Prussian_blue,             RGB565_Robin_egg_blue,
        RGB565_Royal_blue,                RGB565_Sapphire,                   RGB565_Sky_blue,                  RGB565_Slate_blue,
        RGB565_Steel_blue,                RGB565_Teal_blue,                  RGB565_Tiffany_Blue,              RGB565_True_Blue,
        RGB565_Tufts_Blue,                RGB565_Turquoise,                  RGB565_UCLA_Blue,                 RGB565_Ultramarine,
        RGB565_Violet_blue,               RGB565_Vivid_sky_blue
};

string blue_shade_names[62] = {
"Air Force blue RAF",       "Air Force blue USAF",      "Air superiority blue",     "Alice blue",
"Azure",                    "Azureish white",           "Baby blue",                "Bleu de France",
"Blue",                     "Blue gray",                "Bondi blue",               "Brandeis blue",
"Capri",                    "Carolina blue",            "Celeste",                  "Cerulean",
"Cobalt Blue",              "Columbia Blue",            "Cornflower blue",          "Cyan",
"Dark blue",                "Denim",                    "Dodger blue",              "Duke blue",
"Egyptian blue",            "Electric blue",            "Glaucous",                 "Electric indigo",
"Indigo",                   "Indigo dye",               "International Klein Blue", "Iris",
"Light blue",               "Majorelle Blue",           "Maya blue",                "Medium blue",
"Medium slate blue",        "Midnight blue",            "Non photo blue",           "Oxford Blue",
"Pacific Blue",             "Palatinate blue",          "Periwinkle",               "Persian blue",
"Phthalo blue",             "Powder blue",              "Prussian blue",            "Robin egg blue",
"Royal blue",               "Sapphire",                 "Sky blue",                 "Slate blue",
"Steel blue",               "Teal blue",                "Tiffany Blue",             "True Blue",
"Tufts Blue",               "Turquoise",                "UCLA Blue",                "Ultramarine",
"Violet blue",              "Vivid sky blue"    };

#define num_shades 3
string shade_names[num_shades] = {"azure", "black", "blue"};

uint16_t*   shade_tone_colors[num_shades] = {azure_shades,      black_shades,       blue_shades};
string*     shade_tone_names[num_shades] = {azure_shade_names,  black_shade_names,  blue_shade_names};
uint16_t    num_tones[num_shades] = {39, 18, 62};
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