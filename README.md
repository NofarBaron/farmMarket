# Farm Market
The farmMarket class is the class in which we will run. This class include the game`s menu.\
During the game every farmer raises an animal, produces products, and can buy and sell his products.
This game includes error handling, and Observer design pattern in order to handle the trade. 

## The Game
This game include trade in the market, where farmers can buy and sell products accordingly for their needs. 
Each farmer is the owner of a farm that specializes in raising a certain type of animal: cows,
sheep or chickens and therefore raises only the type of animal in which his farm specializes.
Depending on the type of animal the farm produces products: a cow produces milk, a sheep produces wool
And a chicken produces an egg.
Every farmer is interested in a farmer's product as follows: a cow farmer buys eggs, a sheep farmer buys milk
And a chicken farmer buys wool.
During the trading day, each farmer informs the potential buyers (and only them) that he has goods for sale and then the sale is made. 
## Design Pattern
In order to implement the method of transmitting messages between the farmers, we used Observer design pattern.
Saving the farm type and checking it is programmatically incorrect, so i used principles of inheritance
in order to perform a specific gesture action, rather than by type checking.

### Farm class
**Farm production** - Each animal yields an amount of products according to its age, i.e. a sheep whose age is 2 at the time
the call to the function will yield 2 wood.\
**Purchase of products** - Each farm has a farmer who manages it and can purchase products from the farmer who manages another farm. The amount of money of the farms will be updated accordingly after the purchase and sale, when the cost of the products is: Milk goes up $3, wool goes up $2 and an egg goes up.\
**Buying animals** - Each farm can purchase animals according to the type of animal it is raising, and will use any money in order
buy as many animals as possible. Each animal has a different price: a cow costs $10, a sheep costs $5, a chicken costs $3.
