//
// Created by rei on 12/19/24.
//

#ifndef PROJECTDUNGEONDESPOILER_ENDMENU_H
#define PROJECTDUNGEONDESPOILER_ENDMENU_H
#include "../Scene.h"

namespace DespoilerEngine {

    class EndMenu final : public Scene{
    public:
        ~EndMenu() override;
        EndMenu(SDL_Window *p_window, SDL_Renderer *p_renderer, const int *p_width,
                const int *p_height);
        void init() override;
        void run (int &state) override;
        void cleanUp() const override;
        void handleEvents(SDL_Event &event, bool &isRunning,
                          int &currentIndex) override;

    private:
        mutable SDL_Texture *BgTextureMain;
    };

} // DespoilerEngine

#endif //PROJECTDUNGEONDESPOILER_ENDMENU_H
