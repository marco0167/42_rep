# cub3D (codename ----- papon3d)
Progetto 42 Roma Luiss - cub3D - [Marco Coppola](https://www.linkedin.com/in/marcocoppola01/) & [Nicolò Tamiano](https://niko.rip)
- [Make Your Own Raycaster + Playlist ](https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst&index=1&ab_channel=3DSage)
- [Raycasting Documentation 1/x](https://lodev.org/cgtutor/raycasting.html#Introduction)
- [MinilibX Documentation](https://harm-smits.github.io/42docs/)
- [Mlx_Unofficial_Examples](https://github.com/terry-yes/mlx_example)
- [Mlx_Images_Examples](https://github.com/keuhdall/images_example)
- [cub3d Enrik - reference don't copy](https://github.com/Wowbagger1994/42Roma/tree/main)
- [cub3d gleal42 - reference don't copy](https://github.com/gleal42/cub3d)
- [cub3d Portal - reference don't copy](https://github.com/ttranche/cub3D)
- [cub3d basic - reference don't copy](https://github.com/mcombeau/cub3D)
- [cub3d Glagan - reference don't copy](https://github.com/Glagan/42-cub3d)
- [Video Esempio Gioco](http://users.atw.hu/wolf3d/)
- [Javascript Raycasting](https://permadi.com/tutorial/raycast/demo/7/)
- [Another Cub3d Docs](https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf)
- [Tutorial Raycasting written guide](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)

# ~~Makefile config~~
* ~~*NIKO* LINKAR = -Imlx_linux -O3 -lX11 -lXext~~
* ~~*MARCO* LINKAR = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz~~

## Tools
  - [png to xpm converter](https://convertio.co/png-xpm/)
  - [Github Markdown format](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

## PARSER MAP
0 for empty space
1 for wall
C for CLOSED doors (ONLY BONUS)
O for OPEN doors (ONLY BONUS)
N, S, E, W player start position and spawning orientation one of these.
MANAGE SPACES TO BE PARSED

* TODO
- [ ] Parsing Map.
  - [x] Parse all the instructions.
  - [x] Check if the map is not closed by walls.
  - [x] Check if the player spawn position is missing.
  - [x] Check if the there is more than 1 player.
  - [x] Add the door parser. (TO REMOVE)
  - [ ] check verify map that handles every case.
  - [ ] manage new_line and spaces on the end of the file
  - [ ] add the parser for handling ceiling and floor colors.
  - [x] add the parser for handling the textures paths.
- [ ] Check how to handle doors. (SKIP)
- [x] pov direction with arrows.
- [x] Wall Collissions.
- [x] Mouse handler for pov.
  - [ ] Check a better solutionn for Mouse Handling.
- [ ] animated sprite management. (SKIP)
- [x] Raycasting.
  - [x] create the arrow that display the directionn o the player.
  - [x] create the cone of the FoV.
  - [x] each ray must stop when hit a wall.
  - [x] Determine which side of the wall is getting hit.
- [x] Minimap Issues
  - [x] Transform the player to freely move inside the map.
  - [ ] transform the player icon from a square to a dot. (SKIP)
  - [x] the minimap must have a relative position in the game, within fixed border.
- [ ] Textures and Colors
  - [x] Add the Textures to the walls, 1 for each side.
  - [ ] Fix the Textures so that they don't move and they are prefectly fitted and not broken.
  - [x] Add the Ceiling and Floor Colors.
- [ ] Performance Issues
  - [x] Update Minimap only when necessary.
  - [x] Refactoring the code to minimize the numbers of while (marco wants 2 while for everything).
  - [x] Prinnt only background without the space occupied by walls.
- [ ] Check Leaks
- [ ] Check Norminette
- [ ] Complete Check for Pushing :)
