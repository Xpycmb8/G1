{animation
	{sequence "power_up_spawn"
		{file "power_up.anm"}
		{resume}
		{events 
			{1 "power_down_start_spawn"}
			{5 "restart_clunk"}
			{10 "restart_clunk"}
			{20 "restart_clunk"}
			{30 "restart_clunk"}
			{40 "restart_clunk"}
			{60 "restart_clunk"}
			{70 "restart_clunk"}
			{80 "restart_clunk"}
			{90 "power_down_leave"}
		}
	}
	{sequence "power_down"
		{speed 0.5}
		{events 
			{1 "power_down_start"}
			{5 "restart_clunk"}
			{10 "restart_clunk"}
			{20 "restart_clunk"}
			{30 "restart_clunk"}
			{40 "restart_clunk"}
			{60 "restart_clunk"}
			{70 "restart_clunk"}
			{80 "restart_clunk"}
			{90 "restart_clunk"}
		}
		{resume}
	}
	{sequence "power_up"
		{resume}
		{events 
			{1 "power_down_check"}
			{5 "restart_clunk"}
			{10 "restart_clunk"}
			{20 "restart_clunk"}
			{30 "restart_clunk"}
			{40 "restart_clunk"}
			{60 "restart_clunk"}
			{70 "restart_clunk"}
			{80 "restart_clunk"}
			{90 "power_down_leave"}
		}
	}
	{sequence "walkstart_f" 
		{speed 0.7}
		{resume}	
		{events 
			{1 "idle_exit"}
			{6 "joint_med_in"}
			{13 "foot_skirmisher_r_back"}
			{14 "foot_skirmisher_l_front"}
			{18 "joint_med_out"}
			{24 "joint_med_in"}
			{27 "foot_skirmisher_r_front"}
			{29 "foot_skirmisher_l_back"}
			{43 "foot_skirmisher_l"}
			{44 "walkstart_f"}
		}
	}
	{sequence "walkloop_fwd" 
		{resume}	
		{events 
			{2 "idle_exit"}
			{4 "joint_med_in"}
			{8 "joint_med_out"}
			{12 "joint_med_in"}
			{15 "joint_med_out"}
			{16 "foot_skirmisher_r_front"}
			{17 "foot_skirmisher_l_back"}
			{20 "joint_med_in"}
			{24 "joint_med_out"}
			{27 "foot_skirmisher_r_back"}
			{28 "foot_skirmisher_l_front"}
			{26 "joint_med_in"}				
			{29 "walkloop_f"}
			
		}
	}
	{sequence "walkstop_f"
		{resume} 
		{events 	
			{4 "joint_med_in"}
			{14 "joint_med_in"}
			{16 "foot_skirmisher_r_front"}
			{17 "foot_skirmisher_l_back"}
			{18 "joint_med_out"}				
			{24 "joint_med_out"}			
			{25 "foot_skirmisher_l_front"}
			{26 "joint_med_out"}
			{29 "idle_enter"}
			{30 "foot_skirmisher_r_back"}
		}
	}
	{sequence "run_swing_to_walk"
		{resume}	
		{events 
			{1 "idle_exit"}
			{2 "joint_med_in"}
			{3 "joint_med_out"}
			{5 "joint_med_in"}
			{6 "foot_skirmisher_r_front"}
			{9 "joint_med_out"}
			{10 "foot_skirmisher_l_back"}
			;{11 "joint_med_in"}
			{12 "joint_med_out"}
			{16 "foot_skirmisher_r_back"}
			;{11 "foot_skirmisher"}
			{13 "run_swing_to_walk"}
		}
	}

	{sequence "run_pass_to_walk" 
		{resume}	
		{events 
			{1 "idle_exit"}
			{2 "joint_med_in"}
			{3 "joint_med_out"}
			{5 "joint_med_in"}
			{6 "foot_skirmisher_r_back"}
			{7 "joint_med_out"}
			{9 "joint_med_in"}
			{10 "foot_skirmisher_r_front"}
			{11 "joint_med_out"}
			{12 "foot_skirmisher"}
			{14 "run_pass_to_walk"}
		}
	}

	{sequence "runstart_f" 
		{resume}	
		{events 
			{1 "idle_exit"}
			{2 "joint_med_in"}
			{3 "joint_med_out"}
			{5 "joint_med_in"}
			{8 "foot_skirmisher"}
			{9 "joint_med_out"}
			{10 "joint_med_in"}
			{11 "foot_skirmisher"}
			;{12 "joint_med_out"}
			{12 "foot_skirmisher"}
			{13 "runstart_f"}
			;{14 "joint_med_in"}
		}
	}
	{sequence "runloop_fwd" 
		{resume}
		{events 
			{1 "idle_exit"}				
			{2 "foot_skirmisher_lf_run"}
			{4 "joint_med_in"}
			{5 "foot_skirmisher_rf_run"}
			{10 "foot_skirmisher_lb_run"}
			{14 "foot_skirmisher_rb_run"}			
			{18 "joint_med_out"}
			{19 "runloop_f"}
		}
	}
	{sequence "runstop_f" 
		{resume} 
		{events 	
			{3 "joint_med_in"}
			{4 "foot_skirmisher"}
			{6 "foot_skirmisher"}
			{11 "foot_skirmisher"}
			{12 "joint_med_in"}
			{14 "foot_skirmisher"}
			{19 "joint_med_in"}
			{20 "foot_skirmisher"}
			{23 "joint_med_out"}
			{24 "foot_skirmisher"}
			{30 "foot_skirmisher"}
			{32 "joint_med_out"}
			{36 "foot_skirmisher"}
			{39 "joint_med_out"}
			{40 "idle_enter"}
		}
	}
	{sequence "step_l_045" 	
		{resume} 
		{events 	
			{1 "idle_exit"}	
			{6 "joint_med_out"}
			{8 "foot_skirmisher_lf"}
			{14 "foot_skirmisher_rf"}
			{16 "joint_med_in"}
			{19 "update_turn_left"}
			{20 "idle_enter"}
		}
	}
	{sequence "step_l_090" 	
		{resume} 
		{events	
			{1 "idle_exit"} 				
			{6 "joint_med_in"}
			{10 "foot_skirmisher_lf"}
			{14 "foot_skirmisher_rf"}
			{16 "joint_med_out"}
			{19 "update_turn_left"}
			;{20 "foot_skirmisher_lb"}
			{20 "idle_enter"}
		}
	}
	{sequence "step_r_045" 	
		{resume} 
		{events	
			{1 "idle_exit"} 
			{6 "joint_med_out"}
			{8 "foot_skirmisher_rf"}
			{14 "foot_skirmisher_lf"}
			{16 "joint_med_in"}
			{19 "update_turn_right"}
			{20 "idle_enter"}
		}
	}
	{sequence "step_r_090" 
		{resume} 
		{events 	
			{1 "idle_exit"} 
			{6 "joint_med_in"}
			{10 "foot_skirmisher_rf"}
			{14 "foot_skirmisher_lf"}
			{16 "joint_med_out"}
			{19 "update_turn_right"}
			;{20 "foot_skirmisher_rb"}
			{20 "idle_enter"}
		}
	}
	{sequence "idle_loop_var_01" 
		{events 	
			{1 "play_idle"}
			{5 "idle_rand_s"}				
			{10 "idle_rand_s"}				
			{15 "idle_rand_s"}				
			{20 "idle_rand_s"}				
			{25 "idle_rand_s"}				
			{30 "idle_rand_s"}				
			{35 "idle_rand_s"}				
			{40 "idle_rand_s"}				
			{45 "idle_rand_s"}				
			{55 "leave_idle"}
		}
		{resume}
	}
	{sequence "idle_loop_var_02"
		{events 	
			{1 "play_idle"}
			{5 "idle_rand_s"}				
			{10 "idle_rand_s"}				
			{15 "idle_rand_s"}				
			{20 "idle_rand_s"}				
			{25 "idle_rand_s"}				
			{30 "idle_rand_s"}				
			{35 "idle_rand_s"}				
			{40 "leave_idle"}
		}
		{resume}
	}
	{sequence "idle_loop_var_03"
		{events 	
			{1 "play_idle"}
			{5 "idle_rand_s"}				
			{10 "idle_rand_s"}				
			{15 "idle_rand_s"}				
			{20 "idle_rand_s"}				
			{25 "idle_rand_s"}				
			{30 "idle_rand_s"}				
			{35 "idle_rand_s"}				
			{40 "idle_rand_s"}				
			{45 "idle_rand_s"}				
			{50 "idle_rand_s"}				
			{55 "idle_rand_s"}				
			{60 "idle_rand_s"}				
			{65 "idle_rand_s"}				
			{70 "idle_rand_s"}				
			{75 "idle_rand_s"}				
			{80 "idle_rand_s"}				
			{85 "idle_rand_s"}				
			{90 "leave_idle"}
		}
		{resume}
	}
	{sequence "idle_loop_var_04_left" 
		{events 	
			{1 "play_idle"}
			{2 "play_idle_left"}
			{5 "idle_rand_s"}				
			{10 "joint_idle"}		;поворот		
			{15 "idle_rand_s"}				
			{20 "idle_rand_s"}				
			{25 "search_idle"}				
			{30 "idle_rand_s"}				
			{35 "joint_idle"}		;доворот		
			{40 "idle_rand_s"}				
			{45 "idle_rand_s"}				
			{50 "idle_rand_s"}				
			{55 "search_idle"}				
			{60 "idle_rand_s"}				
			{65 "idle_rand_s"}				
			{70 "idle_rand_s"}				
			{75 "idle_rand_s"}				
			{80 "idle_rand_s"}				
			{85 "search_idle"}				
			{90 "joint_idle"}		;поворот		
			{98 "search_idle"}				
			{100 "idle_rand_s"}				
			{105 "joint_idle"}	;доворот			
			{110 "idle_rand_s"}				
			{119 "play_idle_left"}
			{120 "leave_idle"}
		}
		{resume}
	}
	{sequence "idle_loop_var_04_right" 
		{events 	
			{1 "play_idle"}
			{2 "play_idle_right"}
			{5 "idle_rand_s"}				
			{10 "joint_idle"}		;поворот		
			{15 "idle_rand_s"}				
			{20 "idle_rand_s"}				
			{25 "search_idle"}				
			{30 "idle_rand_s"}				
			{35 "joint_idle"}		;доворот		
			{40 "idle_rand_s"}				
			{45 "idle_rand_s"}				
			{50 "idle_rand_s"}				
			{55 "search_idle"}				
			{60 "idle_rand_s"}				
			{65 "idle_rand_s"}				
			{70 "idle_rand_s"}				
			{75 "idle_rand_s"}				
			{80 "idle_rand_s"}				
			{85 "search_idle"}				
			{90 "joint_idle"}		;поворот		
			{98 "search_idle"}				
			{100 "idle_rand_s"}				
			{105 "joint_idle"}	;доворот			
			{110 "idle_rand_s"}				
			{119 "play_idle_right"}
			{120 "leave_idle"}
		}
		{resume}
	}
	{sequence "idle_shuffle_l_fwd" {resume}}
	{sequence "idle_shuffle_r" {resume}}
	{sequence "idle_shuffle_r_fwd" {resume}}
	{sequence "idle_shuffle_l" {resume}}
	{sequence "idle_to_scan" {resume}}
	{sequence "scan_wide_loop"
		{events 	
			{2 "joint_med_in"}
			{6 "scanlines_start"}
			{7 "scanlines_open"}
			{9 "joint_idle"}				
			{10 "scanlines_hide"}
			{12 "scanlines_open"}
			{14 "scanlines_hide"}
			{16 "scanlines_open"}
			{18 "scanlines_hide"}
			{19 "scanlines_open"}
			{20 "scanlines_hide"}
			{21 "joint_idle"}				
			{22 "scanlines_open"}
			{24 "scanlines_hide"}
			{26 "scanlines_open"}
			{28 "scanlines_hide"}
			{29 "scanlines_open"}
			{30 "scanlines_hide"}
			{31 "joint_idle"}				
			{32 "scanlines_open"}
			{34 "scanlines_hide"}
			{36 "scanlines_open"}
			{38 "scanlines_hide"}
			{39 "scanlines_open"}
			{40 "scanlines_hide"}
			{42 "scanlines_open"}
			{44 "scanlines_hide"}
			{46 "scanlines_open"}
			{48 "scanlines_hide"}
			{49 "scanlines_open"}
			{50 "scanlines_hide"}
			{52 "scanlines_open"}
			{54 "scanlines_hide"}
			{56 "scanlines_open"}
			{58 "scanlines_hide"}
			{59 "scanlines_open"}
			{60 "scanlines_hide"}
			{62 "scanlines_open"}
			{64 "scanlines_hide"}
			{66 "scanlines_open"}
			{68 "scanlines_hide"}
			{69 "scanlines_open"}
			{70 "scanlines_hide"}
			{72 "scanlines_open"}
			{74 "scanlines_hide"}
			{76 "scanlines_open"}
			{78 "scanlines_hide"}
			{79 "scanlines_open"}
			{80 "scanlines_hide"}
			{82 "scanlines_open"}
			{84 "scanlines_hide"}
			{86 "scanlines_open"}
			{88 "scanlines_hide"}
			{89 "scanlines_open"}
			{90 "scanlines_hide"}
			{92 "scanlines_open"}
			{94 "scanlines_hide"}
			{96 "scanlines_open"}
			{98 "scanlines_hide"}
			{99 "scanlines_open"}
			{100 "scanlines_hide"}
			{102 "scanlines_open"}
			{104 "scanlines_hide"}
			{106 "scanlines_open"}
			{108 "scanlines_hide"}
			{109 "scanlines_open"}
			{110 "scanlines_hide"}
			{112 "scanlines_open"}
			{114 "scanlines_hide"}
			{116 "scanlines_open"}
			{118 "scanlines_hide"}
			{119 "scanlines_open"}
			{120 "scanlines_hide"}
			{122 "scanlines_open"}
			{124 "scanlines_hide"}
			{126 "scanlines_open"}
			{128 "scanlines_hide"}
			{129 "scanlines_open"}
			{130 "scanlines_hide"}
			{132 "scanlines_open"}
			{134 "scanlines_hide"}
			{136 "scanlines_open"}
			{138 "scanlines_hide"}
			{139 "scanlines_open"}
			{140 "scanlines_hide"}
			{142 "scanlines_open"}
			{144 "scanlines_hide"}
			{146 "scanlines_open"}
			{148 "scanlines_hide"}
			{149 "scanlines_open"}
			{150 "scanlines_hide"}
			{152 "scanlines_open"}
			{154 "scanlines_hide"}
			{156 "scanlines_open"}
			{158 "scanlines_hide"}
			{159 "scanlines_open"}
			{160 "scanlines_hide"}
			{162 "scanlines_open"}
			{164 "scanlines_hide"}
			{166 "scanlines_open"}
			{168 "scanlines_hide"}
			{169 "scanlines_open"}
			{170 "scanlines_hide"}
			{172 "scanlines_open"}
			{174 "scanlines_hide"}
			{176 "scanlines_open"}
			{178 "scanlines_hide"}
			{179 "scanlines_open"}
			{180 "scanlines_hide"}
			{182 "scanlines_open"}
			{184 "scanlines_hide"}
			{186 "scanlines_open"}
			{188 "scanlines_hide"}
			{189 "scanlines_open"}
			{190 "scanlines_hide"}
			{192 "scanlines_open"}
			{194 "scanlines_hide"}
			{196 "scanlines_open"}
			{198 "scanlines_hide"}
			{199 "scanlines_open"}
			{200 "scanlines_hide"}
			{202 "scanlines_open"}
			{204 "scanlines_hide"}
			{206 "scanlines_open"}
			{208 "scanlines_hide"}
			{209 "scanlines_open"}
			{210 "scanlines_hide"}
			{212 "scanlines_open"}
			{214 "scanlines_hide"}
			{216 "scanlines_open"}
			{218 "scanlines_hide"}
			{219 "scanlines_open"}
			{220 "scanlines_hide"}
			{222 "scanlines_open"}
			{224 "scanlines_hide"}
			{226 "scanlines_open"}
			{228 "scanlines_hide"}
			{229 "scanlines_open"}
			{230 "scanlines_hide"}
			{232 "scanlines_open"}
			{234 "scanlines_hide"}
			{236 "scanlines_open"}
			{238 "scanlines_hide"}
			{239 "scanlines_open"}
			{240 "scanlines_hide"}
			{242 "scanlines_open"}
			{244 "scanlines_hide"}
			{246 "scanlines_open"}
			{248 "scanlines_hide"}
			{249 "scanlines_open"}
			{250 "scanlines_hide"}
			{252 "scanlines_open"}
			{254 "scanlines_hide"}
			{256 "scanlines_open"}
			{258 "scanlines_hide"}
			{259 "scanlines_open"}
			{260 "scanlines_hide"}
			{262 "scanlines_open"}
			{264 "scanlines_hide"}
			{266 "scanlines_open"}
			{268 "scanlines_hide"}
			{269 "scanlines_open"}
			{270 "scanlines_hide"}
			{272 "scanlines_open"}
			{274 "scanlines_hide"}
			{276 "scanlines_open"}
			{278 "scanlines_hide"}
			{279 "scanlines_open"}
			{280 "scanlines_hide"}
			{282 "scanlines_open"}
			{284 "scanlines_hide"}
			{286 "scanlines_open"}
			{288 "scanlines_hide"}
			{289 "scanlines_open"}
			{290 "scanlines_hide"}
			{292 "scanlines_open"}
			{294 "scanlines_hide"}
			{296 "scanlines_open"}
			{298 "scanlines_hide"}
			{299 "scanlines_open"}
			{300 "scanlines_hide"}
			{302 "scanlines_open"}
			{304 "scanlines_hide"}
			{306 "scanlines_open"}
			{308 "scanlines_hide"}
			{309 "scanlines_open"}
			{310 "scanlines_hide"}
			{312 "scanlines_open"}
			{314 "scanlines_hide"}
			{316 "scanlines_open"}
			{318 "scanlines_hide"}
			{319 "scanlines_open"}
			{320 "scanlines_hide"}
			{322 "scanlines_open"}
			{324 "scanlines_hide"}
			{326 "scanlines_open"}
			{328 "scanlines_hide"}
			{329 "scanlines_open"}
			{330 "scanlines_hide"}
			{332 "scanlines_open"}
			{334 "scanlines_hide"}
			{336 "scanlines_open"}
			{338 "scanlines_hide"}
			{339 "scanlines_open"}
			{340 "scanlines_hide"}
			{342 "scanlines_open"}
			{344 "scanlines_hide"}
			{346 "scanlines_open"}
			{348 "scanlines_hide"}
			{349 "scanlines_open"}
			{350 "scanlines_hide"}
			{352 "scanlines_open"}
			{354 "scanlines_hide"}
			{356 "scanlines_open"}
			{358 "scanlines_hide"}
			{359 "scanlines_open"}
			{360 "scanlines_hide"}
			{362 "scanlines_open"}
			{364 "scanlines_hide"}
			{366 "scanlines_open"}
			{368 "scanlines_hide"}
			{369 "scanlines_open"}
			{370 "scanlines_hide"}
			{372 "scanlines_open"}
			{374 "scanlines_hide"}
			{376 "scanlines_open"}
			{378 "scanlines_hide"}
			{380 "scanlines_stop"}
		}
		{resume}
	}
	{sequence "scan_narrow_loop" {resume}}
	{sequence "scan_to_idle" {resume}}
	{sequence "wpn_idle_to_combat"
		{resume}
		{events 
			{1 "wpn_idle_to_combat"}
		}
	}
	{sequence "wpn_combat_to_idle" 
		{resume}
		{events 
			{1 "wpn_combat_to_idle"}
		}
	}
	{sequence "attack_melee_charge_01" 
		{movement}	
		{resume}
		{events 
			{1 "idle_exit"}				
			{2 "foot_skirmisher_lf_run"}
			{4 "joint_med_in"}
			{5 "foot_skirmisher_rf_run"}
			{10 "foot_skirmisher_lb_run"}
			{14 "foot_skirmisher_rb_run"}			
			{18 "joint_med_out"}
			{54 "landed_close"}
			{55 "runloop_f"}
		}
	}
	{sequence "stumble_runstart_f_01" {resume}}
	{sequence "break_engine" {speed 0.2} {resume}}
	{sequence "attack_melee_close"	
		{movement}	
		{resume}
		{events 
			{1 "idle_exit"}				
			{5 "joint_med_in"}
			{9 "joint_med_out"}
			{11 "foot_skirmisher_lb_run"}			
			{12 "foot_skirmisher_rf_run"}
			{14 "foot_skirmisher_rb_run"}			
			{15 "jump_close"}			
			{24 "joint_med_in"}
			{29 "foot_skirmisher_lf_run"}
			{30 "joint_med_out"}
			{31 "foot_skirmisher_lb_run"}			
			{33 "foot_skirmisher_rf_run_frontdust"}
			{35 "foot_skirmisher_rb_run"}			
			{40 "joint_med_in"}
			{48 "foot_skirmisher_lb_run"}			
			{50 "foot_skirmisher_rb_run"}			
			{51 "joint_med_out"}
			{59 "foot_skirmisher_lf_run_frontdust"}
			{71 "foot_skirmisher_lf_run"}
			{72 "foot_skirmisher_lb_run"}			
			{73 "landed_close"}
			{74 "foot_skirmisher_rf_run"}
		}
	}
	{sequence "leds_global_hold" {resume}}
	{sequence "leds_global_alarm" {resume}}
	{sequence "leds_global_search" {resume}}
	{sequence "spawn_egg" }
	{sequence "hit_stumble_45ccw"
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{5 "joint_med_in"}
			{8 "joint_med_out"}
			{9 "replace_position_end"}
		}
	}
	{sequence "hit_stumble_45cw"	
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{5 "joint_med_in"}
			{8 "joint_med_out"}
			{9 "replace_position_end"}
		}
	}

	{sequence "hit_stumble_135ccw"
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{5 "joint_med_in"}
			{8 "joint_med_out"}
			{9 "replace_position_end"}
		}
	}

	{sequence "hit_stumble_135cw" 
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{5 "joint_med_in"}
			{8 "joint_med_out"}
			{9 "replace_position_end"}
		}
	}
	{sequence "wpn_recoil"
		{speed 1}
		{resume}
	}
	{sequence "health"
		{resume}
		{events 	
			{5 "5heal"} 
			{20 "20heal"} 
			{40 "40heal"} 
			{70 "70heal"} 
			{99 "explosion_skir"} 
		}
	}
}
