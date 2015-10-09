/*
 *
 * Testing documents for SDL2 Engine
 * 2/10/2015
 *
 * Author: Nathan Hughes /w help from lazyfoo
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

    
int main( int argc, char* args[] ){
   
   //init SDL (Doing all for now so not to have to init all elements) 
   if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
   
		   	//If success then create the window! 
		   	g_pWindow = SDL_CreateWindow("SDL",SDL_WINDOWPOS_CENTERED, 
		   	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		   	
		   	//if the window creation succeeded create the renderer 
		   	if(g_pWindow != 0){
		   		
		   			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1,0); 
		   		
		   	}
		   	else{
		   			return 1; //failed at init
		   	}
   } 
   
   //at this stage everything should have worked, and now the window can be drawn to screen
   
   //this is used to fill the screen and make it black
   SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);   
   
   //clear the window to the black indicated above
   SDL_RenderClear(g_pRenderer); 
   
   //show the window
   SDL_RenderPresent(g_pRenderer); 
   
   //delay the screen 
   SDL_Delay(5000); 
   
   //clean up and exit
   SDL_Quit(); 
   
   
   
   return 0;
}