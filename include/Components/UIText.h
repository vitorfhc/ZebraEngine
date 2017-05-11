#ifndef __UI_TEXT__
#define __UI_TEXT__

#include <string>

#include "Engine/Component.h"
#include "Engine/GameObject.h"
#include "Engine/GraphicsSystem.h"
#include "Engine/SDLSystem.h"
#include "Engine/sdl2include.h"
#include "Log/sdl_log.h"

using namespace std;

class UIText : public Component {
public:
  UIText(GameObject *owner, string message, string fontPath, int size, Uint8 r,
         Uint8 g, Uint8 b, Uint8 a, Uint8 mode);
  string GetComponentName() override { return "UIText"; };
  void Start() override;
  void FixedComponentUpdate() override;
  void ComponentUpdate() override;

private:
  string m_message;
  TTF_Font *m_font = nullptr;
  SDL_Color m_color;
  SDL_Texture *m_texture = nullptr;
  SDL_Rect m_rect;
};

#endif
