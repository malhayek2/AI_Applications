config enable_prompt 0
echo
config generation_limit 1e7
config solution_display 1
config apply_solution 1
config cube_display 3
config heuristic 1
define move level1 F' R' D' R F' F'
define move level2 F U' R U
define move level3 R' D' R F' F'
define move level4 y F' R' D' R F' F' y'
define move level5 y F U' R U  y'
define move level6 y R' D' R F' F' y'
define move level7 y y F' R' D' R F' F' y' y'
define move level8 y y F U' R U y' y'
define move level9 y y R' D' R F' F' y' y'
define move level10 y' F' R' D' R F' F' y
define move level11 y' F U' R U y
define move level12 y' R' D' R F' F' y


define move red_edge2 D R F'
define move green_edge2 y' D R F' y
define move blue_edge2 y D R F' y'
define move orange_edge2 y' y' D R F' y y

define move bow_corner R' D R D'
define move ogw_corner R' D R D'
define move rbw_corner R' D R D'
define move orw_corner R' D R D' 
define move other_w R' D' R
define move other2_w F D F'
define move other3_w R' D2 R D R' D' R
define move other4_w L D L' R' D' R

define move g_right x' x' y' U R U' R' U' F' U F y x x
define move g_left x' x' y' U' L' U L U F U' F y x x
define move r_right x' x' y y U R U' R' U' F' U F y' y' x x
define move r_left x' x' y y U' L' U L U F U' F y' y' x x
define move b_right x' x' y U R U' R' U' F' U F y' x x 
define move b_left x' x' y U' L' U L U F U' F y' x x
define move o_left x' x' U' L' U L U F U' F x x
define move o_right x' x' U R U' R' U' F' U F x x

define move g_right_w x' x' y' U R U' R' U' F' U F U2 U R U' R' U' F' U F y x x
define move g_left_w x' x' y' U' L' U L U F U' F U R U' R' U' F' U F y x x
define move r_right_w x' x' y y U R U' R' U' F' U F U2 U R U' R' U' F' U F y' y' x x
define move r_left_w x' x' y y U' L' U L U F U' F y' y' U R U' R' U' F' U F x x
define move b_right_w x' x' y U R U' R' U' F' U F U2 U R U' R' U' F' U F y' x x 
define move b_left_w x' x' y U' L' U L U F U' F U R U' R' U' F' U F y' x x
define move o_left_w x' x' U' L' U L U F U' F U2 U R U' R' U' F' U F x x
define move o_right_w x' x' U R U' R' U' F' U F U2 U R U' R' U' F' U F   x x


define move yellow_cross y x' x' F R U R' U' F' x x y'
define move yellow_cross2 y y x' x' F R U R' U' F' x x y' y' 
define move fix_edges x' x' R U R' U R U2 R' U x x
define move fix_edges2 x' x' y' R U R' U R U2 R' U y x x
define move fix_edges3 x' x' y' y' R U R' U R U2 R' U y y x x
define move fix_edges4 x' x' y R U R' U R U2 R' U y' x x 


define move corner x' x'  U R U' L' U R' U' L x x
define move corner2 x' x' y U R U' L' U R' U' L y' x x
define move corner3 x' x' y y U R U' L' U R' U' L y' y' x x
define move corner4 x' x' y' U R U' L' U R' U' L y x x

define move test1 x' x' R' D' R D x x
define cube wr_edge ****w**w* ****g**** *r**r**** ****b**** ****o**** ****y****
define cube wg_edge ***ww**** *g**g**** ****r**** ****b**** ****o**** ****y****
define cube wb_edge ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y****
define cube wo_edge *w**w**** ****g**** ****r**** ****b**** *o**o**** ****y****

define cube wr_wg_edge ***ww**w* *g**g**** *r**r**** ****b**** ****o**** ****y****
define cube wr_wb_edge ***ww**w* ****g**** *r**r**** *b**b**** ****o**** ****y****
define cube wg_wb_edge ***www*** *g**g**** ****r**** *b**b**** ****o**** ****y****
define cube wg_wo_edge *w*ww**** *g**g**** ****r**** ****b**** *o**o**** ****y****
define cube wo_wb_edge *w**ww*** ****g**** ****r**** *b**b**** *o**o**** ****y****
define cube wo_wr_edge *w**w**w* ****g**** *r**r**** ****b**** *o**o**** ****y****

define cube wo_wr_wb *w**ww*w* ****g**** *r**r**** *b**b**** *o**o**** ****y****
define cube wo_wr_wg *w*ww**w* *g**g**** *r**r**** ****b**** *o**o**** ****y****
define cube wb_wg_wr ***www*w* *g**g**** *r**r**** *b**b**** ****o**** ****y****
define cube wb_wg_wo *w*www*** *g**g**** ****r**** *b**b**** *o**o**** ****y****

