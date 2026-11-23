#ifndef MAIN_H
#define MAIN_H

#if defined(__has_include)
#if __has_include(<led-matrix-c.h>)
#include <led-matrix-c.h>
#else
struct LedFont;
struct LedCanvas;
struct RGBLedMatrix;
struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};
#endif
#else
#include <led-matrix-c.h>
#endif

// #include <MagickWand/MagickWand.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <strings.h>
#include <math.h>
#include <signal.h>

#define MATRIX_WIDTH 128
#define MATRIX_HEIGHT 32
#define PANEL_WIDTH 64.0
#define PANEL_HEIGHT 32.0
#define NUM_FRAMES 30
#define FRAME_DELAY 4
#define M_PI 3.14159265358979323846
#define MAX_LOOPS 10
#define MIN_LOOPS 5

typedef struct
{
    double time;
    int num_particles;
} ParticleAnimation;

typedef struct
{
    char **lines;
    size_t count;
    char *buffer;
} TextLines;

typedef struct
{
    struct LedFont *font;
    int font_width;
    int font_baseline;
    struct Color color;
    TextLines *lines;
    size_t current_line;
    int x_orig;
    int y_orig;
    int x;
    int y;
    int letter_spacing;
} Text;

typedef struct
{
    struct RGBLedMatrix *matrix;
    struct LedCanvas *offscreen_canvas;
    int width;
    int height;
} MatrixContext;

int matrix_setup(MatrixContext *ctx);
int rand_range(int min, int max);

TextLines *load_text_lines_from_file(const char *filename);
int text_setup(MatrixContext *mctx, Text *top, Text *bottom);
void text_update(MatrixContext *mctx, Text *top, Text *bottom, int should_move);

void particle_animation_init(ParticleAnimation *anim);
void particle_animation_draw(ParticleAnimation *anim, MatrixContext *mctx,
                             int width, int height);
void plot_mapped_pixel(MatrixContext *mctx, double x, double y,
                       int step_idx, int total_steps);

void map_64x64_to_32x128_flipped(double *x, double *y);

#endif