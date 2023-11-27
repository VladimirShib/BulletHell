# YoRHa Hacking Game
This is my version of the hacking game from NieR: Automata, made as a class project for a course on C++ and SFML.

**1. Genre**

This game can be classified as a top-down shooter with bullet hell elements.

**2. Game mechanics**
- The player controls a small ship that can move freely in all directions and shoot a continuous stream of bullets.
- The game consists of progressively harder levels.
- To advance to the next level, player must destroy all enemies on the current level while dodging their attacks.
- Player can take up to two hits before the ship is destroyed.
- The game ends if the player's ship is destroyed.
- Player can press ESC at any time to pause the game. From the pause screen it is possible to exit to the main menu.
- In the main menu player can start the game from the first level, go to the level selection screen or exit the game.
- All levels are available on the level selection screen. Player can start the game from any level.

**3. Details**

- *Controls*

W, A, S, D to move, mouse to rotate the ship (the ship is always pointing in the direction of the mouse). Holding down the left mouse button fires bullets that fly in the ship's front direction.

- *Enemies*

There are different types of enemies: some move in set paths and shoot randomly in all directions, others can chase the player and shoot homing projectiles. Not always are all enemies present on the game field initially - they may appear after certain events (destruction of other enemies or obstacles).

- *Damage*

The player's ship can take two hits, the third one destroys the ship. Damage can be taken from enemy shots or from collision with certain obstacles on the game field. Taking damage prevents the possibility of taking new damage for a short time, to avoid situations with instant destruction from multiple bullets flying together.

- *Level progression*

Transitions between levels are without pause, with a short splash screen. The difficulty of the game increases with each level, which is reflected in the increased number of enemies and projectiles flying around. The goal of the game is to complete as many levels as possible.
<br/><br/><br/><br/><br/>
**1. Жанр**

Игру можно классифицировать как шутер с видом сверху с элементами bullet hell.

**2. Игровые механики**
- Игрок управляет небольшим кораблем, который может свободно перемещаться во всех направлениях и стрелять непрерывным потоком пуль.
- Игра состоит из постепенно усложняющихся уровней.
- Для перехода на следующий уровень нужно уничтожить всех врагов на текущем уровне, параллельно уклоняясь от их выстрелов.
- Игрок может получить до двух ударов прежде чем его корабль разрушится.
- Если корабль игрока уничтожен, игра заканчивается.
- В любой момент можно нажать ESC, что поставит игру на паузу. Из меню паузы можно выйти в главное меню.
- В главном меню можно начать игру с первого уровня, перейти на экран выбора уровней или выйти из игры.
- На экране выбора уровней доступны все уровни. Можно начать игру с любого.

**3. Подробности**

- *Управление*

W, A, S, D для передвижения, мышь для вращения корабля (корабль всегда "смотрит" в направлении мыши). Удержание левой кнопки мыши производит выстрелы, которые летят по направлению взгляда корабля.

- *Противники*

Существуют разные типы противников: одни двигаются по конкретным траекториям и беспорядочно стреляют во все стороны, другие могут преследовать игрока и стрелять самонаводящимися снарядами. Не всегда все противники присутствуют на игровом поле изначально - они могут появляться после определенных событий (уничтожение других противников либо препятствий).

- *Урон*

Корабль игрока может выдержать два удара, на третий корабль уничтожается. Урон можно получить от выстрелов противника либо от столкновения с определенными препятствиями на игровом поле. Получение урона на короткое время предотвращает возможность получения нового, чтобы избежать ситуаций с мгновенным уничтожением от нескольких снарядов, летящих вместе.

- *Продвижение по уровням*

Переходы между уровнями осуществляются без остановок, с короткой заставкой. Сложность игры возрастает с каждым уровнем, что выражается в повышенном числе противников и летающих вокруг снарядов. Цель игры - пройти как можно больше уровней.
