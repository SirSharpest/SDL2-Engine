/*
 *
 * Testing documents for SDL2 Engine
 * 2/10/2015
 *
 * Author: Nathan Hughes /w help from lazyfoo and SDL offical book
 * 
 *
 */

//Using SDL and standard IO
#include <SDL.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
 
//The window we'll be rendering to
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0; 

//Game running switch
bool g_bRunning = false; 


bool init(const* char title, int xpos, int ypos, 
	int height, int witdh, int flags){
	
	   //init SDL (Doing all for now so not to have to init all elements) 
   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
   
		  //If success then create the window! 
		  g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
		   	
		  //if the window creation succeeded create the renderer 
		  if(g_pWindow != 0){
		   		
		   	g_pRenderer = SDL_CreateRenderer(g_pWindow, -1,0); 
		   		
		  }
		  else{
		 			return false; //failed at init
		  }
   }
	
	return true;
	
	}
	
	void render(){
	
   //this is used to fill the screen and make it black
   SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);   
   
   //clear the window to the black indicated above
   SDL_RenderClear(g_pRenderer); 
   
   //show the window
   SDL_RenderPresent(g_pRenderer);	
	
	}
    
int main( int argc, char* args[] ){
   
   if(init("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
   	WINDOW_HEIGHT, WINDOW_WIDTH, SDL_WINDOW_SHOWN)){
   	
   		g_bRunning = true; 
   	
   	}
   	else{
   	
   		return 1; //something went work
   	
   	}
   	
   	while(g_bRunning){
   	
   		render(); 
   	
   	} 
   
   //clean up and exit
   SDL_Quit(); 
   
   
   
   return 0;
}