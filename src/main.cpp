// for initializing and shutdown functions
#include <SDL.h>
#include <iostream>

// SDL requires main to be defined with int, char**
int main(int, char**)
{
  // returns zero on success else non-zero
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "error initializing SDL: " << SDL_GetError() << std::endl;
  }

  SDL_Window* window = SDL_CreateWindow("Random Walk",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					50 * 10, 50 * 10, 0);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_RenderSetScale(renderer, 10, 10);

  int x = 25;
  int y = 25;
  SDL_Color color = { 160, 250, 90, 255 };

  SDL_Event event;
  while (true) {
    if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
      break;
    }

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, x, y);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}

