#include <iostream>

#include "SDL2/SDL.h"

class Game {
 public:
  Game();
  ~Game();
  /**
   * It starts the whole game, creating a window and a renderer and setting the isRunning flag.
   * @param title Window's name that shows on its top.
   * @param xPos Window's position in the screen - X axis.
   * @param yPos Window's position in the screen - Y axis.
   * @param width Window's width.
   * @param height Window's height.
   * @param fullscreen Whether the game will be fullscreen.
   */
  void init(const char *, int, int, int, int, bool);
  /**
   * Waits and checks for events triggered by SDL2.
   * - SDL_QUIT
   */
  void handleEvents();
  void update();
  /**
   * Handles what is shown in the screen.
   */
  void render();
  /**
   * Destroys the renderer, the window, and quits the game.
   */
  void clean();
  /**
   * @return Whether the game is running.
   */
  bool running() { return isRunning; }

 private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
};
