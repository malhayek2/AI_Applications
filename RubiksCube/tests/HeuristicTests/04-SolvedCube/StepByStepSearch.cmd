config enable_prompt 0
echo
config generation_limit 1e7
config solution_display 1
config apply_solution 1
config cube_display 3
config heuristic 1
echo
run moves.cmd
run goals.cmd

moves basic
init goal \
    ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y**** \

run astarSearch.cmd

init goal \
    *w**ww*** ****g**** ****r**** *b**b**** *o**o**** ****y**** \

run astarSearch.cmd

init goal \
    *w*www*** *g**g**** ****r**** *b**b**** *o**o**** ****y**** \

run astarSearch.cmd

init goal \
    *w*www*w* *g**g**** *r**r**** *b**b**** *o**o**** ****y**** \

run astarSearch.cmd


init goal \
    ww*www*w* gg**g**** *r**r**** *b**b**** *oo*o**** ****y**** \

run astarSearch.cmd

init goal \
    wwwwww*w* gg**g**** *r**r**** *bb*b**** ooo*o**** ****y**** \

run astarSearch.cmd

init goal \
    wwwwwwww* ggg*g**** rr**r**** *bb*b**** ooo*o**** ****y**** \

run astarSearch.cmd


init goal \
    wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**** ****y**** \

run astarSearch.cmd

config heuristic 2 

init goal \
    wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *b**y**** \
    wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yr*** \
    wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***ry**** \
    wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***oy**** \


run astarSearch.cmd
init goal rg_rb_ob_corners rb_bo_og_corners og_rg_rb_corners layer1
run astarSearch.cmd
config generation_limit 1e7
init goal layer1
run astarSearch.cmd

moves D D'
init goal rb_t rg_t br_t bo_t gr_t go_t og_t ob_t
run astarSearch.cmd

moves g_right g_left r_right r_left b_right b_left o_left o_right g_right_w g_left_w r_right_w r_left_w b_right_w b_left_w o_left_w o_right_w

init goal rg_edge rb_edge bo_edge og_edge layer2
run astarSearch.cmd

moves D D'
init goal rb_t rg_t br_t bo_t gr_t go_t og_t ob_t
run astarSearch.cmd

moves g_right g_left r_right r_left b_right b_left o_left o_right g_right_w g_left_w r_right_w r_left_w b_right_w b_left_w o_left_w o_right_w

init goal rg_rb_bo_edge rb_bo_og_edge bo_og_rg_edge og_rg_rb_edge layer2
run astarSearch.cmd
config generation_limit 1e6

moves D D'
init goal rb_t rg_t br_t bo_t gr_t go_t og_t ob_t
run astarSearch.cmd

moves g_right g_left r_right r_left b_right b_left o_left o_right g_right_w g_left_w r_right_w r_left_w b_right_w b_left_w o_left_w o_right_w
init goal layer2
run astarSearch.cmd

moves yellow_cross yellow_cross2

config generation_limit 1e6

init goal yellow_cross
run astarSearch.cmd

moves fix_edges  y y'


init goal cross&edges
run astarSearch.cmd

config generation_limit 1e7

moves corner y y'

init goal solved
run astarSearch.cmd



show cube
equal goal
