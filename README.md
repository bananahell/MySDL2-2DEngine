# My functional SDL2 2D Engine!!!

Pedro Nogueira  

## Specs

### ./makefile

Project's Mr. Compiler dude. ```make help``` shows you the commands and you can run off from that.  
It basically just compiles using either ```make debug``` or ```make release``` (difference being the -d debug flag, anyway...), [cppcheck](https://cppcheck.sourceforge.io/) with ```make cppcheck``` and execute the compiled executable with ```make execute```.  
A "does it all" command suggestion:  
```make clean && make debug && make cppcheck && make execute```  

#### ./(lib, include and src)

My makefile's organization (follow it (ง'̀-'́)ง):  

* lib - Imported libraries  
* include - Headers' home (in this case, the .h's)  
* src - Beautifull raw code (.cpp's)  
* bin - Object files generated from compilation (.o's)  

### ./README.md

Always updated (I wish), in its beatifull markdown format. watchout for trailing whitespaces!!!  

## Style

I'm using [VSCode](https://code.visualstudio.com/) in my [Ubuntu 20.04.3 LTS](https://ubuntu.com/download).  
In it I'm using [this very famous C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) and I'll config it to Google's formatting style using 120 long lines.  

## Project's content

The main goal of this whole debauchery, besides procrastinating from uni, is gathering my SDL2 knowledge I got from a game development class I took a while ago (gods, i miss [Lucity](https://github.com/bananahell/Lucity) =/) and using it to make a "copy-paste" engine.  
This means that, by cloning this engine in the same directory as a game I would make, I'd be able to use it for said game immediately. This would:  
* Reduce the game's own code;  
* Expand the reusability of this engine;  
* Keep the engine clean from "game code" to actually work on it alone without having to bother to delete code everytime I want to enhance it;  
* Maybe even more shit, idk man...  