define cube white_cross *w*www*w* *g**g**** *r**r**** *b**b**** *o**o**** *********

define cube wog_corner_0 ww*www*w* gg**g**** *r**r**** *b**b**** *oo*o**** *********
define cube wob_corner_0 *wwwww*w* *g**g**** *r**r**** *bb*b**** oo**o**** *********
define cube wrg_corner_0 *w*wwwww* *gg*g**** rr**r**** *b**b**** *o**o**** *********
define cube wrb_corner_0 *w*www*ww *g**g**** *rr*r**** bb**b**** *o**o**** *********

define cube ow_corners wwwwww*w* gg**g**** *r**r**** *bb*b**** ooo*o**** *********
define cube bw_corners *wwwww*ww *g**g**** *rr*r**** bbb*b**** oo**o**** *********
define cube rw_corners *w*wwwwww *gg*g**** rrr*r**** bb*b***** *o**o**** *********
define cube gw_corners ww*wwwww* ggg*g**** rr**r**** *b**b**** *oo*o**** *********
define cube og_rb_corner ww*www*ww gg**g**** *rr*r**** bb**b**** *oo*o**** *********
define cube rg_ob_corner *wwwwww** *gg*g**** rr**r**** *bb*b**** oo**o**** *********

define cube rg_rb_ob_corners *wwwwwwww *gg*g**** rrr*r**** bbb*b**** oo**o**** *********
define cube rb_bo_og_corners wwwwww*ww gg**g**** *rr*r**** bbb*b**** ooo*o**** *********
define cube og_rg_rb_corners ww*wwwwww ggg*g**** rrr*r**** bb**b**** *oo*o**** *********


define cube layer1 wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**** *********

define cube ob_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**o* ****y**b*
define cube og_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**o* ****y**g*
define cube go_t wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***oy****
define cube gr_t wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***ry****
define cube bo_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yo***
define cube br_t wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yr***
define cube rg_t wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *g**y****
define cube rb_t wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *b**y****

define cube rg_edge wwwwwwwww ggg*gg*** rrrrr**** bbb*b**** ooo*o**** *********
define cube rb_edge wwwwwwwww ggg*g**** rrr*rr*** bbbbb**** ooo*o**** *********
define cube bo_edge wwwwwwwww ggg*g**** rrr*r**** bbb*bb*** ooooo**** *********
define cube og_edge wwwwwwwww ggggg**** rrr*r**** bbb*b**** ooo*oo*** *********

define cube ft1 rb_t rg_edge
define cube ft2 rb_t og_edge
define cube ft3 rg_t rb_edge
define cube ft4 rg_t og_edge
define cube ft5 og_t bo_edge
define cube ft6 og_t rg_edge
define cube ft7 ob_t rb_edge
define cube ft8 ob_t rg_edge
define cube ft9 go_t rg_edge
define cube ft10 go_t bo_edge
define cube ft11 gr_t rb_edge
define cube ft12 gr_t og_edge
define cube ft13 br_t rg_edge
define cube ft14 br_t og_edge
define cube ft15 bo_t rb_edge
define cube ft16 bo_t og_edge

define cube et1 rb_t rg_edge og_edge
define cube et2 rb_t rg_edge bo_edge
define cube et11 rb_t bo_edge og_edge
define cube et3 rg_t rb_edge og_edge
define cube et4 rg_t rb_edge bo_edge
define cube et13 rg_t og_edge bo_edge
define cube et5 og_t bo_edge rb_edge
define cube et6 og_t bo_edge rg_edge
define cube et12 og_t rb_edge rg_edge
define cube et7 ob_t og_edge rg_edge
define cube et8 ob_t rb_edge og_edge
define cube et14 ob_t rb_edge rg_edge
define cube et9 go_t rb_edge bo_edge
define cube et10 go_t bo_edge rg_edge
define cube et15 go_t rb_edge bo_edge
define cube et16 gr_t rb_edge bo_edge
define cube et17 gr_t bo_edge og_edge
define cube et18 gr_t rb_edge og_edge

define cube rg_rb_edge wwwwwwwww ggg*gg*** rrrrrr*** bbbbb**** ooo*o**** *********
define cube rb_bo_edge wwwwwwwww ggg*g**** rrr*rr*** bbbbbb*** ooooo**** *********
define cube bo_og_edge wwwwwwwww ggggg**** rrr*r**** bbb*bb*** oooooo*** *********
define cube rg_og_edge wwwwwwwww gggggg*** rrrrr**** bbb*b**** ooo*oo*** *********
define cube rg_bo_edge wwwwwwwww ggg*gg*** rrrrr**** bbb*bb*** ooooo**** *********
define cube rb_og_edge wwwwwwwww ggggg**** rrr*rr*** bbbbb**** ooo*oo*** *********

