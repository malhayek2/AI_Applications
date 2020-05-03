config apply_solution 1
config cube_display 3
config depth_limit 6
config ids_limit 6
config solution_display 1
config generation_limit 1e+06
config storage_limit 1e+06

echo ------------------init Yellow_green edge goal ----------
init goal \
    ****w**** ****g**g* ****r**** ****b**** ****o**** ***yy**** \

run astarSearch.cmd
echo ------------------init Yellow_orange edge goal----------
init goal \
    ****w**** ****g**g* ****r**** ****b**** ****o**o* ***yy**y* \

run astarSearch.cmd
echo ------------------init 2x2x2 YGO goal ----------
init goal \
    ****w**** ***gg*gg* ****r**** ****b**** ****oo*oo ***yy*yy* \

run astarSearch.cmd


echo Was it solved?
equal goal