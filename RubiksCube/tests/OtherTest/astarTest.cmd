config apply_solution 1
config cube_display 3
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+07
config storage_limit 1e+07
echo ------------------init goals---------------
init goal \
    ***ww**** *g**g**** ****r**** ****b**** ****o**** ****y***y \
    ****w**w* ****g**** *r**r**** ****b**** ****o**** ****y***y \
    **w**www* ggg*g*g*g ****r**** bb*bb*bb* **o*o*o** yyy*yyy*y \
echo --------------------init cube--------------


echo --------------------set Allan moves--------
define move Allan F F U' L R' F F L' R U' F F
moves Allan

echo Apply solution is ON
echo Trying to solve this cube
show cube
search graph astar
echo

echo Resulting cube is
show cube
echo

echo Goal states
show goal

echo --------------------moves B D F L R' ---------
moves B D F L R'

echo Trying to solve this cube
show cube
search graph astar
echo

echo Resulting cube is
show cube
echo

echo Goal states
show goal
