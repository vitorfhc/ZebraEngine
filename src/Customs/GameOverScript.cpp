#include "Customs/GameOverScript.h"

GameOverScript::GameOverScript(GameObject *owner) : Script(owner) {}
void GameOverScript::Start() {

  CreateAnimations();
  position = GetOwner()->GetPosition();
  animator = (Animator *)GetOwner()->GetComponent("Animator");
  input = InputSystem::GetInstance();
 GetOwner()->SetZoomProportion(Vector(0,0));


}
void GameOverScript::CreateAnimations(){

    auto snowImage = new Image("assets/Ending_PARTE_FINAL.png",0,0,4096, 2048);

    auto gameOverAnimation= new Animation(GetOwner(),snowImage );
    for (int i = 0; i < 30; i++)
      gameOverAnimation->AddFrame(new Frame(i * 341,0, 341, 256));


     // animator
      auto gameOverAnimator = new Animator(GetOwner());
      gameOverAnimator->AddAnimation("snowAnimation", gameOverAnimation);


}


void GameOverScript::ComponentUpdate() {

 if(play==1)
     animator->PlayAnimation("snowAnimation");

    if(input->GetKeyDown(INPUT_T) && play==0){
   // animator->StopAllAnimations();
      AudioController::GetInstance()->PlayAudio("snowSound", -1);
    play=1;
    }
    else if(input->GetKeyDown(INPUT_T) && play==1){
    play=0;
    AudioController::GetInstance()->StopAudio("snowSound");
    animator->StopAllAnimations();
    }

}
void GameOverScript::FixedComponentUpdate() {

  position->m_x=0;
  position->m_y=0;

}
