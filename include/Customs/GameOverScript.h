#ifndef __GAME_OVER_SCRIPT__
#define __GAME_OVER_SCRIPT__

#include "Components/Animator.h"
#include "Engine/InputSystem.h"
#include "Components/Script.h"
#include "Engine/GameObject.h"
#include "Engine/SceneManager.h"
#include "Engine/CameraSystem.h"
#include "Customs/AudioController.h"

#include <string>

class GameOverScript : public Script {

public:
  GameOverScript(GameObject *owner);
  std::string GetComponentName() override { return "SnowScript"; };
  void FixedComponentUpdate() override;
  void Start() override;
 // char GetMovement() { return movements; };

protected:
  void ComponentUpdate() override;
private:
  void CreateAnimations();
  InputSystem *input = nullptr;
  Animator *animator = nullptr;
  Vector *position = nullptr;
  int play=0;

};

#endif
