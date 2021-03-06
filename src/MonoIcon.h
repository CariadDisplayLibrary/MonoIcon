#ifndef _MONO_ICON_H
#define _MONO_ICON_H

#include <Cariad.h>

class MonoIcon : public Widget {
    private:
        const color_t *_bg;
        const uint8_t *_icon;
        color_t _color;
        const char *_text;
        const uint8_t *_font;
        color_t _textcol;

        uint16_t *_buffer;

    public:
        static const color_t MonoIconBG[];

        MonoIcon(Touch &ts, Cariad &dev, int x, int y, int w, int h, const color_t *bg, const uint8_t *icon, color_t color, 
                                const char *text, const uint8_t *font, color_t textcol) :
            Widget(ts, dev, x, y), _bg(bg), _icon(icon), _color(color), _text(text), _font(font), _textcol(textcol) {
                _touch = true;
                _sense_x = 0;
                _sense_y = 0;
                _sense_w = w;
                _sense_h = h;
            }

        MonoIcon(Touch &ts, Cariad &dev, int x, int y, int w, int h, const color_t *bg,  
                                const char *text, const uint8_t *font, color_t textcol) :
            Widget(ts, dev, x, y), _bg(bg), _icon(NULL), _color(Color::Black), _text(text), _font(font), _textcol(textcol) {
                _touch = true;
                _sense_x = 0;
                _sense_y = 0;
                _sense_w = w;
                _sense_h = h;
            }

        void draw(Cariad *dev, int x, int y);
        void setColor(color_t c);
        void setIcon(const uint8_t *i);

        void setPixel(int x, int y, color_t c);
        color_t colorAt(int x, int y);
};

#endif
