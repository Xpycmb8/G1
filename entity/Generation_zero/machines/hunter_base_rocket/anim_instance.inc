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
				{48 "joint_med_out"}
				{60 "restart_clunk"}
				{68 "retract_blade"}
				{70 "restart_clunk"}
				{80 "restart_clunk"}
				{90 "restart_clunk"}
				{95 "melee_extend_blade"}
				{100 "restart_clunk"}
				{110 "restart_clunk"}
				{128 "power_down_leave"}
			}
		}
		{sequence "power_down"
			{file "power_down_fwd.anm"}
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
				{95 "restart_clunk"}
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
				{48 "joint_med_out"}
				{60 "restart_clunk"}
				{68 "retract_blade"}
				{70 "restart_clunk"}
				{80 "restart_clunk"}
				{90 "restart_clunk"}
				{95 "melee_extend_blade"}
				{100 "restart_clunk"}
				{110 "restart_clunk"}
				{128 "power_down_leave"}
			}
		}
		{sequence "walkstart_f"	
			{resume}
			{speed 0.8}
			{events 
				{1 "walkstart_f_start"}				
				{2 "walk_limit"}
				{3 "idle_exit"}
				{8 "walk_limit_end"}
				{22 "joint_big"}
				{35 "foot_hunter_r"}
				{48 "joint_big"}
				{60 "foot_hunter_l"}
				{67 "walkstart_hf_end"}
			}
		}
		{sequence "walkloop_fwd"
			{resume}
			{events 
				{1 "walkloop_f_start"}
				{2 "idle_exit"}
				{5 "joint_big"}
				{21 "foot_hunter_r"}
				{36 "joint_big"}
				{48 "foot_hunter_l"}
				{55 "walkloop_f"}
			}
		}
		{sequence "walkstop_f" 
			{smooth 0.1}
			;{movement}
			{events 	
				{1 "walkstop_f_start"}
				{8 "joint_big"}
				{15 "joint_big"}
				{22 "foot_hunter_l"}
				{24 "idle_enter"}
				{25 "walkstop_f_exit"}
			}
			{resume}
		}
		{sequence "walkstop_45ccw" {resume}}
		{sequence "walkstop_45cw" {resume}}
		{sequence "runstart_f" {resume}}
		{sequence "step_l_045" 	
			{smooth 0.5}
			{resume} 
			{events 	
				{1 "idle_exit"}	
				{6 "joint_med_in"}
				{21 "foot_hunter_r"}
				{28 "joint_med_out"}
				{31 "foot_hunter_l"}
				{39 "update_turn_left"}
				{40 "idle_enter"}
			}
		}
		{sequence "step_l_090" 	
			{smooth 0.5}
			{resume} 
			{events	
				{1 "idle_exit"} 				
				{6 "joint_med_in"}
				{18 "foot_hunter_l"}
				{23 "joint_med_out"}
				{26 "foot_hunter_r"}
				{39 "update_turn_left"}
				{40 "idle_enter"}
			}
		}
		{sequence "step_r_045" 	
			{smooth 0.5}
			{resume} 
			{events 	
				{1 "idle_exit"}	
				{6 "joint_med_in"}
				{21 "foot_hunter_l"}
				{28 "joint_med_out"}
				{31 "foot_hunter_r"}
				{39 "update_turn_right"}
				{40 "idle_enter"}
			}
		}
		{sequence "step_r_090" 
			{smooth 0.5}
			{resume} 
			{events 	
				{1 "idle_exit"} 				
				{6 "joint_med_in"}
				{18 "foot_hunter_r"}
				{23 "joint_med_out"}
				{26 "foot_hunter_l"}
				{39 "update_turn_right"}
				{40 "idle_enter"}
			}
		}
		{sequence "runloop_fwd" {resume}}
		{sequence "runstop_f" {resume}}
		{sequence "idle_loop_var_01" {resume}}
		{sequence "idle_loop_var_02" {resume}}
		{sequence "idle_loop_var_03" {resume}}
		{sequence "idle_shuffle_l" {resume}}
		{sequence "idle_shuffle_l_fwd" {resume}}
		{sequence "idle_shuffle_r" {resume}}
		{sequence "idle_shuffle_r_fwd" {resume}}
		{sequence "idle_to_lure" {resume}}
		{sequence "idle_to_ready" {resume}}
		{sequence "idle_to_ready_shoulder" {resume}}
		{sequence "idle_to_scan_high" {resume}}
		{sequence "idle_to_scan_low" {resume}}
		{sequence "lure_call" {resume}}
		{sequence "lure_to_idle" {resume}}
		{sequence "ready_shoulder_to_idle" {resume}}
		{sequence "scan" {speed 3} {resume}}
		{sequence "scan_low_narrow_loop"
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
				{160 "scanlines_stop"}
			}
			{resume}
		}
		{sequence "scan_high_wide_loop"
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
				{160 "scanlines_stop"}
			}
			{resume}
		}
		{sequence "death_l_bwd" {resume}{movement}
			{events 	
				{1 "idle_exit"} 
				{10 "joint_med_in"} 				
				{15 "death_r_bwd_hunter_03"}
				{20 "foot_hunter_r"}
				{25 "joint_med_out"}
				{27 "death_r_bwd_hunter_03"}
				{30 "death_r_bwd_hunter_01"} ; контакт с землей
				{38 "death_r_bwd_hunter_02"}
				{45 "death_r_bwd_hunter_03"}
			}
		}
		{sequence "death_l_fwd"
			{resume}
			{movement}
			{events 	
				{1 "idle_exit"} 
				{7 "joint_med_in"} 				
				{8 "death_r_bwd_hunter_03"}
				{11 "foot_hunter_r"}
				{21 "foot_hunter_r"}
				{25 "joint_med_out"}
				{27 "death_r_bwd_hunter_03"}
				{36 "death_r_bwd_hunter_01front"} ; контакт с землей
			}
		}
		{sequence "death_r_bwd"
			{resume}
			{movement}
			{events 	
				{1 "idle_exit"} 
				{10 "joint_med_in"} 				
				{15 "death_r_bwd_hunter_03"}
				{20 "foot_hunter_r"}
				{25 "joint_med_out"}
				{27 "death_r_bwd_hunter_03"}
				{30 "death_r_bwd_hunter_01"} ; контакт с землей
				{38 "death_r_bwd_hunter_02"}
				{45 "death_r_bwd_hunter_03"}
			}
		}
		{sequence "death_r_fwd"
			{resume}
			{movement}
			{events 	
				{1 "idle_exit"} 
				{7 "joint_med_in"} 				
				{8 "death_r_bwd_hunter_03"}
				{11 "foot_hunter_r"}
				{21 "foot_hunter_r"}
				{25 "joint_med_out"}
				{27 "death_r_bwd_hunter_03"}
				{36 "death_r_bwd_hunter_01front"} ; контакт с землей
			}
		}
		{sequence "attack_melee_stab" 
			{movement}
			{resume}
			{events 	
				{1 "block_all_hunter_melee"} 				
				{2 "hunter_melee_stab_start"} 				
				{3 "idle_exit"} 				
				{4 "hunter_run_start"} 					
				{15 "joint_med_in"}
				{17 "foot_hunter_r_run"}
				{21 "joint_med_out"}
				{26 "foot_hunter_l_run"}
				{29 "joint_med_in"}
				{34 "foot_hunter_r_run"}
				{38 "joint_med_out"}
				{42 "foot_hunter_l_run"}
				{47 "joint_med_in"}
				{51 "foot_hunter_r_run"}
				{54 "joint_med_out"}
				{59 "foot_hunter_l_run"}
				{62 "hunter_jump"}				
				{74 "melee_warning"}
				{75 "hunter_red_light"}
				{79 "retract_blade"}
				{88 "landed"}
				{136 "foot_hunter_l"}
				{137 "melee_extend_blade"}
				{158 "unblock_all_hunter_melee"}
			}
		}
		{sequence "attack_melee_swipe_bwd"
			{resume}
			{movement}
			{events 	
				{1 "block_all_hunter_melee"} 
				{2 "idle_exit"} 				
				{6 "joint_med_in"}
				{12 "foot_hunter_r"}
				{13 "retract_blade"}
				{18 "foot_hunter_l"}
				{19 "blade_damage"}				
				{20 "melee_stab_swing"}
				{21 "blade_damage"}				
				{22 "blade_damage"}				
				{23 "blade_damage"}				
				{25 "blade_damage_big"}				
				{26 "joint_med_out"}
				{29 "blade_damage"}				
				{31 "blade_damage"}				
				{45 "melee_extend_blade"}
				{90 "unblock_all_hunter_melee"}
			}
		}
		{sequence "attack_melee_swipe_fwd"
			{resume}
			{events 	
				{1 "block_all_hunter_melee"} 
				{2 "idle_exit"} 				
				{6 "joint_med_in"}
				{8 "blade_damage"}				
				{10 "blade_damage"}				
				{12 "blade_damage"}				
				{14 "blade_damage"}				
				{16 "blade_damage"}				
				{17 "retract_blade"}				
				{18 "foot_hunter_l"}
				{20 "blade_damage"}				
				{22 "blade_damage"}				
				{23 "melee_stab_swing"}
				{24 "blade_damage"}				
				{25 "blade_damage_big"}				
				{26 "blade_damage"}				
				{28 "blade_damage"}				
				{30 "blade_damage"}				
				{50 "melee_extend_blade"}
				{62 "joint_med_out"}
				{70 "foot_hunter_r"}
				{95 "unblock_all_hunter_melee"}
			}
		}
		{sequence "hit_stumble_45ccw"
			{events 	
				{1 "block_all_hunter"} 
				{2 "idle_exit"} 				
				{67 "unblock_all_hunter"}	
			}
			{smooth 0.5}
			{resume}
			{movement}
		}
		{sequence "hit_stumble_45cw" 
			{events 	
				{1 "block_all_hunter"} 
				{2 "idle_exit"} 				
				{67 "unblock_all_hunter"}	
			}
			{smooth 0.5}
			{resume}
			{movement}
		}
		{sequence "hit_stumble_135ccw" 
			{events 	
				{1 "block_all_hunter"} 
				{2 "idle_exit"} 				
				{67 "unblock_all_hunter"}	
			}
			{resume}
			{movement}
			{smooth 0.5}
		}
		{sequence "hit_stumble_135cw"
			{events 	
				{1 "block_all_hunter"} 
				{2 "idle_exit"} 				
				{67 "unblock_all_hunter"}	
			}
			{smooth 0.5}
			{resume}
			{movement}
		}
		{sequence "drop_pest" 
			{events 
				{4 "hatch_small_open"}				
				{19 "hatch_small_drop"}
			}
			{resume}
		}
		{sequence "reload_rocket"
			{speed 0.5}
			; {events 	
				; {1 ""} 
			; }
			{resume}
		}
		{sequence "health"
			{resume}
			{events 	
				{5 "5heal"} 
				{20 "20heal"} 
				{40 "40heal"} 
				{70 "70heal"} 
				{99 "explosion_hunter"} 
			}
		}
	}
