#include <cmath>
#include <pthread.h>
#include <stdio.h>

#include "AStarPathfinder.h"
#include "Small_Vector.h"
#include "raylib.h"

static const int WIDTH = 800;
static const int HEIGHT = 800;

static const int N_SQUARES = 64;

// TODO: Add keyboard input to stablish through display origin and target, as
// well
//       as the 'walls' and call the AStarPathfinder algorithm every time it
//       adds a new wall. It should not start until you have one origin and one
//       target
//

float
actual_distance( size_t x, size_t y )
{
    return abs( (int)x - (int)y );
}

float
manhattan( size_t x, size_t y )
{
    return std::sqrt( x * x - y * y );
}

int
main(void)
{
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

  // Ni idea de esas constantes
  for (int i = 0; i < (N_SQUARES * N_SQUARES); ++i) {
    squares[i].x = x_start + 5.7 * (i % N_SQUARES) + 5.7 * (i % N_SQUARES);
    squares[i].y = y_start + 5.7 * (i / N_SQUARES) + 5.7 * (i / N_SQUARES);
    squares[i].width = w_pitch;
    squares[i].height = h_pitch;
  }

  static Color tile_color = VIOLET;

  size_t tile_begin = 0;
  size_t tile_target = 0;

  SetTargetFPS(60);
  while (!WindowShouldClose())
  {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      tile_color = YELLOW;
      int mx = GetMouseX();
      int my = GetMouseY();

      printf("Values mouse %d %d\n", mx, my);

      tiles_drawed = false;
    } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        tile_color = BLACK;
        // int mx = GetMouseX();
        // int my = GetMouseY();
        tiles_drawed = false;
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

  CloseWindow();

  return 0;
}
