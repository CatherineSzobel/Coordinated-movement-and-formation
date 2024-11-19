# Coordinated-movement-and-formation
# Description of the topic (with a graphic of the final result)
Coordinated movement and formation is a topic i've chosen to research for the course of Gameplay programming at Digital Arts and Entertainment.
The project is implemented using Unreal Engine 4 with a mixture of Blueprints and C++.
the formation logic is implemented in c++ while the logic of selecting the players is made in blueprints.
Coordinated movement and formation is commonly used in game genre such as RTS.

***What is RTS?***

RTS (Real time strategy) is a subgenre of strategy video games that do not progress incrementally in turns, but allow all players to play simultaneously, in "real time". 
By contrast, in turn-based strategy (TBS) games, players take turns to play.

## Design/implementation
one of the important element in coordinated unit movement is the position prediction, 
the units need to know where they will have to go and stand together as one group.

***Units? Groups? Formations?***

**Units** are game entities that have the ability to move around the map using the mouse input of the player.

**Groups** is the general term of the collections of units that will move together, the player can choose and select which units to group together.

**Formations** a more complex group, A formation has an orientation (a front, a back, a right flank, and a left flank). Each unit in the formation tries to maintain a unique relative position within the formation.
More complex models provide an individualized unit facing within the overall formation and support for wheeling during movement.

With this aqcuired information, we have to know that we need to store several pieces of data. 
we need a list of units that make up a group, i used an array to store all the selected units.
Starting from the first unit which is the leader, after choosing a position by clicking, the units start their formation starting from the leader unit.
In general it doesn't matter who is selected as the leader, as it is mostly important to have one.

Using formations, it is good to know that units in a group need to move at the same speed, 
so they could all arrive at their designated positions at the same time.
The most important thing about the formation while in movement and not, is that they stick together as a group.

for this research i've decided on implementing a few formations that were by default in every rts and a few that were interesting to try out.
Formations as such were: 

* the simple line formation in four directions:
* a two line formation:
* a circle formation
* and an extra accidental one while i was experimenting on the two line formation,
* a stair like formation, a not so practical formation to be used in RTS but nevertheless i found it a nice looking formation so I've kept it in the project. 

Each formation has a leader unit, a starting unit in which the formation will build up starting from that unit,
the starting unit is always the first unit of the array.

## Result




[![Watch the video]](https://user-images.githubusercontent.com/55833598/213611435-e9a03c9d-4b3c-4d8e-a1b8-73047aad9221.mp4)
## Conclusion/Future work

I've enjoyed working on this project and would love to work further on it,
as there is still alot of improvements to be made of course.

When the current implementations are improved, I would like to continue on formations I've sadly lacked the time to implement
such as the split formation where the two lines formation split into two groups.


## Articles

https://en.wikipedia.org/wiki/Real-time_strategy#:~:text=Real%2Dtime%20strategy%20(RTS),players%20take%20turns%20to%20play.
https://www.gamedeveloper.com/programming/implementing-coordinated-movement
