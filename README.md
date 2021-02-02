# Algorithms-and-Data-Structures
This is the Final Project for the *Algorithms and Data Structures* course (Politecnico di Milano)

## Topic
To implement a monitoring mechanism of relationships between entities (for example people) that change over time
Imagine, for example, a social network, in which new users can register, and existing users can cancel their own account, become "friends" with other users, break the friendship relationship, etc.
Relationships between entities are not necessarily symmetrical. For example, Alice may be Bruno's "friend", but the friendship is not reciprocated (Bruno is not Alice's friend)

More abstractly, the mechanism monitors the following phenomena:
  * A new entity begins to be monitored
  * A monitored entity stops being monitored
  * A new relationship is established between 2 monitored entities
  * A relationship existing between 2 monitored entities ceases to exist
  * Each entity has an identifying name (for example "Alice", "Bruno", "Carlo")
  * There can be different types of relationships between entities, each identified by a name (for example, "friend_of", "follows", "peer_of")
  * Every relationship has a line (for example, if Alice is "friend_of" Bruno, the line of the relationship is from Alice to Bruno, so Bruno is the "receiver" of the relationship), and it is not necessarily symmetrical

Following a specific command, the system returns, for each relationship, the entity that "receives" more reports (if there are more entities whose number of reports received is maximum, these are printed in ascending order of identification)
The application must be optimized to manage a large number of entities and relationship instances, but generally few (identifying) types of relationships

## The project
* Standard C language implementation (with *libc only*) of a program that reads a sequence of commands from standard input,
each corresponding to a change in the entities or in the relationships between entities and, when required, produces on standard output,
for each type of monitored relationship, the identifier of the entity that is the recipient of the largest number of instances of that relationship, and the number of relationships that the entity receives

## The code
**main.c** contains the program implemented

**file.in** contains the given input while **file.out** contains the expected output
