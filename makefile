CPP_FARM:Farm.o chickenException.o chickenFarm.o cowException.o cowFarm.o Animal.o farmMarket.o Market.o sheepException.o sheepFarm.o Cow.o Chicken.o Sheep.o
	g++ -g Animal.o chickenException.o chickenFarm.o cowException.o cowFarm.o Farm.o 		farmMarket.o Market.o sheepException.o sheepFarm.o Cow.o Chicken.o Sheep.o -o CPP_FARM
Animal.o:Animal.cpp Animal.h
	g++ -c Animal.cpp
Chicken.o:Chicken.cpp Chicken.h Animal.h
	g++ -c Chicken.cpp
chickenException.o:chickenException.cpp chickenException.h
	g++ -c chickenException.cpp
chickenFarm.o:chickenFarm.cpp chickenFarm.h Farm.h Animal.h Chicken.h
	g++ -c chickenFarm.cpp
Cow.o:Cow.cpp Cow.h Animal.h
	g++ -c Cow.cpp
cowException.o:cowException.cpp cowException.h
	g++ -c cowException.cpp
cowFarm.o:cowFarm.cpp cowFarm.h Farm.h Animal.h Cow.h
	g++ -c cowFarm.cpp
Farm.o:Farm.cpp Farm.h Animal.h
	g++ -c Farm.cpp
farmMarket.o:farmMarket.cpp Market.h Farm.h Animal.h cowException.h sheepException.h chickenException.h cowFarm.h sheepFarm.h chickenFarm.h Cow.h Chicken.h Sheep.h
	g++ -c farmMarket.cpp
Market.o:Market.cpp Market.h Farm.h Animal.h cowException.h sheepException.h chickenException.h cowFarm.h sheepFarm.h chickenFarm.h Cow.h Chicken.h Sheep.h
	g++ -c Market.cpp
Sheep.o:Sheep.cpp Sheep.h Animal.h
	g++ -c Sheep.cpp
sheepException.o:sheepException.cpp sheepException.h
	g++ -c sheepException.cpp
sheepFarm.o:sheepFarm.cpp sheepFarm.h Farm.h Animal.h Sheep.h
	g++ -c sheepFarm.cpp
clean:
	rm -f *.o
