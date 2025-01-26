	{animation
		{sequence "walkstart_f" 
			;{movement}	
			{speed 1}
			{events 
				{1 "walkstart_f_start"}
				{2 "idle_exit"}
				{30 "joint_big"}
				{56 "foot_harvest_fr"}
				{72 "joint_big"}
				{92 "foot_harvest_fl"}
				{99 "walkstart_f"}
				{100 "walkstart_f_end"}
			}
		}
		{sequence "walkloop_f" 
			;{movement}	
			{events 
				{1 "walkloop_f_start"}
				{2 "idle_exit"}
				{8 "joint_big"}
				{44 "foot_harvest_fr"}
				{55 "joint_big"}
				{92 "foot_harvest_fl"}
				{100 "walkloop_f_exit"}
			}
		}
		{sequence "walkstop_f"
			{movement}	
			{events 	
				{1 "walkstop_f_start"}
				{20 "joint_big"}
				{45 "foot_harvest_fr"}
				{55 "joint_big"}
				{94 "foot_harvest_fl"}
				{114 "idle_enter"}
				{115 "walkstop_f_exit"}
			}
		}
		{sequence "step_l_045" 	
;			{movement}	
			{events 	
				{1 "step_l_045_start"}	
				{2 "idle_exit"}	
				{20 "joint_big"}
				{32 "foot_harvest_fr"}
				{40 "joint_big"}
				{63 "foot_harvest_fl"}
				{105 "step_l_045_exit"}
			}
		}
		{sequence "step_l_090" 	
			;{movement}	
			{events	
				{1 "idle_exit"}	
				{15 "joint_big"}
				{34 "foot_harvest_fl"}
				{40 "joint_big"}
				{60 "foot_harvest_fr"}
				{75 "joint_big"}
				{86 "foot_harvest_fl"}
				{96 "joint_big"}
				{115 "foot_harvest_fr"}
				{139 "update_turn_left_movement"}
			}
		}
		{sequence "step_r_045" 	
;			{movement}	
			{events	
				{1 "step_r_045_start"}	
				{2 "idle_exit"}	
				{20 "joint_big"}
				{32 "foot_harvest_fr"}
				{40 "joint_big"}
				{63 "foot_harvest_fl"}
				{105 "step_r_045_exit"}
			}
		}
		{sequence "step_r_090" 
			;{movement}	
			{events 	
				{1 "idle_exit"}	
				{15 "joint_big"}
				{34 "foot_harvest_fr"}
				{40 "joint_big"}
				{60 "foot_harvest_fl"}
				{75 "joint_big"}
				{86 "foot_harvest_fr"}
				{96 "joint_big"}
				{115 "foot_harvest_fl"}
				{140 "update_turn_right_movement"}
			}
		}
		{sequence "curl_step_l_045"	
			{resume}
			;{movement}	
			{events	
				{1 "curl_step_l_045_start"}	
				{2 "idle_exit"}	
				{15 "joint_big"}
				{30 "foot_harvest_fl"}
				{35 "foot_harvest_br"}
				{55 "foot_harvest_fr"}
				{95 "curl_step_l_045_exit"}
			}
		}
		{sequence "curl_step_r_045"
			{resume}
			;{movement}	
			{events	
				{1 "curl_step_r_045_start"}	
				{2 "idle_exit"}	
				{15 "joint_big"}
				{30 "foot_harvest_fr"}
				{35 "foot_harvest_bl"}
				{55 "foot_harvest_fl"}
				{95 "curl_step_r_045_exit"}
			}
		}
		{sequence "power_up_spawn"
			{file "power_up.anm"}
			{resume}
			{events 
				{1 "power_down_start_spawn"}
				{5 "restart_clunk_harvester"}
				{10 "restart_clunk_harvester"}
				{20 "restart_clunk_harvester"}
				{30 "restart_clunk_harvester"}
				{40 "restart_clunk_harvester"}
				{60 "restart_clunk_harvester"}
				{70 "restart_clunk_harvester"}
				{80 "restart_clunk_harvester"}
				{90 "restart_clunk_harvester"}
				{100 "restart_clunk_harvester"}
				{134 "restart_clunk_harvester"}
				{135 "power_down_leave"}
			}
		}
		{sequence "power_down"
			{events 
				{1 "power_down_start"}
				{5 "restart_clunk_harvester"}
				{10 "restart_clunk_harvester"}
				{20 "restart_clunk_harvester"}
				{30 "restart_clunk_harvester"}
				{40 "restart_clunk_harvester"}
				{60 "restart_clunk_harvester"}
				{70 "restart_clunk_harvester"}
				{80 "restart_clunk_harvester"}
				{120 "restart_clunk_harvester"}
			}
			{resume}
		}
		{sequence "power_up"
			{resume}
			{events 
				{1 "power_down_check"}
				{2 "power_up_load"}
				{5 "restart_clunk_harvester"}
				{10 "restart_clunk_harvester"}
				{20 "restart_clunk_harvester"}
				{30 "restart_clunk_harvester"}
				{40 "restart_clunk_harvester"}
				{60 "restart_clunk_harvester"}
				{70 "restart_clunk_harvester"}
				{80 "restart_clunk_harvester"}
				{90 "restart_clunk_harvester"}
				{100 "restart_clunk_harvester"}
				{110 "restart_clunk_harvester"}
				{130 "restart_clunk_harvester"}
				{135 "power_down_leave"}
			}
		}
		{sequence "attack_concussion"
			{events 	
				{1 "fire_script_begin"}	
				{2 "idle_exit"}	
				{15 "concussion_riser"}
				{20 "joint_big"}
				{35 "attack_concussion"}
				{70 "fire_script_end"}
			}
		}
		{sequence "attack_gas"
			{events 	
				{1 "fire_script_begin"}	
				{2 "idle_exit"}	
				{120 "fire_script_end"}
			}
			{resume}
		}
		{sequence "attack_l"
			{events 	
				{1 "fire_script_begin"}	
				{2 "block_hit"}
				{7 "joint_big"}
				{8 "close_attack_enter"}
				{23 "foot_harvest_melee_l"}
				{56 "joint_big"}
				{71 "foot_harvest_fl"}
				{70 "unblock_hit"}
				{95 "fire_script_end"}
				{96 "close_attack_leave"}
			}
			{resume}
		}
		{sequence "attack_l_bwd"
			{events 	
				{1 "fire_script_begin"}	
				{2 "block_hit"}
				{15 "joint_big"}
				{30 "foot_harvest_fl"}
				{40 "foot_harvest_br"}
				{43 "close_attack_enter"}
				{47 "restart_clunk_harvester"}
				{53 "foot_harvest_fl"}
				{54 "close_attack_leave"}
				{56 "joint_big"}
				{60 "foot_harvest_melee_r"}
				{75 "restart_clunk_harvester"}
				{95 "joint_big"}
				{109 "foot_harvest_fr"}
				{113 "foot_harvest_bl"}
				{128 "unblock_hit"}			
				{120 "fire_script_end"}
			}
			{movement}	
			{resume}
		}
		{sequence "attack_r"
			{events 	
				{1 "fire_script_begin"}	
				{2 "block_hit"}
				{7 "joint_big"}
				{8 "close_attack_enter"}
				{23 "foot_harvest_melee_r"}
				{56 "joint_big"}
				{71 "foot_harvest_fr"}
				{70 "unblock_hit"}			
				{95 "fire_script_end"}
				{96 "close_attack_leave"}
			}
			{resume}
		}
		{sequence "attack_r_bwd" 
			{movement}	
			{resume}
			{events 	
				{1 "fire_script_begin"}	
				{2 "block_hit"}
				{18 "joint_big"}
				{25 "foot_harvest_fr"}
				{45 "close_attack_enter"}
				{47 "joint_big"}
				{50 "foot_harvest_bl"}
				{53 "foot_harvest_fr"}
				{61 "foot_harvest_melee_l"}
				{94 "joint_big"}
				{95 "close_attack_leave"}
				{109 "foot_harvest_fl"}
				{120 "fire_script_end"}
			}
		}
		{sequence "death_l_fwd"	
			{resume}
			{events 	
				{10 "death_harv_01"}
				{35 "death_harv_02"}
				{45 "death_harv_04"}
				{58 "death_harv_03"}
			}
		}
		{sequence "death_r_fwd"	
			{resume}
			{events 	
				{10 "death_harv_01"}
				{35 "death_harv_02"}
				{45 "death_harv_04"}
				{58 "death_harv_03"}
			}
		}
		{sequence "harvest_hit" {resume}}
		{sequence "harvest_to_idle" {resume}}
		{sequence "harvest_stance" {resume}}
		{sequence "hit_reel_45cw" 
			{movement}	
			{resume}
			{events 	
				{1 "replace_position_start"}
				{25 "joint_big"}
				{75 "replace_position_end"}
			}
		}
		{sequence "hit_reel_135ccw"
			{movement}	
			{resume}
			{events 	
				{1 "replace_position_start"}
				{25 "joint_big"}
				{75 "replace_position_end"}
			}
		}
		{sequence "hit_reel_135cw"
			{movement}	
			{resume}
			{events 	
				{1 "replace_position_start"}
				{25 "joint_big"}
				{75 "replace_position_end"}
			}
		}
		{sequence "idle_combat_var_01"
			{events 	
				{1 "play_idle"}
				{100 "leave_idle"}
			}
			{resume}
		}
		{sequence "idle_loop_var_01" 
			{events 	
				{1 "play_idle"}
				{115 "leave_idle"}
			}
			{resume}
		}
		{sequence "idle_loop_var_02"
			{events 	
				{1 "play_idle"}
				{75 "leave_idle"}
			}
			{resume}
		}
		{sequence "idle_loop_var_03"
			{events 	
				{1 "play_idle"}
				{115 "leave_idle"}
			}
			{resume}
		}
		{sequence "idle_loop_var_04"
			{events 	
				{1 "play_idle"}
				{105 "leave_idle"}
			}
			{resume}
		}
		{sequence "idle_loop_var_05"
			{events 	
				{1 "play_idle"}
				{150 "leave_idle"}
			}
			{resume}
		}
		{sequence "curl_attack_concussion"
			{events 	
				{1 "fire_script_begin"}	
				{2 "idle_exit"}	
				{15 "concussion_riser"}
				{20 "joint_big"}
				{35 "attack_concussion"}
				{70 "fire_script_end"}
			}
			{resume}
		}
		{sequence "curl_to_idle" 
			{events 
				{1 "fire_script_begin"}	
				{12 "joint_big"}
				{25 "joint_big"}
				{27 "restart_clunk_harvester"}
				{50 "joint_big"}
				{87 "curl_end"}	
				{90 "fire_script_end"}
			}
			{resume}
		}
		{sequence "idle_to_curl"
			{events 
				{1 "fire_script_begin"}	
				{2 "curl_start"}	
				{12 "joint_big"}
				{25 "joint_big"}
				{27 "restart_clunk_harvester"}
				{50 "joint_big"}
				{90 "fire_script_end"}
			}
			{resume}
		}
		{sequence "idle_to_harvest" {resume}}
		{sequence "idle_to_scan_narrow" {resume}}
		{sequence "idle_to_scan_wide" {resume}}
		{sequence "scan_narrow" {resume}}
		{sequence "scan_wide_to_idle" {resume}}
		{sequence "walkstart_l_045"
			{movement}	
			{resume}
		}
		{sequence "leds_global_hold" {resume}}
		{sequence "leds_global_search" {resume}}
		{sequence "leds_global_alarm" {resume}}		
		{sequence "rocket_ready_l" {resume}}
		{sequence "rocket_reload_l" {resume}}
		{sequence "rocket_ready_r" {resume}}
		{sequence "rocket_reload_r" {resume}}
		{sequence "health"
			{resume}
			{events 	
				{5 "5heal"} 
				{20 "20heal"} 
				{40 "40heal"} 
				{70 "70heal"} 
				{99 "explosion_harv"} 
			}
		}
	}
