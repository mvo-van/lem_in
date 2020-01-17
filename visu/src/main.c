#include "../includes/visu.h"


int		set_SDL(t_sdl_setup *sdl_setup)
{
	int	ret;
	if (0 != SDL_Init(SDL_INIT_VIDEO))
		return (0);
	ret = SDL_CreateWindowAndRenderer(X_SCREEN,Y_SCREEN,0, &sdl_setup->window, &sdl_setup->render);	if (ret || !(sdl_setup->window && sdl_setup->render && sdl_setup->render))
	{

		if (sdl_setup->window)
			SDL_DestroyWindow(sdl_setup->window);
		if (sdl_setup->render)
			SDL_DestroyRenderer(sdl_setup->render);
		SDL_Quit();
		return (0);
	}
	SDL_SetWindowTitle(sdl_setup->window, "lem_in");
	return (1);
}

SDL_Texture *loadImage(const char path[], SDL_Renderer *renderer)
{
	SDL_Surface *tmp = NULL;
	SDL_Texture *texture = NULL;
	tmp = SDL_LoadBMP(path);
	if(NULL == tmp)
		return NULL;
	texture = SDL_CreateTextureFromSurface(renderer, tmp);
	SDL_FreeSurface(tmp);
	if(NULL == texture)
		return NULL;
	return texture;
}


int main(int argc, char *argv[])
{
	t_sdl_setup	sdl_setup;
	SDL_Texture *img_back;
	if (!set_SDL(&sdl_setup))
		return (0);



	if (!(img_back = loadImage("./img/fourmiliere.bmp", sdl_setup.render)))
		printf("error image");

	SDL_Rect rect;
	SDL_QueryTexture(img_back, NULL, NULL, &rect.w, &rect.h);
	rect.x = 0; rect.y = 0;

	SDL_RenderCopy(sdl_setup.render, img_back, NULL, &rect);

SDL_SetRenderDrawColor(sdl_setup.render,255,255,255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(sdl_setup.render,0,0,200,120);
	//SDL_RenderDrawCircle(sdl_setup.render,200,200,200);


	SDL_Event ev;
	int flag = 1;
	while (flag)
	{
 		if ( SDL_PollEvent(&ev) ) // Nous traitons les événements de la queue
 		{
			// if (ev.type == SDL_Quit)
			// 	flag = 0;
			// else
			// {
				SDL_RenderPresent(sdl_setup.render);
				SDL_Delay(2000);

				flag = 0;
		}
	}
	SDL_DestroyTexture(img_back);
	SDL_DestroyRenderer(sdl_setup.render);
	SDL_DestroyWindow(sdl_setup.window);
	SDL_Quit();
	return EXIT_SUCCESS;
}



