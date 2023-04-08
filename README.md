# Inventory-management-system
This application is supposed to be an inventory system and for my project 
I chose as an inspiration a real game that I play when I have some time to waste:
Counter Strike Global Offensive (CSGO). The menu and the basics of this project 
are designed to represent the basics/the basic concepts of the skins from CSGO and 
the inventory of players.
When I built the program I used four main classes: Shop, Item, Skin and 
Inventory. The application was programmed such that Shop is the base class, from 
which Item inherits its elements. In the same manner the class Skin, inherits from 
Item and Inventory inherits from Skin. For all the classes there were created a set of 
attributes, setters and getters, constructors, and destructors as well as additional 
methods where needed.
When it comes to skins, there isn’t in general much attributes to talk about, 
there are a few places where you can buy skins for CSGO, some of them are verified 
by the game developers but some are not. In CSGO there are many items such as 
guns, knives, characters, gloves, each being a part of a category. For each item exists 
dozens of skins with various prices, wears, rarities, numbers of stickers. Moreover, 
each player has its own inventory containing various skins for different items. To 
easy up the process and since there an infinite number of skin for sale we consider 
an infinite stock of each skin in each shop. To be generic we consider the inventory
of a single person which has enough money to buy anything.
