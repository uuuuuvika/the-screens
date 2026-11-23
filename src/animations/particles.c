#include "../../main.h"

// 900 - crazy stuff
//  void particle_animation_draw(ParticleAnimation *anim, MatrixContext *mctx, int x_offset, int width)
//  {
//      const double centerX = x_offset + width / 2.0;
//      const double centerY = mctx->height / 2.0;
//      const double baseRadius = (mctx->height < width ? mctx->height : width) * 0.25;

//     const double xAmplitude = 2.4;
//     const double yAmplitude = 1.2;
//     const double xFreq = 0.015;
//     const double yFreq = 0.060;
//     const double xSpeed = 2.2;
//     const double ySpeed = 2.0;

//     for (int f = 0; f < anim->num_particles; f++) {
//         double x = centerX - baseRadius * xAmplitude *
//                    sin((anim->time + f * xFreq) * xSpeed);
//         double y = centerY - baseRadius * yAmplitude *
//                    cos((anim->time + f * yFreq) * ySpeed);

//     double fade = (double)f / anim->num_particles;

//     uint8_t brightness = 255 * (1.0 - fade);
//     uint8_t red = brightness;
//     uint8_t green = brightness;
//     uint8_t blue = brightness;

//     if (x >= x_offset && x < x_offset + width && y >= 0 && y < mctx->height) {
//         led_canvas_set_pixel(mctx->offscreen_canvas, (int)x, (int)y, red, green, blue);
//     }
//     }

//     anim->time += 0.002;
// }

// with 800 particles - snake
// void particle_animation_draw(ParticleAnimation *anim, MatrixContext *mctx, int x_offset, int width)
// {
//     const double centerX = x_offset + width / 2.0;
//     const double centerY = mctx->height / 2.0;
//     const double baseRadius = (mctx->height < width ? mctx->height : width) * 0.25;

//     const double xAmplitude = 3.0;
//     const double yAmplitude = 1.2;
//     const double xFreq = 0.02;
//     const double yFreq = 0.04;
//     const double xSpeed = 0.2;
//     const double ySpeed = 1.0;

//     for (int f = 0; f < anim->num_particles; f++) {
//         double x = centerX - baseRadius * xAmplitude *
//                    sin((anim->time + f * xFreq) * xSpeed);
//         double y = centerY - baseRadius * yAmplitude *
//                    cos((anim->time + f * yFreq) * ySpeed);

//        double fade = (double)f / anim->num_particles;

//         uint8_t brightness = 255 * (1.0 - fade);
//         uint8_t red = brightness;
//         uint8_t green = brightness;
//         uint8_t blue = brightness;

//         if (x >= x_offset && x < x_offset + width && y >= 0 && y < mctx->height) {
//             led_canvas_set_pixel(mctx->offscreen_canvas, (int)x, (int)y, red, green, blue);
//         }
//     }
//     anim->time += 0.03;
// }

static void draw_circle(ParticleAnimation *anim, MatrixContext *mctx,
                                double cx, double cy,
                                double rx, double ry,
                                double xFreq, double yFreq,
                                double dir)
{
    int count = anim->num_particles > 0 ? anim->num_particles : 800;

    double xSpeed = 1.0 * dir;
    double ySpeed = 0.5 * dir;

    for (int f = 0; f < count; f++)
    {
        double x = cx - rx * sin((anim->time + f * xFreq) * xSpeed);
        double y = cy - ry * cos((anim->time + f * yFreq) * ySpeed);

        plot_mapped_pixel(mctx, x, y, f, count);
    }
}

void particle_animation_draw(ParticleAnimation *anim, MatrixContext *mctx, int width, int height)
{
    double cx = width * 0.5;
    double cy = height * 0.5;

    double baseRadius = (height < width ? height : width) * 0.25;

    draw_circle(anim, mctx, cx, cy,
                        baseRadius * 1.6, baseRadius * 1.6,
                        0.015, 0.03,
                        1.0);

    draw_circle(anim, mctx, cx, cy,
                        baseRadius * 1.6, baseRadius * 1.6,
                        0.015, 0.03,
                        -1.0);

    anim->time += 0.03;
}
