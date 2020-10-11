
#include "Mechanics.h"

int main()
{
    srand (time(NULL));

    Mechanics Game;

    Game.Intro();

    while (true)
    {
        Game.PrintActors();
        Game.GetPlayerChoice();
        Game.CheckForKilled();

    }

}
