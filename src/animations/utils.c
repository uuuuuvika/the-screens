#include "../../main.h"

void particle_animation_init(ParticleAnimation *anim)
{
    anim->time = 0.0;
    anim->num_particles = 900;
}

// map 64x64 coordinates into 32x128:
// the lower half has to be shifted up by 32 (y - 32) onto the 1st panel (x: 0..63, y: 0..31)
// the upper half (y < 32) is shifted right by 64 (x + 64) onto the 2nd panel (x: 64..127, y: 0..31)
void map_64x64_to_32x128_flipped(double *x, double *y)
{
    double shifted_x = *x;
    double shifted_y = *y;

    if (*y >= PANEL_HEIGHT)
        shifted_y = *y - PANEL_HEIGHT;
    else
        shifted_x = *x + PANEL_WIDTH;

    *x = shifted_x;
    *y = shifted_y;
}

void plot_mapped_pixel(MatrixContext *mctx, double x, double y,
                       int step_idx, int total_steps)
{
    map_64x64_to_32x128_flipped(&x, &y);

    float fade = step_idx / total_steps;
    uint8_t col = 255.0 * (1.0 - fade);

    if (x >= 0 && x < mctx->width && y >= 0 && y < mctx->height)
        led_canvas_set_pixel(mctx->offscreen_canvas, (int)x, (int)y, col, col, col);
}