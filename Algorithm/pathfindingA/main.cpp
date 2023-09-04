#include <cmath>
#include <cstddef>
#include <pthread.h>
#include <stdio.h>

#include "AStarPathfinder.h"
#include "Small_Vector.h"
#include "raylib.h"
#include "easy/profiler.h"
#include "easy/reader.h"

static const int WIDTH = 800;
static const int HEIGHT = 800;

static const int N_SQUARES = 64;

// TODO: Add keyboard input to stablish through display origin and target, as
// well
//       as the 'walls' and call the AStarPathfinder algorithm every time it
//       adds a new wall. It should not start until you have one origin and one
//       target
//

    static float
actual_distance( size_t x, size_t y )
{
    return abs( (int)x - (int)y );
}

    static float
manhattan( size_t x, size_t y )
{
    return std::sqrt( x * x - y * y );
}

// TODO: Implement so that given a coordinate it returns the
// tile it was pointing to
//
    static size_t
get_box_from_coord( size_t x, size_t y )
{
    return 0;
}

    static void
fill_tiles(
        Rectangle* rec,
        size_t x_start,
        size_t y_start,
        size_t w_pitch,
        size_t h_pitch
        )
{
    EASY_FUNCTION(profiler::colors::cyan);

    // Ni idea de esas constantes
    for (int i = 0; i < (N_SQUARES * N_SQUARES); ++i)
    {
        rec[i].x = x_start + 5.7 * (i % N_SQUARES) + 5.7 * (i % N_SQUARES);
        rec[i].y = y_start + 5.7 * (i / N_SQUARES) + 5.7 * (i / N_SQUARES);
        rec[i].width = w_pitch;
        rec[i].height = h_pitch;
    }
}

    int
main(void)
{
    EASY_PROFILER_ENABLE;

    profiler::startListen();

    Small_Vector<size_t, N_SQUARES * N_SQUARES> Algorithm;

    InitWindow(WIDTH, HEIGHT, "Raylib PATHFIND");

    Rectangle squares[N_SQUARES * N_SQUARES] = {0};

    int w_pitch = (WIDTH / N_SQUARES);
    w_pitch = w_pitch - w_pitch / 2;
    int h_pitch = (HEIGHT / N_SQUARES);
    h_pitch = h_pitch - h_pitch / 2;

    int x_start = w_pitch;
    int y_start = h_pitch;

    x_start += 30;
    y_start += 30;

    bool tiles_drawed = false;

    static Color tile_color = VIOLET;

    fill_tiles( squares, x_start, y_start, w_pitch, h_pitch );

    size_t tile_begin = 0;
    size_t tile_target = 0;

    EASY_BLOCK(profiler::color::magenta);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            tile_color = YELLOW;
            int mx = GetMouseX();
            int my = GetMouseY();

            size_t tile = get_box_from_coord( mx, my );

            tile_begin = tile;

            printf("Values mouse %d %d\n", mx, my);

            tiles_drawed = false;
        } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            tile_color = BLACK;
            int mx = GetMouseX();
            int my = GetMouseY();
            tiles_drawed = false;

            tile_target = get_box_from_coord( mx , my );

        } else if ( IsKeyPressed( KEY_S ) )
        {
            AStar<N_SQUARES * N_SQUARES> a_star {
                .Adyacent = {},
                    .Path = Algorithm,
                    .Closed = {},
                    .Opened = {},
                    .Distance = {},
                    .Heuristic = {},
                    .ComputedDistance = {},
                    .estimate_distance = manhattan,
                    .distance = actual_distance
            };

            EASY_BLOCK(profiler::color::blue);
            ComputeAStar( a_star, tile_begin, tile_target );
        }
        else
        {

        }

        BeginDrawing();
        if (!tiles_drawed)
        {
            ClearBackground(LIGHTGRAY);
            DrawText("PATHFIND Example!", 10, 10, 20, BLACK);

            for (int i = 0; i < N_SQUARES * N_SQUARES; ++i) {
                DrawRectangleRec(squares[i], tile_color);
            }
            tiles_drawed = true;
        }
        EndDrawing();
    }

    profiler::dumpBlocksToFile("test_profile.prof");

    CloseWindow();

    profiler::dumpBlocksToFile("test_profile.prof");

    return 0;
}