define cube rg_rb_bo_edge wwwwwwwww ggg*gg*** rrrrrr*** bbbbbb*** ooooo**** *********
define cube rb_bo_og_edge wwwwwwwww ggggg**** rrr*rr*** bbbbbb*** oooooo*** *********
define cube bo_og_rg_edge wwwwwwwww gggggg*** rrrr***** bbb*bb*** oooooo*** *********
define cube og_rg_rb_edge wwwwwwwww gggggg*** rrrrrr*** bbbbb**** ooo*oo*** *********

define cube layer2 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *********

define cube yellow_l1 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yy****
define cube yellow_l2 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y**yy***
define cube yellow_l3 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ***yy**y*
define cube yellow_l4 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ****yy*y*

define cube yellow_line1 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y**y**y*
define cube yellow_line2 wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** ***yyy***

define cube yellow_cross wwwwwwwww gggggg*** rrrrrr*** bbbbbb*** oooooo*** *y*yyy*y*
define cube by_edge wwwwwwwww gggggg*** rrrrrr*** bbbbbb*b* oooooo*** *y*yyy*y*
define cube ry_edge wwwwwwwww gggggg*** rrrrrr*r* bbbbbb*b* oooooo*** *y*yyy*y*
define cube gy_edge wwwwwwwww gggggg*g* rrrrrr*r* bbbbbb*b* oooooo*** *y*yyy*y*
define cube cross&edges wwwwwwwww gggggg*g* rrrrrr*r* bbbbbb*b* oooooo*o* *y*yyy*y*

define cube yob_corner wwwwwwwww gggggg*g* rrrrrr*r* bbbbbb*bb oooooooo* *y*yyy*yy
define cube yog_corner wwwwwwwww gggggggg* rrrrrr*r* bbbbbb*b* oooooo*oo *y*yyyyy*
define cube yrg_corner wwwwwwwww gggggg*gg rrrrrrrr* bbbbbb*b* oooooo*o* yy*yyy*y*
define cube yrb_corner wwwwwwwww gggggg*g* rrrrrr*rr bbbbbbbb* oooooo*o* *yyyyy*y*

define cube yob_yog_corner yob_corner yog_corner
define cube yog_yrg_corner yog_corner yrg_corner
define cube yrg_yrb_corner yrg_corner yrb_corner
define cube yob_yrg_corner yob_corner yrg_corner
define cube yob_yrb_corner yob_corner yrb_corner
define cube yog_yrb_corner yog_corner yrb_corner 

define cube yob_yog_yrg_corner yob_corner yog_corner yrg_corner
define cube yob_yog_yrb_corner yob_corner yog_corner yrb_corner
define cube yob_yrg_yrb_corner yob_corner yrg_corner yrb_corner

define cube yog_yrg_yrb_corner  yog_corner yrg_corner yrb_corner

define cube yrg_01 wwwwwwwww ****g***r ****r*y** ****b**** ****o**** g***y****
define cube yrg_02 wwwwwwwww ****g***g ****r*r** ****b**** ****o**** y***y****
define cube yrg_03 wwwwwwwww ****g***y ****r*g** ****b**** ****o**** r***y****

define cube yob_01 wwwwwwwww ****g**** ****r**** ****b***b ****o*o** ****y***y
define cube yob_02 wwwwwwwww ****g**** ****r**** ****b***y ****o*b** ****y***o
define cube yob_03 wwwwwwwww ****g**** ****r**** ****b***o ****o*y** ****y***b

define cube yrb_01 ****w**** ****g**** ****r***r ****b*b** ****o**** **y*y****
define cube yrb_02 ****w**** ****g**** ****r***b ****b*y** ****o**** **r*y****
define cube yrb_03 ****w**** ****g**** ****r***y ****b*r** ****o**** **b*y****

define cube ygo_01 ****w**** ****g*y** ****r**** ****b**** ****o***g ****y*o**
define cube ygo_02 ****w**** ****g*o** ****r**** ****b**** ****o***y ****y*g**
define cube ygo_03 ****w**** ****g*g** ****r**** ****b**** ****o***o ****y*y**

define cube stuff00 cross&edges yrg_01 yob_01 yrb_01 ygo_01
define cube stuff01 cross&edges yrg_01 yob_02 yrb_02 ygo_02
define cube stuff02 cross&edges yrg_01 yob_02 yrb_03 ygo_03
define cube stuff03 cross&edges yrg_01 yob_03 yrb_03 ygo_03

define cube stuff10 cross&edges yrg_02 yob_02 yrb_02 ygo_02
define cube stuff11 cross&edges yrg_02 yob_03 yrb_03 ygo_03
define cube stuff12 cross&edges yrg_02 yob_03 yrb_01 ygo_01
define cube stuff13 cross&edges yrg_02 yob_01 yrb_01 ygo_01

