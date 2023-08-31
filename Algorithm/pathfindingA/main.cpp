#include "raylib.h"
#include "Small_Vector.h"
#include "AStarPathfinder.h"


static const int WIDTH = 800;
static const int HEIGHT = 800;

static const int N_SQUARES = 64;

// TODO: Add keyboard input to stablish through display origin and target, as well
//       as the 'walls' and call the AStarPathfinder algorithm every time it adds
//       a new wall. It should not start until you have one origin and one target
//

int
main( void )
{
  InitWindow( WIDTH, HEIGHT, "Raylib PATHFIND" );

  Rectangle squares[N_SQUARES * N_SQUARES] = {0};

  int w_pitch = (WIDTH / N_SQUARES);
  w_pitch = w_pitch - w_pitch / 2;
  int h_pitch = (HEIGHT / N_SQUARES);
  h_pitch = h_pitch - h_pitch / 2;
  
  int x_start = w_pitch;
  int y_start = h_pitch;

  x_start += 30;
  y_start += 30;

  // Ni idea de esas constantes
  for( int i = 0; i < (N_SQUARES * N_SQUARES); ++i )
    {
      squares[i].x = x_start + 5.7 * (i % N_SQUARES) + 5.7 * (i % N_SQUARES);
      squares[i].y = y_start + 5.7 * (i / N_SQUARES) + 5.7 * (i / N_SQUARES);
      squares[i].width  = w_pitch;
      squares[i].height = h_pitch;
    }
    
  SetTargetFPS(60);
  while( !WindowShouldClose() )
    {
      BeginDrawing();

      ClearBackground(LIGHTGRAY);
      DrawText("PATHFIND Example!", 10, 10, 20, BLACK);

      for( int i = 0; i < N_SQUARES * N_SQUARES; ++i )
	{
	  DrawRectangleRec( squares[i], VIOLET );
	}
      EndDrawing();
    } 

  CloseWindow();
  
  return 0;
}