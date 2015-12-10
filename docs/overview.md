@mainpage
@tableofcontents

@section Allapot A robot állapotleírása

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
Az alkalmazásunk felhasználói felülete QML alapú GUI. A QML felelős az adatok összekapcsolásáért, változások esetén a megfelelő objektumok frissítéséért, grafikonok
újrarajzolásáért, valamint gombok kezeléséért. 
