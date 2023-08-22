#ifndef MUSIC
#define MUSIC

#include <SDL2/SDL_mixer.h>

#include <string>

#define PLAY_FOREVER -1

class Music {
 public:
  Mix_Music* music;  // SDL mix music component

  /**
   * Default constructor. Just starts as nullptr.
   */
  Music();
  /**
   * Constructor that already opens the song passed.
   * @param fileName Name of the file with its directory.
   */
  explicit Music(std::string);
  /**
   * Opens the song passed.
   * @param fileName Name of the file with its directory.
   */
  void open(const std::string&);
  /**
   * Plays music in the game, specially for background music.
   * @param times Number of times music is played (PLAY_FOREVER for forever).
   */
  void play(int);
  /**
   * Stops the currently playing music.
   * @param msToStop Time in miliseconds until the music stops.
   */
  void stop(int);
};

#endif  // MUSIC
