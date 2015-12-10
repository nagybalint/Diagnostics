@mainpage
@tableofcontents

@section Architektura Architektúra áttekintés

@section Allapot A robot állapotleírása
A robot egy időpillanthoz tartozó állapotát egy RobotState osztály fogja össze. Ez a robotra jellemző adatokat tartalmazza (vonalszenzor adatai, szabályozó paraméterek, akku feszültség, autó sebesség, lásd: a linkelt osztályt).

A robot állapot lekérdezését egy timer ütemezi, 100 milliszekundumonként kér új státuszjelentést a robottól. Minden a robottól kapott státusz üzenet bekerül egy RobotState példányba, ami aztán mentésre kerül egy history-ban. 
A RobotStateHistory osztály megvalósít egy tárolót (std::vector), aminek az elemei RobotState példányokra mutató unique pointerek. Ezen felül tárolja az utolsó N db elemet külön QList listákban is, mivel a QML csak ezeket tudja feldolgozni.

A robot aktuális állapotára mindig mutat a RobotStateHistory::currentState pointer. 

Mivel a program egyéb komponenseinek szüksége van az új állapotra, ezért új állapot eltárolása után egy szignál kerül kibocsátásra.

@section Kommunikacio Kommunikáció
@subsection Kapcsolat Kapcsolat a robottal
@subsection Uzenetfeldolgozas Az üzenettípusok
Az üzenetek feldolgozása a Strategy tervezési minta alaján történik. Az üzenetfeldolgozást végző osztályok UML diagramja az alábbi ábrán látató.
![](umldiagrams/RobotMessage.jpg)
Minden üzenet típus a közös absztrakt RobotMessage ősosztályból származik le. Ez rendelkezik egy publikus belső enum osztállyal, melyben a lehetséges üzenetek típusai vannak felsorolva. Az ősosztálynak van is egy ilyen RobotMessage::Type típusú tagváltozója, melyet minden leszármazott osztály megörököl és magának köteles kitölteni.

Az osztály rendelkezik egy virtuális parseMessage() függvénnyel, melyet minden leszármazott osztály megvalósít. Ennek a feladat, hogy a bemeneteként kapott streamből az üzenetet beolvassa.

Ezen kívül található az ősosztályban még egy std::uniqueptr<RobotMessage> típusú pointer is. Ehhez a mutatóhoz az üzenet feldolgozása során, az üzenet típusát már feldolgozva fog létrejönni egy leszármazott típusú objektu, amire a messageIn pointer fog mutatni, majd a messageIn-re a parseMessage() függvényt meghívva a leszármazott osztály azonos függvénye fog lefutni.

Ezzel megoldható, hogy a beérkező üzenetek típusa által meghatározott módon, különböző algoritmusok szerint olvassák be magukat, így megvalósítva a Strategy tervezési mintát.  

@subsection Feldolgozas A bejövő üzenetek feldolgozása
A bejövő üzenetek feldolgozása a következő állapotdiagramon látszik.
![](umldiagrams/protocol.jpg)
@section UI A user interface
