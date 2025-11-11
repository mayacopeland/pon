#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

int main() {
  // TODO(maya): make this customisable
  int width = 1280;
  int height = 720;

  SDL_Window *window = nullptr;
  SDL_Surface *screen_surface = nullptr;
  SDL_Surface *man1 = nullptr;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    SDL_Log("SDL failed to initialize: %s", SDL_GetError());
    return 1;
  }

  window = SDL_CreateWindow("pon!", width, height, 0);
  if (window == nullptr) {
    SDL_Log("Failed to Create Window: %s", SDL_GetError());
    return 1;
  }

  screen_surface = SDL_GetWindowSurface(window);
  bool exit = false;

  std::string path = "./Man1.bmp";
  man1 = SDL_LoadBMP(path.c_str());
  if (man1 == nullptr) {
    SDL_Log("Failed to load man1.png: %s", SDL_GetError());
    return 1;
  }
  while (!exit) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      // If event is quit type
      if (e.type == SDL_EVENT_QUIT) {
        exit = true;
      }
    }

    SDL_FillSurfaceRect(screen_surface, nullptr,
                        SDL_MapSurfaceRGB(screen_surface, 0xFF, 0xFF, 0xFF));
    SDL_BlitSurface(man1, nullptr, screen_surface, nullptr);

    SDL_UpdateWindowSurface(window);
  }
  SDL_DestroySurface(man1);
  man1 = nullptr;

  SDL_DestroyWindow(window);
  window = nullptr;
  screen_surface = nullptr;

  SDL_Quit();
  return 0;
}