define cube stuff20 cross&edges yrg_03 yob_03 yrb_03 ygo_03
define cube stuff21 cross&edges yrg_03 yob_01 yrb_01 ygo_01
define cube stuff22 cross&edges yrg_03 yob_01 yrb_02 ygo_02
define cube stuff23 cross&edges yrg_03 yob_03 yrb_03 ygo_03

define cube ol_01 wwwwwwwww ****g*ygy ********* ****b*yby ********* *********
define cube ol_11 wwwwwwwww ****g**** ****r*yry ****b**** ****o*yoy *********
define cube ol_21 wwwwwwwww ****g**** ****r*y** ****b*y*y ****o***y *y*yyy*y*
define cube ol_31 wwwwwwwww ****g*y** ****r*y*y ****b***y ****o**** *y*yyy*y*
define cube ol_41 wwwwwwwww ****g*y*y ****r***y ****b**** ****o*y** *y*yyy*y*
define cube ol_51 wwwwwwwww ****g***y ****r**** ****b*y** ****o*y*y *y*yyy*y*

define cube yellow ********* ********* ********* ********* ********* yyyyyyyyy

define cube ol_02 ol_01 ygo_01 yrg_03 yob_02 yrb_02
define cube ol_12 ol_11 yrb_03 yrg_01 yob_03 ygo_02
define cube ol_22 ol_21 yob_02 yrb_02 ygo_02 yrg_01
define cube ol_32 ol_31 ygo_01 yrg_01 yrb_03 yob_02
define cube ol_42 ol_41 ygo_01 yrg_03 yrb_03 yob_03
define cube ol_52 ol_51 yrg_03 yrb_02 ygo_02 yob_03

define cube ol_finished layer2 yellow


define cube solved wwwwwwwww ggggggggg rrrrrrrrr bbbbbbbbb ooooooooo yyyyyyyyy

moves basic
init goal \
    ****ww*** ****g**** ****r**** *b**b**** ****o**** ****y**** \

search graph astar
init goal \
    *w**ww*** ****g**** ****r**** *b**b**** *o**o**** ****y**** \

search graph astar
init goal \
    *w*www*** *g**g**** ****r**** *b**b**** *o**o**** ****y**** \

search graph astar
init goal \
    *w*www*w* *g**g**** *r**r**** *b**b**** *o**o**** ****y**** \

search graph astar
init goal \
    ww*www*w* gg**g**** *r**r**** *b**b**** *oo*o**** ****y**** \

search graph astar
init goal \
    wwwwww*w* gg**g**** *r**r**** *bb*b**** ooo*o**** ****y**** \

search graph astar
init goal \
    wwwwwwww* ggg*g**** rr**r**** *bb*b**** ooo*o**** ****y**** \

search graph astar
init goal \
    wwwwwwwww ggg*g**** rrr*r**** bbb*b**** ooo*o**** ****y**** \

search graph astar
config heuristic 2 
init goal \
    wwwwwwwww ggg*g**** rrr*r**r* bbb*b**** ooo*o**** *b**y**** \
    wwwwwwwww ggg*g**** rrr*r**** bbb*b**b* ooo*o**** ****yr*** \
    wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***ry**** \
    wwwwwwwww ggg*g**g* rrr*r**** bbb*b**** ooo*o**** ***oy**** \

search graph astar
init goal rg_rb_ob_corners rb_bo_og_corners og_rg_rb_corners layer1
search graph astar
config generation_limit 1e7
init goal layer1
search graph astar
moves D D'
init goal rb_t rg_t br_t bo_t gr_t go_t og_t ob_t
search graph astar
moves g_right g_left r_right r_left b_right b_left o_left o_right g_right_w g_left_w r_right_w r_left_w b_right_w b_left_w o_left_w o_right_w
init goal rg_edge rb_edge bo_edge og_edge layer2
search graph astar
moves D D'
init goal rb_t rg_t br_t bo_t gr_t go_t og_t ob_t
search graph astar
moves g_right g_left r_right r_left b_right b_left o_left o_right g_right_w g_left_w r_right_w r_left_w b_right_w b_left_w o_left_w o_right_w
init goal rg_rb_bo_edge rb_bo_og_edge bo_og_rg_edge og_rg_rb_edge layer2
search graph astar
config generation_limit 1e6
moves D D'
init goal rb_t rg_t br_t bo_t gr_t go_t og_t ob_t
search graph astar
moves g_right g_left r_right r_left b_right b_left o_left o_right g_right_w g_left_w r_right_w r_left_w b_right_w b_left_w o_left_w o_right_w
init goal layer2
search graph astar
moves yellow_cross yellow_cross2
config generation_limit 1e6
init goal yellow_cross
search graph astar
moves fix_edges  y y'
init goal cross&edges
search graph astar
config generation_limit 1e7
moves corner y y'
init goal solved
search graph astar