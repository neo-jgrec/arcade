# Arcade

Arcade is a **gaming platform**: a program that lets the user choose a game to play and keeps a register of player scores

To be able to deal with the elements of your gaming plateform at run-time, your graphics libraries and your games must be implemented as **dynamic libraries**, loaded at runtime

Each GUI available for the program must be used as a shared library that will be loaded and used dynamically by the main program.

> [!WARNING]
> It is STRICTLY FORBIDDEN to refer to a graphics library explicitly in your main program.  
> Only your dynamic libraries can do so.  
> This also applies to your games.

## Interfaces

> [!NOTE]
> You must add a README.md file in your repository containing, at least, the email address of the leader of the group with which you have collaborated for the interface.
