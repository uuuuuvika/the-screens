#include "../../main.h"

void text_update_horizontal(MatrixContext *mctx, Text *text, int should_move)
{
    if (mctx == NULL || mctx->offscreen_canvas == NULL || text == NULL)
        return;
    if (text->lines == NULL || text->lines->lines == NULL || text->lines->count == 0)
        return;

    size_t idx = text->current_line % text->lines->count;
    const char *line = text->lines->lines[idx];
    if (line == NULL)
        return;

    int text_advance = draw_text(
        mctx->offscreen_canvas,
        text->font,
        text->x,
        text->y + text->font_baseline,
        text->color.r,
        text->color.g,
        text->color.b,
        line,
        text->letter_spacing
    );

    if (should_move) {
        text->x -= 1;
        if (text->x + text_advance < 0) {
            text->x = text->x_orig;
            text->y = text->y_orig;
            text->current_line = (text->current_line + 1) % text->lines->count;
        }
    }
}

void text_update(MatrixContext *mctx, Text *top, Text *bottom, int should_move)
{
    if (mctx == NULL || mctx->offscreen_canvas == NULL || top == NULL || bottom == NULL)
        return;

    text_update_horizontal(mctx, top, should_move);
    text_update_horizontal(mctx, bottom, should_move);
}
