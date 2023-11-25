//
// Copyright Neil McGill, goblinhack@gmail.com
//

#include "my_game.hpp"

void Game::start(void)
{
  TRACE_AND_INDENT();
  CON("Start the game!");

  CON("%%fg=red$OOOOOO  OOOOO  OOOOOO  OOOOOO   OOOOO   OOOO  OOO OOO%%fg=reset$");
  CON("%%fg=red$OOOOOO OOOOOOO OOOOOOO OOOOOOO OOOOOOO OOOOOO OOO OOO%%fg=reset$");
  CON("%%fg=red$   OO! OO! OOO OO! OOO OO! OOO OO! OOO !OO    OO! OOO%%fg=reset$");
  CON("%%fg=red$   O!  !O! O!O !O! O!O !O  O!O !O! O!O !O!    !O! O!O%%fg=reset$");
  CON("%%fg=red$  O!   O!O !O! O!O!O!  O!OO!O  O!OO!O! !!O!!  O!O!!O!%%fg=reset$");
  CON("%%fg=red$ !!    !O! !!! !!O!!   !!!!!!! !!!!!!!  !!!!! !!!O!!!%%fg=reset$");
  CON("%%fg=red$ !:    !!: !!! !!: !!  !!: !!! !!: !!!     !: !!: !!!%%fg=reset$");
  CON("%%fg=red$:!     :!: !:! :!: !:! :!: !:! :!: !:!    !:! :!: !:!%%fg=reset$");
  CON("%%fg=red$:::::: ::::::: ::  ::: ::::::: ::: ::: :::::: ::  :::%%fg=reset$");
  CON("%%fg=red$::::::  :::::  ::  ::: ::::::  ::: ::: :::::: ::  :::%%fg=reset$");
  CON("%%fg=red$::::::  :::::  ::  ::: ::::::  ::: : : :::::  ::  :::%%fg=reset$");
  CON("%%fg=red$:  :    :       :  :    :  ::   :  : : :   :   :  : :%%fg=reset$");
  CON("%%fg=red$.  .      .     .    .  :  :           .   .        :%%fg=reset$");
  CON("%%fg=red$.         .                :     . :   .            :%%fg=reset$");
  CON("%%fg=red$.  . .  : . :   .  : .  :  ::   :. : . ..  .   .  : :%%fg=reset$");
  CON("%%fg=green$Version: " MYVER "%%fg=reset$");
  CON("Press %%fg=yellow$<tab>%%fg=reset$ to complete commands.");
  CON("Press %%fg=yellow$?%%fg=reset$ to show command options.");
  CON("You can also enter python code here.%%fg=reset$");
}
