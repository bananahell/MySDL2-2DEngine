#ifndef STATE
#define STATE

#include <SDL2/SDL.h>

#include "Music.h"
#include "Sprite.h"

/**
 * The interface to creating a state/phase in the game. This is where the "level
 * logic" is made.
 * @author Pedro Nogueira
 */
class State {
 public:
  bool isRunning;  // Flag that continues the game loop.

  /**
   * Default destructor.
   */
  virtual ~State();
  /**
   * Initializes the state in specific, like sprites and sounds.
   */
  virtual void initState() = 0;
  /**
   * Main game logic of this specific state.
   */
  virtual void update() = 0;
  /**
   * Handles what is shown in the screen.
   * @param renderer Engine's renderer, passed all the way up from the game.
   */
  virtual void render() = 0;

  /**
   * Waits and checks for events triggered by SDL2. Has default.
   * SDL_QUIT - User-requested quit
   */
  virtual void handleEvents();

  /**
   * Main state loop. While isRunning - handleEvents(), update() and render().
   * @param renderer Engine's renderer, passed all the way up from the game.
   */
  void stateLoop();
};

#endif  // STATE
