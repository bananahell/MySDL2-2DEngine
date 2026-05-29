#ifndef STATE
#define STATE

#include <SDL2/SDL.h>

#include <memory>
#include <vector>

#include "GameObject.h"
#include "Music.h"
#include "Sprite.h"

/**
 * The interface to creating a state/phase in the game. This is where the "level
 * logic" is made.
 * @author Pedro Nogueira
 */
class State {
 public:
  bool quitRequested;  // Flag that continues the game loop.
  std::vector<std::unique_ptr<GameObject>> objectVector;

  /**
   * Default constructor.
   */
  State();
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
   */
  virtual void render();
  /**
   * Waits and checks for events triggered by SDL2. Has default.
   * SDL_QUIT - User-requested quit
   */
  virtual void handleEvents();
  virtual void keyDownKeyboard(SDL_Event);
  virtual void mouseButtonDown();

  /**
   * Main state loop. While isRunning - handleEvents(), update() and render().
   */
  void stateLoop();
};

#endif  // STATE
