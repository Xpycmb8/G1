	{animation
		{sequence "power_up_spawn"
			{file "power_up.anm"}
			{resume}
			{events 
				{1 "power_down_start_spawn"}
				{5 "restart_clunk_dread"}
				{10 "restart_clunk_dread"}
				{20 "restart_clunk_dread"}
				{30 "restart_clunk_dread"}
				{40 "restart_clunk_dread"}
				{60 "restart_clunk_dread"}
				{70 "restart_clunk_dread"}
				{80 "restart_clunk_dread"}
				{90 "restart_clunk_dread"}
				{100 "restart_clunk_dread"}
				{110 "restart_clunk_dread"}
				{110 "power_down_leave"}
			}
		}
		{sequence "power_down"
			;{speed 0.5}
			{events 
				{1 "power_down_start"}
				{5 "restart_clunk_dread"}
				{10 "restart_clunk_dread"}
				{20 "restart_clunk_dread"}
				{30 "restart_clunk_dread"}
				{40 "restart_clunk_dread"}
				{60 "restart_clunk_dread"}
				{70 "restart_clunk_dread"}
				{80 "restart_clunk_dread"}
				{110 "restart_clunk_dread"}
			}
			{resume}
		}
		{sequence "power_up"
			{resume}
			{events 
				{1 "power_down_check"}
				{2 "power_up_load"}
				{5 "restart_clunk_dread"}
				{10 "restart_clunk_dread"}
				{20 "restart_clunk_dread"}
				{30 "restart_clunk_dread"}
				{40 "restart_clunk_dread"}
				{60 "restart_clunk_dread"}
				{70 "restart_clunk_dread"}
				{80 "restart_clunk_dread"}
				{90 "restart_clunk_dread"}
				{100 "restart_clunk_dread"}
				{110 "restart_clunk_dread"}
				{120 "power_down_leave"}
			}
		}
		{sequence "walkstart_f" 
			;{movement}	
			{speed 1}
			{events 
				{1 "walkstart_f_start"}
				{2 "idle_exit"}
				{30 "joint_big"}
				{46 "foot_dreadnought_r"}
				{72 "joint_big"}
				{92 "foot_dreadnought_l"}
				{125 "walkstart_f"}
				{126 "walkstart_f_end"}
			}
		}
		{sequence "walkloop_f" 
;			{smooth 1}
			;{movement}	
			{events 
				{1 "walkloop_f_start"}
				{2 "idle_exit"}
				{8 "joint_big"}
				{21 "foot_dreadnought_r"}
				{55 "joint_big"}
				{76 "foot_dreadnought_l"}
				{109 "walkloop_f_exit"}
			}
		}
		{sequence "walkloop_l" {resume}}
		{sequence "walkloop_r" {resume}}
		{sequence "walkstop_f"
			;{smooth 0.2}
			{movement}	
			{events 	
				{1 "walkstop_f_start"}
				{5 "joint_big"}
				{21 "foot_dreadnought_r"}
				{55 "joint_big"}
				{76 "foot_dreadnought_l"}
				{113 "idle_enter"}
				{114 "walkstop_f_exit"}
			}
		}
		{sequence "walk_to_run" {resume}}
		{sequence "runstart_f" 
			{resume}	
			{events 
				{1 "idle_exit"}
				{86 "runstart_f"}
			}
		}
		{sequence "runloop_f" 
			{resume}
			{events 
				{1 "idle_exit"}				
				{32 "runloop_f"}
			}
		}
		{sequence "runstop_f" 
			{resume} 
			{events 	
				{60 "idle_enter"}
			}
		}
		{sequence "step_l_045" 	
			;{file "step_r_045.anm"}
			;{movement}	
			{speed 0.6}
			{events 	
				{1 "step_l_045_start"}	
				{2 "idle_exit"}	
				{20 "joint_big"}
				{35 "foot_dreadnought_r"}
				{40 "joint_big"}
				{52 "foot_dreadnought_l"}
				{75 "step_l_045_exit"}
			}
		}
		{sequence "step_l_090" 	
			;{file "step_r_090.anm"}
			;{movement}	
			{events	
				{1 "idle_exit"}	
				{15 "joint_big"}
				{33 "foot_dreadnought_r"}
				{40 "joint_big"}
				{52 "foot_dreadnought_l"}
				{75 "update_turn_left_movement"}
			}
		}
		{sequence "step_r_045" 	
			;{file "step_l_045.anm"}
			;{movement}	
			{speed 0.6}
			{events	
				{1 "step_r_045_start"}	
				{2 "idle_exit"}	
				{20 "joint_big"}
				{35 "foot_dreadnought_l"}
				{40 "joint_big"}
				{52 "foot_dreadnought_r"}
				{75 "step_r_045_exit"}
			}
		}
		{sequence "step_r_090" 
			;{file "step_l_090.anm"}
			;{movement}	
			{events 	
				{1 "idle_exit"}	
				{15 "joint_big"}
				{33 "foot_dreadnought_l"}
				{40 "joint_big"}
				{52 "foot_dreadnought_r"}
				{75 "update_turn_right_movement"}
			}
		}
		{sequence "step_ready_l_045" {resume}}
		{sequence "step_ready_l_090" {resume}}
		{sequence "step_ready_r_045" {resume}}
		{sequence "step_ready_r_090" {resume}}
		{sequence "attack_gas" 
			{events 	
				{1 "idle_exit"}	
				{2 "fire_script_begin"}
				{20 "joint_big"}
				{40 "foot_dreadnought_l"}
				{175 "joint_big"}
				{187 "foot_dreadnought_l"}
				{188 "fire_script_end"}
			}
			{resume}
		}
		{sequence "attack_concussion" 
			{movement}	
			{events 	
				{1 "idle_exit"}	
				{2 "fire_script_begin"}
				{5 "concussion_riser"}
				{10 "joint_big"}
				{22 "foot_dreadnought_r"}
				{50 "joint_big"}
				{90 "attack_concussion"}
				{130 "joint_big"}
				{144 "foot_dreadnought_r"}
				{145 "fire_script_end"}
			}
			{resume}	
		}
		{sequence "hit_reel_45ccw"
			{resume}
			{events 	
				{1 "block_hit"}
				{10 "joint_big"}
				{13 "foot_dreadnought_r"}
				{60 "joint_big"}
				{70 "foot_dreadnought_r"}
				{95 "unblock_hit"}
			}
		}
		{sequence "hit_reel_45cw"
			{resume}
			{events 	
				{10 "joint_big"}
				{13 "foot_dreadnought_l"}
				{60 "joint_big"}
				{70 "foot_dreadnought_l"}
				{95 "unblock_hit"}
			}
		}
		{sequence "hit_reel_135ccw"
			{resume}
			{events 	
				{1 "block_all_dread_call"}
				{10 "joint_big"}
				{13 "foot_dreadnought_l"}
				{60 "joint_big"}
				{70 "foot_dreadnought_l"}
				{95 "unblock_hit"}
				{98 "unblock_all_dread_call"}
			}
		}
		{sequence "hit_reel_135cw" 
			{resume}
			{events 	
				{1 "block_all_dread_call"}
				{10 "joint_big"}
				{13 "foot_dreadnought_l"}
				{60 "joint_big"}
				{70 "foot_dreadnought_l"}
				{95 "unblock_hit"}
				{98 "unblock_all_dread_call"}
			}
		}
		{sequence "leds" {autostart}}
		{sequence "drop_pest" 
			{events 
				{4 "hatch_small_open"}				
				{19 "hatch_small_drop"}
			}
			{resume}
		}
		{sequence "recoil_gun" {resume}}		
		{sequence "attack_melee_l_stamp"
			{movement}	
			{events 
				{1 "fire_script_begin"}
				{12 "joint_big"}
				{15 "close_attack_enter"}				
				{21 "melee_l_stamp"}
				{45 "joint_big"}
				{55 "close_attack_leave"}				
				{68 "fire_script_end"}
			}				
			{resume}
		}
		{sequence "attack_melee_l_stamp_bwd"
			{movement}	
			{events 
				{1 "fire_script_begin"}
				{12 "joint_big"}
				{25 "foot_dreadnought_l"}
				{40 "close_attack_enter"}	
				{30 "joint_big"}
				{40 "joint_big"}
				{43 "melee_l_stamp"}
				{70 "joint_big"}
				{80 "close_attack_leave"}				
				{110 "fire_script_end"}
			}				
			{resume}
		}
		{sequence "attack_melee_r_stamp"
			{movement}	
			{events 
				{1 "fire_script_begin"}
				{12 "joint_big"}
				{15 "close_attack_enter"}				
				{21 "melee_r_stamp"}
				{45 "joint_big"}
				{55 "close_attack_leave"}				
				{68 "fire_script_end"}
			}				
			{resume}
		}
		{sequence "attack_melee_r_stamp_bwd"
			{movement}	
			{events 
				{1 "fire_script_begin"}
				{12 "joint_big"}
				{25 "foot_dreadnought_r"}
				{40 "close_attack_enter"}	
				{30 "joint_big"}
				{40 "joint_big"}
				{43 "melee_r_stamp"}
				{70 "joint_big"}
				{80 "close_attack_leave"}				
				{110 "fire_script_end"}
			}				
			{resume}
		}
		{sequence "death_l_bwd" {resume}
			{events 
				{1 "start_fall_dread"}				
				{5 "joint_big"}	
				{13 "death_dread_01"}				
				{21 "fx_fall_l"}				
				{41 "death_dread_02"}
				{56 "death_l_bwd_dread_04"}
				{60 "fx_fall_hit_l"}				
			}
			{movement}	
		}
		{sequence "death_l_fwd" {resume}
			{events 
				{1 "start_fall_dread"}				
				{5 "joint_big"}	
				{21 "fx_fall_l"}				
				{14 "death_dread_01"}				
				{37 "foot_dreadnought_r"}				
				{43 "death_dread_03"}
				{63 "death_r_bwd_dread_04"}				
				{73 "fx_fall_hit_r"}				
			}
			{movement}	
		}
		{sequence "death_r_bwd" {resume}
			{events 
				{1 "start_fall_dread"}				
				{5 "joint_big"}	
				{13 "death_dread_01"}				
				{21 "fx_fall_l"}				
				{41 "death_dread_02"}
				{56 "death_l_bwd_dread_04"}
				{60 "fx_fall_hit_l"}				
			}
			{movement}	
		}
		{sequence "death_r_fwd" {resume}
			{events 
				{1 "start_fall_dread"}				
				{5 "joint_big"}	
				{21 "fx_fall_l"}				
				{14 "death_dread_01"}				
				{37 "foot_dreadnought_r"}				
				{43 "death_dread_03"}
				{63 "death_r_bwd_dread_04"}				
				{73 "fx_fall_hit_r"}				
			}
			{movement}	
		}
		{sequence "idle_combat_var_01" {resume}}
		{sequence "idle_combat_var_02" {resume}}
		{sequence "idle_combat_var_03" {resume}}
		{sequence "idle_combat_var_04" {resume}}
		{sequence "idle_loop_var_01" {resume}}
		{sequence "idle_loop_var_02" {resume}}
		{sequence "idle_loop_var_03" {resume}}
		{sequence "idle_to_lure" {resume}}
		{sequence "idle_to_ready" {resume}}
		{sequence "idle_to_scan_high" {resume}}
		{sequence "idle_to_scan_low" {resume}}
		{sequence "lure_call" {resume}}
		{sequence "scan_high_to_idle" {resume}}
		{sequence "scan_low_to_idle" {resume}}
		{sequence "heat_mg" 
			{resume}
			{events 
				{20 "heat_20"}				
				{50 "heat_50"}				
				{80 "heat_80"}				
				{99 "heat_99"}				
			}
		}
		{sequence "random_weapon_cooling" 
			{resume}
			{events 
				{15 "hatch_mg_open"}				
			}
		}
		{sequence "reload" 
			{events 
				{7 "reload_small_dr"}	;выдвигание			
				; {25 ""}	;выставка			
				; {30 ""}	;уход			
			}
			{resume}
		}
		{sequence "health"
			{resume}
			{events 	
				{5 "5heal"} 
				{20 "20heal"} 
				{40 "40heal"} 
				{70 "70heal"} 
				{99 "explosion_dread"} 
			}
		}
	}

