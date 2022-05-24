#ifndef ENGINE
#define ENGINE

#include <SDL2/SDL.h>

#include "Rect.h"
#include "State.h"
#include "Vec2.h"

/**
 * The big daddy of the whole code, the whole reason of this project. This is
 * the class that, if handled well, will reduce a lot of redundant code in the
 * game that's usually used by any SDL2 game. Just inherit this guy in your main
 * Game class that your game's code will be shortened to exactly the necessary.
 * @author Pedro Nogueira
 */
class Engine {
 public:
  static Engine *engineInstance;  // "this" engine, accessed from anywhere
  SDL_Window *window;             // The window of the engine itself.
  SDL_Renderer *renderer;  // Whatever that needs to be rendered to the screen.
  State *state;            // The current state/phase of the game.

  /**
   * Default constructor, initializes all as nullptr.
   */
  Engine();
  /**
   * Default destructor, simply calls Engine::clean().
   */
  ~Engine();

  /**
   * Initializes the game in specific, like its states and flags.
   */
  virtual void initGame() = 0;
  /**
   * Runs the game in specific. Put your states logic here, and don't forget to
   * clean in the end.
   */
  virtual void run() = 0;

  /**
   * Initializes SDL, the window, and the renderer.
   * @param title Window's name that shows on its top.
   * @param xPos Window's position in the screen - X axis.
   * @param yPos Window's position in the screen - Y axis.
   * @param width Window's width.
   * @param height Window's height.
   * @param fullscreen Whether the game will be fullscreen.
   */
  void initEngine(const char *, int, int, int, int, bool);
  /**
   * Destroys the audio mix, the images, the renderer, the window, and quits the
   * game.
   */
  void clean();
};

#endif  // ENGINE
