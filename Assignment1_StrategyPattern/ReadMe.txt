By Oleksandr Dymov
#25987555

Runs on Vs 2010 and higher

- No external libraries need


Description of work done:

The strategy pattern was successfully implemented directly into the course project.
As the different strategies were assigned to comupter players randomly, some manual
input is required directly into the console. The strategies work according to the 
specifications and the program displays the before and after status of the players 
statistics (countries owned only and number of armies in them). The program flow 
is pretty strtaight forward and involves all the main steps seen the actual risk 
implementation game.

Here is the list of affected files for this assignment were a specific demarquation
was inserted in comments for modifications:

- MainPlayPhase.cpp : line 144
- Player.cpp : line 24
- battle.cpp : line 18

Added classes:

- CompAttack (for strategy implementation)
- Strategy (for the different strategies used)

**Analysis and Design are explained in the code comments**

 