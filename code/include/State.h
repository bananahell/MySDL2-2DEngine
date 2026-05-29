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

  std::vector<std::unique_ptr<GameObject>> objectVector;  // Game objects here.

  /**
   * Default constructor.
   */
  State();

  /**
   * `[VIRTUAL]` Default destructor.
   */
  virtual ~State();

  /**
   * `[PURE VIRTUAL]` Initializes the state, with sprites and sounds.
   */
  virtual void initState() = 0;

  /**
   * `[PURE VIRTUAL]` Main game logic of this specific state.
   */
  virtual void update() = 0;

  /**
   * `[VIRTUAL]` Handles what is shown in the screen.
   */
  virtual void render();

  /**
   * `[VIRTUAL]` Handling of player input.
   */
  virtual void handleEvents();

  /**
   * Handling of player keyboard press.
   * @param event Used to specify which key was pressed.
   */
  void keyDownKeyboard(SDL_Event);

  /**
   * Handling of player mouse press.
   */
  void mouseButtonDown();

  /**
   * Main state loop. While isRunning - handleEvents(), update() and render().
   */
  void stateLoop();
};

#endif  // STATE
