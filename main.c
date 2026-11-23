#include "main.h"

volatile sig_atomic_t running = 1;

void handle_signal(int sig)
{
    (void)sig;
    running = 0;
}

int main(int argc, char **argv)
{
    MatrixContext mctx = {0};
    ParticleAnimation particle_anim = {0};

    signal(SIGINT, handle_signal);
    signal(SIGTSTP, handle_signal);

    if (!matrix_setup(&mctx))
    {
        printf("Failed to setup matrix.\n");
        return 1;
    }
    particle_animation_init(&particle_anim);

    while (running)
    {
        led_canvas_fill(mctx.offscreen_canvas, 0, 0, 0);
        particle_animation_draw(&particle_anim, &mctx, PANEL_WIDTH, PANEL_HEIGHT * 2);
        usleep(25000);

        mctx.offscreen_canvas = led_matrix_swap_on_vsync(mctx.matrix, mctx.offscreen_canvas);
    }

    printf("\x1b[36m\nShutting down gracefully.\n\x1b[0m");
    led_matrix_delete(mctx.matrix);
    return 0;
}